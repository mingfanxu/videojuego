#pragma once
#define PI 3.1416

class Figura
{
    public:
    virtual ~Figura(){};//Destructor

    virtual float area()=0;
    virtual float perimetro() =0;
    virtual void reporte() =0;
    virtual void init() =0;

};

class Circulo : public Figura
{
    public:
    Circulo();
    virtual ~Circulo();

    float area();
    float perimetro();
    void reporte();
    void init();
    private:
    float radio;


};

class Rectangulo : public Figura
{
    public:
    Rectangulo();

    virtual ~Rectangulo();

    float area();
    float perimetro();
    void reporte();
    void init();
    private:
    float base;
    float altura;

};
