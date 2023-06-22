#include "FSMEnemigo.hpp"
#include <iostream>
#include "../Func_aux.hpp"

void FSMEnemigo_IDLE::entrar(Enemigo& enemigo)
{
    frames_actual_ani= 0;
    frames_maxim_ani = 1;
    strnombre = "IDLE";
};
void FSMEnemigo_IDLE::salir(Enemigo& enemigo)
{

};
void FSMEnemigo_IDLE::update(Enemigo& enemigo,double dt)
{
    if(frames_actual_ani>=frames_maxim_ani)
        return;
    enemigo.get_sprite()->play_frame("Idle",frames_actual_ani%frames_maxim_ani);
    frames_actual_ani++;
};


void FSMEnemigo_MoverDerecha::entrar(Enemigo& enemigo)
{
    frames_actual_ani= 0;
    frames_maxim_ani = 9;
    strnombre = "MoverDerecha";
};
void FSMEnemigo_MoverDerecha::salir(Enemigo& enemigo)
{

};
void FSMEnemigo_MoverDerecha::update(Enemigo& enemigo,double dt)
{
    enemigo.get_sprite()->play_frame("Walk",frames_actual_ani%frames_maxim_ani);
    //enemigo.MoverDerecha(1);

    if(frame_dt> 3)
    {
        frame_dt=0;
        frames_actual_ani++;
    }

    frame_dt++;
    
};

void FSMEnemigo_MoverIzquierda::entrar(Enemigo& enemigo)
{
    frames_actual_ani= 0;
    frames_maxim_ani = 9;
    strnombre = "MoverIzquierda";
};
void FSMEnemigo_MoverIzquierda::salir(Enemigo& enemigo)
{

};
void FSMEnemigo_MoverIzquierda::update(Enemigo& enemigo,double dt)
{

    enemigo.get_sprite()->play_frame("Walk",frames_actual_ani%frames_maxim_ani);
    //enemigo.MoverIzquierda(1);

    if(frame_dt> 3)
    {
        frame_dt=0;
        frames_actual_ani++;
    }

    frame_dt++;
    
};
