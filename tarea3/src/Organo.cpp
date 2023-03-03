#include "Organo.hpp"
#include <iostream>

bacterias::bacterias()
{
    bacteria=1024;
    int fuerza()   rand() % 255 + 100;;
    int agilidad()  rand() % 255 + 100; 
    int dureza() rand() % 255 + 100; 
};

bacterias::bacterias()
{
    std::cout<<"Destruye bacterias\n";

};

int bacterias::danio()
{
    return (fuerza+dureza)/globulos.agilidad;
    
};

void bacterias::init()
{
    std::cout,"\nfuerza:";
    std::cin>>fuerza;
    std::cout<<"\ndureza:";
    std::cin>>dureza;
    std::cout<<"\naglidad:";
    std::cin>>aglidad;
};

void bacterias::reporte()
{
    std::cout<<"\nLa danio es:"<<this->danio();
}





globulos::globulos()
{
    globulo=512;

};

globulos::globulos()
{
    std::cout<<"Destruye globulos\n";

};

int globulos::danio()
{
    return (fuerza+agilidad)/bacterias.dureza;
};

void globulos::init()
{
    std::cout,"\nfuerza:";
    std::cin>>fuerza;
    std::cout<<"\ndureza:";
    std::cin>>dureza;
    std::cout<<"\naglidad:";
    std::cin>>aglidad;
};

void globulos::reporte()
{
    std::cout<<"\nLa danio es:"<<this->danio();
}
