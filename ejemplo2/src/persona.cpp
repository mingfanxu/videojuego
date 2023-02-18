#include "persona.hpp"

//persona
Persona::Persona(std::string n, std::string a)
{
    nombre=n;
    apellido=a;
};

void Persona::set_nombre(std::string n)
{
    nombre=n;
};

void Persona::set_apellido(std::string a)
{
    apellido=a;
};

//estudiente
//estandadar menor a 17 usar persona(n," ")
//estander 17++ usar persona{n,""}
Estudiante::Estudiante(std::string n):Persona{n,""}
{
    matricula="";
};

void Estudiante::set_matricula(std::string m)
{
    matricula=m;

};

