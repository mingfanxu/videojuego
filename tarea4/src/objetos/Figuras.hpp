#pragma once
#define PI 3.1416

class Figura //clase padre
{
    public:
    virtual ~Figura(){};
    virtual void show(HDC) = 0;
};

class locacion{
    public:
        locacion(int x, int y);
        int get_x();
        int get_y();

    protected:
        int x_pos, y_pos
};

class point:public locacion, public Figura
{
    public:
        point(int x, int y);
        bool is_visible();
        void show(HDC hdc);
        void hide(HDC hdc);
        void move_to(HDC hdc, int x, int y);

    protected:
        bool visible;
};

class Rectangulo : public Figura
{
    private:
        int x,y,w,h;
    
    public:
        Rectangulo(int x, int y, int w, int h);
        void show(HDC);
};

class Triangulo : public Figura
{
     private:
        int x,y,w,h;
    
    public:
        Triangulo(int x, int y, int w, int h,Coordenadas p1 , Coordenadas p2 , Coordenadas p3);
        void show(HDC);
};

class Circulo : public Figura
{
    private:
        int radio,x,y, numvertices;
    
    public:
        Rectangulo(int x, int y, int radio, int numvertices);
        void show(HDC);
};
//clases derivadas
// Rectangulo
//Triangulo
//Circulo