#pragma once
#include <SDL.h>
#include<string>
#include <SDL_ttf.h>
/**
 *  RenderTexto
 *  Es la clase que se encarga de pintar textos en la pantalla.
 *  Es una clase Singleton por lo que no se ocupa hacer una instancia.
 */
class RenderTexto
{
    public:
        ~RenderTexto();
        /**
         *  get 
         *  Esta función sirve para acceder a la instancia y poder utilizar los métodos de la clase de manera segura
         */
        static RenderTexto& get();
        /**
         *  render_texto 
         *  Esta función sirve para pintar el texto deseado en pantalla
         *  @param ren canvas en donde pintar el texto.
         *  @param x posición en el eje de las x.
         *  @param y posición en el eje de las y.
         *  @param texto texto a pintar en pantalla.
         *  @param fontsize el tamaño del texto a pintar.
         *  @param color el color del texto a pintar.
         *  @param font el nombre del font a utilizar.
         */
        static void render_texto(SDL_Renderer *ren, int x, int y, std::string texto, int fontsize, SDL_Color color, std::string font="SunnySpells");
        /**
         *  render_texto 
         *  Esta función sirve para pintar el texto deseado en pantalla, especificando un tamaño
         *  @param ren canvas en donde pintar el texto.
         *  @param x posición en el eje de las x.
         *  @param y posición en el eje de las y.
         *  @param texto texto a pintar en pantalla.
         *  @param w ancho máximo del texto.
         *  @param h alto máximo del texto.
         *  @param color el color del texto a pintar.
         */
        static void render_texto(SDL_Renderer *ren, int x, int y, std::string texto, int w, int h,SDL_Color color);
    
    private:
        RenderTexto();
        static RenderTexto* instancia;

        SDL_Rect font_rect;
        SDL_Texture *font_texture;
        SDL_Surface *font_surface;
        
        //fonts para este caso solo uno
        TTF_Font* font_default;

        static bool inicio; 
};