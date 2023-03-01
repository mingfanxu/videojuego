#include "Figuras.hpp"
#include <iostream>

Circulo::Circulo()
{
    radio=0;
};


Circulo::~Circulo()
{
    std::cout<<"Destruye Circulo\n";
};

float Circulo::area()
{
    return PI * radio*radio;
};

float Circulo::perimetro()
{
    return 2*PI*radio;
};

void Circulo::init()
{
    std::cout<<"Radio: ";
    std::cin>>radio;
};

void Circulo::reporte()
{
    std::cout<<"El area es:"<<this->area();
    std::cout<<"\nEl perimetro es:"<<this->perimetro();
};




Rectangulo::Rectangulo()
{
    base=0;
    altura=0;
};

Rectangulo::~Rectangulo()
{
    std::cout<<"Destruyendo Rectangulo\n";
};

float Rectangulo::area()
{
    return base*altura;
};

float Rectangulo::perimetro()
{
    return 2*(base+altura);
};

void Rectangulo::init()
{
    std::cout,"\nBase:";
    std::cin>>base;
    std::cout<<"\nAltura:";
    std::cin>>altura;
};

void Rectangulo::reporte()
{
    std::cout<<"\nEl area es:"<<this->area();
    std::cout<<"\nEl perimetro es:"<<this->perimetro();
};


