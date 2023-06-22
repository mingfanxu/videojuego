#include "FSMJugador.hpp"
#include "../Func_aux.hpp"
#include<SDL.h>
#include<iostream>
#include <sstream>
#include "../../motor/fisica/MotorFisico.hpp"
#include "../../motor/Plotter.hpp"
#include "../../motor/camaras/ManejadorCamara.hpp"
#include <cmath>

/*
IDLE
禁止不动的时候
*/
EstadoJugadorIDLE::EstadoJugadorIDLE()
{
    strnombre = "IDLE";
    frames_actual_ani=0;
    frames_maxim_ani=1;
    dir=1;
};

FSMJugador* EstadoJugadorIDLE::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    /*#if defined(GRAVEDAD)
    if(input.estaPresionado(SDL_SCANCODE_SPACE))
        return new EstadoJugadorGravedadBrinco(-10);
    #endif*/

    if( ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_A))) 
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_A))))
    {
        return NULL;
    }

    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorDerecha();
    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorIzquierda();
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorArriba();
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorAbajo();
    
    

    return NULL;
};
void EstadoJugadorIDLE::entrar(Jugador& player)
{
    frames_actual_ani=0;
    frames_maxim_ani=1;
    //DEBUGCOOR(player.get_piso());
    dir = (player.get_sprite()->get_flip())? -1 : 1;
    //printf("DIR: %d\n",dir);
};
void EstadoJugadorIDLE::salir(Jugador& player)
{

};
void EstadoJugadorIDLE::update(Jugador& player,double dt)
{
    player.get_sprite()->play_frame("IdleBlue",frames_actual_ani%frames_maxim_ani);
    if(frame_dt>7)
    {
        frame_dt=0;
        frames_actual_ani++;
    }
    frame_dt++;

};

/*
MOVER移动
*/

//游戏角色左手
EstadoJugadorIzquierda::EstadoJugadorIzquierda()
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    strnombre="IZQUIERDA";
};
void EstadoJugadorIzquierda::entrar(Jugador &player)
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    player.get_sprite()->set_flip(true);
};

void EstadoJugadorIzquierda::salir(Jugador &player)
{
    //player.get_sprite()->set_flip(false);
};

FSMJugador* EstadoJugadorIzquierda::input_handle(KeyOyente& input, MouseOyente& mouse)
{

    if( ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_A))) 
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_A))))
    {
        return NULL;
    }

    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorDerecha();
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorAbajo();
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorArriba();


    /*#if defined(GRAVEDAD)
    if(input.estaPresionado(SDL_SCANCODE_SPACE))
        return new EstadoJugadorGravedadBrinco(-10);
    
    #endif*/

    if(!(input.estaPresionado(SDL_SCANCODE_A)) && !(input.estaPresionado(SDL_SCANCODE_D)) 
    && !(input.estaPresionado(SDL_SCANCODE_W)) && !(input.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoJugadorIDLE();
    }

    return NULL;
};

void EstadoJugadorIzquierda::update(Jugador &player, double dt)
{
    //animación solamente
    player.get_sprite()->play_frame("WalkBlue",frames_actual_ani%frames_maxim_ani);

    if(frame_dt>3)
    {
        frame_dt=0;
        frames_actual_ani++;
    }
    frame_dt++;
};

//--游戏角色右手
EstadoJugadorDerecha::EstadoJugadorDerecha()
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    strnombre="DERECHA";
};
void EstadoJugadorDerecha::entrar(Jugador &player)
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    player.get_sprite()->set_flip(false);
    //ManejadorCamaras::unluck_objeto();
};

void EstadoJugadorDerecha::salir(Jugador &player)
{
    //player.get_sprite()->set_flip(false);
    //ManejadorCamaras::lock_objeto(player);
};

FSMJugador* EstadoJugadorDerecha::input_handle(KeyOyente& input, MouseOyente& mouse)
{

    if( ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_A))) 
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_A))))
    {
        return NULL;
    }

    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorIzquierda();
    
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorAbajo();
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorArriba();

    

    /*#if defined(GRAVEDAD)
    if(input.estaPresionado(SDL_SCANCODE_SPACE))
        return new EstadoJugadorGravedadBrinco(-10);
    #endif*/

    if(!(input.estaPresionado(SDL_SCANCODE_A)) && !(input.estaPresionado(SDL_SCANCODE_D)) 
    && !(input.estaPresionado(SDL_SCANCODE_W)) && !(input.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoJugadorIDLE();
    }

    return NULL;
};

void EstadoJugadorDerecha::update(Jugador &player, double dt)
{
    //animación
    player.get_sprite()->play_frame("WalkBlue",frames_actual_ani%frames_maxim_ani);

    if(frame_dt>3)
    {
        frame_dt=0;
        frames_actual_ani++;
    }
    frame_dt++;
};

/*
Arriba 上
*/

EstadoJugadorArriba::EstadoJugadorArriba()
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    strnombre="arriba";
};
void EstadoJugadorArriba::entrar(Jugador &player)
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    //player.get_sprite()->set_flip(false);
    //ManejadorCamaras::unluck_objeto();
};

