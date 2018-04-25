#include<iostream>
#include<cstdlib>
#include <ctime>
#include <windows.h>
#include <chrono>
#include <fstream>
#include <math.h>
using namespace std;

int *pom;

void sortowanie_introspektywne (int tab[], int N, int M);
void sortowanie_przez_kopcowanie (int tab[], int N);
int partition (int tab[], int lewy, int prawy);
void mediana_3 (int tab[], int &lewy, int &prawy);
void kopcowanie (int tab[], int i, int N);
void sortowanie_przez_wstawianie (int tab[], int N);

void sortowanie_hybrydowe (int tab[], int N)
{
  sortowanie_introspektywne(tab,N,(int)floor(2*log(N)/M_LN2));
  sortowanie_przez_wstawianie(tab,N);
}

void sortowanie_introspektywne (int tab[], int N, int M)
{
  int i;
  if (M<=0)
  {
    sortowanie_przez_kopcowanie(tab,N);
    return;
  }
  i=partition(tab,0,N);
  if (i>9)
    sortowanie_introspektywne(tab,i,M-1);
  if (N-1-i>9)
    sortowanie_introspektywne(tab+i+1,N-1-i,M-1);
}

int partition (int tab[], int lewy, int prawy)
{
  int i, j;
  if (prawy>=3)
    mediana_3(tab,lewy,prawy);
  for (i=lewy, j=prawy-2; ; )
  {
    for ( ; tab[i]<tab[prawy-1]; ++i);
    for ( ; j>=lewy && tab[j]>tab[prawy-1]; --j);
    if (i<j)
      swap(tab[i++],tab[j--]);
    else break;
  }
    swap(tab[i],tab[prawy-1]);
  return i;
}

void mediana_3 (int tab[], int &lewy, int &prawy)
{
  if (tab[++lewy-1]>tab[--prawy])
    swap(tab[lewy-1],tab[prawy]);
  if (tab[lewy-1]>tab[prawy/2])
    swap(tab[lewy-1],tab[prawy/2]);
  if (tab[prawy/2]>tab[prawy])
    swap(tab[prawy/2],tab[prawy]);
  swap(tab[prawy/2],tab[prawy-1]);
}

void sortowanie_przez_kopcowanie (int tab[], int N)
{
  int i;
  for (i=N/2; i>0; --i)
    kopcowanie(tab-1,i,N);
  for (i=N-1; i>0; --i)
  {
    swap(tab[0],tab[i]);
    kopcowanie(tab-1,1,i);
  }
}

void kopcowanie (int tab[], int i, int N)
{
  int j;
  while (i<=N/2)
  {
    j=2*i;
    if (j+1<=N && tab[j+1]>tab[j])
      j=j+1;
    if (tab[i]<tab[j])
      swap(tab[i],tab[j]);
    else break;
    i=j;
  }
}

void sortowanie_przez_wstawianie (int tab[], int N)
{
  int i, j;
  int temp;
  for (i=1; i<N; ++i)
  {
    temp=tab[i];
    for (j=i; j>0 && temp<tab[j-1]; --j)
      tab[j]=tab[j-1];
    tab[j]=temp;
  }
}
void scal(int tab[], int lewy, int srodek, int prawy)
{
    int i = lewy, j = srodek + 1;

  //kopiujemy lewą i prawą część tablicy do tablicy pomocniczej
  for(int i = lewy;i<=prawy; i++)
    pom[i] = tab[i];

  //scalenie dwóch podtablic pomocniczych i zapisanie ich
  //we własciwej tablicy
  for(int k=lewy;k<=prawy;k++)
  if(i<=srodek)
    if(j <= prawy)
         if(pom[j]<pom[i])
             tab[k] = pom[j++];
         else
             tab[k] = pom[i++];
    else
        tab[k] = pom[i++];
  else
      tab[k] = pom[j++];
}

