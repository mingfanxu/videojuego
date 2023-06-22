#include "sdlapp.hpp"
#include "utilidad/Tiempo.hpp"
#include "utilidad/Estructuras.hpp"
#include "utilidad/Func_aux.hpp"
#include "motor/KeyOyente.hpp"
#include "motor/MouseOyente.hpp"
#include <SDL_ttf.h>
#include "utilidad/RenderTexto.hpp"
#include "motor/fisica/MotorFisico.hpp"
#include "motor/Plotter.hpp"
#include "utilidad/FSMS/FSMJugador.hpp"
#include "motor/HUD.hpp"
#include <math.h>

#include <iostream>

//#define RECTANGULOS
//#define TRIANGULOS
//#define CIRCULOS
//#define GRAVEDAD

SDLApp* SDLApp::instancia = 0;

SDLApp::SDLApp()
{
    vnt = nullptr;
    vntsurf = nullptr;
    render = nullptr;
    ensamble= nullptr;
    bg_color.r = 255; //rojo
    bg_color.g = 255; //verde
    bg_color.b = 255; //azul
    bg_color.a = 255; //alpha

    esta_corriendo = true;
    WIDTH=1024;
    HEIGHT=720;
    maxFPS=60;
    fps=0;

    
};

//Como solo queremos una instancia del esta clase, entonces se hace una clase singleton
SDLApp& SDLApp::get()
{
    if(!instancia)
        instancia = new SDLApp();
    return *instancia;
};

bool SDLApp::on_init()
{
    //revisar que SDL inicio bien
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){return false;};
    //crear la ventana
    get().vnt = SDL_CreateWindow(
        "Juego",                // Titulo de la ventana
        SDL_WINDOWPOS_UNDEFINED,// posicion X de la pantalla
        SDL_WINDOWPOS_UNDEFINED,// posicion Y de la pantalla
        get().WIDTH,            // ancho de la ventana
        get().HEIGHT,           // alto de la ventana
        SDL_WINDOW_OPENGL);     // que use OPENGL
    
    TTF_Init();
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    //revisar que se creo bien la ventana
    if(get().vnt == NULL)
    {
        printf("No se creo la ventana por: %s",SDL_GetError());
        return false;
    }
    //la forma de procesar en GPU
    SDL_SetHint(SDL_HINT_RENDER_BATCHING,"opengl");
    //creamos el 'canvas'
    get().render = SDL_CreateRenderer(
        get().vnt,                  // la ventana
        -1,                         // driver
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);  // flags driver
    //revisamos si se creo correctamente
    if(get().render == NULL)
    {
        printf("No se creo el renderer por: %s",SDL_GetError());
        return false; 
    }

    Plotter::get().set_renderer(*get().render);
    // si se creo correcto lo agregamos al Pipeline
    get().ensamble = new Pipeline(*get().render);

    //06_Camaras

    get().camara_principal = new Camara(0,0,get().WIDTH,get().HEIGHT,*get().render);
    
    ManejadorCamaras::get().set_camara(*get().camara_principal);

    HUD::get().set_pipeline(*get().ensamble);
    
    //08 tiles
    mapa = new Atlas("assets/sprites/mundo/ids/extramundo.txt");
    mapa->generar_mapa(get().render,2,0);
    //05
    player = new Jugador("assets/spritesheets/spritesheet_players.xml",
                //      hp , x , y, vW,vH ,color
                        100,900,1760,64,128,{255,0,255,255});
    get().ensamble->cargar_texturas(player->get_sprite());
    player->set_velocidad(5);
    player->get_colbox()->set_rellenocolor({0,0,255,255});
    player->render_colbox = false;
    printf("Se creo el player\n");

    plataformas = mapa->get_objetos_fisicos();



    artest = new Artefactos("assets/sprites/planets/planet07.png",
    300,300,1280,1280,50,50,{255,180,180,255});
    get().ensamble->cargar_texturas(artest->get_sprite());
    artest->set_target(*player);



    //lock camara
    ManejadorCamaras::get().lock_objeto(*player);
    ManejadorCamaras::get().set_estado(new EstadoCamaraTransicion());

    //09 parallax
    background = new BackGroundDinamico("assets/sprites/mundo/bg/bg1.png",2048,1024);
    background->set_velocidad(3);
    get().ensamble->cargar_texturas(background->get_sprite());

    objetos.push_back(background);
    

    for(int i=0;i<(int)plataformas.size();i++)
    {
        //agregar todos los objetos en una lista para la camara
        plataformas[i]->set_velocidad(5);
        objetos.push_back(plataformas[i]);
    }


    //player->set_objetos_mundo(objetos);
    objetos.push_back(artest);
    objetos.push_back(player);
    
    //敌人 enemigo
    enemigo= new Enemigo("assets/spritesheets/spritesheet_zombie.xml",100,500,500,80,110,{0,0,0,255});
    get().ensamble->cargar_texturas(enemigo->get_sprite());
    
    objetos.push_back(enemigo);

    pastotest = new Arbusto("assets/spritesheets/spritesheet_entorno.xml",{900,900},1,19,2,2);
    get().ensamble->cargar_texturas(pastotest->get_sprite());

    objetos.push_back(pastotest);
    
    torres = new Torres*[4];
    Coordenadas pos_torr[] = {{128,95},{128,1664},{1664,1664},{1664,95}} ;
    for(int i=0;i<4;i++)
    {
        torres[i] = new Torres("assets/spritesheets/spritesheet_entorno.xml",pos_torr[i],19,25,2,2);
        get().ensamble->cargar_texturas(torres[i]->get_sprite());
        objetos.push_back(torres[i]);
    } 


    printf("\nSe crearon los objetos exitosamente\n");

    //agregamos el color del background del frame
    SDL_SetRenderDrawColor(
        get().render,       // canvas
        get().bg_color.r,   // rojo
        get().bg_color.g,   // verde
        get().bg_color.b,   // azul
        SDL_ALPHA_TRANSPARENT);// como usar el alpha

    return true;
};

