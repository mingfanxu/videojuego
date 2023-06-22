#pragma once
#include "ObjetoDinamico.hpp"
#include <SDL.h>
/**
 *  Arbusto
 *  Es una clase hijo de ObjetoDinamico, representa una planta, arbusto o árbol en el mundo.
 */
class Arbusto : public ObjetoDinamico
{
    public:
        /**
         *  Constructor
         *  @param xml dirección del archivo XML donde se encuentra la información de los Tile o Sprite.
         *  @param pos la Coordenada del mundo donde se va a colocar.
         *  @param col_init columna en donde inicia la imagen dentro de la hoja de Sprite o Tile.
         *  @param row_init renglón en donde inicia la imagen dentro de la hoja de Sprite o Tile.
         * @param rows cuantos renglones extra va abarcar la imagen.
         * @param cols cuantas columnas extra va abarcar la imagen.
         */
        Arbusto(std::string xml,Coordenadas pos, int col_init, int row_init,int rows, int cols);
        /**
         *  update
         *  Función que actualiza al objeto.
         *  @param dt diferencia de tiempo de un frame a otro.
         */
        void update(double dt);
        /**
         *  set_estado
         *  Función para cambiar el estado del Objeto.
         *  No esta implementado ya que arbustos no tiene estados
         *  @param estado el nuevo estado a cambiar *
         */
        void set_estado(void* estado);
        /**
         *  get_estado
         *  Función para obtener el estado del Objeto.
         *  No esta implementado ya que arbustos no tiene estados
         *  \return NULL no esta implementada.
         */
        void* get_estado();

    private:
        int row_init;
        int width;
        int height;
        std::string xml_path;
};