void sortowanie_przez_scalanie(int tab[],int lewy, int prawy)
{
    //gdy jeden element
    if(prawy<=lewy) return;

    //znajdujemy srodek podtablicy
    int srodek = (prawy+lewy)/2;

    //dzielimy tablice
    sortowanie_przez_scalanie(tab, lewy, srodek);
    sortowanie_przez_scalanie(tab, srodek+1, prawy);

    //scalamy posortowane tablice
    scal(tab, lewy, srodek, prawy);
}
void sortowanie_szybkie( int tab[], int lewy, int prawy )
{
    int i = lewy;
    int j = prawy;
    int x = tab[( lewy + prawy ) / 2 ];
    do
    {
        while( tab[ i ] < x )
             i++;

        while( tab[ j ] > x )
             j--;

        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );

            i++;
            j--;
        }
    } while( i <= j );

    if( lewy < j ) sortowanie_szybkie( tab, lewy, j );

    if( prawy > i ) sortowanie_szybkie( tab, i, prawy );

}
int main()
{

    int a = 1;
    srand(time(NULL));
    while(a!=0)
    {
    char w = 'k';
    float k = 0;
    auto suma = 0;
    auto suma1 = 0;
    auto suma2 = 0;
    while (w != 'a' && w != 'b'&& w != 'c'&& w != 'd'&& w != 'e'&& w != 'f'&& w != 'g'&& w != 'h')
    {
        cout << "wybierz poziom wstepnego posortowania tablicy :" << endl;
        cout << "a = 0%" << endl;
        cout << "b = 25%" << endl;
        cout << "c = 50%" << endl;
        cout << "d = 75%" << endl;
        cout << "e = 95%" << endl;
        cout << "f = 99%" << endl;
        cout << "g = 99.7%" << endl;
        cout << "h = posortowane odwrotnie" << endl << ">>";
        cin >> w;
        cout << endl;
        switch(w)
        {
        case 'a':{ k = 0; break; }
        case 'b':{ k = 25; break; }
        case 'c':{ k = 50; break; }
        case 'd':{ k = 75; break; }
        case 'e':{ k = 95; break; }
        case 'f':{ k = 99; break; }
        case 'g':{ k = 99.7; break; }
        case 'h':{ k = -100; break; }
        default :{ k = -1; cout << "jeszcze raz" << endl; break; }
        }
    }
        int *tab;
        int n; //liczba elementów tablicy
        cout << "podaj liczbe elementow tablicy" << endl << ">>";
        cin >>n ;
        cout << "wybierz sposob sortowania" << endl;
        cout << "1 - sortowanie introspektywne" << endl;
        cout << "2 - quicksort" << endl;
        cout << "3 - sortowanie przez scalanie" << endl;
        cout << "4 - wszystkie sortowania" << endl << ">>";
    int p = k*n/100;
    int s;
    cin >> s;
    for(int i = 0;i < 100;i++)
    {
    tab = new int[n]; //przydzielenie pamięci na tablicę liczb
    pom = new int[n]; //przydzielenie pamięci na tablicę pomocniczą
    if(p>=0){
    for (int i = 0; i<p; i++)
    {
        tab[i] = i;
    //cout << tab[i] << " ";
    }
    for(int i=p;i<n;i++)
    {
        tab[i] = (rand() % (n*100)) + p;
    //cout << tab[i] << " ";
    }
    }
    else
    {
        for(int i = -p-1;i>-1;i--)
            tab[i] = -i;
    }
   // for(int i=0;i<n;i++)
        //cout<<tab[i]<<" ";
    switch(s)
    {
    case 1:
    {
        auto start = std::chrono::high_resolution_clock::now();
        sortowanie_hybrydowe(tab,n);
        auto stop = std::chrono::high_resolution_clock::now();
        auto diff = stop - start;
        suma = suma + chrono::duration <double, milli> (diff).count();
         cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
        break;
    }
    case 2:
    {
        auto start = std::chrono::high_resolution_clock::now();
        sortowanie_szybkie(tab,0,n-1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto diff = stop - start;
        suma1 = suma1 + chrono::duration <double, milli> (diff).count();
         cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
        break;
    }
    case 3:
    {
        auto start = std::chrono::high_resolution_clock::now();
        sortowanie_przez_scalanie(tab,0,n-1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto diff = stop - start;
        suma2 = suma2 + chrono::duration <double, milli> (diff).count();
         cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
        break;
    }
    case 4:
    {
        int *tab1 = new int[n];
        int *tab2 = new int[n];
        for (int i = 0; i<n; i++)
        {
            tab1[i] = tab[i];
            tab2[i] = tab[i];
        }
        auto start = std::chrono::high_resolution_clock::now();
        sortowanie_hybrydowe(tab,n);
        auto stop = std::chrono::high_resolution_clock::now();
        auto diff = stop - start;
        suma = suma + chrono::duration <double, milli> (diff).count();

        //cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
        start = std::chrono::high_resolution_clock::now();
        sortowanie_szybkie(tab1,0,n-1);
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        suma1 = suma1 + chrono::duration <double, milli> (diff).count();

       // cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
        start = std::chrono::high_resolution_clock::now();
        sortowanie_przez_scalanie(tab2,0,n-1);
        stop = std::chrono::high_resolution_clock::now();
        diff = stop - start;
        suma2 = suma2 + chrono::duration <double, milli> (diff).count();
       // cout << chrono::duration <double, micro> (diff).count() << " ms" << endl;
        delete tab1;
        delete tab2;
        break;
    }

    default :
    {
        cout << "zly wybor" << endl;
        break;
        }
}
   // wypisanie wyników
   // for(int i=0;i<n;i++)
       // cout<<tab[i]<<" ";
    delete tab;
    delete pom;
   }
        cout << "srednia czasu (sortowanie introspektywne) : " << chrono::duration <double, milli> (suma).count()/100 << " ms" << endl;
                cout << "srednia czasu (sortowanie szybkie) : " << chrono::duration <double, milli> (suma1).count()/100 << " ms" << endl;
                        cout << "srednia czasu (sortowanie przez scalanie) : " << chrono::duration <double, milli> (suma2).count()/100 << " ms" << endl;
        cout << "czy chcesz kontynuować?(0 - nie, 1 - tak)" << endl;
        cin >> a;
    }
        return 0;
}
