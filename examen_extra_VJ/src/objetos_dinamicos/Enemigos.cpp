#include "Enemigos.hpp"
#include "../utilidad/Func_aux.hpp"
#include <iostream>
#include <cmath>





Enemigo::Enemigo(std::string path_xml,float vida, int x, int y, int sw,int sh, SDL_Color c )
:ObjetoDinamico{}
{
    hp=vida;
    hp_max=vida;
    posicion_mundo = {x,y};
    posicion_camara = {0,0};
    avatar = nullptr;
    col_box = new Rectangulo(x,y,sw,sh,c);
    col_box->set_serellena(false);
    tiene_fisica = true;
    en_colision = false;
    estado_actual = new FSMEnemigo_IDLE();
    tile = nullptr;
    sprite = new Sprite(path_xml,posicion_mundo,sw,sh);
    velocidad=2000;
    dtgravedad=0;

    col_ataque=nullptr;
    col_dano=nullptr;

    KeyPot[0] = { 650,580 };
    KeyPot[1] = { 1145,580 };
    KeyPot[2] = { 1145,1100 };
    KeyPot[3] = { 650,1100 };

    posicion_mundo = KeyPot[0];

    dir = 0;
    clockwise = 0;

};

bool Enemigo::closePot(Coordenadas p)
{
    int x = posicion_mundo.x - p.x;
    int y = posicion_mundo.y - p.y;
    return sqrt(x * x + y * y) < 10;
}

void Enemigo::update(double dt)
{    
    if(!estado_actual)
        return;
    
    estado_actual->update(*this,dt);

    /*DEBUGPRINT("Enemigo: "<<this)
    DEBUGCOOR(this->posicion_mundo)
    DEBUGCOOR(posicion_camara)*/

    if (clockwise > 0)
    {
        int dirto = (dir + 1) % 4;
        if (closePot(KeyPot[dirto]))
        {
            posicion_mundo = KeyPot[dirto];
            dir = (dir + 1) % 4;
        }
        else
        {
            if (dir == 0)
            {
                posicion_mundo.x += velocidad * dt;           
            }
            else if (dir == 1)
            {
                posicion_mundo.y += velocidad * dt;
            }
            else if (dir == 2)
            {
                posicion_mundo.x -= velocidad * dt;
            }
            else if (dir == 3)
            {
                posicion_mundo.y -= velocidad * dt;
            }
        }        
    }
    else if (clockwise < 0)
    {
        if (closePot(KeyPot[dir]))
        {
            posicion_mundo = KeyPot[dir];
            dir = dir - 1;
            if(dir < 0) dir = 3;
        }
        else
        {
            if (dir == 0)
            {
                posicion_mundo.x -= velocidad * dt;
            }
            else if (dir == 1)
            {
                posicion_mundo.y -= velocidad * dt;
            }
            else if (dir == 2)
            {
                posicion_mundo.x += velocidad * dt;
            }
            else if (dir == 3)
            {
                posicion_mundo.y += velocidad * dt;
            }
        }
    }
};
        
void Enemigo::set_estado(void* estado)
{
    //DEBUGPRINT("Dejando estado "<<estado_actual->get_namestate())
    estado_actual->salir(*this);
    delete estado_actual;
    estado_actual = (FSMEnemigo*) estado;
    estado_actual->entrar(*this);
    //DEBUGPRINT("Entrando estado "<<estado_actual->get_namestate())
};
void* Enemigo::get_estado()
{
    return estado_actual;
};

void Enemigo::MoverDerecha(double dt)
{
    posicion_mundo.x+=velocidad*dt;
};
void Enemigo::MoverIzquierda(double dt)
{
    posicion_mundo.x-=velocidad*dt;
};
void Enemigo::MoverArriba(double dt)
{
    posicion_mundo.y-=velocidad*dt;
};
void Enemigo::MoverAbajo(double dt)
{
    posicion_mundo.y+=velocidad*dt;
};
void Enemigo::Brincar(double dt)
{

};
void Enemigo::Atacar(double dt)
{

};