void SDLApp::on_evento(SDL_Event* evento)
{
    if(evento->type==SDL_QUIT)
    {
        get().esta_corriendo = false;
    }
    //eventos del mouse
    MouseOyente::get().evento_movimiento(evento);
    MouseOyente::get().evento_presionado(evento);
    MouseOyente::get().evento_scroll(evento);
    // que esta presionado
    KeyOyente::get().keyPresionado(evento);
    
};

void SDLApp::on_fisicaupdate(double dt)
{
    
    //Camara Lock UnLock
    
    if(KeyOyente::get().estaPresionado(SDL_SCANCODE_1))
    {
        enemigo->set_estado(new FSMEnemigo_MoverDerecha());
        enemigo->setClockwise(1);
    }
    else if(KeyOyente::get().estaPresionado(SDL_SCANCODE_2))
    {
        //enemigo->set_estado(new FSMEnemigo_IDLE());
        //player->set_hp(player->get_hp()-10);
        //enemigo->set_hp(enemigo->get_hp()-5);
        enemigo->set_estado(new FSMEnemigo_MoverDerecha());
        enemigo->setClockwise(-1);
    }
    else if(KeyOyente::get().estaPresionado(SDL_SCANCODE_3))
    {
        //enemigo->set_estado(new FSMEnemigo_MoverIzquierda());
    }

    if(KeyOyente::get().estaPresionado(SDL_SCANCODE_F))
    {
        player->get_col_ataque()->set_strokecolor({0,255,0,255});
    }
    else
    {
        player->get_col_ataque()->set_strokecolor({255,0,255,50});
    }


    player->input_handle(KeyOyente::get(),MouseOyente::get());
    
    for(auto &p:objetos)
    {          
        p->update(dt);        

        /*if(p!= player && p->get_colbox() && p!=artest && p!=enemigo && p != pastotest)
        {
            MotorFisico2D::get().diag_overlap(*player,*p);
            bool pc = MotorFisico2D::get().aabb_colision(*player->get_colbox(),*p->get_colbox());
            player->en_colision|=pc;
        }*/
        if (p == enemigo)
        {
            //MotorFisico2D::get().diag_overlap(*player, *p);
            bool pc = MotorFisico2D::get().aabb_colision(*player->get_colbox(), *p->get_colbox());
            if (pc)
            {
                player->set_hp(player->get_hp() - 0.1);
            }
        }
        if (p == artest)
        {
            //MotorFisico2D::get().diag_overlap(*enemigo, *p);
            bool pc = MotorFisico2D::get().aabb_colision(*enemigo->get_colbox(), *p->get_colbox());
            if (pc)
            {
                enemigo->set_hp(player->get_hp() - 0.1);
            }
        }
    }

    #ifdef GRAVEDAD
    //MotorFisico2D::get().gravedad({get().player});
    #endif
    /*CAMARA al final para actualizar la proyeción de los objetos*/
    ManejadorCamaras::get().input_handle(KeyOyente::get(),MouseOyente::get());
    ManejadorCamaras::get().update(objetos);

    //Manejador de clases que borre los objetos del arreglo de objetos
    //por mientras revisamos una variable
    for(int i=0;i<(int)objetos.size();i++)
    {
        if(objetos[i]->se_borra)
        {
            delete objetos[i];
            objetos.erase(std::next(objetos.begin()+i-1));
        }
    }
    
};

