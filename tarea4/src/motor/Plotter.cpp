#include "Plotter.hpp"
Plotter::Plotter () { /* nada que inicializar */};
e
void Plotter::render_pixel(SDL_Renderer *r, Coordenadas p, SDL_Color color)
{
    /* designar como utilizar el alpha */
    SDL_SetRenderDrawBlendMode ( r, SDL_BLENDMODE_BLEND);
    /*asignar el color */
    SDL_SetRenderDrawColor( r, color.r,color.g,color.b , color.a);
    /*pintar el pixel */
    SDL_RenderDrawPoint (r,p.x,p.y);
};

void Plotter::render_linea(SDL_Renderer *r , Coordenadas p1 , Coordenadas p2 , SDL_Color color)
{
    /* Implementar usando el algoritmo BRESSENHAM y el render_pixel
    NO USAR SDL_RenderDrawLine */

    int dx = std::abs(p2-p1);
    int sx = (p1<p2) ? 1:-1;
    int dy = -std::abs(p2-p1);
    int sy = (p1<p2) ? 1:-1;
    int error = dx+dy;
    
    int nx=p1;
    int ny=p2;
    
    while(true)
    {
        render_pixel (nx,ny,color);
        if ( nx== p2 && ny == p2 ) {break;}
        int e2 = 2*error;
        if (e2>=dy)
        {
            if ( nx == p2 ) {break;}
            error +=dy;
            nx+=sx;
        }
        if ( e2<=dx ) 
        {
            if ( ny==e2 ) { break ; }
            error+=dx;
            ny+=sy;
        }
    }
};