#pragma once
#include <SDL.h>
#include "../objetos_dinamicos/Jugador.hpp"
#include "../objetos_dinamicos/Enemigos.hpp"
#include "../objetos/Objeto.hpp"
#include "imagen/sprites.hpp"
#include "Pipeline.hpp"
/**
 *  HUD 
 *  Esta clase se encarga de la GUI para mostrar información del juego al usuario.
 *  Es una clase singleton, por lo que no se ocupa crear un objeto de ella.
 */
class HUD
{
    public:
        /**
         *  num_botones 
         *  Este atributo simboliza la cantidad de botones a utilizar el juego.
         */
        static int num_botones;
        /**
         *  set_pipeline 
         *  Esta función sirve para asignar la referencia del Buffer para renderizar.
         *  @param p la referencia del Buffer a utilizar.
         */
        static void set_pipeline(Pipeline &p);
        /**
         *  show_vida 
         *  Esta función sirve para mostrar un rectángulo con el porcentaje de vida actual del ente.
         *  @param ente la referencia del ente para obtener los stats.
         *  @param pos_mundo la posición que se va a mostrar el rectángulo.
         *  @param color el color del rectángulo de tipo SDL_Color
         */
        static void show_vida(Objeto* ente, Coordenadas pos_mundo,SDL_Color color);
        /**
         *  show_stats 
         *  Esta función sirve para mostrar los atributos(stats) del ente.
         *  @param ente la referencia del ente para obtener los stats.
         *  @param pos_mundo la posición que se va a mostrar.
         *  @param color el color del rectángulo de tipo SDL_Color
         */
        static void show_stats(Objeto* ente, Coordenadas pos_mundo,SDL_Color color);
        /**
         *  show_controles 
         *  Esta función sirve para mostrar que botones se utilizan en el juego.
         *  @param pos_mundo la posición que se va a mostrar.
         *  @param color el color del rectángulo de tipo SDL_Color
         */
        static void show_controles(Coordenadas pos_mundo, SDL_Color color);
        /**
         *  get 
         *  Esta función sirve para obtener la instancia de la clase y poder acceder de manera segura a sus métodos.
         */
        static HUD& get();
        ~HUD();
    private:
        HUD();
        Pipeline *ensamble;
        static HUD *instancia;
        Sprite **sprite_controles;
        
};