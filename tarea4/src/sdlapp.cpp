#include "sdlapp.hpp"
#include "utilidad/Tiempo.hpp"
#include "motor/KeyOyente.hpp"
#include "motor/MouseOyente.hpp" //agregar
#include <SDL_ttf.h> //agregar
#include"utilidad/Rendertexto.hpp"

#define RECTANGULOS
//#define TRIANGULOS
//#define CIRCULOS

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
        inicio=fin ; // e l nuevo frame inicia en este tiempo
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

    #ifdef RECTANGULOS
        // creamo dos cuadros
        testfiguras.push_back (new Rectangulo (150,200,50,30,SDL_Color{255,0,0,255}));
        //testfiguras.push_back (new Rectangulo (500,200,100,100,SDL_Color{255, 0,255,255})); 

    #endif

    #ifdef TRIANGULOS
        // creamos un Triangulo
        testfiguras.push_back (new Triangulo ({300,200}, {350,150},{400,200} , SDL_Color {255,0,255,255}));
        testfiguras.push_back (new Triangulo ( {450,100},{450,150},{500,100}, SDL_Color{100,100,130,255}));
        testfiguras[3]->set_rellenocolor ({240,240,240,255});
    #endif

    #ifdef CIRCULOS
        // creamos circulos
        testfiguras.push_back(new Circulo (100,750,250,16,SDL_Color{0,255,0,255})); 
        testfiguras[4]->set_rellenocolor ({100,255,100,255});
    #endif


    // si se cero correcto lo agregamos al Pipeline
    get().ensamble = new Pipeline(*get().render);

    //creamos algunos pixeles
    for(int i=0;i<4;++i)  //i<4 修改前
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

    //posicion del mouse
    int mx = MouseOyente::get().getX();
    int my = MouseOyente::get().getY();
    std::string pm = " mouse("+std::to_string(mx)+","+std::to_string(my)+")";
    RenderTexto::get().render_texto(get().render ,815,630,pm,100,30,SDL_Color{0,0,0,255});

    ensamble->figuras(testfiguras);

    SDL_RenderPresent(get().render); //muestra en pantalla lo anterior
    SDL_SetRenderDrawColor(get().render,255,255,255,SDL_ALPHA_TRANSPARENT); //limpia el background


};
void SDLApp::on_limpiar()
{
    SDL_DestroyRenderer(get().render);
    SDL_FreeSurface (get().vntsurf);
    SDL_DestroyWindow(get().vnt);
    SDL_Quit();
} ;