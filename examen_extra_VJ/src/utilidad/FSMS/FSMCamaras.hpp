#pragma once
#include "../../motor/KeyOyente.hpp"
#include "../../motor/MouseOyente.hpp"
#include "../../motor/camaras/Camaras.hpp"
#include "../../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../../objetos_dinamicos/Jugador.hpp"
#include "../Estructuras.hpp"
#include<string>

class Camara; //declaración circular
/**
 *  FSMCamara
 *  Es una clase interface que representa la Maquina de Estados de la Camara (FSM).
 *  Las clases heredadas son los estados de la Camara.
 */
class FSMCamara
{
    protected:
        /**
         *  atributo vel.
         *  Este atributo define la velocidad de la Camara.
         */
        float vel;
        /**
         *  atributo pos_final.
         *  Este atributo define la posición final que quiere llegar la Camara.
         */
        Coordenadas pos_final;
        /**
         *  atributo pos_inicial.
         *  Este atributo define la posición inicial donde parte laCamara.
         */
        Coordenadas pos_inicial;
        /**
         *  atributo frames_actual.
         *  Este atributo define un contador de la cantidad de frames que han transcurrido actualmente.
         */
        int frames_actual;
        /**
         *  atributo frames_maximo.
         *  Este atributo define la cantidad máxima de frames que debe de transcurrir.
         */
        int frames_maximo;
        
    public:
        /**
         *  atributo strestado.
         *  Este atributo representa el nombre del estado.
         */
        std::string strestado;
    public:
        virtual ~FSMCamara(){};
        /**
         *  input_handle.
         *  Esta función representa la entrada de la Maquina de Estado.
         *  Se implementa en las clases hijos.
         *  @param cam  referencia a la Camara que pertenece la Maquina de Estados.
         *  @param obj  referencia del objeto principal que va seguir la Camara.
         *  @param keys referencia al Manejador de eventos por teclado.
         *  @param mouse referencia al manejador de eventos por mouse.
         */
        virtual FSMCamara* input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)=0;
        /**
         *  on_entrar.
         *  Esta función representa que sucede cuando entramos a un nuevo estado.
         *  @param  cam referencia a la Camara que pertenece la Maquina de Estados.
         */
        virtual void on_entrar(Camara &cam)=0;
        /**
         *  on_salir.
         *  Esta función representa que sucede cuando salimos del estado.
         *  @param  cam referencia a la Camara que pertenece la Maquina de Estados.
         */
        virtual void on_salir(Camara &cam)=0;
        /**
         *  on_update.
         *  Esta función representa que sucede cuando actualizamos el estado.
         *  @param  cam referencia a la Camara que pertenece la Maquina de Estados.
         */
        virtual void on_update(Camara &cam)=0;
};

/**
 *  EstadoCamaraMover
 *  Es un Estado que se utiliza para mover a la Camara en cualquier dirección.
 */
class EstadoCamaraMover : public FSMCamara
{
    public:
        EstadoCamaraMover(Coordenadas dir);
        virtual ~EstadoCamaraMover(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        Coordenadas direccion;
        Jugador* obj;

};

/**
 *  EstadoCamaraMoverDer
 *  Es un Estado que se utiliza para mover a la derecha a la Camara.
 */
class EstadoCamaraMoverDer : public FSMCamara
{
    public:
        EstadoCamaraMoverDer();
        virtual ~EstadoCamaraMoverDer(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;
};
/**
 *  EstadoCamaraMoverIzq
 *  Es un Estado que se utiliza para mover a la izquierda a la Camara.
 */
class EstadoCamaraMoverIzq : public FSMCamara
{
    public:
        EstadoCamaraMoverIzq();
        virtual ~EstadoCamaraMoverIzq(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;

};
/**
 *  EstadoCamaraArriba
 *  Es un Estado que se utiliza para mover arriba a la Camara.
 */
class EstadoCamaraArriba : public FSMCamara
{
    public:
        EstadoCamaraArriba();
        virtual ~EstadoCamaraArriba(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;

};
/**
 *  EstadoCamaraMoverAbajo
 *  Es un Estado que se utiliza para mover abajo a la Camara.
 */
class EstadoCamaraMoverAbajo : public FSMCamara
{
    public:
        EstadoCamaraMoverAbajo();
        virtual ~EstadoCamaraMoverAbajo(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;
};
/**
 *  CamAD
 *  Es un Estado que se utiliza para mover arriba-derecha a la Camara.
 */
class CamAD : public FSMCamara
{
    public:
        CamAD();
        virtual ~CamAD(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;
};
/**
 *  CamAI
 *  Es un Estado que se utiliza para mover arriba-izquierda a la Camara.
 */
class CamAI : public FSMCamara
{
    public:
        CamAI();
        virtual ~CamAI(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;
};
/**
 *  CamABD
 *  Es un Estado que se utiliza para mover abajo-derecha a la Camara.
 */
class CamABD : public FSMCamara
{
    public:
        CamABD();
        virtual ~CamABD(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;
};
/**
 *  CamABI
 *  Es un Estado que se utiliza para mover abajo-izquierda a la Camara.
 */
class CamABI : public FSMCamara
{
    public:
        CamABI();
        virtual ~CamABI(){};
        FSMCamara* input_handle(Camara &cam,Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        //Coordenadas direccion;
        Jugador* obj;
};



//EJEMPLO DE LERP
/**
 *  EstadoCamaraTransicion
 *  Es un Estado que se utiliza para mover a la Camara hacia el objeto principal.
 */
class EstadoCamaraTransicion : public FSMCamara
{
    public:
        EstadoCamaraTransicion();
        virtual ~EstadoCamaraTransicion(){};
        FSMCamara* input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        Coordenadas check;
        Coordenadas ant_check;
        Coordenadas centro;
        //float distancia;
};
