#include "Pipeline.hpp"
#include "../motor/Plotter.hpp"


Pipeline::Pipeline (SDL_Renderer &ren)
{
    ptrren = &ren;
};

void Pipeline::puntos(std::vector<Coordenadas> p ,SDL_Color c)
{
    //cada p es un punto en el espacio, simplemente llamar a plotter para pintarlos
    for ( auto &punto:p )
        Plotter::get().render_pixel(ptrren,punto, c);
};

void Pipeline::figuras (std::vector <Figura*> f)
{
    // asumiend o que las lineas de la figuras estan p1−p2−p3−loop
    for ( auto &fig:f){
    // primero rellenamos para tapar imperfectos
        Plotter::get().rellenoscandline ( ptrren , fig);
    // luego los contornos
    // codigo de la actividad pasada    
        int nv = fig->get_vertices().size();
        std::vector<Coordenadas> copia = fig->get_vertices();
        for(int i=0;i<nv;++i)
            Plotter::get().render_linea(ptrren,copia[i],copia[(i+1)%nv] ,fig->get_rellenocolor());
    }
    
};


