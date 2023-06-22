#pragma once
#include "../../objetos_dinamicos/Enemigos.hpp"

class Enemigo; //declaración hacia delante
/**
 *  FSMEnemigo
 *  Es una clase interface que representa la Maquina de Estados de la clase Enemigo (FSM).
 *  Las clases heredadas son los estados del Enemigo.
 */
class FSMEnemigo
{
    protected:
        /**
         *  atributo strnombre.
         *  Este atributo representa el nombre del estado.
         */
        std::string strnombre;
    
    public:
        virtual ~FSMEnemigo(){};
        /**
         *  on_entrar.
         *  Esta función representa que sucede cuando entramos a un nuevo estado.
         *  @param  enemigo referencia a Enemigo que pertenece la Maquina de Estados.
         */
        virtual void entrar(Enemigo& enemigo)=0;
        /**
         *  on_salir.
         *  Esta función representa que sucede cuando salimos del estado.
         *  @param enemigo referencia a Enemigo que pertenece la Maquina de Estados.
         */
        virtual void salir(Enemigo& enemigo)=0;
        /**
         *  on_update.
         *  Esta función representa que sucede cuando actualizamos el estado.
         *  @param enemigo referencia a Enemigo que pertenece la Maquina de Estados.
         */
        virtual void update(Enemigo& enemigo,double dt)=0;
        std::string get_namestate()const{return strnombre;};
    protected:
        /**
         *  atributo frames_actual_ani.
         *  Este atributo representa el frame actual de la animación.
         */
        int frames_actual_ani{0};
        /**
         *  atributo frames_maxim_ani.
         *  Este atributo representa los frames máximos de la animación.
         */
        int frames_maxim_ani{0};
        /**
         *  atributo int frame_dt.
         *  Este atributo representa una diferencia de frames.
         */
        int frame_dt{0};
};
/**
 *  FSMEnemigo_IDLE
 *  Es el Nodo de la Maquina de Estados de Enemigo. 
 *  Cuando el Enemigo esta sin moverse.
 */
class FSMEnemigo_IDLE : public FSMEnemigo
{
    public:
        virtual ~FSMEnemigo_IDLE(){};
        //virtual FSMEnemigo* input_handle(KeyOyente& input, MouseOyente& mouse)=0;
        void entrar(Enemigo& enemigo);
        void salir(Enemigo& enemigo);
        void update(Enemigo& enemigo,double dt);
};
/**
 *  FSMEnemigo_MoverDerecha
 *  Es el Nodo de la Maquina de Estados de Enemigo. 
 *  Cuando el Enemigo se mueve a la derecha.
 */
class FSMEnemigo_MoverDerecha : public FSMEnemigo
{
    public:
        virtual ~FSMEnemigo_MoverDerecha(){};
        //virtual FSMEnemigo* input_handle(KeyOyente& input, MouseOyente& mouse)=0;
        void entrar(Enemigo& enemigo);
        void salir(Enemigo& enemigo);
        void update(Enemigo& enemigo,double dt);
};
/**
 *  FSMEnemigo_MoverIzquierda
 *  Es el Nodo de la Maquina de Estados de Enemigo. 
 *  Cuando el Enemigo se mueve a la izquierda.
 */
class FSMEnemigo_MoverIzquierda : public FSMEnemigo
{
    public:
        virtual ~FSMEnemigo_MoverIzquierda(){};
        //virtual FSMEnemigo* input_handle(KeyOyente& input, MouseOyente& mouse)=0;
        void entrar(Enemigo& enemigo);
        void salir(Enemigo& enemigo);
        void update(Enemigo& enemigo,double dt);
};