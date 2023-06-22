#include "Torres.hpp"

Torres::Torres(std::string xml,Coordenadas pos,int col_init,int row_init,int rows, int cols)
:Arbusto{xml,pos,col_init,row_init,rows,cols}
{
    hp=300;
    hp_max=hp;
};