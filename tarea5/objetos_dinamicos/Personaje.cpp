#include "Personaje.hpp"
#include "../utilidad/Estructuras.hpp"
#include "../utilidad/Func_aux.hpp"
#include <SDL.h>
#include<iostream>
Personaje::Personaje (int v , Figura* av)
{
    avatar = av;
    estado_actual=new EstadoPersonajeReposo();
    vidas = v;
    avatar->set_rellenocolor(avatar->get_strokecolor());
    avatar->set_serellena(true);
} ;

void Personaje::inputHandle (KeyOyente& input)
{
    if(input.estaPresionado (SDLK_d ))
    {
        set_vel({10,0});
    }

    if(input.estaPresionado(SDLK_a))
    {
        set_vel({-10,0});
    }

    if(input.estaPresionado (SDLK_w))
    {
        set_vel({0,-10});
    }

    if(input.estaPresionado(SDLK_s))
    {
        set_vel({0,10});
    }

    FSM* estado = estado_actual->handle Input(*this ,input);

    if(estado)
    {
    // salir del estado anterior
    estado_actual->salir (*this);
    //borrar estado anterior
    estado_actual = estado;
    //transicion al siguiente estado
    estado_actual->entrar (* this);
    }
} ;

void Personaje::update ( double dt)
{
    estado_actual->update(* this,dt);
};

std::string Personaje::get_estadonombre()
{
    return estado_actual->get_namestate();
};

EstadoPersonajeReposo::EstadoPersonajeReposo()
{
    strnombre = "estado REPOSO";
} ;

FSM* EstadoPersonajeReposo::handleInput (Entidad& personaje, KeyOyente& input)
{
    if(input.estaPresionado (SDLK_g))
    {
        return new EstadoPersonajeGirar();
    }
    if (input.estaPresionado (SDLK_w) | input.estaPresionado (SDLK_s)
        | input.estaPresionado (SDLK_a ) | input.estaPresionado (SDLK_d))
    {
        return new EstadoPersonajeMover();
    }
// si no aplasto nada me quedo en reposo
    return NULL;
} ;

void EstadoPersonajeReposo::entrar ( Entidad& personaje)
{
    printf (" \x1B [32m Entrando al estado reposo \x1B [0m \n ");
} ;

void EstadoPersonajeReposo::salir ( Entidad& personaje)
{
    printf " \x1B [ 32m Saliendo del estado reposo \x1B [ 0m \n ");
} ;

void EstadoPersonajeReposo::update ( Entidad& personaje , double dt )
{
    if(personaje.esta_vivo())
    {
        // resetear todo
        personaje.set_vel({0,0});
    }
} ;

EstadoPersonajeGirar::EstadoPersonajeGirar()
{
    strnombre = "estado Girar";
} ;
FSM* EstadoPersonajeGirar::handleInput ( Entidad& personaje, KeyOyente& input)
{
    if(!input.estaPresionado (SDLK_g))
    {
        return new EstadoPersonajeReposo();
    }
    // si no aplasto nada me quedo en girar
    return NULL;
} ;


void EstadoPersonajeGirar::entrar ( Entidad& personaje)
{
    printf (" \x1B [ 34m Entrando al estado Girar \x1B [ 0m \n ");
} ;

void EstadoPersonajeGirar::salir ( Entidad& personaje)
{
    printf ( " \x1B [ 34m Saliendo del estado Girar \x1B [ 0m \n ");
} ;

void EstadoPersonajeGirar::update ( Entidad& personaje , double dt)
{
    /*
    En contrar el centro=
    0.25∗(A.x+B.x+C.x+D.x),0.25∗(A.y+B.y+C.y+D.y)
    */
    std::vector <Coordenadas> rotado = personaje.get_avatar()->get_vertices();
    Coordenadas centro = personaje.get_avatar()->get_posicion ();
    for(int i =0; i<rotado.size();++i)
    {
    rotado [ i ] = TRASLADAR(rotado [ i ] ,{ -centro.x,- centro.y});
    rotado [ i ] = ROTAR(-PI*dt , rotado [ i ]);
    rotado [ i ] = TRASLADAR(rotado[i],centro);
    //DEBUGCOOR(rotado [ i ] )
    }
    personaje.get_ avatar()->set_vertices (rotado);
} ;