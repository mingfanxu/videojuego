#pragma once
#include<SDL.h>
#include<vector>
#include "../utilidad/Estructuras.hpp"
#include "../objetos/Figuras.hpp"

#include "Plotter.hpp"

class Pipeline
{
    public:
    Pipeline(SDL_Renderer &ren);
    //quitar copias
    Pipeline (const Pipeline&) = delete;
    Pipeline &operator=(const Pipeline&) = delete;
    void puntos (std::vector<Coordenadas> p , SDL_Color c ) ;
    void lineas (std::vector<Coordenadas> p, SDL_Color c);
    void figuras (std::vector <Figura*> f);

    private:
    SDL_Renderer *ptrren;
};

