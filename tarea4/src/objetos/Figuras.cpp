#include "Figuras.hpp"

Rectangulo::Rectangulo(int x, int y, int w, int h, SDL_Color c)
{

    set_rellenocolor(c);
    set_strokecolor(c);
    set_serellena(true);
    //vertices
    vertices.push_back({x-w/2,y-h/2}); //a
    vertices.push_back({x+w/2,y-h/2}); //b
    vertices.push_back({x+w/2,y+h/2}); //a
    vertices.push_back({x-w/2,y+h/2}); //a

};

Triangulo::Triangulo(Coordenadas p1, Coordenadas p2, Coordenadas p3, SDL_Color color)
{
    // de L to R
    posicion = p1;
    pivote = p1;
    A = p1;
    B = p2;
    C = p3;
    lineacolor = color;
    this->generar_vertices();
    se_rellena=true;
};

Circulo::Circulo(int r,int x, int y, int numvertices,SDL_Color color)
{
    radio = r;
    segmentos = numvertices;
    posicion = Coordenadas{x,y};
    lineacolor = color;
    this->generar_vertices();
    se_rellena=true;
}