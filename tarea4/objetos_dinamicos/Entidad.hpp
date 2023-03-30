#pragma once 
#include "../objetos/Figuras.hpp"
#include "../motor/KeyOyente.hpp"
#include "../utilidad/Estructuras.hpp"
#include <SDL.h> 
#include<string>
class Entidad
{
    protected:
        Figura* avatar;
        int vidas;
        Coordenadas vel;

    public:
        virtual ~Entidad(){};
        virtual void update ( double dt )=0;
        virtual std::string get_estadonombre()= 0;
        inline bool esta_vivo() const{return vidas > 0;};
        virtual void inputHandle (KeyOyente& input)=0;
        void render (SDL_Renderer *r);
        int get_vida() const{return vidas;};
        void set_vida (int v ) {vidas=v;};
        Figura* get_avatar() const{return avatar;};
        Coordenadas get_vel() const{return vel;};
        void set_vel(Coordenadas nv){vel=nv;};
} ;