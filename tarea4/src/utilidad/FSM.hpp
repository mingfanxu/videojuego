#pragma once 
#include "../objetos_dinamicos/Entidad.hpp"
#include "../motor/KeyOyente.hpp"
#include <string>
class FSM
{
    protected:
        std::string strnombre;

    public:
    virtual ~FSM(){};
    virtual FSM* handle Input ( Entidad& personaje, KeyOyente& input )=0;
    virtual void entrar ( Entidad& personaje)=0;
    virtual void salir (Entidad& personaje )=0;
    virtual void update ( Entidad& personaje, double dt )=0;
    std::string get_namestate ( ) const { return strnombre;};
} ;