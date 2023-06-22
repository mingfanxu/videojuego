#pragma once
#include "ObjetoDinamico.hpp"
#include "../utilidad/FSMS/FSMEnemigo.hpp"

class FSMEnemigo;
/**
 *  Enemigo
 *  Es una clase hijo de ObjetoDinamico, representa un enemigo o jefe.
 */
class Enemigo : public ObjetoDinamico
{
    public:
        /**
         *  Destructor
         *  Libera la memoria de todos los apuntadores utilizados
         */
        virtual ~Enemigo(){};
        /**
         *  Constructor
         *  @param path_xml dirección donde se encuentra el archivo XML con información de los Sprite.
         *  @param vida vida del enemigo.
         *  @param x posición mundo en el eje x.
         *  @param y posición mundo en el eje y.
         *  @param sw width del Sprite que queremos mostrar.
         *  @param sh height del Sprite que queremos mostrar.
         *  @param c color del enemigo en formato SDL_Color.
         */
        Enemigo(std::string path_xml,float vida, int x, int y, int sw,int sh, SDL_Color c );
        /**
         *  update
         *  Función que actualiza al objeto.
         *  @param dt diferencia de tiempo de un frame a otro.
         */
        void update(double dt);
        /**
         *  set_estado
         *  Función para cambiar el estado del Objeto.
         *  @param estado el nuevo estado a cambiar de tipo FSMEnemigo
         *  \see FSMEnemigo
         */
        void set_estado(void* estado);
        /**
         *  get_estado
         *  Función para obtener el estado del Objeto.
         *  \return el estado actual como una clase de FSMenemigo
         *  \see FSMEnemigo
         */
        void* get_estado();

        /**
         *  MoverDerecha
         *  Función para mover el Enemigo a la derecha
         */
        void MoverDerecha(double dt);
        /**
         *  MoverIzquierda
         *  Función para mover el Enemigo a la izquierda
         */
        void MoverIzquierda(double dt);
        /**
         *  MoverArriba
         *  Función para mover el Enemigo a la arriba
         */
        void MoverArriba(double dt);
        /**
         *  MoverAbajo
         *  Función para mover el Enemigo a la abajo
         */
        void MoverAbajo(double dt);
        /**
         *  Brincar
         *  Función para que el Enemigo Brinque
         *  NO ESTA IMPLEMENTADA
         */
        void Brincar(double dt);
        /**
         *  Atacar
         *  Función para que el Enemigo Ataque.
         *  NO ESTA IMPLEMENTADA
         */
        void Atacar(double dt);

        void setClockwise(int c) { clockwise = c; }

        bool closePot(Coordenadas p);

    private:
        FSMEnemigo* estado_actual;
        Figura *col_ataque;
        Figura *col_dano;

        Coordenadas KeyPot[4];
        int dir;
        int clockwise;
};