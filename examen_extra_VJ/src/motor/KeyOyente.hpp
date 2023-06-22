#pragma once
#include<SDL.h>
/**
 *  KeyOyente 
 *  Esta clase se encarga de capturar y registrar que teclas del teclado fueron presionadas.
 *  Es una clase singleton, por lo que no se ocupa crear un objeto de ella.
 */
class KeyOyente
{
    private:
        KeyOyente();
        bool keys[SDL_NUM_SCANCODES];
    public:
        /**
         *  get 
         *  Esta función sirve para acceder a la instancia y poder utilizar los métodos de la clase de manera segura
         */
        static KeyOyente& get();
        /**
         *  keyPresionado 
         *  Esta función sirve monitorear que teclas están siendo presionado.
         *  @param e el evento monitoreado de tipo SDL_Event
         */
        static void keyPresionado(SDL_Event *e);
        /**
         *  estaPresionado 
         *  Esta función sirve para revisar que tecla exactamente esta presionado
         *  @param key la tecla a revisar, debe ser de tipo SDL_SCANCODE
         *  @return true si la tecla esta presionado de lo contrario false.
         */
        static bool estaPresionado(int key) {return get().keys[key];};
        /**
         *  nadaPresionado 
         *  Esta función revisa si nada esta presionado. 
         *  Actualmente no se utiliza en el código
         *  @return true si la nada esta presionado de lo contrario false.
         */
        static bool nadaPresionado();
};