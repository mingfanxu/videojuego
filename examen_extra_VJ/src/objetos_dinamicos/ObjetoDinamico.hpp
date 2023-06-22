#pragma once
#include "../objetos/Objeto.hpp"
#include "../motor/KeyOyente.hpp"
#include "../motor/MouseOyente.hpp"

#include<SDL.h>
#include<string>

/**
 *  ObjetoDinamico
 *  Clase abstracta que representa un objeto que puede tener animaciones, estados o movimiento.
 *  Las clases hijas implementan algunos metodos.
 */
class ObjetoDinamico : public Objeto
{
    public:
        /**
         *  Destuctor
         *  Se implementa en las clases hijas
         */
        virtual ~ObjetoDinamico(){};
        /**
         *  update
         *  Se implementa en las clases hijas
         */
        virtual void update(double dt)=0;
        /**
         *  get_dtgf
         *  función que regresa la diferencia de graverdad (un numero pequeño).
         *  NO SE ESTA UTILIZANDO
         *  \see MotorFisica2D
         */
        float get_dtgf()const{return dtgravedad;};
        /**
         *  set_dtgf
         *  función que asigna la diferencia de graverdad (un numero pequeño).
         *  NO SE ESTA UTILIZANDO
         *  @param v flotante pequeño para restar a gravedad
         *  \see MotorFisica2D
         */
        void set_dtgf(float v){dtgravedad=v;};

        /**
         *  set_estado
         *  Se implementa en las clases hijas
         */
        virtual void set_estado(void* estado)=0;
        /**
         *  get_estado
         *  Se implementa en las clases hijas
         */
        virtual void* get_estado()=0;

        Coordenadas offsetoverlap;
    protected:
        float dtgravedad{0};
        
};

/**
 *  BackGroundDinamico
 *  Clase hija de ObjetoDinamico el cual representa una background que puede moverse.
 */
class BackGroundDinamico : public ObjetoDinamico
{
    public:
        /**
         *  Constructor
         *  @param path_sprite dirección de la hoja de Sprite o de la imagen del Sprite.
         *  @param w ancho del Sprite
         *  @param h alto del Sprite
         *  \see Sprite
         */
        BackGroundDinamico(std::string path_sprite,int w, int h);
        virtual ~BackGroundDinamico(){};
        /**
         *  update
         *  Función que actualiza al objeto.
         *  @param dt diferencia de tiempo de un frame a otro.
         */
        void update(double dt);
        /**
         *  set_estado
         *  Función asigna el estado del BackGroundDinamico.
         *  NO ESTA EN USO
         *  @param estado Un estado nuevo.
         */
        void set_estado(void* estado);
        /**
         *  get_estado
         *  Función regresa el estado del BackGroundDinamico.
         *  NO ESTA EN USO
         */
        void* get_estado();
    private:
        Coordenadas limites;
        Coordenadas centro_cam;
};

/**
 *  PlataformasDinamicas
 *  Clase hija de ObjetoDinamico el cual representa una plataforma que puede moverse.
 */
class PlataformasDinamicas : public ObjetoDinamico
{
    public:
        /**
         *  Constructor
         *  @param path_sprite dirección de la hoja de Sprite o de la imagen del Sprite.
         *  @param x posición mundo en x.
         *  @param y posición mundo en y.
         *  @param w ancho del Sprite.
         *  @param h alto del Sprite.
         *  @param sw ancho a mostrar en pantalla del Sprite.
         *  @param sh alto a mostrar en pantalla del Sprite.
         *  \see Sprite
         */
        PlataformasDinamicas(std::string sprite_path, int x, int y, int w, int h,int sw, int sh,SDL_Color c);
        virtual ~PlataformasDinamicas(){};
        /**
         *  update
         *  Función que actualiza al objeto.
         *  @param dt diferencia de tiempo de un frame a otro.
         */
        void update(double dt);
        /**
         *  set_estado
         *  Función asigna el estado del PlataformasDinamicas.
         *  NO ESTA EN USO
         *  @param estado Un estado nuevo.
         */
        void set_estado(void* estado);
        /**
         *  get_estado
         *  Función regresa el estado del BackGroundDinamico.
         *  NO ESTA EN USO
         */
        void* get_estado();
        /**
         *  nombre
         *  atributo que se usa para debugear que plataforma es.
         */
        std::string nombre;

};

/**
 *  Artefactos
 *  Clase hija de ObjetoDinamico el cual representa una ente u objeto diferente a Enemigo o Jugador.
 */
class Artefactos : public ObjetoDinamico
{
    public:
        /**
         *  Constructor
         *  @param path_sprite dirección de la hoja de Sprite o de la imagen del Sprite.
         *  @param x posición mundo en x.
         *  @param y posición mundo en y.
         *  @param w ancho del Sprite.
         *  @param h alto del Sprite.
         *  @param sw ancho a mostrar en pantalla del Sprite.
         *  @param sh alto a mostrar en pantalla del Sprite.
         *  @param c color del artefacto (para debugear)
         *  \see Sprite
         */
        Artefactos(std::string sprite_path, int x, int y, int w, int h,int sw, int sh,SDL_Color c);
        virtual ~Artefactos(){};
        /**
         *  update
         *  Función que actualiza al objeto.
         *  @param dt diferencia de tiempo de un frame a otro.
         */
        void update(double dt);
        /**
         *  set_estado
         *  Función asigna el estado del Artefactos.
         *  NO ESTA EN USO
         *  @param estado Un estado nuevo.
         */
        void set_estado(void* estado);
        /**
         *  get_estado
         *  Función regresa el estado del Artefactos.
         *  NO ESTA EN USO
         */
        void* get_estado();
        /**
         *  set_target
         *  Función que asigna un objeto el cual el Artefacto persigue
         *  @param t Objeto el cual persigue el Artefacto.
         */
        void set_target(Objeto& t);
        /**
         *  render
         *  Función que se usa para debugear, pinta una línea entre el Objeto a seguir y el Artefacto.
         *  @param r Canvas a pintar en formato SDL_Renderer
         */
        void render(SDL_Renderer *r);
    private:
        Objeto* target;
        int frames_actual;
        int frames_maximo;
        Coordenadas Pm;
        Coordenadas Pf;
        Coordenadas tempF;
        int curAngle; // 0-360 angle
        int perAngle; // angle per update
        float radius;  
    
    private:
        /**
         *  ReAjustar
         *  Función ajusta la posición del Artefacto para encontrar el Objeto target.
         */
        bool ReAjustar();

};