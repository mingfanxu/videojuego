#include <iostream>
using namespace std;
#include<string>
using namespace std;

struct student
{
    string name;
    int sno;
    int score;
};

int main()
{
    student student[5];
    cout<<"Ingresa nombre alumnos  Matricula  Calificaciones"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"Ingresar "<<i+1<<"student information: ";
        cin>>student[i].name>>student[i].sno>>student[i].score;

    };

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if(student[j].score>student[j+1].score)
            {
                struct student temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            };
        };
    };

    for(int i=0;i<9;i++)
    {
        cout<<"Numero"<<i+1<<"alumno nombre es:"<<student[i].name<<"Numero"<<i+1<<"alumno matricula es:"
        <<student[i].sno<<"Numero"<<i+1<<"alumno calificaciones es:"
        <<student[i].score<<endl;

    };

    int sum=0;
    for(int i=0;i<5;i++)
    {
        sum+=student[i].score;
    };

    int ave=sum/5;
    cout<<"Alumno calificacion por medio es"<<sum<<endl;
}