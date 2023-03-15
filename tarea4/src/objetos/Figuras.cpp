#include "Figuras.hpp"
#include <iostream>


locacion::locacion(int x, int y)
{
    x_pos=x;
    y_pos=y;

};

int locacion::get_y()
{
    return y_pos;
};

int locacion::get_x()
{
    return x_pos;
};

Circulo::Circulo()
{
    int x;
    int y;
    int radio;
    int numvertices;
};

std::vector<Coordenadas> tmp {};
for (int i =0; i<numvert;++i)
{
    float angulo = i * ( 2* PI) / numvert;
    int xx = x+cos(angulo)* radio;
    int yy = y+sin (angulo )* radio;
    tmp.push_back ( Coordenadas{ xx , yy } ) ;
}

std::vector <Coordenadas> vertices{};
for( int i =0; i<numvert;++i)
{
    vertices.push_back (tmp[i]);
    vertices.push_back (tmp [( i +1)%numvert]) ;
}


void Circulo::show(HDC hdc)
{
    if (! is_visible())
    {
        visible = true;
        HPEN hpen = CeratePen(0, 5 RGB(200, 256,256));
        Circulo(hdc,hpen,x_pos,y_pos,radio);
    }
};







Rectangulo::Rectangulo()
{
    int x;
    int y;
    int w;
    int h;
};

void Rectangulo::show(HDC hdc) 
{
    HPEN hpen = CreatPen(0,5,RGB(200,256,256));
    HBRUSH hBrush = CreateSoliBrush(RGB(0,0,0));
    Rectangulo(hdc, hpen, x,y,w,h)
};

Triangulo::Triangulo()
{
    int x;
    int y;
    int w;
    int h;
    int rx,rytx,ty,rx,ry;
};

void Triangulo::show(HDC hdc)
{
    HPEN hpen = CreatPen(0,5,RGB(200,256,256));
    HBRUSH hBrush = CreateSoliBrush(RGB(0,0,0));
    //line(hdc,hpen,x,y,rw,ry);
    line(hdc,hpen,x,y,w,h);
};