#include "Arbustos.hpp"

Arbusto::Arbusto(std::string xml,Coordenadas pos,int col_init,int row_init,int rows,int cols)
{ 
    hp=100;
    hp_max=hp;
    posicion_mundo=pos;
    posicion_camara=pos;
    this->row_init = row_init;
    sprite = new Sprite(xml,pos,100,100);

    width = sprite->get_sprite_src()->w;
    height = sprite->get_sprite_src()->h ;

    sprite->get_sprite_src()->x = (col_init-1)*width ; // inicio
    sprite->get_sprite_src()->y = (row_init-1)*height;
    sprite->get_sprite_src()->w = width*cols;
    sprite->get_sprite_src()->h = height*rows;

    col_box = new Rectangulo(pos.x,pos.y,100,100,{255,255,100,255});
    col_box->set_serellena(false);

    avatar=nullptr;
    tile = nullptr;
    area_plataforma=nullptr;

}

void Arbusto::update(double dt)
{

};

void Arbusto::set_estado(void* estado)
{

};
void* Arbusto::get_estado()
{
    return NULL;
};