void SDLApp::on_frameupdate(double dt)
{
    // limpiar frame
    SDL_RenderClear(get().render);

    //Renderizar todo a través de la camara
    ManejadorCamaras::get().renderizar(objetos);
    //camara_principal->render_cross();
    
    /*
        Pintar Guías como los cuadros de daño o lineas extras
        伤害，例如损坏或额外的线条
    */
    if(player->get_col_dano())
    {
        get().ensamble->figuras(player->get_col_dano());
    }
    if(player->get_col_ataque())
    {
        get().ensamble->figuras(player->get_col_ataque());
    }

    get().ensamble->lineas({player->get_centro(),player->get_guia()},{0,0,0,255});

    /*
        HUD  X、血条
    */

    HUD::get().show_vida(player,player->get_posicion_camara(),{0,255,0,255});
    HUD::get().show_vida(enemigo,enemigo->get_posicion_camara(),{100,20,100,255});
    
    Coordenadas pm = player->get_posicion_mundo();
    Coordenadas pc = player->get_posicion_camara();
    
    std::string spm = "mundo ( "+std::to_string(pm.x)+", "+std::to_string(pm.y)+")";

    RenderTexto::get().render_texto(
        get().render,100,100,
        spm,
        150,50,{0,0,0,255}
    );

    std::string spc = "camara ( "+std::to_string(pc.x)+", "+std::to_string(pc.y)+")";

    RenderTexto::get().render_texto(
        get().render,800,100,
        spc,
        150,50,{0,0,0,255}
    );



    //Actualizar
    SDL_RenderPresent(get().render);

    //resetear color del frame
    SDL_SetRenderDrawColor(
        get().render,
        get().bg_color.r,
        get().bg_color.g,
        get().bg_color.b,
        SDL_ALPHA_OPAQUE);
};

void SDLApp::on_limpiar()
{
    SDL_DestroyRenderer(get().render);
    SDL_FreeSurface(get().vntsurf);
    SDL_DestroyWindow(get().vnt);

    for(std::vector<Objeto*>::iterator it = objetos.begin();it!=objetos.end();it++)
    {
        Objeto *p=*it;
        delete p;
    }

    delete torres;
    //objetos.clear();
    delete ensamble;
    //delete player;
    //delete enemigo;
    
    SDL_Quit();
};

int SDLApp::on_correr()
{
    //revisar que todo se inicializo bien
    if(get().on_init()==false){return -1;}

    SDL_Event eventos;
    double dt=0;
    double frecuencia = 1/get().maxFPS; // 1 frame a 60fps
    get().msfrecuencia = frecuencia*1000;

    while(get().estaCorriendo())
    {
        //double start = SDL_GetTicks();
        double inicio = Tiempo::get_tiempo();

        //printf("%lf <> %d\n",Tiempo::get_tiempo(),SDL_GetTicks());
        //captura eventos
        while(SDL_PollEvent(&eventos))
        {
            get().on_evento(&eventos);
        }

        //actualizamos si inicia o hay una diferencia de tiempo
        
        get().on_fisicaupdate(dt);
        get().on_frameupdate(dt);

        //calculamos el tiempo del frame
        dt = (Tiempo::get_tiempo() - inicio)/(frecuencia*1000);
        
        inicio=dt; //el nuevo frame inicia en este tiempo
        //printf("<%d>[%lf][%d]\n",get().fps,dt,(int)Tiempo::get_tiempo());
        if(dt>get().msfrecuencia)
        {
            SDL_Delay(std::floor(get().msfrecuencia-dt));
        }
        //get().fps++;
    }
    //liberamos memoria
    get().on_limpiar();
    return 0;
};



