#pragma once
#include<chrono>
/**
 *  Tiempo
 *  Es la clase que se encarga de contar el tiempo transcurrido en milisegundo.
 *  Es una clase Singleton por lo que no se ocupa hacer una instancia.
 */
class Tiempo
{
    public:
        /**
         *  tiempo_inicial
         *  atributo que guarda cuando inicio a contar el tiempo.
         */
        static std::chrono::time_point<std::chrono::steady_clock> tiempo_inicial;
        /**
         *  get_tiempo
         *  Función que regresa el tiempo transcurrido desde que inicio el conteo.
         */
        static double get_tiempo();
};