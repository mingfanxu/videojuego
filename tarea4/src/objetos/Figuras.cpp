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