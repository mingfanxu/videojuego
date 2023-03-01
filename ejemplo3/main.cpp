#include<iostream>
#include<vector>
#include"scr/Figuras.hpp"
//#include<SDL.h>

int main(int argc, char* argv[])
{
    std::vector<Figura*> figuras ={new Circulo(), new Rectangulo()};

    for (auto &f: figuras)
    {
        f->init();
        f->reporte();
    };

    //limpiar
    for(int i=0; i<figuras.size();++i)
    delete figuras[i];
    return 0;

};


//make && ./inter > debug.txt