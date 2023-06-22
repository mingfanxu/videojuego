#pragma once
#include "../../utilidad/Estructuras.hpp"
#include "../../objetos/Objeto.hpp"
#include "../Pipeline.hpp"
#include "../KeyOyente.hpp"
#include "../MouseOyente.hpp"
#include "../../utilidad/FSMS/FSMCamaras.hpp"
#include "../../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../../objetos_dinamicos/Jugador.hpp"

#include <SDL.h>
#include <vector>

class FSMCamara; //declaración circular

/**
 *  Cámara es la clase que se encarga de mostrar los objetos en la ventana
 *  Por defecto la cámara siempre se encuentra en (0,0) y actualiza el atributo 
 *  posición_camara de cualquier objeto.
 */

class Camara
{
    public:
        /**
         * Constructor
         * @param x es un entero con el valor de la posición en el eje de las x
         * @param y es un entero con el valor de la posición en el eje de las y
         * @param w es un entero con el valor de lo largo de la cámara.
         * @param h es un entero con el valor de lo ancho de la cámara.
         * @param view es el canvas de la ventana que se va renderizar los objetos.
         */
        Camara(int x, int y, int w, int h, SDL_Renderer &view);
        /**
         * El destructor.
         * Borra manualmente todos los apuntadores usados dentro de la clase Cámara.
         */
        ~Camara();
        /**
         * Renderizar, es una función que pinta todos los objetos que se encuentren dentro
         * del area de la camara.
         * @param objetos es una lista enlazada de apuntadores de objetos, los cuales se van a renderizar
         */
        void renderizar(std::vector<Objeto*> objetos);
        /**
         * proyectar, es una función que proyecta la posición mundo de los objetos a posición camara.
         * @param objetos es una lista enlazada de apuntadores de objetos, los cuales se van a proyectar
         */
        void proyectar(std::vector<Objeto*> objetos);
        /**
         * render_cross,pinta las guías de la cámara
         */
        void render_cross();
        /**
         * get_posicion_mundo
         * Función que regresa la posición del objeto en el mundo
         * @return Coordenadas del objeto en el mundo.
         */
        Coordenadas get_posicion_mundo() const {return pos_mundo;};
        /**
         * set_posicion_mundo
         * Función que modifica la posición de la cámara en el mundo
         * @param np es la nueva Coordenada de la posición.
         */
        void set_posicion_mundo(Coordenadas np);
        /**
         * set_posicion_centro
         * Función que modifica la posición central de la cámara
         * @param np es la nueva Coordenada de la posición.
         */
        void set_posicion_centro(Coordenadas np);
        /**
         * get_posicion_centro
         * Función que regresa la posición central de la cámara
         */
        Coordenadas get_posicion_centro() const{return pos_centro;};
        /**
         * lock_objeto
         * Función que le dice a la cámara que objeto seguir.
         * @param obj referencia del objeto que la cámara debe seguir.
         */
        void lock_objeto(Objeto &obj);
        /**
         * unluck_objeto
         * Función que libera a la cámara del objeto seguir.
         */
        void unluck_objeto();
        /**
         * get_obj_lock
         * Función que regresa que objeto esta siguiendo la cámara.
         */
        Objeto* get_obj_lock()const{return objeto_seguir;};

        /**
         * input_handle
         * Función que se encarga de leer los  inputs para que la cámara actué.
         * @param input  el input del teclado.
         * @param mouse  el input del mouse.
         */
        void input_handle(KeyOyente &input, MouseOyente &mouse);
        /**
         * update
         * Función que se encarga actualizar a la cámara cada frame.
         */
        void update();
        /**
         * set_estado
         * Función que se encarga de cambiar el estado de la cámara.
         * @param nuevo es un estado de tipo FSMCamara \see FSMCamara
         */
        void set_estado(void* nuevo);
        /**
         * get_estado
         * Función que se encarga de regresar el estado de la cámara.
         * @return regresa un estado de tipo FSMCamara \see FSMCamara
         */
        void *get_estado()const{return estado_actual;};
    
    public:
        /**
         * un publico atributo para revisar si ya esta siguiendo a un objeto
         */
        int lock{0};
        /**
         * un publico atributo para que tan rápido se mueve la cámara
         */
        float velocidad;
        /**
         * un publico atributo para revisar si esta en transición a un objeto
         */
        int en_transicion{0};
    
    private:
        int width;
        int height;
        Coordenadas pos_mundo;
        Coordenadas pos_centro;
        SDL_Renderer *viewport;
        Pipeline * objensamble;
        std::vector<Coordenadas> cruz;
        std::vector<Coordenadas> limder;
        std::vector<Coordenadas> limizq;
        std::vector<Coordenadas> limsup;
        std::vector<Coordenadas> liminf;
        Jugador* objeto_seguir;
        FSMCamara* estado_actual;
};