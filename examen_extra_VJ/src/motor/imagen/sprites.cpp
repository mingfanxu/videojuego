#include "sprites.hpp"
#include "../../utilidad/Func_aux.hpp"
#include <iostream>


Sprite::Sprite(std::string file,Coordenadas pos, int w, int h, int sw, int sh)
{
    width = w;
    height = h;
    path = file;
    //SDL_Rect A. --- .B 
    //         c.     .d
    sprite_select ={0,0,width,height};
    sprite_frame = {pos.x,pos.y,width,height};
    sprite_size={sw,sh};
    estado_animacion = nullptr;
};

Sprite::Sprite(std::string xml, Coordenadas pos,int sw, int sh)
{
    spritexml = xml;
    //modificar width y height en los datos del XML
    sprite_size ={sw,sh};
    sprite_frame = {pos.x,pos.y,0,0};
    sprite_select = {0,0,0,0};
    estado_animacion = nullptr;
    LoadDataXML();
};

Sprite::~Sprite()
{
    SDL_DestroyTexture(hoja);
    //delete cuando sea del tipo FSMAnimacionIdle
    //delete estado_animacion;
};

void Sprite::LoadDataXML()
{
    std::cout<<"Creando Sprite \n";
    pugi::xml_parse_result datainfo = info.load_file(spritexml.c_str());

    if(!datainfo)
    {
        std::cout<<"No se pudo cargar el XML: "<<spritexml<<std::endl<<datainfo.description()<<std::endl;
        
        exit(EXIT_FAILURE);
    }
    path = info.child("SpriteAtlas").attribute("imagePath").as_string();
    std::cout<<"sprites en -> "<<path<<"\n";
    width = info.child("SpriteAtlas").child("Info").attribute("width").as_int();
    height = info.child("SpriteAtlas").child("Info").attribute("height").as_int();
    std::cout<<"width: "<<width <<"height: "<<height <<"\n";
    sprite_frame.w=width;
    sprite_frame.h=height;
    sprite_select.w=width;
    sprite_select.h=height;

    std::cout<<"Frame: ("<<sprite_frame.x <<","<<sprite_frame.y<<") dim ("<<sprite_frame.w<<","<<sprite_frame.h<<")\n";
    std::cout<<"Select: ("<<sprite_select.x <<","<<sprite_select.y<<") dim ("<<sprite_select.w<<","<<sprite_select.h<<")\n";

};

bool Sprite::cargar_textura(SDL_Renderer* r)
{
    hoja = IMG_LoadTexture(r,path.c_str());
    if(!hoja)
    {
        std::cout<<SDL_GetError()<<"\n";
        return false;
    }
    return true;
};

void Sprite::set_sprite_position(Coordenadas p)
{
    
    sprite_frame.x = p.x;//-(sprite_size.x/2);
    sprite_frame.y = p.y;//-(sprite_size.y/2);
}

Coordenadas Sprite::get_sprite_position()
{
    return {sprite_frame.x,sprite_frame.y};
};

void Sprite::play_frame(int row, int frame)
{
    sprite_select.x = row+(width*frame);
    sprite_select.y = row*height; //(0,0) -> (500,500) etc..
    sprite_select.w = width;
    sprite_select.h = height;
};

void Sprite::play_frame(std::string nombre,int frame)
{
    //buscar nodo de la animación
    pugi::xml_node animacion = info.child("SpriteAtlas").child(nombre.c_str());
    if(!animacion)
        return;
    
    //buscar el frame a mostrar
    std::string nombre_frame = nombre+"_"+std::to_string(frame);
    pugi::xml_node frame_ani = animacion.find_child_by_attribute("name",nombre_frame.c_str());
    if(!frame_ani) 
    {
        std::cout<<"NO EXISTE ESE FRAME ->"<<nombre_frame;
        return;
    }

    //frame a mostrar
    sprite_select.x = frame_ani.attribute("x").as_int();
    sprite_select.y = frame_ani.attribute("y").as_int();
    sprite_select.w = frame_ani.attribute("width").as_int();
    sprite_select.h = frame_ani.attribute("height").as_int();

};

void Sprite::set_estado_animacion(void *estado)
{
    /*
    estado_animacion->salir(*this);
    delete estado_animacion;
    estado_animacion = estado;
    estado_animacion->entrar(*this);
    */
};