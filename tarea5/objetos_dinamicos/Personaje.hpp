#pragma once
#include "Entidad.hpp"
#include "../objetos/Figuras.hpp"
#include "../utilidad/FSM.hpp"
#include "../motor/KeyOyente.hpp"
class Personaje:public Entidad
{
    public:
        virtual ~Personaje(){};
        Personaje (int v , Figura* av);
        void inputHandle (KeyOyente& input);
        void update ( double dt );
        std::string get_estadonombre();
    private:
        FSM * estado_actual;
} ;

class EstadoPersonajeReposo:public FSM
{
    public:
        EstadoPersonajeReposo ( ) ;
        FSM* handleInput ( Entidad& personaje , KeyOyente& input);
        void entrar (Entidad& pesonaje);
        void salir ( Entidad& personaje);
        void update (Entidad& personaje, double dt);
} ;

class EstadoPersonajeGirar:public FSM
{
    public:
        EstadoPersonajeReposo ( ) ;
        FSM* handleInput ( Entidad& personaje , KeyOyente& input);
        void entrar (Entidad& pesonaje);
        void salir ( Entidad& personaje);
        void update (Entidad& personaje, double dt);
};

class EstadoPersonajeMover:public FSM
{
    public:
        EstadoPersonajeMover();
        FSM* handle Input ( Entidad& personaje , KeyOyente& input);
        void entrar ( Entidad& personaje);
        void salir ( Entidad& personaje);
        void update ( Entidad& personaje , double dt);
} ;

EstadoPersonajeMover::EstadoPersonajeMover()
{
    strnombre = "estado MOVER";
} ;

FSM* EstadoPersonajeMover::handle Input ( Entidad& personaje , KeyOyente& input)
{
    if( !input.estaPresionado(SDLK_w) | !input.estaPresionado ( SDLK_s ) |
        !input.estaPresionado (SDLK_a) | !input.estaPresionado (SDLK_d ))
    {
        return new EstadoPersonajeReposo ( ) ;
    }
    // si estoya plastando las direcciones me quedo en mover
    return NULL ;
} ;

void EstadoPersonajeMover::entrar ( Entidad& personaje)
{
    printf ( " \x1B [ 36m Entrando al estado Mover \x1B [ 0m \n ");
} ;

void EstadoPersonajeMover::salir(Entidad& personaje)
{
    printf ( " \x1B [ 36m Saliendo del estado Mover \x1B [0m \n ");
} ;

void EstadoPersonajeMover::update (Entidad& personaje , double dt)
{
    Coordenadas pos = personaje.get_avatar()->get_posicion ();
    pos = TRASLADAR( pos,personaje.get_vel());
    personaje.get_avatar ()->set_ position (pos.x,pos.y);
    personaje.get_avatar()->update_vertices();
} ;