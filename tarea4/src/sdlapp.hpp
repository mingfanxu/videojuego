#include <SDL.h>
#pragma once
#include <vector>
#include <string>
#include "motor/Pipeline.hpp "
#include "objetos/Figuras.hpp"

class SDLApp
{
    private:
    SDLApp();
    bool on_init();
    void on_evento(SDL_Event *evento);
    void on_fisicaupdate(double dt);
    void on_frameupdate(double dt);
    void on_limpiar();

    bool esta_corriendo;
    int WIDTH;
    int HEIGHT;

    SDL_Window* vnt;
    SDL_Surface* vntsurf; 
    SDL_Renderer* render;

    //singleton
    static SDLApp* instancia;

    // 02_lineas_figuras
    Pipeline *ensamble;
    std::vector <Coordenadas> testpixeles;
    std::vector <Coordenadas> testlineas;
    std::vector<Figura*> testfiguras;

    Pipeline *ensamble;
    std::vector<Coordenadas> testpixeles;
    std::vector<Coordenadas> testlineas;
    std::vector<Figura*>testfiguras;
    std::vector <Entidad*>lista_personajes;


    public:
    SDL_Color bg_color;
    static int on_correr();
    static void set_bgcolor(Uint8 rojo, Uint8 verde , Uint8 azul);
    static SDLApp& get();
    static bool estaCorriendo() {return get().esta_corriendo;}; 
};