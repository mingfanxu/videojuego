#include "Arbustos.hpp"
/**
 *  Torres
 *  Clase hija de ObjetoDinamico el cual representa una ente u objeto diferente a Enemigo o Jugador o Artefacto.
 *  Representa principalmente torres, trampas etc...
 */
class Torres: public Arbusto
{
    public:
        /**
         *  Constructor
         *  @param xml dirección del archivo XML donde se encuentra la información de los Tile o Sprite.
         *  @param pos la Coordenada del mundo donde se va a colocar.
         *  @param col_init columna en donde inicia la imagen dentro de la hoja de Sprite o Tile.
         *  @param row_init renglón en donde inicia la imagen dentro de la hoja de Sprite o Tile.
         *  @param rows cuantos renglones extra va abarcar la imagen.
         *  @param cols cuantas columnas extra va abarcar la imagen.
         */
        Torres(std::string xml,Coordenadas pos,int col_init,int row_init,int rows, int cols);
};