void EstadoJugadorArriba::salir(Jugador &player)
{
    //player.get_sprite()->set_flip(false);
    //ManejadorCamaras::lock_objeto(player);
};

FSMJugador* EstadoJugadorArriba::input_handle(KeyOyente& input, MouseOyente& mouse)
{

    if( ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_A))) 
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_A))))
    {
        return NULL;
    }

    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorIzquierda();
    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorDerecha();
    if(input.estaPresionado(SDL_SCANCODE_S))
        return new EstadoJugadorAbajo();
    
    

    /*#if defined(GRAVEDAD)
    if(input.estaPresionado(SDL_SCANCODE_SPACE))
        return new EstadoJugadorGravedadBrinco(-10);
    #endif*/

    if(!(input.estaPresionado(SDL_SCANCODE_A)) && !(input.estaPresionado(SDL_SCANCODE_D)) 
    && !(input.estaPresionado(SDL_SCANCODE_W)) && !(input.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoJugadorIDLE();
    }

    return NULL;
};

void EstadoJugadorArriba::update(Jugador &player, double dt)
{
    //animación
    player.get_sprite()->play_frame("ClimbBlue",frames_actual_ani%frames_maxim_ani);

    if(frame_dt>3)
    {
        frame_dt=0;
        frames_actual_ani++;
    }
    frame_dt++;
};

/*
Abajo
*/

EstadoJugadorAbajo::EstadoJugadorAbajo()
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    strnombre="arriba";
};
void EstadoJugadorAbajo::entrar(Jugador &player)
{
    frames_actual_ani=0;
    frames_maxim_ani=2;
    player.get_sprite()->set_flip(false);
    //ManejadorCamaras::unluck_objeto();
};

void EstadoJugadorAbajo::salir(Jugador &player)
{
    //player.get_sprite()->set_flip(false);
    //ManejadorCamaras::lock_objeto(player);
};

FSMJugador* EstadoJugadorAbajo::input_handle(KeyOyente& input, MouseOyente& mouse)
{

    if( ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_W)) && (input.estaPresionado(SDL_SCANCODE_A))) 
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_D)))
    ||  ( (input.estaPresionado(SDL_SCANCODE_S)) && (input.estaPresionado(SDL_SCANCODE_A))))
    {
        return NULL;
    }

    if(input.estaPresionado(SDL_SCANCODE_A))
        return new EstadoJugadorIzquierda();
    if(input.estaPresionado(SDL_SCANCODE_D))
        return new EstadoJugadorDerecha();
    if(input.estaPresionado(SDL_SCANCODE_W))
        return new EstadoJugadorArriba();
    
    

    /*#if defined(GRAVEDAD)
    if(input.estaPresionado(SDL_SCANCODE_SPACE))
        return new EstadoJugadorGravedadBrinco(-10);
    #endif*/

    if(!(input.estaPresionado(SDL_SCANCODE_A)) && !(input.estaPresionado(SDL_SCANCODE_D)) 
    && !(input.estaPresionado(SDL_SCANCODE_W)) && !(input.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoJugadorIDLE();
    }

    return NULL;
};

void EstadoJugadorAbajo::update(Jugador &player, double dt)
{
    //animación
    player.get_sprite()->play_frame("WalkBlue",frames_actual_ani%frames_maxim_ani);

    if(frame_dt>3)
    {
        frame_dt=0;
        frames_actual_ani++;
    }
    frame_dt++;
};

/*
- BRINCO GRAVEDAD  跳跃
*/
EstadoJugadorGravedadBrinco::EstadoJugadorGravedadBrinco(int fuerza)
{
    f=fuerza;
    frames_actual_ani=0;
    frames_maxim_ani=1;
    strnombre="BRINCAR";
    en_aire=true;
};

FSMJugador * EstadoJugadorGravedadBrinco::input_handle(KeyOyente& input, MouseOyente& mouse)
{
    if(!en_aire)
        return new EstadoJugadorIDLE();
    
    if(input.estaPresionado(SDL_SCANCODE_D))
        P1.x+=1;
    if(input.estaPresionado(SDL_SCANCODE_A))
        P1.x-=1;

    return NULL;
};

void EstadoJugadorGravedadBrinco::entrar(Jugador& player)
{
    player.set_dtgf(f);
    P1 = player.get_posicion_mundo();//player.get_piso();
    en_aire=true;
    player.set_onPlataforma(false);

    //ManejadorCamaras::set_estado(new EstadoCamaraTransicion());

};
void EstadoJugadorGravedadBrinco::salir(Jugador& player)
{
    
};

void EstadoJugadorGravedadBrinco::update(Jugador& player,double dt)
{

    player.get_sprite()->play_frame("JumpBlue",frames_actual_ani%frames_maxim_ani);
    P1.y+=player.get_dtgf(); 

    player.set_posicion_mundo(P1);
    if(player.get_onPlataforma())
        en_aire=false;
    
    if(frame_dt>(int)13)
    {
        frame_dt=0;
        if(frames_actual_ani<frames_maxim_ani-1)
            frames_actual_ani++;
    }
    frame_dt++;
};
