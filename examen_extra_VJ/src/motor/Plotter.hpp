#pragma once
#include<SDL.h>
#include "../utilidad/Estructuras.hpp"
#include "../objetos/Figuras.hpp"
/**
 *  Plotter 
 *  Esta clase se encarga de renderizar puntos, objetos, figuras en pantalla utilizando el CPU o el GPU (es la última face de la línea de renderizado).
 *  Es una clase singleton, por lo que no se ocupa crear un objeto de ella.
 */
class Plotter
{
    private:
        Plotter();
        //singleton
        static Plotter* instancia;
        SDL_Renderer *render;
        
    public:
        /**
         *  get 
         *  Esta función sirve para acceder a la instancia y poder utilizar los métodos de la clase de manera segura
         */
        static Plotter& get();
        /**
         *  set_renderer 
         *  Esta función sirve definir el canvas en donde se va a pintar los objetos.
         *  @param r el canvas de la ventana de tipo SDL_Renderer.
         */
        static void set_renderer(SDL_Renderer &r);
        /**
         *  render_pixel 
         *  Esta función sirve para renderizar in pixel en pantalla.
         *  Utiliza el CPU
         *  @param r el canvas de la ventana de tipo SDL_Renderer.
         *  @param p la posición del pixel a renderizar.
         *  @param color el color del pixel.
         */
        static void render_pixel(SDL_Renderer*r,Coordenadas p,SDL_Color color);
        /**
         *  render_pixel 
         *  Esta función sirve para renderizar in pixel en pantalla.
         *  Utiliza el CPU
         *  @param p la posición del pixel a renderizar.
         *  @param color el color del pixel.
         */
        static void render_pixel(Coordenadas p,SDL_Color color);
        /**
         *  render_linea 
         *  Esta función sirve para renderizar una linea conformado por dos puntos de tipo Coordenadas en pantalla.
         *  Utiliza el CPU
         *  @param r el canvas de la ventana de tipo SDL_Renderer.
         *  @param p1 la posición del punto 1 de tipo Coordenadas.
         *  @param p2 la posición del punto 2 de tipo Coordenadas.
         *  @param color el color del pixel.
         */
        static void render_linea(SDL_Renderer *r, Coordenadas p1, Coordenadas p2, SDL_Color color);
        /**
         *  rellenoscandline 
         *  Esta función sirve para rellenar una figura de tipo Figura.
         *  Utiliza el CPU
         *  @param r el canvas de la ventana de tipo SDL_Renderer.
         *  @param fig la Figura a rellenar.
         */
        static void rellenoscandline(SDL_Renderer *r,Figura *fig);
        /**
         *  pintar_textura 
         *  Esta función sirve para pintar una imagen en pantalla utilizando el GPU.
         *  Utiliza el GPU
         *  @param r el canvas de la ventana de tipo SDL_Renderer.
         *  @param textura la imagen a pintar de tipo SDL_Texture.
         *  @param src un rectángulo del área de la imagen a pintar de tipo SDL_Rect.
         *  @param dest un rectángulo del área a pintar en el mundo de tipo SDL_Rect.
         *  @param size el tamaño a pintar la imagen de tipo Coordenadas.
         */
        static void pintar_textura(SDL_Renderer *r,SDL_Texture *textura,SDL_Rect &src , SDL_Rect &dest,Coordenadas size);
        /**
         *  pintar_textura_fip 
         *  Esta función sirve para pintar una imagen en pantalla utilizando el GPU aplicando transformaciones como rotación o reflexión.
         *  Utiliza el GPU
         *  @param r el canvas de la ventana de tipo SDL_Renderer.
         *  @param textura la imagen a pintar de tipo SDL_Texture.
         *  @param src un rectángulo del área de la imagen a pintar de tipo SDL_Rect.
         *  @param dest un rectángulo del área a pintar en el mundo de tipo SDL_Rect.
         *  @param size el tamaño a pintar la imagen de tipo Coordenadas.
         */
        static void pintar_textura_flip(SDL_Renderer *r,SDL_Texture *textura,SDL_Rect &src , SDL_Rect &dest,Coordenadas size);
};