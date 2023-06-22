#pragma once
#include "../../utilidad/Estructuras.hpp"
#include "../../lib_externas/pugixml.hpp"
#include<SDL.h>
#include<SDL_image.h>
#include<string>

/**
 *  Sprite 
 *  Esta clase se encarga de cargar las imágenes correspondientes a los personajes
 */
class Sprite 
{
    public:
        /**
         *  Sprite Constructor
         *  @param file dirección de donde se encuentra la imagen con los Sprite del personaje
         *  @param pos Coordenadas del mundo en donde nacer.
         *  @param w entero que representa el width del Sprite
         *  @param h entero que representa el height del Sprite
         *  @param sw entero que representa el width que se quiere mostrar en pantalla del Sprite
         *  @param sh entero que representa el height que se quiere mostrar en pantalla del Sprite
         */
        Sprite(std::string file, Coordenadas pos, int w, int h,int sw, int sh);
        /**
         *  Sprite Constructor
         *  @param xml dirección de donde se encuentra un archivo XML que contiene toda la información de la hoja de Sprite
         *  @param pos Coordenadas del mundo en donde nacer.
         *  @param sw entero que representa el width que se quiere mostrar en pantalla del Sprite
         *  @param sh entero que representa el height que se quiere mostrar en pantalla del Sprite
         */
        Sprite(std::string xml, Coordenadas pos,int sw, int sh);
        /**
         *  Sprite Destructor
         *  Libera la memoria utilizada por todos los apuntadores de esta clase.
         */
        ~Sprite();

        /**
         *  get_textura
         *  Función para obtener la hoja de Sprite
         *  @return la hoja de sprite como un apuntador del tipo SDL_Texture
         */
        SDL_Texture* get_textura() const{return hoja;};
        /**
         *  get_sprite_src
         *  Función para obtener la el rectángulo que se encarga de navegar en la hoja de Sprite
         *  @return  un apuntador del rectángulo de tipo SDL_Rect \see SDL_Rect
         */
        SDL_Rect *get_sprite_src(){return &sprite_select;}
        /**
         *  get_sprite_frame
         *  Función para obtener la el rectángulo que se encarga mostrar la textura en pantalla
         *  @return  un apuntador del rectángulo de tipo SDL_Rect \see SDL_Rect
         */
        SDL_Rect *get_sprite_frame(){return &sprite_frame;};
        /**
         *  cargar_textura
         *  Función cargar la texutura del Sprite en el GPU
         *  @return  verdadero si la textura se pudo cargar, de lo contrario falso.
         */
        bool cargar_textura(SDL_Renderer* r);
        /**
         *  set_sprite_position
         *  Función para mover el Sprite por las Coordenadas del mundo
         */
        void set_sprite_position(Coordenadas p);
        /**
         *  get_sprite_position
         *  Función para obtener las Coordenadas del mundo del Sprite
         *  @return las Coordenadas del Mundo del Sprite
         */
        Coordenadas get_sprite_position();
        /**
         *  get_sprite_sizes
         *  Función para obtener las dimensiones del Sprite que queremos mostrar en pantalla
         *  @return el width y height que queremos mostrar en pantalla del Sprite como una Coordenada
         */
        Coordenadas get_sprite_sizes()const{return sprite_size;};
        /**
         *  play_frame
         *  Función para mover el frame del Sprite y mostrar otra imagen diferente.
         *  Donde utiliza:
         * 
         *      frame.x = row*(width*frame);
         *      frame.y = row*height;
         * 
         *  @param row en que renglón iniciar para mostrar la imagen (asumiendo que la imagen tenga Sprites como si fuera una cuadricula)
         *  @param frame cual Sprite mostrar dentro del renglón.
         */
        void play_frame(int row, int frame);
        /**
         *  play_frame
         *  Función para cambiar la imagen del Sprite utilizando el archivo XML.
         *  @param nombre el nombre del nodo de XML que se encuentran las imagenes del Sprite
         *  @param frame cual Sprite mostrar dentro del renglón.
         */
        void play_frame(std::string nombre,int frame);
        void set_estado_animacion(void* estado);
        /**
         *  set_flip
         *  Función para decirle a Plotter que utilice la función de pintar usando reflexión de la imagen.
         *  @param v boleano 
         */
        void set_flip(bool v){flip=v;};
        bool get_flip()const{return flip;};

    private:
        SDL_Rect sprite_select;
        SDL_Rect sprite_frame;
        SDL_Texture *hoja;
        int width;
        int height;
        std::string path;
        std::string spritexml;
        void *estado_animacion;
        //int max_frames{0};
        Coordenadas sprite_size;
        bool flip{false};

        void LoadDataXML();
        pugi::xml_document info;


        
};