#pragma once
#include "../../objetos/Objeto.hpp"
#include "../../motor/Pipeline.hpp"
#include <SDL.h>
/**
 *  PlataformasSpawner
 *  Es una clase que lleva el control de cuando debe de crearse un objeto de tipo Plataforma.
 *  NO SE ESTA UTILIZANDO PARA ESTE PROYECTO
 */
class PlataformasSpawner
{
    public:
        /**
         *  Constructor
         *  @param sprite_path direccón donde se encuentra la hoja de Sprite.
         *  @param x posición mundo en x.
         *  @param y posición mundo en y.
         *  @param w ancho del Sprite.
         *  @param h alto del Sprite.
         *  @param sw ancho a mostrar del Sprite.
         *  @param sh alto a mostrar del Sprite.
         */
        PlataformasSpawner(std::string sprite_path, int x, int y, int w, int h,int sw, int sh,SDL_Color c,Pipeline &p);
        /**
         *  spawn
         *  Función que crea un objeto de tipo Plataforma y lo agrega al la lista de objetos del mundo.
         *  @param lista lista de objetos del mundo.
         */
        void spawn(std::vector<Objeto*>*lista);
        /**
         *  despawn
         *  Función que marca a un objeto de tipo Plataforma para ser borrado al final del update mundo(SDLApp).
         *  @param lista lista de objetos del mundo.
         */
        void despawn(std::vector<Objeto*>*lista);
        /**
         *  update
         *  Función que actualiza a la clase PlataformasSpawner.
         *  @param lista lista de objetos del mundo.
         */
        void update(std::vector<Objeto*>*lista);
         /**
         *  set_velocidad
         *  Función que modifica la velocidad de los objetos a crear.
         *  @param v entero nuevo de la velocidad.
         */
        void set_velocidad(int v);

    private:
        std::vector<Objeto*> objetos;
        std::string sprite_path;
        SDL_Color colordebug;
        int x; // pos x
        int y; // pos y
        int w; // ancho sprite
        int h; // alto sprite
        int sw;// ancho mostrar sprite
        int sh;// alto mostrar sprite
        int objetos_activos;
        int delay;
        double init_tiempo;
        int past_tiempo;
        bool check;
        Pipeline *pipeline;
        int velocidad;

};