#include "HUD.hpp"
#include "../objetos/Figuras.hpp"
#include <iostream>

HUD* HUD::instancia =0;
int HUD::num_botones = 10;

HUD::HUD()
{
    ensamble=nullptr;
    sprite_controles = new Sprite*[HUD::num_botones];
    for (int i=0;i<HUD::num_botones;i++)
    {
        sprite_controles[i] = new Sprite("assets/spritesheets/spritesheet_complete.xml",{100,100},16,16);
    }
    
};
HUD::~HUD()
{
    for (int i=0;i<HUD::num_botones;i++)
    {
        delete [] sprite_controles[i];
    }
    delete sprite_controles;
}
HUD& HUD::get()
{
    if(!instancia)
        instancia = new HUD();
    return *instancia;
}

void HUD::set_pipeline(Pipeline &p)
{
    get().ensamble = &p;
};
void HUD::show_vida(Objeto* ente, Coordenadas pos_mundo,SDL_Color color)
{
    int rec_max = 250;
    int rec_por = (ente->get_hp()/ente->get_hpmax())*rec_max;

    if (rec_por<=0)
        rec_por=0;

    Coordenadas centro;
    centro.x = ente->get_posicion_camara().x - rec_max/3;
    centro.y = ente->get_posicion_camara().y;

    Rectangulo hp(centro.x,centro.y,rec_por,20,{color.r,color.g,color.b,100});
    hp.set_rellenocolor({color.r,color.g,color.b,100});
    hp.set_serellena(true);
    Rectangulo hpmax(centro.x,centro.y,rec_max,20,color);
    hpmax.set_serellena(false);
    get().ensamble->figuras(&hp);
    get().ensamble->figuras(&hpmax);
};
void HUD::show_stats(Objeto* ente, Coordenadas pos_mundo,SDL_Color color)
{

};
void HUD::show_controles(Coordenadas pos_mundo, SDL_Color color)
{

};