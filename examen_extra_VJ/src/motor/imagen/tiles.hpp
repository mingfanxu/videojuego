#pragma once
#include "../../utilidad/Estructuras.hpp"
#include<string>
#include<SDL.h>
/**
 *  Tile 
 *  Esta clase se encarga de cargar las imágenes correspondientes al entorno o mundo
 */
class Tile
{
    public:
        /**
         *  Tile Constructor
         *  @param info es una estructura tipo TileInfo lo cual contiene toda la información necesaria
         */
        Tile(TileInfo info);
        /**
         *  render
         *  Renderiza el Tile en pantalla
         *  @param r es el canvas donde se va Renderizar el Tile.
         */
        void render(SDL_Renderer *r);
        /**
         *  get_textura
         *  Función para obtener la hoja de Tiles
         *  @return la hoja de Tiles como un apuntador de tipo SDL_Texture 
         *  \see SDL_Texture
         *  \see Sprite
         */
        SDL_Texture* get_textura() const{return atlas;};
        SDL_Rect* get_src() {return &src;};
        SDL_Rect* get_dst() {return &dst;};
        Coordenadas get_sizes()const{return size;};
    private:
        SDL_Rect dst;
        SDL_Rect src;
        Coordenadas pos;
        SDL_Texture *atlas;
        Coordenadas size;
};