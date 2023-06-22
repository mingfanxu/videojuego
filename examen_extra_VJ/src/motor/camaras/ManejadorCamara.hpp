#pragma once
#include "Camaras.hpp"
#include "../../objetos/Objeto.hpp"
/**
 *  ManejadorCamaras 
 *  Esta clase se encarga de llevar y administrar todas las cámaras que se
 *  creen dentro del proyecto. Es una clase singleton por lo que no es necesario
 *  instanciar la clase.
 */
class ManejadorCamaras
{
    public:
        /**
         *  Función get 
         *  Esta función sirve para acceder a la instancia creada al momento de ejecución
         *  @return regresa la instancia de tipo ManejadorCamaras
         */
        static ManejadorCamaras& get();
        /**
         *  Función set_camara 
         *  Esta función sirve activar una cámara como la principal.
         */
        static void set_camara(Camara &cam);
        /**
         *  Función get_camara 
         *  Esta función sirve obtener la cámara principal @see Camara
         *  @return regresa la referencia de una cámara tipo Camara
         */
        static Camara& get_camara();
        /**
         *  Función lock_objeto 
         *  Esta función sirve para decirle a la cámara principal que objeto seguir
         *  \see Camara
         *  @param obj es el objeto que la cámara principal seguirá
         */
        static void lock_objeto(Objeto& obj);
        /**
         *  Función unluck_objeto 
         *  Esta función sirve para decirle a la cámara que deje seguir al objeto
         *  \see Camara
         */
        static void unluck_objeto();

        /**
         *  Función input_handle 
         *  Esta función sirve capturar los inputs para controlar a la cámara principal
         *  @param input los inputs del teclado.
         *  @param mouse los inputs del mouse.
         *  \see Camara
         */
        static void input_handle(KeyOyente &input, MouseOyente &mouse);
        /**
         *  Función update 
         *  Esta función sirve para actualizar a la cámara principal y hacer la proyección a Coordenadas cámara
         *  @param objetos una lista de objetos para actualizar y hacer la proyección.
         *  \see Camara
         */
        static void update(std::vector<Objeto*> objetos);
        static void set_estado(void *nuevo);
        static void* get_estado();
        /**
         *  Función renderizar 
         *  Esta función sirve para renderizar los objetos a pantalla
         *  @param objetos una lista de objetos a renderizar.
         *  \see Camara
         */
        static void renderizar(std::vector<Objeto*> objetos);


    private:
        ManejadorCamaras();
        static ManejadorCamaras* instancia;
        Camara *camara_actual;
};