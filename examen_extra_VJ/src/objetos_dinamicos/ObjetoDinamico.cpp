#include "ObjetoDinamico.hpp"
#include "../objetos/Figuras.hpp"
#include "../utilidad/Func_aux.hpp"
#include "../motor/camaras/ManejadorCamara.hpp"
#include "../motor/fisica/MotorFisico.hpp"
#include<iostream>
#include <math.h>

#define PI 3.1415926

/*
---
*/

BackGroundDinamico::BackGroundDinamico(std::string path_sprite,int w, int h)
{
    posicion_mundo.x=-w/2;
    posicion_mundo.y=0;
    posicion_camara = posicion_mundo;
    avatar= nullptr;
    tile = nullptr;
    col_box = nullptr;
    //toda la imagen sprite?
    limites.x = w;
    limites.y = 0;
    sprite = new Sprite(path_sprite,posicion_mundo,w,h,w,h);
    tiene_fisica=false;
    en_colision=false;
    velocidad=0;
    area_plataforma=nullptr;
    //crear la camara antes del background
    centro_cam = ManejadorCamaras::get_camara().get_posicion_centro();
};
void BackGroundDinamico::set_estado(void *estado){};
void* BackGroundDinamico::get_estado()
{
    return NULL;
}
void BackGroundDinamico::update(double dt)
{   
    //parallax/scroller reset    
    float dist = std::sqrt(std::pow( posicion_mundo.x-limites.x/2,2)+std::pow( posicion_mundo.y-limites.y,2));
    //DEBUGPRINT(dist)
    if(dist < (limites.x/2)+centro_cam.x-velocidad) //izquierda
    {
        //reset
        posicion_mundo.x=-(limites.x/2)-centro_cam.x-velocidad;
    }
    else if(dist > limites.x+centro_cam.x+velocidad) //derecha
    {
         //reset
        posicion_mundo.x=-(limites.x/2)+centro_cam.x+velocidad;
    }
};

/*
Plataformas Dinámicas
动态平台
*/

PlataformasDinamicas::PlataformasDinamicas(std::string sprite_path, int x, int y, int w, int h,int sw, int sh,SDL_Color c)
:ObjetoDinamico{}
{
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    posicion_camara = {0,0};
    avatar= nullptr;
    tile = nullptr;
    //usar para la colision
    col_box = new Rectangulo(x,y,sw,sh,c);
    col_box->set_serellena(false);
    render_colbox=false;

    //usar para el area de piso de la plataforma
    area_plataforma = new Rectangulo(x-10,y,sw+20,5,{0,0,255,255});

    //toda la imagen sprite?
    sprite      = new Sprite(sprite_path,posicion_mundo,w,h,sw,sh);
    tiene_fisica=false;
    en_colision =false;
    velocidad=0;
    nombre = "PlataformaDinamica";
};

void PlataformasDinamicas::update(double dt)
{
    area_plataforma->set_position(posicion_camara.x-10,posicion_camara.y);
    area_plataforma->update_vertices();
    //DEBUGCOOR(area_plataforma->get_posicion());
    //DEBUGPRINT(this)
    //DEBUGLINEA(posicion_mundo,posicion_camara)
};
void PlataformasDinamicas::set_estado(void* estado)
{

};
void* PlataformasDinamicas::get_estado()
{
    return NULL;
};

/*ARTEFACTO*/
Artefactos::Artefactos(std::string sprite_path, int x, int y, int w, int h,int sw, int sh,SDL_Color c)
:ObjetoDinamico{}
{
    posicion_mundo.x=x;
    posicion_mundo.y=y;
    posicion_camara = posicion_mundo;
    avatar= nullptr;
    tile = nullptr;
    //usar para la colision
    col_box = new Rectangulo(x,y,sw,sh,c);
    col_box->set_serellena(false);
    render_colbox=false;

    area_plataforma = nullptr;

    sprite      = new Sprite(sprite_path,posicion_mundo,w,h,sw,sh);
    tiene_fisica=false;
    en_colision =false;
    velocidad=10;
    frames_actual=0;
    frames_maximo=100;

    curAngle = 0;
    perAngle = 5;
    radius = 100;
};

void Artefactos::update(double dt)
{
    Pf = target->get_posicion_mundo(); //Pf使用插值函数  插值玩家位置  LERP是插值函数

    /*
    Pm.x = posicion_mundo.x+100;
    Pm.y = (posicion_mundo.y + Pf.y)/2;

    if(ReAjustar())
        frames_actual=0;

    if (frames_actual>frames_maximo)
        return;

    float t= (frames_actual/(float)frames_maximo);
    //DEBUGPRINT(t)
    Coordenadas A = LERP(posicion_mundo,Pm,t);
    Coordenadas B = LERP(A,Pf,t);
    posicion_mundo = LERP(A,B,t);
    frames_actual++;

    if(MotorFisico2D::aabb_colision(*col_box,*target->get_colbox()))
    {
        //se_borra=true;
    }
    */

    float d = curAngle * PI / 180;
    posicion_mundo.x = Pf.x + cos(d) * radius; 
    posicion_mundo.y = Pf.y + 60 + sin(d) * radius;

    curAngle += perAngle;
    curAngle %= 360;

};
void Artefactos::set_estado(void* estado)
{

};
void* Artefactos::get_estado()
{
    return NULL;
};

void Artefactos::set_target(Objeto& t)
{
    target =&t;
};

void Artefactos::render(SDL_Renderer *r)
{
    
    Pipeline temp{*r};
    Coordenadas inicio = posicion_camara;
    Coordenadas punto_medio;
    //punto_medio.x-=20;
    //punto_medio.y = (posicion_camara.y+target->get_posicion_camara().y)/2;
    Coordenadas punto_final = target->get_posicion_camara();
    temp.lineas({inicio,punto_final},{120,80,150,255});
}
bool Artefactos::ReAjustar()
{
    if (tempF.x!=Pf.x && tempF.y!= Pf.y )
    {
        tempF=Pf;
        return true;
    }
    return false;
};