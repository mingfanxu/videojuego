#pragma once
#include "ObjetoDinamico.hpp"
#include "../objetos/Figuras.hpp"
#include "../utilidad/Func_aux.hpp"

#include "../utilidad/FSMS/FSMJugador.hpp"

class FSMJugador;//forward declaration
/**
 *  Jugador
 *  Clase hijo de ObjetoDinamico representa al usuario y el avatar que utiliza.
 */
class Jugador : public ObjetoDinamico
{
    public:
        /**
         *  Destructor
         *  Libera la memoria de todos los apuntadores utilizados en esta clase.
         */
        virtual ~Jugador(){};
        /**
         *  Constructor
         *  @param path_sprite dirección donde se encuentra la hoja de Sprite a utilizar.
         *  @param vida la vida del jugador.
         *  @param x la posición mundo en x.
         *  @param y la posición mundo en y.
         *  @param w el ancho del Sprite.
         *  @param h lo alto del Sprite.
         *  @param sw el ancho a mostrar en pantalla.
         *  @param sh el alto a mostrar en pantalla.
         *  @param c el color del jugador representado como SDL_Color.
         */
        Jugador(std::string path_sprite,float vida, int x, int y, int w, int h,int sw,int sh, SDL_Color c );
        /**
         *  Constructor
         *  @param path_xml dirección donde se encuentra el archivo XML donde esta toda la información sobre la hoja de Sprite a utilizar.
         *  @param vida la vida del jugador.
         *  @param x la posición mundo en x.
         *  @param y la posición mundo en y.
         *  @param sw el ancho a mostrar en pantalla.
         *  @param sh el alto a mostrar en pantalla.
         *  @param c el color del jugador representado como SDL_Color.
         */
        Jugador(std::string path_xml,float vida, int x, int y, int sw,int sh, SDL_Color c );
        /**
         *  update
         *  Función que actualiza al objeto.
         *  @param dt diferencia de tiempo de un frame a otro.
         */
        void update(double dt);
        /**
         *  input_handle
         *  Función que se utiliza para cambiar de estado dependiendo que tipo de entrada obtuvo. En el caso del jugador utiliza el teclado y/o el mouse.
         *  @param input Referencia al Manejador de entradas de teclado KeyOyente.
         *  @param mouse Referencia al Manejador de entradas de mouse MouseOyente.
         *  \see MouseOyente
         *  \see KeyOyente
         */
        void input_handle(KeyOyente& input,MouseOyente& mouse);
        /**
         *  get_strEstado
         *  Función que regresa el nombre del estado que se encuentra el Jugador.
         * \return Nombre del estado.
         */
        std::string get_strEstado();
        Coordenadas get_piso()const{return piso;};
        void set_piso(Coordenadas p){piso = p;};
        /**
         *  set_estado
         *  Función que cambia el estado del Jugador.
         *  Los estados son de la clase tipo FSMJugador.
         *  @param estado El nuevo estado a cambiar, tiene que ser derivado de FSMJugador.
         *  \see FSMJugador
         */
        void set_estado(void* estado);
        /**
         *  get_estado
         *  Función que regresa el estado del Jguador
         *  Los estados son de la clase tipo FSMJugador.
         *  \return  El estado del jugador como un derivado de FSMJugador.
         *  \see FSMJugador
         */
        void* get_estado();

        std::vector<Objeto*> get_objetos_mundo()const{return *objetos;};
        void set_objetos_mundo(std::vector<Objeto*> &o){objetos = &o;};

        Figura* get_col_piso()const{return col_piso;};
        bool get_onPlataforma()const{return en_plataforma;};
        /**
         *  set_onPlataforma
         *  Función que indica que esta encima de un área de plataforma.
         *  @param v booleano para indicar si esta o no en una plataforma.
         *  \see Objeto
         */
        void set_onPlataforma(bool v);
        /**
         *  get_centro
         *  Función que regresa la Coordenadas del centro del Sprite del Jugador.
         *  \return  Coordenadas del punto central del Sprite.
         *  \see Sprite
         */
        Coordenadas get_centro() const{return centro;};
        /**
         *  get_guia
         *  Función que regresa la Coordenadas del un punto fuera del Sprite del Jugador.
         *  \return  Coordenadas del punto fuera  del Sprite.
         *  \see Sprite
         */
        Coordenadas get_guia() const{return guia;};

        /**
         *  MoverDerecha
         *  Función para mover al Jugador a la derecha.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverDerecha(double dt);
        /**
         *  MoverIzquierda
         *  Función para mover al Jugador a la izquierda.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverIzquierda(double dt);
        /**
         *  MoverArriba
         *  Función para mover al Jugador a la arriba.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverArriba(double dt);
        /**
         *  MoverAbajo
         *  Función para mover al Jugador a la abajo.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverAbajo(double dt);
        /**
         *  MoverArribaDerecha
         *  Función para mover al Jugador a la arriba derecha.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverArribaDerecha(double dt);
        /**
         *  MoverArribaIzquierda
         *  Función para mover al Jugador a la arriba arriba izquierda.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverArribaIzquierda(double dt);
        /**
         *  MoverAbajoDerecha
         *  Función para mover al Jugador a la arriba abajo derecha.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverAbajoDerecha(double dt);
        /**
         *  MoverAbajoIzquierda
         *  Función para mover al Jugador a la arriba abajo izquierda.
         *  @param dt diferencia de tiempo de un frame a otro.
         *  \see FSMJugador
         */
        void MoverAbajoIzquierda(double dt);
        /**
         *  AtaqueUno
         *  Función para calcular el ataque del Jugador
         *  NO ESTA IMPLEMENTADA
         *  @param obj Objeto a quien va atacar
         *  @param dt diferencia de tiempo de un frame a otro
         *  \see FSMJugador
         *  \see Objeto
         */
        void AtaqueUno(Objeto* obj, double dt);

        /**
         *  get_col_dano
         *  Función que regresa el Rectangulo de colisión de daño recibido al Jugador.
         *  \see FSMJugador
         *  \see Objeto
         */
        Figura *get_col_dano()const {return col_dano;};
        /**
         *  get_col_ataque
         *  Función que regresa el Rectangulo de colisión del ataque del Jugador.
         *  \see FSMJugador
         *  \see Objeto
         */
        Figura *get_col_ataque()const {return col_ataque;};

    private:
        FSMJugador* estado_actual;
        Coordenadas piso;
        std::vector<Objeto*> *objetos;
        Figura *col_piso;
        Figura *col_ataque;
        Figura *col_dano;
        bool en_plataforma{false};
        Coordenadas centro;
        Coordenadas guia;
        int dir;
};