#include "FSMCamaras.hpp"
#include "../Func_aux.hpp"
#include <iostream>

EstadoCamaraMover::EstadoCamaraMover(Coordenadas dir)
{
    direccion = dir;
    strestado = "mover";
};

FSMCamara* EstadoCamaraMover::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();


    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }
    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_S))
    {
        return new EstadoCamaraMoverAbajo();
    }

    
    return NULL;
};

void EstadoCamaraMover::on_entrar(Camara &cam)
{
    //Alumnos implementa
    vel =0;// cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void EstadoCamaraMover::on_salir(Camara &cam){};
void EstadoCamaraMover::on_update(Camara &cam){};

/*DER*/
EstadoCamaraMoverDer::EstadoCamaraMoverDer()
{
    strestado = "mover";
};

FSMCamara* EstadoCamaraMoverDer::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }

    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_S))
    {
        return new EstadoCamaraMoverAbajo();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void EstadoCamaraMoverDer::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
};
void EstadoCamaraMoverDer::on_salir(Camara &cam){};
void EstadoCamaraMoverDer::on_update(Camara &cam)
{
    obj->MoverDerecha(1);
};

/*IZQ*/

EstadoCamaraMoverIzq::EstadoCamaraMoverIzq()
{
    strestado = "mover";
};

FSMCamara* EstadoCamaraMoverIzq::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_S))
    {
        return new EstadoCamaraMoverAbajo();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void EstadoCamaraMoverIzq::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void EstadoCamaraMoverIzq::on_salir(Camara &cam){};
void EstadoCamaraMoverIzq::on_update(Camara &cam)
{
    
    obj->MoverIzquierda(1);
};


/*
Arriba
*/
EstadoCamaraArriba::EstadoCamaraArriba()
{
    strestado = "mover";
};

FSMCamara* EstadoCamaraArriba::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }
    if(keys.estaPresionado(SDL_SCANCODE_S))
    {
        return new EstadoCamaraMoverAbajo();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void EstadoCamaraArriba::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void EstadoCamaraArriba::on_salir(Camara &cam){};
void EstadoCamaraArriba::on_update(Camara &cam)
{
    
    obj->MoverArriba(1);
};

/*
ABAJO
*/

EstadoCamaraMoverAbajo::EstadoCamaraMoverAbajo()
{
    strestado = "mover";
};

FSMCamara* EstadoCamaraMoverAbajo::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void EstadoCamaraMoverAbajo::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void EstadoCamaraMoverAbajo::on_salir(Camara &cam){};
void EstadoCamaraMoverAbajo::on_update(Camara &cam)
{
    
    obj->MoverAbajo(1);
};

/*
    Arriba Derecha
*/
CamAD::CamAD()
{
    strestado = "mover";
};

FSMCamara* CamAD::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void CamAD::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void CamAD::on_salir(Camara &cam){};
void CamAD::on_update(Camara &cam)
{
    
    obj->MoverArribaDerecha(1);
};

/*
    Arriba Izquierda
*/

CamAI::CamAI()
{
    strestado = "mover";
};

FSMCamara* CamAI::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void CamAI::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void CamAI::on_salir(Camara &cam){};
void CamAI::on_update(Camara &cam)
{
    
    obj->MoverArribaIzquierda(1);
};

/*
    Abajo Derecha
*/

CamABD::CamABD()
{
    strestado = "mover";
};

FSMCamara* CamABD::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void CamABD::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void CamABD::on_salir(Camara &cam){};
void CamABD::on_update(Camara &cam)
{
    
    obj->MoverAbajoDerecha(1);
};

/*
    Abajo Izquierda
*/

CamABI::CamABI()
{
    strestado = "mover";
};

FSMCamara* CamABI::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamAD();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_D))
        return new CamABD();
    if(keys.estaPresionado(SDL_SCANCODE_W) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamAI();
    if(keys.estaPresionado(SDL_SCANCODE_S) && keys.estaPresionado(SDL_SCANCODE_A))
        return new CamABI();

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        return new EstadoCamaraMoverDer();
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        return new EstadoCamaraArriba();
    }
    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        return new EstadoCamaraMoverIzq();
    }

    if(!(keys.estaPresionado(SDL_SCANCODE_A)) && !(keys.estaPresionado(SDL_SCANCODE_D)) 
    && !(keys.estaPresionado(SDL_SCANCODE_W)) && !(keys.estaPresionado(SDL_SCANCODE_S)))
    {
        return new EstadoCamaraMover({0,0});
    }
    
    return NULL;
};

void CamABI::on_entrar(Camara &cam)
{
    vel = cam.velocidad;
    obj = dynamic_cast<Jugador*>(cam.get_obj_lock());
    
};
void CamABI::on_salir(Camara &cam){};
void CamABI::on_update(Camara &cam)
{
    
    obj->MoverAbajoIzquierda(1);
};

/*
TRANSICIÓN
*/
EstadoCamaraTransicion::EstadoCamaraTransicion()
{
    frames_actual =0;
    frames_maximo = 20;
    strestado = "transicion";
};

FSMCamara* EstadoCamaraTransicion::input_handle(Camara &cam, Jugador &obj, KeyOyente &keys, MouseOyente& mouse)
{
    if(frames_actual>frames_maximo)
    {
        /*if(distancia<10)
        {
            return new EstadoCamaraLock(*cam.get_obj_lock());
        }*/
        return new EstadoCamaraMover({0,0});
    }

    if(keys.estaPresionado(SDL_SCANCODE_D))
    {
        obj.MoverDerecha(1);
    }
    if(keys.estaPresionado(SDL_SCANCODE_A))
    {
        obj.MoverIzquierda(1);
    }
    if(keys.estaPresionado(SDL_SCANCODE_W))
    {
        obj.MoverArriba(1);
    }
    if(keys.estaPresionado(SDL_SCANCODE_S))
    {
        obj.MoverAbajo(1);
    }

    return NULL;
};

void EstadoCamaraTransicion::on_entrar(Camara &cam)
{
    //Alumnos implementa
    cam.en_transicion = 1;

    vel = cam.velocidad;
    pos_inicial = cam.get_posicion_mundo();//(0,0) 

    //seguro decir que este estado siempre entra en lock object
    // no es necesario comprobar que lock object no es nulo
    pos_final = cam.get_obj_lock()->get_posicion_mundo(); //o.x,o.y
    
    //convertir en posicion relativo a las coordenads camara
    centro = cam.get_posicion_centro();
    pos_final.x -= centro.x;
    pos_final.y -= centro.y;

    //la diferencia es la cantidad de pixeles que se mueve
    ant_check={0,0};

};
void EstadoCamaraTransicion::on_salir(Camara &cam)
{
    
    cam.en_transicion=0;
};
void EstadoCamaraTransicion::on_update(Camara &cam)
{

    
    if(frames_actual>frames_maximo)
        return;

    float t = frames_actual/(float)frames_maximo;
    check= LERP(pos_inicial,pos_final,t);
    cam.set_posicion_mundo(check);
    frames_actual++;
    //DEBUGCOOR(cam.get_posicion_mundo())
};

