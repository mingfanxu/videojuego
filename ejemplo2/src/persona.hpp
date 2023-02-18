#pragma once
#include<string>


class Persona
{
    public:
    Persona(std::string n, std::string a);
   

    private:
    std::string nombre;
    std::string apellido;

    public:
    void set_nombre(std::string n);
    void set_apellido(std::string a);

    //funcion inline
    std::string get_nombre() const{return nombre;};
    std::string get_apellido() const{return apellido;};
};

class Estudiante: public Persona
{
    public:
    Estudiante(std::string n);
    void set_matricula(std::string m);

    //inline functions
    std::string get_matricula() const{return matricula;};

    private:
    std::string matricula;

 
};