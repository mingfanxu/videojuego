#pragma once
#include <SDL.h>
/**
 *  MouseOyente 
 *  Esta clase se encarga de capturar y registrar los eventos relacionado con el mouse.
 *  Es una clase singleton, por lo que no se ocupa crear un objeto de ella.
 */
class MouseOyente
{
    private:
        MouseOyente();
        int scrollX;
        int scrollY;
        int xPos;
        int yPos;
        int lastX;
        int lastY;
        bool mouse_boton[3];
        bool esta_arrastrando;
        bool esta_moviendo;
    
    public:
        /**
         *  get 
         *  Esta función sirve para acceder a la instancia y poder utilizar los métodos de la clase de manera segura
         */
        static MouseOyente& get();
        /**
         *  evento_movimiento 
         *  Esta función sirve para capturar el evento de movimiento del mouse.
         *  @param e es el evento a capturar de tipo SDL_Event
         */
        static void evento_movimiento(SDL_Event* e);
        /**
         *  evento_presionado 
         *  Esta función sirve para capturar el evento de botones presionados del mouse.
         *  @param e es el evento a capturar de tipo SDL_Event
         */
        static void evento_presionado(SDL_Event* e);
        /**
         *  evento_scroll 
         *  Esta función sirve para capturar el evento del scroll del mouse.
         *  @param e es el evento a capturar de tipo SDL_Event
         */
        static void evento_scroll(SDL_Event* e);

        static int getX(){return get().xPos;};
        static int getY(){return get().yPos;};
        static int getDX(){return get().lastX-get().xPos;};
        static int getDY(){return get().lastY-get().yPos;};
        static int getScrollX(){return get().scrollX;};
        static int getScrollY(){return get().scrollY;};
        static bool esArrastrado(){return get().esta_arrastrando;};
        static bool seMueve(){return get().esta_moviendo;};
};