#include "sdlapp.hpp"
#include "utilidad/Tiempo.hpp"
#include "motor/KeyOyente.hpp"
#include "motor/MouseOyente.hpp" //agregar
#include <SDL_ttf.h> //agregar

SDLApp* SDLApp::instancia=0;

SDLApp::SDLApp ( )
{
    vnt = nullptr ;
    vntsurf = nullptr ;
    render = nullptr ;
    ensamble = nullptr;

    bg_color.r = 255; // rojo
    bg_color.g = 255; // verde
    bg_color.b = 255; // azul
    bg_color.a = 255; // alpha
    esta_corriendo = true ; 
    WIDTH=1024;
    HEIGHT=720;
};

void SDLApp::on_evento(SDL_Event* evento )
{
    if (evento->type==SDL_QUIT)
    {
        get().esta_corriendo = false;
    }
    MouseOyente::get().evento_movimiento (evento);
    MouseOyente::get().evento_presionado (evento);
    MouseOyente::get().evento_scroll(evento);
        // que esta presionado
    KeyOyente::get().keyPresionado (evento);
} ;

void SDLApp:: on_fisicaupdate(double dt )
{
    //printf("Esta presionadoW: %d\n",
    //KeyOyente::get().estaPresionado(SDLK_w));
};


SDLApp& SDLApp::get()
{
 static SDLApp instancia ;
return instancia ;
};

int SDLApp::on_correr()
{
    // tiempo
    double inicio = Tiempo::get_tiempo() ;
    // revisar que todo se inicializo bien
    if(get().on_init()== false){return -1;}

    SDL_Event eventos;
    double dt =0; 
    while(get().estaCorriendo())
    {
        //captura eventos 
        while (SDL_PollEvent(&eventos))
        {
            get().on_evento(&eventos) ;
        }
        // actualizamos si inicia o hay una diferencia de tiempo
        if ( dt >=0)
        {
            get().on_fisicaupdate (dt) ;
            get().on_frameupdate(dt) ;
        }
        //calcula mosel tiempo de lframe
        double fin = Tiempo::get_tiempo();
        dt = fin-inicio; // diferencia
        inicio=fin ; // e l nuevo f rame i n i c i a en e s t e tiem p o
    }
    // liberamos memoria
    get().on_limpiar() ;
    return 0;
};

bool SDLApp::on_init()
{
    //revisar que SDL inicio bien
    if (SDL_Init (SDL_INIT_EVERYTHING)<0){return false;} ;
    TTF_Init();

    // crear la ventana
    get().vnt = SDL_CreateWindow(
    "Juego " , // Titulo 
    SDL_WINDOWPOS_UNDEFINED, //posicion X
    SDL_WINDOWPOS_UNDEFINED, //posicion Y
    get().WIDTH, // ancho
    get().HEIGHT , //alto 
    SDL_WINDOW_OPENGL ); // que use OPENGL

    // revisar que se creo bien la ventana
    if( get ().vnt == NULL)
    { 
        printf ( "No se creo la ventana por : %s " , SDL_GetError ( ) ) ;
        return false;
    }

    // la forma de procesar en GPU
    SDL_SetHint (SDL_HINT_RENDER_BATCHING, " opengl") ;

    // creamos el 'canvas ’
    get(). render = SDL_CreateRenderer
    (
        get().vnt , // la ventana 
        -1, // driver 
        SDL_RENDERER_ACCELERATED 
    ) ;

    // revisamos si se creo correctamente
    if (get().render == NULL)
    { 
        printf ( "No se creo el renderer por:%s" , SDL_GetError());
        return false;
    }

    // si se cero correcto lo agregamos al Pipeline
    get().ensamble = new Pipeline(*get().render);

    //creamos algunos pixeles
    for(int i=0;i<300;++i)  //i<4 修改前
        testpixeles.push_back({100,100+i});

    // agregamos el color del background del frame 
    SDL_SetRenderDrawColor(
    get().render , // ca n va s
    get().bg_color.r , // r o j o
    get().bg_color.g , // v e r d e
    get().bg_color.b , // a z u l 
    SDL_ALPHA_TRANSPARENT ) ; // como u s a r e l a l p h a

    return true ;
};


void SDLApp::on_frameupdate ( double dt )
{
    // limpiar frame
    SDL_RenderClear(get().render);
    int mx = MouseOyente::get().getX();
    int my = MouseOyente::get().getY();

    std::string pm = " mouse("+std::to_string(mx)+","+std::to_string(my)+")";
    renderTexto(get().render,815,630,pm,20,SDL_Color{0,0,0,255},"onuava");
    //mensaje X
    renderTexto(
        get().render,
        (get().WIDTH/2)-100 ,
        (get().HEIGHT/2) ,
        "SI FUNCIONA",
        50,
        SDL_Color{0,0,255,255});

    //fps
    renderTexto(
        get().render,
        get().WIDTH-100,
        30,
        std::to_string ((int)(1/dt))+"fps",
        18,
        SDL_Color {0,135,62,255},
        "onuava"
    );

        // Mostrar frame
        //SDL_RenderPresent (get().render) ;

    //probar plotter
    ensamble->puntos(testpixeles, SDL_Color{255,100,255,255});
    ensamble->lineas(testpixeles, SDL_Color{255,100,0,255});
    ensamble->figuras(testfiguras);
    //Actualizar
    SDL_RenderPresent(get().render);

    // resetear color del frame
    SDL_SetRenderDrawColor(
        get().render ,
        get().bg_color.r ,
        get().bg_color.g ,
        get().bg_color.b,
        SDL_ALPHA_TRANSPARENT 
    ) ;
} ;

void SDLApp::renderTexto(SDL_Renderer *ren ,int x ,int y,std::string texto,
int fontsize , SDL_Color color, std::string font)
{
// Agregar el font
std::string ff = "assets//fonts//"+font+".ttf"; 
TTF_Font* fontTipo= TTF_OpenFont(ff.c_str(),fontsize);

//revisamos que silocalizamos el font
if (fontTipo == NULL)
{
    printf ( "No se en contro el FONT: %s \n ",TTF_GetError());
    exit (EXIT_FAILURE);
}

//creamos una superficie donde pintar 
SDL_Surface* surftexto = TTF_RenderText_Solid(
    fontTipo,
    texto.c_str(),
    color);

// La convertimos en textura 
SDL_Texture *textexto = SDL_CreateTextureFromSurface (
    ren,
    surftexto);

//lo pintamos en un cuadro que se mostrara en el canvas SDL_Rect rectexto;
SDL_Rect rectexto;
rectexto.x=x;
rectexto.y=y;
rectexto.w = surftexto ->w;
rectexto.h = surftexto->h;
//mandarlo a mostrar al canvas 
SDL_RenderCopy(
    ren,
    textexto, 
    NULL, 
    &rectexto);
    //Liberamos la memoria 
    TTF_CloseFont (fontTipo); 
    SDL_DestroyTexture (textexto); 
    SDL_FreeSurface(surftexto);
} ;

void SDLApp::on_limpiar()
{
    SDL_DestroyRenderer(get().render);
    SDL_FreeSurface (get().vntsurf);
    SDL_DestroyWindow(get().vnt);
    SDL_Quit ( ) ;
} ;