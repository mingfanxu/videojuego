#include<iostream>
#include "src/persona.hpp"

int main()
{
    Estudiante *est = new Estudiante("Mingfan");
    est->set_apellido("Xu");
    est->set_matricula("1274233");

    std::cout<<est->get_nombre() <<" "<<est->get_apellido()<<"\n";

    std::cout<<est->get_matricula()<<"\n";


    delete est;
    return 0;
};