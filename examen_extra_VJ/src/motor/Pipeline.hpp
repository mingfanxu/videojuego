#pragma once
#include<SDL.h>
#include<vector>
#include "../utilidad/Estructuras.hpp"
#include "../objetos/Figuras.hpp"
#include "imagen/sprites.hpp"
#include "imagen/tiles.hpp"
/**
 *  Pipeline 
 *  Esta clase se encarga de administrar el BUFFER para renderizar los objetos en pantalla
 */
class Pipeline
{
    public:
        Pipeline(SDL_Renderer &ren);

        //quitar copias
        Pipeline(const Pipeline&) = delete;
        Pipeline &operator=(const Pipeline&) = delete;
        /**
         *  puntos 
         *  Esta función se encarga de mandar al renderizador una lista de puntos a pintar en pantalla como pixeles.
         *  Renderiza utilizando el CPU.
         *  @param p una lista de Coordenadas que representan un pixel.
         *  @param c el color del pixel en formato SDL_Color.
         */
        void puntos(std::vector<Coordenadas> p,SDL_Color c);
        /**
         *  lineas 
         *  Esta función se encarga de mandar al renderizador una lista de puntos a pintar en pantalla como lineas.
         *  Renderiza utilizando el CPU.
         *  @param p una lista de Coordenadas que representan un punto parte de un a linea por ejemplo {(0,0),(0,1)} es una linea.
         *  @param c el color del pixel en formato SDL_Color.
         */
        void lineas(std::vector<Coordenadas> p,SDL_Color c);
        /**
         *  figuras 
         *  Esta función se encarga de mandar al renderizador una lista objetos de tipo Figura para renderizar.
         *  Renderiza utilizando el CPU.
         *  @param f una lista de objetos de tipo Figura. 
         * \see Figura
         */
        void figuras(std::vector<Figura*> f);
        /**
         *  figuras 
         *  Esta función se encarga de mandar al renderizador un solo objeto de tipo Figura para renderizar.
         *  Renderiza utilizando el CPU.
         *  @param f un objeto de tipo Figura. 
         * \see Figura
         */
        void figuras(Figura* f);
        /**
         *  pintar_texturas 
         *  Esta función se encarga de mandar al renderizador un objeto de tipo Sprite (imagen) para renderizar .
         *  Renderiza utilizando el GPU.
         *  @param obj un objeto de tipo Sprite. 
         * \see Sprite
         */
        void pintar_texturas(Sprite* obj);
        /**
         *  pintar_texturas 
         *  Esta función se encarga de mandar al renderizador un objeto de tipo Tile (hoja de imágenes) para renderizar .
         *  Renderiza utilizando el GPU.
         *  @param obj un objeto de tipo Tile. 
         * \see Tile
         */
        void pintar_texturas(Tile* obj);
        /**
         *  cargar_texturas 
         *  Esta función se encarga cargar la imagen del objeto Sprite en la memoria del GPU y RAM .
         *  Renderiza utilizando el GPU.
         *  @param obj un objeto de tipo Sprite. 
         * \see Sprite
         */
        bool cargar_texturas(Sprite* obj);

    private:
        SDL_Renderer *ptrren;
        
};