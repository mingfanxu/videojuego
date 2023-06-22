#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include "motor/Pipeline.hpp"
#include "objetos_dinamicos/ObjetoDinamico.hpp"
#include "objetos_dinamicos/Enemigos.hpp"
#include "objetos_dinamicos/Jugador.hpp"
#include "objetos_dinamicos/Arbustos.hpp"
#include "objetos_dinamicos/Torres.hpp"
#include "objetos_estaticos/ObjetoEstatico.hpp"
#include "motor/camaras/Camaras.hpp"
#include "motor/camaras/ManejadorCamara.hpp"
#include "motor/imagen/atlas.hpp"
#include "utilidad/Spawns/PlataformasSpawner.hpp"
/**
 *  SDLApp
 *  Clase principal del Juego también se puede ver como el Mapa
 *  Es una clase Singleton por lo que no se ocupa hacer una instancia.
 */
class SDLApp
{
    private:
        SDLApp();   
        bool on_init();
        void on_evento(SDL_Event *evento);
        void on_fisicaupdate(double dt); 
        void on_frameupdate(double dt); 
        void on_limpiar();

        bool esta_corriendo;
        int WIDTH;
        int HEIGHT;

        SDL_Window* vnt;
        SDL_Surface* vntsurf;
        SDL_Renderer* render;

        //singleton
        static SDLApp* instancia;

        //02_lineas_figuras
        Pipeline *ensamble;
    
        //a03_Maquinas_estados.
        double maxFPS;
        double msfrecuencia;
        int fps;

        //05_Colisiones
        Jugador* player;
        Enemigo* enemigo;

        Arbusto * pastotest;

        Torres **torres;

        std::vector<Objeto*> plataformas;

        //06_Camaras
        Camara* camara_principal;
        std::vector<Objeto*> objetos;

        //08 tiles
        Atlas *mapa;

        //09 parallax
        BackGroundDinamico *background;


        Artefactos * artest;
    
    public:
        SDL_Color bg_color;
        /**
         *  on_correr
         *  Función que se ejecuta al iniciar la aplicación.
         *  Esta función ejecuta la estructura principal de un juego:
         * 
         *      mientras esta corriendo:
         *          capturar eventos
         *          update física
         *          update frame
         *      limpiar
         */
        static int on_correr();
        /**
         *  set_bgcolor
         *  Función se encarga de agregar el color por defecto del fondo.
         *  @param rojo valor de [0-255] para el color rojo
         *  @param verde valor de [0-255] para el color verde
         *  @param azul valor de [0-255] para el color azul
         *
         */
        static void set_bgcolor(Uint8 rojo,Uint8 verde,Uint8 azul);
        /**
         *  get 
         *  Esta función sirve para acceder a la instancia y poder utilizar los métodos de la clase de manera segura
         */
        static SDLApp& get();
        static bool estaCorriendo() {return get().esta_corriendo;};
};