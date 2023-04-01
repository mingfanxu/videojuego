#include<iostream>
#include<time.h>

using namespace std;

bool Crearand()
{
    int a = rand() %10;

    int b = rand() %10;
    if(a==b){
        return true;
    }
    else{
        return false;
    }
};  //概率10%

void Infect(int **&p, int i, int j)
{
    if(i>0 && i<20 && j>0 && j<20)
    {
        if (p[i-1][j-1]==0 && Crearand()) {p[i-1][j-1]=1;}
        if (p[i-1][j]==0 && Crearand()) {p[i-1][j]=1;}
        if (p[i-1][j+1]==0 && Crearand()) {p[i-1][j+1]=1;}
        if (p[i][j-1]==0 && Crearand()) {p[i][j-1]=1;}
        if (p[i][j]==0 && Crearand()) {p[i][j]=1;}
        if (p[i][j+1]==0 && Crearand()) {p[i][j+1]=1;}
        if (p[i+1][j-1]==0 && Crearand()) {p[i+1][j-1]=1;}
        if (p[i+1][j]==0 && Crearand()) {p[i+1][j]=1;}
        if (p[i+1][j+1]==0 && Crearand()) {p[i+1][j+1]=1;}
    }

    else if (i==0 && j>0 && j<20)
    {
        if (p[i][j-1]==0 && Crearand()) {p[i][j-1]=1;}
        if (p[i][j]==0 && Crearand()) {p[i][j]=1;}
        if (p[i][j+1]==0 && Crearand()) {p[i][j+1]=1;}
        if (p[i+1][j-1]==0 && Crearand()) {p[i+1][j-1]=1;}
        if (p[i+1][j]==0 && Crearand()) {p[i+1][j]=1;}
        if (p[i+1][j+1]==0 && Crearand()) {p[i+1][j+1]=1;}
    }

    else if (i=20 && j>0 && j<20)
    {
        if (p[i-1][j-1]==0 && Crearand()) {p[i-1][j-1]=1;}
        if (p[i-1][j]==0 && Crearand()) {p[i-1][j]=1;}
        if (p[i-1][j+1]==0 && Crearand()) {p[i-1][j+1]=1;}
        if (p[i][j-1]==0 && Crearand()) {p[i][j-1]=1;}
        if (p[i][j]==0 && Crearand()) {p[i][j]=1;}
        if (p[i][j+1]==0 && Crearand()) {p[i][j+1]=1;}
    }

    else if (j==0 && i>0 && i<20)
    {
        int a;
        a=i;
        i=j;
        j=a;
        if (p[i][j-1]==0 && Crearand()) {p[i][j-1]=1;}
        if (p[i][j]==0 && Crearand()) {p[i][j]=1;}
        if (p[i][j+1]==0 && Crearand()) {p[i][j+1]=1;}
        if (p[i+1][j-1]==0 && Crearand()) {p[i+1][j-1]=1;}
        if (p[i+1][j]==0 && Crearand()) {p[i+1][j]=1;}
        if (p[i+1][j+1]==0 && Crearand()) {p[i+1][j+1]=1;}
    }

    else if (j=20 && i>0 && i<20)
    {
        int a;
        a=i;
        i=j;
        j=a;
        if (p[i-1][j-1]==0 && Crearand()) {p[i-1][j-1]=1;}
        if (p[i-1][j]==0 && Crearand()) {p[i-1][j]=1;}
        if (p[i-1][j+1]==0 && Crearand()) {p[i-1][j+1]=1;}
        if (p[i][j-1]==0 && Crearand()) {p[i][j-1]=1;}
        if (p[i][j]==0 && Crearand()) {p[i][j]=1;}
        if (p[i][j+1]==0 && Crearand()) {p[i][j+1]=1;}
    }

    else if (i==0 && j==0)
    {
        if(p[0][1] == 0 && Crearand()) {p[0][1] = 1;}
        if(p[1][0] == 0 && Crearand()) {p[1][0] = 1;}
        if(p[1][1] == 0 && Crearand()) {p[1][1] = 1;}
    }

    else if (i==0 && j==20)
    {
        if(p[0][19] == 0 && Crearand()) {p[0][19] = 1;}
        if(p[1][19] == 0 && Crearand()) {p[1][19] = 1;}
        if(p[1][20] == 0 && Crearand()) {p[1][20] = 1;}
    }

    else if (i==20 && j==0)
    {
        if(p[19][0] == 0 && Crearand()) {p[19][0] = 1;}
        if(p[19][1] == 0 && Crearand()) {p[19][1] = 1;}
        if(p[20][1] == 0 && Crearand()) {p[20][1] = 1;}
    }

    else if (i==20 && j==20)
    {
        if(p[19][19] == 0 && Crearand()) {p[19][19] = 1;}
        if(p[20][19] == 0 && Crearand()) {p[20][19] = 1;}
        if(p[19][20] == 0 && Crearand()) {p[19][20] = 1;}
    }//感染方块

    void Check_first(int**& p){
        for (int i=0; i<21; ++1) {
            for (int j=0; j<21; ++j){
                if (p[i][j]==2) {
                    Infect(p,i,j);
                }
            }
        }
    }//第一次感染

    void Check(int **&p){
        for (int i=0; i<21; ++i) {
            for (int j=0; j<21; ++j){
                if (p[i][j] ==2) {
                    cout << "X"
                    num_infect++;
                }

                else if (p[i][j] == 1){
                    cout << "√"
                    num_infect++;
                    first_infect++;
                }
                else {
                    cout <, " ";
                }
            }
            cout<<endl;
        }
        num = num_infect;
        cout <<"Número total de infecciones actuales:" <<num_infect <<" "<<"paciente nuevo:"<<first_infect << endl;
    } //输出感染人数   Exportar el número de infecciones

    
};

