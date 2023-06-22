#include "Jugador.hpp"
#include <math.h>
#include<iostream>


Jugador::Jugador(std::string path_sprite,float vida, int x, int y, int w, int h, int sw, int sh, SDL_Color c)
:ObjetoDinamico{}
{
    hp = vida;
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    posicion_camara={0,0};
    avatar = new Rectangulo(x,y,sw,sh,c);
    c.a=150;
    color = c;
    avatar->set_rellenocolor(c);
    avatar->set_serellena(false);
    col_box = new Rectangulo(x,y-5,sw-25,sh-10,c);
    col_box->set_serellena(false);
    tiene_fisica = true;
    en_colision = false;
    estado_actual = new EstadoJugadorIDLE();

    c.a=255;
    col_piso = new Rectangulo(x+10,y+sh,sw/2+10,10,{150,200,0,255});


    piso = {x,y+sw}; // definir el piso en general
    sprite = new Sprite(path_sprite,posicion_mundo,w,h,sw,sh);
    tile = nullptr;
    objetos=nullptr;
    velocidad=5;
    dtgravedad=0;
    area_plataforma=col_piso;
    centro={posicion_camara.x+sprite->get_sprite_sizes().x/2,posicion_camara.y+sprite->get_sprite_sizes().y/2};
    
    col_ataque=nullptr;
    col_dano=nullptr;

    dir = 0;
};

Jugador::Jugador(std::string path_xml,float vida, int x, int y, int sw,int sh, SDL_Color c )
:ObjetoDinamico{}
{
    hp=vida;
    hp_max=vida;
    posicion_mundo = {x,y};
    posicion_camara = {0,0};
    avatar = new Rectangulo(x,y,sw,sh,c);
    avatar->set_rellenocolor(c);
    avatar->set_serellena(false);
    col_box = new Rectangulo(x,y,sw,sh,c);
    col_box->set_serellena(false);
    tiene_fisica = true;
    en_colision = false;
    estado_actual = new EstadoJugadorIDLE();
    tile = nullptr;
    sprite = new Sprite(path_xml,posicion_mundo,sw,sh);
    velocidad=5;
    dtgravedad=0;

    piso = {x,y+sw}; // definir el piso en general
    col_piso = new Rectangulo(x+10,y+sh,sw/2+10,10,{150,200,0,255});
    col_piso->set_serellena(false);
    area_plataforma=col_piso;
    area_plataforma->set_serellena(false);
    centro={posicion_camara.x+sprite->get_sprite_sizes().x/2,posicion_camara.y+sprite->get_sprite_sizes().y/2};

    col_ataque=new Rectangulo(x+sw,y+sh/2,sw,sh/3,{255,0,255,50});
    col_ataque->set_rellenocolor({255,0,255,50});
    col_ataque->set_serellena(false);
    col_dano= new Rectangulo(x,y,sw,sh/2,{255,0,0,128});
    col_dano->set_rellenocolor({255,0,0,50});
    col_dano->set_serellena(false);
};


std::string Jugador::get_strEstado()
{
    return estado_actual->get_namestate();
};

void* Jugador::get_estado()
{
    return estado_actual;
};

void Jugador::set_estado(void* estado)
{
    estado_actual->salir(*this);
    delete estado_actual;
    estado_actual = (FSMJugador*)estado;
    estado_actual->entrar(*this);
};

void Jugador::set_onPlataforma(bool v)
{
    en_plataforma=v;
};

