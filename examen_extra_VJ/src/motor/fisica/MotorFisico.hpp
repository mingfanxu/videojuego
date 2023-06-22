#pragma once
#include "../../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../../objetos_estaticos/ObjetoEstatico.hpp"
#include "../../objetos/Objeto.hpp"
#include "../../objetos/Figuras.hpp"
#include<vector>
/**
 *  MotorFisico2D 
 *  Esta clase se encarga de aplicar las colisiones o la gravedad en los objetos
 *  Es una clase singleton por lo que no es necesario instanciar la clase.
 */
class MotorFisico2D
{
    public:
        /**
         *  get 
         *  Esta función sirve para acceder a la instancia creada al momento de ejecución
         *  @return regresa la instancia de tipo MotorFisico2D
         */
        static MotorFisico2D& get();
        /**
         *  aabb_colision 
         *  Esta función sirve para revisar si hay solapamiento entre dos rectángulos, usando la técnica de AABB
         *  @param A es la primera Figura
         *  @param B es la segunda Figura
         *  @return true si hay solapamiento o false si no lo hay.
         *  \see Figura
         *  \see Objeto
         */
        static bool aabb_colision(Figura& A, Figura& B);
        /**
         *  diag_colision 
         *  Esta función sirve para revisar si hay solapamiento entre dos rectángulos, usando la técnica de la Diagonal
         *  @param A es la primera Figura
         *  @param B es la segunda Figura
         *  @return true si hay solapamiento o false si no lo hay.
         *  \see Figura
         *  \see Objeto
         */ 
        static bool diag_colision(Figura& A, Figura& B);
        /**
         *  diag_overlap 
         *  Esta función sirve para revisar si hay solapamiento entre dos rectángulos, usando la técnica de la Diagonal
         *  @param A es la primera Figura
         *  @param B es la segunda Figura
         *  @return siempre regresa false, ya que resuelve la colisión y empuja a la Figura A fuera de la Figura B.
         *  \see Figura
         *  \see Objeto
         */
        static bool diag_overlap(Objeto& A, Objeto& B);
        /**
         *  sat_colision 
         *  Esta función sirve para revisar si hay solapamiento entre dos rectángulos, usando la técnica de la SAT
         *  @param p es el objeto que va comparar
         *  @param obj una lista de objetos que se compara con p
         *  \see Figura
         *  \see Objeto
         */
        static void sat_colision(ObjetoDinamico&p, std::vector<ObjetoEstatico*> obj);
        /**
         *  sat_colision 
         *  Esta función sirve para revisar si hay solapamiento entre dos rectángulos, usando la técnica de la SortAndSweep
         *  @param obj una lista de objetos que se revisan entre si
         *  \see Figura
         *  \see Objeto
         */
        static void sortandsweep_colision(std::vector<ObjetoDinamico*> objs);
        /**
         *  gravedad 
         *  Esta función sirve para aplicar gravedad a una lista de objetos
         *  @param objs una lista de objetos que se le va aplicar gravedad
         *  \see Figura
         *  \see Objeto
         */
        static void gravedad(std::vector<ObjetoDinamico*> objs);

    public:
        /**
         *  gforce
         *  Atributo que sirve para incrementar o decrementar que cuanta gravedad hay
         */
        static float gforce;

    private:
        bool sat(Objeto &A, Objeto& B);
        //bool aabb(Objeto &A, Objeto &B);

    private:
        MotorFisico2D(){};
        static MotorFisico2D* instancia;
        
        //float dtgravedad{0};

};
