#pragma once
#include "Figuras.hpp"
#include "../utilidad/Estructuras.hpp"
#include "../motor/imagen/sprites.hpp"
#include "../motor/imagen/tiles.hpp"
#include <SDL.h>

/**
 *  Objeto 
 *  Esta clase se encarga de ser la interface para todo lo relacionado con Objetos o entes de todo el motor gráfico.
 *  Es una clase Abstracta
 */
class Objeto
{
    protected:
        /**
         * atributo avatar
         * Este atributo es un objeto por defecto cuando no hay un Sprite o Tile.
         * Se utiliza como un Rectangulo en vez de imagen.
         */
        Figura* avatar;
        /**
         * atributo sprite
         * Este atributo es un objeto Sprite el cual va a cargar la imagen a mostrar del objeto.
         */
        Sprite* sprite;
        /**
         * atributo tile
         * Este atributo es un objeto Tile el cual va a cargar la un fragmento de una imagen grande.
         */
        Tile *tile;
        /**
         * atributo col_box
         * Este atributo es un objeto Figura que funciona como un area rectangular para calcular las colisiones con
         * otros objetos.
         */
        Figura* col_box;
        
        float hp;
        float hp_max;
        Coordenadas posicion_mundo;
        Coordenadas posicion_camara;
        bool tiene_fisica;
        SDL_Color color;
        float velocidad{0};
        

        
    public:
        /**
         *  Atributo en_colision
         *  Bandera para revisar si el objeto esta en colisión con otro objeto.
         */
        bool en_colision{false};
        /**
         *  Atributo render_colbox
         *  Bandera para revisar si se va renderizar el cuadro de colbox.
         */
        bool render_colbox{false};
        /**
         *  Atributo area_plataforma
         *  Figura que representa una superficie de piso o plataforma. 
         */
        Figura *area_plataforma;
        /**
         *  Atributo se_borra
         *  Bandera para revisar si el objeto será borrado al final del update.
         */
        bool se_borra{false};

    public:
        /**
         *  Destructor
         *  Se implementa en los clases hijos.
         */
        virtual ~Objeto(){};
        /**
         *  update
         *  Se implementa en los clases hijos.
         *  @param dt la diferencia entre el frame anterior y el actual.
         */
        virtual void update(double dt)=0;
        /**
         *  render
         *  Renderiza el objeto en pantalla, se utiliza en el Pipeline.
         *  @param r Canvas donde se va pintar el objeto.
         */
        void render(SDL_Renderer *r);
        Figura* get_avatar()const{return avatar;};
        Figura* get_colbox()const{return col_box;};
        float get_hp()const{return hp;};
        void set_hp(float v){hp=v;};
        float get_hpmax()const{return hp_max;};
        void set_hpmax(float v){hp_max=v;};
        inline Coordenadas get_posicion_mundo(){return posicion_mundo;};
        inline Coordenadas get_posicion_camara(){return posicion_camara;};
        int get_posx()const{return posicion_mundo.x;};
        int get_posy()const{return posicion_mundo.y;};
        void set_posicion_mundo(Coordenadas p);
        void set_posicion_camara(Coordenadas p);
        void set_posx(int x);
        void set_posy(int y);
        SDL_Color get_color()const{return color;};
        void set_color(SDL_Color c){color=c;};
        bool get_tiene_fisica()const{return tiene_fisica;};

        /**
         *  get_sprite
         *  Regresa la referencia del Sprite del objeto
         *  \return el Sprite del objeto.
         *  \see Sprite
         */
        Sprite * get_sprite()const{return sprite;};
        /**
         *  get_tile
         *  Regresa la referencia del Tile del objeto
         *  \return el Tile del objeto.
         *  \see Tile
         */
        Tile * get_tile()const{return tile;};

        float get_velocidad()const{return velocidad;};
        void set_velocidad(float v){velocidad=v;};

};