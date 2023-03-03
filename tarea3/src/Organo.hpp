#pragma once
#include<string>

class Atributos //属性
{
    public:

    virtual ~Atributos (){};
    virtual int fuerza() = 0; //rand() % 255 + 100;
    virtual int agilidad() = 0; //rand() % 255 + 100; 
    virtual int dureza() = 0; //rand() % 255 + 100; 
    virtual int danio()= 0;
    virtual void reporte() =0;
    virtual void init() =0;

};

class bacterias : public Atributos
{
    public:
    bacterias();
    virtual ~bacterias();
    int fuerza();
    int agilidad();
    int dureza();
    int danio();

    void reporte();
    void init();

    private:
    float bacteria;

};

class globulos : public Atributos
{
    public:
    globulos();
    virtual ~globulos();
    int fuerza();
    int agilidad();
    int dureza();
    int danio();
    
    void reporte();
    void init();

    private:
    float globulo;

};

