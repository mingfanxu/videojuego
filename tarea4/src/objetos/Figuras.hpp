#pragma once
#include "../utilidad/Estructuras.hpp"
#include<vector>
#include<SDL.h>
#define PI 3.1416

class Figura //clase padre
{
    public:
        virtual ~Figura (){};
        Coordenadas get_posicion() const {return posicion;};
        std::vector <Coordenadas> get_vertices() const {return vertices;};
        void set_strokecolor (SDL_Color nc ) {lineacolor=nc;};
        SDL_Color get_strokecolor() const{ return lineacolor ;};
        void set_rellenocolor (SDL_Color nc ) {rellenocolor=nc;};
        SDL_Color get_rellenocolor() const { return rellenocolor;};

        bool get_serellena() const{return se_rellena;};
        void set_serellena ( bool v ) {se_rellena=v;}
    
    protected:
        std::vector <Coordenadas>vertices;
        Coordenadas posicion;
        SDL_Color lineacolor;
        SDL_Color rellenocolor;

        bool se_rellena;

};


//clases derivadas
// Rectangulo
class Rectangulo : public Figura
{
    public:
        Rectangulo(int x, int y, int w, int h, SDL_Color c);
};
//Triangulo
class Triangulo : public Figura
{
    public:
        Triangulo(int x, int y,)
}
//Circulo