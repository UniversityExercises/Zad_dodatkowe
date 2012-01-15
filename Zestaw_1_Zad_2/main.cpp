#include <iostream>

using namespace std;

struct Tcos
{
    int liczba;
    char znak;
    Tcos *next;
};

void funkcja (Tcos *wsk)
{
    if (wsk!=NULL)
    {
        int suma_p=0;
        int suma_o=0;

        do
        {
            if (wsk->znak>='0' && wsk->znak<='9')
            {
                suma_p=suma_p + wsk->liczba;
            }
            else
            {
                suma_o=suma_o + wsk->liczba;
            }

            wsk=wsk->next;

            if(wsk->next==NULL)
            {
                wsk->next = new Tcos;
                wsk = wsk->next;
                wsk->liczba = suma_p;
                wsk->znak = 'p';

                wsk->next = new Tcos;
                wsk = wsk->next;
                wsk->liczba = suma_o;
                wsk->znak = 'o';
                wsk->next = NULL;
            }

        }
        while (wsk->next != NULL);
    }
}

int main()
{

    return 0;
}
