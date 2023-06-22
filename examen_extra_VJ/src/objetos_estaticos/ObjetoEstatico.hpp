#pragma once
#include "../objetos/Objeto.hpp"
#include "../utilidad/Estructuras.hpp"
#include "../motor/imagen/tiles.hpp"
#include <SDL.h>
/**
 *  ObjetoEstatico
 *  Clase Abstracta que sirve como interface a los ObjetosEstatico.
 */
class ObjetoEstatico : public Objeto
{
    public:
        virtual ~ObjetoEstatico(){};
        /**
         *  update
         *  Se implementa en la clase hija
         */
        virtual void update(double dt) = 0;

};
/**
 *  Plataformas
 *  Clase Hija de ObjetoEstatico.
 *  Representa todos las Plataformas que no se mueven en el mundo.
 */
class Plataformas : public ObjetoEstatico
{
    public:
        virtual ~Plataformas(){};
        /**
         *  Constructor
         *  @param x posición mundo en x.
         *  @param y posición mundo en y.
         *  @param w ancho del Sprite.
         *  @param h alto del Sprite.
         *  @param color color del objeto en formato SDL_Color.
         */
        Plataformas(int x, int y, int w, int h, SDL_Color color);
        /**
         *  Constructor
         *  @param tiles una estructura que contiene toda la información de los Tile a usar.
         *  @param colision un boleano que le dice si va tener colisión la Plataforma
         */
        Plataformas(TileInfo tiles,bool colision);
        /**
         *  update
         *  Función que se usa para actualizar los atributos de la Plataforma.
         *  @param dt diferencia de tiempo de un frame a otro.
         */
        void update(double dt);
};
