#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int n=10;

struct rekord
{
    int x;
    string y;
};

rekord stworz_rekord ()
{

    rekord wsk;
    wsk.x=rand()/double(RAND_MAX)*10;
    wsk.x=wsk.x - 5;

    int x =1+10*(rand()/double(RAND_MAX));

    char znak;
    for (int i=0; i<x; i++)
    {
        znak='a'+('z'+1-'a')*(rand()/double(RAND_MAX));
        wsk.y=wsk.y+znak;
    }

    return wsk;
}

rekord* stworz_tablice(int n)
{
    rekord* wsk = new rekord [n];

    for (int i=0; i<n; i++)
    {
    wsk[i]=stworz_rekord();
    }
    return wsk;
}

void print_array (rekord *wsk)
{
     for (int i=0; i<n; i++)
    {
    cout<<wsk[i].x<<"  "<<wsk[i].y<<endl;
    }
}

void modyfikuj (rekord*wsk)
{
    string najdl;
    najdl=wsk[0].y;
    for (int i=0; i<n; i++)
    {
        if( (wsk[i].y).length() > najdl.length())
        {
            najdl=wsk[i].y;
        }
    }
    for (int i=0; i<n; i++)
    {
        if (wsk[i].x>0)
        {
            wsk[i].y=najdl;
        }
    }
}

int main()
{
    srand (time(0));

    rekord* A=stworz_tablice(n);
    rekord* B=stworz_tablice(n);

    cout<<"Tablica A:"<<endl;
    print_array(A);
    cout<<endl<<"Tablica B:"<<endl;
    print_array(B);

    modyfikuj(A);
    modyfikuj(B);

    cout<<endl<<"po zmianie:"<<endl<<"Tablica A:"<<endl;
    print_array(A);
    cout<<endl<<"Tablica B:"<<endl;
    print_array(B);

    delete []A;
    delete []B;
    return 0;
}
