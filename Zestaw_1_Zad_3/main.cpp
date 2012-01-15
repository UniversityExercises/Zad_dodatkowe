#include <iostream>
#include <fstream>

using namespace std;

 void tworzenie_pliku (string nazwa)
  {
      string linia;
      ofstream plik;
      plik.open(nazwa.c_str());
      do
      {
          cin>>linia;
          plik<<linia<<endl;;
      }
      while (  (linia[0]>='a'&&linia[0]<='z') || (linia[0]>='A'&&linia[0]<='Z')  );

      plik.close();
  }

  void przepisz (string dane, string nazwa, char warunek, int dlugosc)
  {
      ifstream plik_we;
      plik_we.open (dane.c_str());

      ofstream plik_wy;
      plik_wy.open(nazwa.c_str());


      string line;
      char znak;
      bool jest = false;


      while (!plik_we.eof())
      {
          getline (plik_we, line);
          if(line.length() <= dlugosc)
          {
              continue;
          }

          for (int i=0; i<line.length(); i++)
          {
              znak=line[i];
              if (znak==warunek)
              {
                  jest = true;
              }
          }

          if (jest==false)
          {
              plik_wy<<line<<endl;
          }
          jest=false;
      }

      plik_we.close();
      plik_wy.close();

  }

  void drukuj (string nazwa)
  {
      string linia;

      ifstream plik;
      plik.open (nazwa.c_str());
      if (!plik.good())
      {
          cout<<"blad otwarcia pliku"<<endl;
      }
      else
      {
          while (!plik.eof())
          {
              getline (plik, linia);
              cout<<linia<<endl;
          }
      }
      plik.close();
  }

int main()
{
    cout<<"stworz plik:"<<endl;
    tworzenie_pliku("dane.txt");
    ofstream a;
    a.open("a.txt");
    ofstream b;
    b.open("b.txt");

    przepisz("dane.txt","a.txt",'a',5);
     przepisz("dane.txt","b.txt",'b',7);

    cout<<"zawartosc dane.txt"<<endl;
     drukuj("dane.txt");
     cout<<"zawartosc a.txt"<<endl;
     drukuj("a.txt");
     cout<<"zawartosc b.txt"<<endl;
     drukuj("b.txt");

    return 0;
}
