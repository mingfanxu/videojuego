#pragma once 
#include "Estructuras.hpp " 
#include<vector>
#define DEBUG
#define PI 3.1416

#ifdef DEBUG 
    #define DEBUGPRINT(X) std::cout<<" \x1B[34m"<<X<<"\x1B [0m"<<std::endl ; 
    #define DEBUGCOOR(P1 )std::cout<<" \x1B[34m("<<P1.x<<" , "<<P1.y <<" ) \x1B [0m"<<std::endl;
    #define DEBUGLINEA(P1,P2 ) std::cout<<" \x1B [32m( "<<P1.x <<","<<P1.y<<") -- ( "<<P2.x<<","<<P2.y<<")\x1B[0m"<<std::endl; 
#else
    #define DEBUGPRINT(X)do{} while ( 0 ) 
    #define DEBUGCOOR(X) do {} while( 0 ) 
    #define DEBUGLINEA(X) do {} while( 0 ) 
#endif

bool tiene_determinante (Coordenadas p1 , Coordenadas p2 , Coordenadas p3 , Coordenadas p4)
{
    // Si es 0, quieredecir que son paralelas y no tiene determinante.
    return ( (p1.x-p2.x) * (p3.y-p4.y)-( p1.y-p2.y) * (p3.x-p4.x))!= 0;
} ;

Coordenadas interseccion (Coordenadas p1 ,Coordenadas p2 ,Coordenadas p3 ,Coordenadas p4)
{
    /* el punto puede estar fuera de los limites de la figura verificarlo */
    int x=((p1.x*p2.y-p1.y*p2.x)*(p3.x-p4.x)-( p1.x-p2.x)*(p3.x*p4.y-p3.y*p4.x))/((p1.x-p2.x)*(p3.y-p4.y)-(p1.y-p2.y)*( p3.x-p4.x));
    int y=((p1.x*p2.y-p1.y*p2.x)*(p3.y-p4.y)-( p1.y-p2.y)*(p3.x*p4.y-p3.y*p4.x))/((p1.x-p2.x)*(p3.y-p4.y)-(p1.y-p2.y)*(p3.x-p4.x));
    return {x,y};
};

bool tiene_interseccion ( Coordenadas p1,Coordenadas p2,Coordenadas p3 ,Coordenadas p4);

int coordenada_maxima ( std::vector<Coordenadas> vertices,char eje) 
{
    int max ;
    if (eje=='x' )
    {
        max = vertices[0].x;
        for(int i =1; i<vertices.size();++ i)
        {
            if (vertices[i].x>=max)
            {
                max=vertices[i].x;
            }
        }
    } else 
    {
        max=vertices[0].y;
        for(int i =1;i<vertices.size();++i)
        {
            if(vertices[i].y>=max)
            {
                max=vertices[i].y;
            }
        }
    }
    return max; //O(n)
} ;

int coordenada_minima ( std::vector<Coordenadas> vertices,char eje) 
{
    int min ;
    if (eje=='x' )
    {
        min = vertices[0].x;
        for(int i =1; i<vertices.size();++ i)
        {
            if (vertices[i].x<=min)
            {
                min=vertices[i].x;
            }
        }
    } else 
    {
        min=vertices[0].y;
        for(int i =1;i<vertices.size();++i)
        {
            if(vertices[i].y<=min)
            {
                min=vertices[i].y;
            }
        }
    }
    return min; //O(n)
} ;

std::vector <Coordenadas>sort_insertion(std::vector<Coordenadas>lista,char eje)
{
    std::vector <Coordenadas>copia=lista;
    int i =1; 
    while (i<copia.size())
    {
        int v = (eje == 'X' ) ? copia[i].x:copia[i].y;
        int j = i-1;
        int m = (eje == 'x' ) ? copia[j].x:copia[j].y; 
        Coordenadas temp = copia[i]; 
        while ( j >=0 && m<v) // menor a mayor
        {
            // swap
            copia [j+1] = copia[j];
            j -=1;
        }
        copia [j+1] = temp;
        i++;
    }
    return copia;
} ;

std::vector<Coordenadas>wrapper_sort(std::vector <Coordenadas>vec,char e,std::vector<Coordenadas> (*algoritmo)( std::vector<Coordenadas>lista, char eje))
{
    return (*algoritmo)(vec,e);
} ;

Coordenadas LERP( Coordenadas p1 , Coordenadas p2 , float t )
{
    int x = p1.x+t*(p2.x-p1.x);
    int y = p1.y+t*(p2.y-p1.y);
    return {x,y};
} ;

Coordenadas ROTAR( double radianes , Coordenadas P){
    int x = P.x*SDL_cos(radianes) - P.y*SDL_sin(radianes);
    int y = P.x*SDL_sin(radianes) + P.y *SDL_cos(radianes);
    return {x,y};
}; 
Coordenadas TRASLADAR( Coordenadas A, Coordenadas B)
{
    return {A.x+B.x,A.y+B.y};
};