#pragma once
#include "../../utilidad/Estructuras.hpp"
#include "../../objetos_estaticos/ObjetoEstatico.hpp"
#include<string>
#include<SDL.h>
/**
 *  Atlas 
 *  Esta clase se encarga de cargar las imágenes correspondientes al entorno o mundo
 */
class Atlas
{
    public:
        /**
         *  Atlas Constructor
         *  Crea un objeto de tipo Atlas
         *  @param atlas recibe como parámetro la dirección del archivo codificado en una matriz para cargar el mapa.
         */
        Atlas(std::string atlas);
        /**
         *  ~Atlas Destructor 
         *  Libera la memoria de todos los apuntadores utilizados dentro de esta clase.
         */
        ~Atlas();
        /**
         *  cargar_textura 
         *  Esta función se encarga de cargar la imagen donde se encuentran todos los Tile en memoria RAM
         */
        bool cargar_textura(SDL_Renderer *r);
        /**
         *  generar_mapa 
         *  Esta función se encarga de leer el archivo codificado y de generar los objetos adecuados para renderizar el mundo.
         */
        void generar_mapa(SDL_Renderer *r,int idflip,int notidobjfisicos);
        /**
         *  get_objetos_fisicos 
         *  Esta función regresa todos los objetos del mundo que tienen colisión o que se le puede aplicar física.
         *  @return objetos que se le puede aplicar física o tienen colisión
         *  \see Objeto
         */
        std::vector<Objeto*> get_objetos_fisicos() const{return objetos_fisicos;};

    private:
        AtlasInfo info;
        std::vector<Objeto*> objetos_fisicos;
        SDL_Texture *atlas_sheet;
        
};