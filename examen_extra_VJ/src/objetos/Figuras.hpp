#pragma once

#include<vector>
#include "../utilidad/Estructuras.hpp"
#include<SDL.h>
/**
 *  Figura 
 *  Esta clase se encarga de ser la interface para todo lo relacionado con las figuras (Rectangulo,Circulos, Etc).
 *  Es una clase Abstracta
 */
class Figura
{
    public:
        /**
         *  Figura  Destructor
         *  Se implementa en las clases hijas.
         *  \see Rectangulo
         *  \see Circulo
         *  \see Triangulo
         */
        virtual ~Figura(){};
        /**
         *  get_posicion
         *  Regresa la posición de la Figura
         */
        Coordenadas get_posicion() const {return posicion;};
        /**
         *  get_posicion
         *  Asigna una posición a la Figura.
         *  @param x entero que corresponde al eje de la x.
         *  @param y entero que corresponde al eje de la y.
         */
        void set_position(int x, int y){posicion.x=x;posicion.y=y;};
        /**
         *  get_vertices
         *  Regresa una lista de Coordenadas que representan los puntos que conforman a la Figura.
         *  \return una lista de vertices de tipo Coordenada.
         */
        std::vector<Coordenadas> get_vertices() const {return vertices;};
        /**
         *  set_vertices
         *  Asigna unos vertices nuevos a la Figura.
         *  \return una lista de vertices de tipo Coordenada.
         */
        void set_vertices(std::vector<Coordenadas> nv){vertices=nv;};
        /**
         *  set_strokecolor
         *  Asigna el color de la líneas del contorno.
         *  @param nc un color de tipo SDL_Color.
         */
        void set_strokecolor(SDL_Color nc){lineacolor=nc;};
        /**
         *  get_strokecolor
         *  Regresa el color de la líneas de la Figura.
         *  \return el color como una estructura SDL_Color
         */
        SDL_Color get_strokecolor() const {return lineacolor;};
        /**
         *  set_rellenocolor
         *  Asigna el color del relleno de la Figura.
         *  @param nc un color de tipo SDL_Color.
         */
        void set_rellenocolor(SDL_Color nc){rellenocolor=nc;};
        /**
         *  get_rellenocolor
         *  Regresa el color del relleno de la Figura.
         *  \return el color como una estructura SDL_Color
         */
        SDL_Color get_rellenocolor()const {return rellenocolor;};
        /**
         *  get_pivote
         *  Regresa la Coordenada del punto inicial para formar la Figura.
         *  \return una Coordenada del punto del cual se forma la Figura.
         */
        Coordenadas get_pivote() const{return pivote;};
        bool get_serellena() const{return se_rellena;};
        void set_serellena(bool v){se_rellena=v;};
        /**
         *  generar_vertices
         *  Se implementa en las Figuras.
         *  Sirve para generar los vertices de la Figura.
         *  \see Rectangulo
         *  \see Circulo
         *  \see Triangulo
         */
        virtual void generar_vertices()=0;
        /**
         *  generar_vertices
         *  Se implementa en las Figuras.
         *  Sirve para actualizar los vertices de la Figura.
         *  \see Rectangulo
         *  \see Circulo
         *  \see Triangulo
         */
        virtual void update_vertices()=0;

    protected:
        std::vector<Coordenadas> vertices;
        Coordenadas posicion;
        SDL_Color lineacolor;
        SDL_Color rellenocolor;
        Coordenadas pivote;
        bool se_rellena;
};
/**
 *  Rectangulo 
 *  Esta clase es hijo de Figura y representa un Rectangulo
 */
class Rectangulo : public Figura
{
    public:
        /**
         *  Rectangulo Constructor.
         *  @param x entero que representa el eje de las x.
         *  @param y entero que representa el eje de las y.
         *  @param w entero que representa el largo del Rectangulo.
         *  @param h entero que representa lo alto del Rectangulo.
         */
        Rectangulo(int x, int y, int w, int h,SDL_Color color);
        /**
         *  Rectangulo Destructor.
         *  Borra el apuntador de Figura en memoria.
         */
        virtual ~Rectangulo(){};
        /**
         *  generar_vertices.
         *  Genera los vertices del Rectangulo en el siguiente orden.
         * 
         *  A--D--C--B--A
         *  
         */
        void generar_vertices();
        /**
         *  update_vertices.
         *  Actualiza los vertices del Rectangulo  
         */
        void update_vertices();
    private:
        int width;
        int height;

};
/**
 *  Triangulo 
 *  Esta clase es hijo de Figura y representa un Triangulo
 */
class Triangulo : public Figura
{
    
    public:
        /**
         *  Triangulo Constructor.
         *  @param p1 vértice del Triangulo tipo Coordenadas.
         *  @param p2 vértice del Triangulo tipo Coordenadas.
         *  @param p3 vértice del Triangulo tipo Coordenadas
         *  @param color color del Triangulo en formato SDL_Color
         */
        Triangulo(Coordenadas p1,Coordenadas p2,Coordenadas p3,SDL_Color color);
        //Triangulo(int x,int y,int w, int h, SDL_Color color);
        virtual ~Triangulo(){};
        /**
         *  genera_vertices.
         *  Genera los vertices del Triangulo
         */
        void generar_vertices();
        /**
         *  update_vertices.
         *  Actualiza los vertices del Triangulo  
         */
        void update_vertices();
    private:
        Coordenadas A;
        Coordenadas B;
        Coordenadas C;

};
/**
 *  Circulo 
 *  Esta clase es hijo de Figura y representa un Circulo
 */
class Circulo : public Figura
{
    public:
        Circulo(int r,int x,int y,int numvertices, SDL_Color color);
        virtual ~Circulo(){};
        /**
         *  genera_vertices.
         *  Genera los vertices del Circulo
         */
        void generar_vertices();
        /**
         *  update_vertices.
         *  Actualiza los vertices del Circulo
         */
        void update_vertices();
    private:
        int radio;
        int segmentos;

};