void Jugador::update(double dt)
{
    if(!estado_actual) //nulo
        return;

    centro={posicion_camara.x+sprite->get_sprite_sizes().x/2,posicion_camara.y+sprite->get_sprite_sizes().y/2};
    if(area_plataforma)
    {
        area_plataforma->set_position(posicion_camara.x+20,posicion_camara.y+sprite->get_sprite_sizes().y-10);
        area_plataforma->update_vertices();
    }

    if(col_dano)
    {
        col_dano->set_position(posicion_camara.x,posicion_camara.y+sprite->get_sprite_sizes().y/2);
        col_dano->update_vertices();
    }

    if(col_ataque)
    {
        if (dir == 1)
        {
            col_ataque->set_position( //左
                posicion_camara.x - sprite->get_sprite_sizes().x + 60, 
                posicion_camara.y + sprite->get_sprite_sizes().y / 2 - 60
            );
            col_ataque->update_vertices();
        }
        else if (dir == -1)
        {
            col_ataque->set_position(
                posicion_camara.x - sprite->get_sprite_sizes().x + 60, 
                posicion_camara.y + sprite->get_sprite_sizes().y / 2 + 80
            );
            col_ataque->update_vertices();
        }
        else
        {
            if (sprite->get_flip())
            {
                col_ataque->set_position(
                    posicion_camara.x - sprite->get_sprite_sizes().x, 
                    posicion_camara.y + sprite->get_sprite_sizes().y / 2
                );
                col_ataque->update_vertices();
            }
            else
            {
                col_ataque->set_position(
                    posicion_camara.x + sprite->get_sprite_sizes().x, 
                    posicion_camara.y + sprite->get_sprite_sizes().y / 2
                );
                col_ataque->update_vertices();
            }
        }        
    }

    estado_actual->update(*this,dt);
    
    //reset
    
    if(en_plataforma) 
    {
        set_dtgf(0);
    }
    set_onPlataforma(false);
    
    /* float magnitud = std::sqrt(std::pow(centro.x-guia.x,2)+std::pow(centro.y-guia.y,2));
    float angulo = std::atan2(centro.y-guia.y,centro.x-guia.x)*180/3.14159265;
    DEBUGPRINT("Magnitud: "<<magnitud)
    DEBUGPRINT("Angulo: "<<angulo) */

};

void Jugador::input_handle(KeyOyente& input,MouseOyente& mouse)
{
    if(!estado_actual) //nulo
        return;
    FSMJugador* estado = estado_actual->input_handle(input,mouse);
    if(estado)
    {
        set_estado(estado);
    }
};

void Jugador::MoverDerecha(double dt)
{
    dir = 0;
    posicion_mundo.x+=velocidad*dt;
    guia.x = posicion_camara.x+100;
    guia.y = posicion_camara.y;

};
void Jugador::MoverIzquierda(double dt)
{
    dir = 0;
    posicion_mundo.x-=velocidad*dt;
    guia.x = posicion_camara.x-100;
    guia.y = posicion_camara.y;
};
void Jugador::MoverArriba(double dt)
{
    dir = 1;
    posicion_mundo.y-=velocidad*dt;
    guia.y = posicion_camara.y-100;
    guia.x = posicion_camara.x;
};
void Jugador::MoverAbajo(double dt)
{
    dir = -1;
    posicion_mundo.y+=velocidad*dt;
    guia.y = posicion_camara.y+100;
    guia.x = posicion_camara.x;
};

void Jugador::MoverArribaDerecha(double dt)
{
    dir = 0;
    posicion_mundo.y-=velocidad*dt;
    posicion_mundo.x+=velocidad*dt;
    guia.y = posicion_camara.y-100;
    guia.x = posicion_camara.x+100;
};
void Jugador::MoverArribaIzquierda(double dt)
{
    dir = 0;
    posicion_mundo.y-=velocidad*dt;
    posicion_mundo.x-=velocidad*dt;
    guia.y = posicion_camara.y-100;
    guia.x = posicion_camara.x-100;
};
void Jugador::MoverAbajoDerecha(double dt)
{
    dir = 0;
    posicion_mundo.y+=velocidad*dt;
    posicion_mundo.x+=velocidad*dt;
    guia.y = posicion_camara.y+100;
    guia.x = posicion_camara.x+100;
};
void Jugador::MoverAbajoIzquierda(double dt)
{
    dir = 0;
    posicion_mundo.y+=velocidad*dt;
    posicion_mundo.x-=velocidad*dt;
    guia.y = posicion_camara.y+100;
    guia.x = posicion_camara.x-100;
};

void Jugador::AtaqueUno(Objeto* obj,double dt)
{

};