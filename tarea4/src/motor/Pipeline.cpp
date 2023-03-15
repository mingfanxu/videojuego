#include "Pipeline.hpp"
#include "Plotter.hpp"

Pipeline::Pipeline (SDL_Renderer &ren)
{
    ptrren = &ren;
};

void Pipeline::puntos(std::vector<Coordenadas> p ,SDL_Color c)
{
    //cada p es un punto en el espacio, simplemente llamar a plotter para pintarlos
    for ( auto &punto:p )
        Plotter::render_pixel(ptrren,punto, c);
};

