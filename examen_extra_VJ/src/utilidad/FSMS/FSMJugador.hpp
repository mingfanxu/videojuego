#pragma once
#include "../../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../../motor/KeyOyente.hpp"
#include "../../motor/MouseOyente.hpp"
#include<string>

class Jugador; //forward declaration
/**
 *  FSMJugador
 *  Es una clase interface que representa la Maquina de Estados de las Animaciones de la clase Jugador (FSM).
 *  Las clases heredadas son los estados del Enemigo.
 */
class FSMJugador
{
    protected:
        /**
         *  atributo strnombre.
         *  Este atributo representa el nombre del estado.
         */
        std::string strnombre;
    
    public:
        virtual ~FSMJugador(){};
        /**
         *  input_handle.
         *  Esta función representa las entradas de cada nodo de la Maquina de Estados.
         *  @param input referencia al Manejador de entradas por teclado.
         *  @param mouse referencia al Manejador de entradas por mouse.
         */
        virtual FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse)=0;
        /**
         *  on_entrar.
         *  Esta función representa que sucede cuando entramos a un nuevo estado.
         *  @param player referencia a Jugador que pertenece la Maquina de Estados.
         */
        virtual void entrar(Jugador& player)=0;
        /**
         *  on_salir.
         *  Esta función representa que sucede cuando salimos del estado.
         *  @param player referencia a Jugador que pertenece la Maquina de Estados.
         */
        virtual void salir(Jugador& player)=0;
        /**
         *  on_update.
         *  Esta función representa que sucede cuando actualizamos el estado.
         *  @param player referencia a Jugador que pertenece la Maquina de Estados.
         */
        virtual void update(Jugador& player,double dt)=0;
        std::string get_namestate()const{return strnombre;};
    protected:
        /**
         *  atributo frames_actual_ani.
         *  Este atributo representa el frame actual de la animación.
         */
        int frames_actual_ani;
        /**
         *  atributo frames_maxim_ani.
         *  Este atributo representa los frames máximos de la animación.
         */
        int frames_maxim_ani;
        /**
         *  atributo int frame_dt.
         *  Este atributo representa una diferencia de frames.
         */
        int frame_dt{0};
};
/**
 *  EstadoJugadorIDLE
 *  Es el Nodo de la Maquina de Estados de Jugador. 
 *  Cuando el Jugador esta sin moverse.
 */
class EstadoJugadorIDLE : public FSMJugador
{
    public:
        EstadoJugadorIDLE();
        virtual ~EstadoJugadorIDLE(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
    private:
        int dir;

};
/**
 *  EstadoJugadorIzquierda
 *  Es el Nodo de la Maquina de Estados de jugador. 
 *  Cuando el Jugador se mueve a la izquierda.
 */
class EstadoJugadorIzquierda : public FSMJugador
{
    public:
        EstadoJugadorIzquierda();
        virtual ~EstadoJugadorIzquierda(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
};
/**
 *  EstadoJugadorDerecha
 *  Es el Nodo de la Maquina de Estados de jugador. 
 *  Cuando el Jugador se mueve a la derecha.
 */
class EstadoJugadorDerecha : public FSMJugador
{
    public:
        EstadoJugadorDerecha();
        virtual ~EstadoJugadorDerecha(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
};
/**
 *  EstadoJugadorArriba
 *  Es el Nodo de la Maquina de Estados de jugador. 
 *  Cuando el Jugador se mueve a la arriba.
 */
class EstadoJugadorArriba : public FSMJugador
{
    public:
        EstadoJugadorArriba();
        virtual ~EstadoJugadorArriba(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
};
/**
 *  EstadoJugadorAbajo
 *  Es el Nodo de la Maquina de Estados de jugador. 
 *  Cuando el Jugador se mueve a la abajo.
 */
class EstadoJugadorAbajo : public FSMJugador
{
    public:
        EstadoJugadorAbajo();
        virtual ~EstadoJugadorAbajo(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
};


/**
 *  EstadoJugadorGravedadBrinco
 *  Es el Nodo de la Maquina de Estados de jugador. 
 *  Cuando el Jugador brinca utiilzando el sistema de gravedad de MotorFisico2D.
 *  \see MotorFisico2D
 */
class EstadoJugadorGravedadBrinco: public FSMJugador
{
    public:
        EstadoJugadorGravedadBrinco(int fuerza);
        virtual ~EstadoJugadorGravedadBrinco(){};
        FSMJugador* input_handle(KeyOyente& input, MouseOyente& mouse);
        void entrar(Jugador& player);
        void salir(Jugador& player);
        void update(Jugador& player,double dt);
    private:
        int f;
        Coordenadas P1;
        bool en_aire;

};

