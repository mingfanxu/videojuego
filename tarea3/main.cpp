#include<iostream>
#include<vector>
#include"scr/Organo.hpp"
//#include<SDL.h>

int main(int argc, char* argv[])
{
    std::vector<Organo*> organo ={new globulos(), new bacterias()};

    for (auto &f: organo)
    {
        f->init();
        f->reporte();
    };

    //limpiar
    for(int i=0; i<organo.size();++i)
    delete organo[i];
    return 0;

};