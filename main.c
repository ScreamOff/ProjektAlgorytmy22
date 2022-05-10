#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>




struct timeval begin, end;
//rozmiar tablicy modyfikowany w zaleznosci od ilosci elementow do zbadania
const int rozmiar = 10000;
int i;




/*prosty skrypt do wypelniania tablicy liczbami pseudolosowymi
*/

void wypelnijtablice(int tablica[rozmiar],int rozmiar){
for(i=0; i<rozmiar; i++)
{
tablica[i]=rand()%10;
}
}


/*prosty skrypt do wyswietlania tablicy liczbami pseudolosowymi
*/

void wyswietltablice(int tablica[rozmiar],int rozmiar){
printf("\nTablica po posortowaniu:");
for(i=0; i<rozmiar; i++) printf("\n%i",tablica[i]);
}

/*
skrypt do zaczynania odliczania czasu czasomierzstart wlacza timer czasomierzstop konczy jego prace
*/

int czasomierzstart() {

    
    gettimeofday(&begin, 0);
    return 0;
}



int czasomierzstop(){
    
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    
    
    printf("Time measured: %.3f seconds.\n", elapsed);
    
    return elapsed;
}

/*
funkcje sortujace pobrane ze strony z algorytmami opracowane przez nasz zespol
*/



void b_sort(int tablica[rozmiar], int rozmiar)
{
int temp,i,zmiana;
do
{
zmiana=0;
i=rozmiar-1;
do
{
i--;
if (tablica[i+1]< tablica[i])
{
temp=tablica[i];
tablica[i]=tablica[i+1];
tablica[i+1]=temp;
zmiana=1;
}
}
while (i!=0);
}
while (zmiana!=0);
}

/* sortowanie przez wstawianie elementow */



void insertionsort(int tablica[rozmiar], int rozmiar)
{
int j,v;
for (i=1;i<rozmiar;i++)
{
j=i;
v=tablica[i];
while ((j>0) && (tablica[j-1]>v))
{
tablica[j]=tablica[j-1];
j--;
}
tablica[j]=v;
}
}
/*
sortowanie przez wybor elementow
*/


void selectionsort(int tablica[rozmiar], int rozmiar)
{
int min,j,temp;
for (i=0;i<rozmiar-1;i++)
{
min=i;
for (j=i+1;j<rozmiar;j++)
if (tablica[j]<tablica[min]) min=j;
temp=tablica[min];
tablica[min]=tablica[i];
tablica[i]=temp;
}
}










/*
program wywolujacy funkcje
*/




int main()
{
int i,liczba;
int tablica[rozmiar];
wypelnijtablice(tablica,rozmiar);

czasomierzstart();
printf("Tablica przed posortowaniem:");
for(i=0; i<rozmiar; i++) printf("\n%i",tablica[i]);
selectionsort(tablica,rozmiar);

printf("\n");

czasomierzstop();

/*
jesli nie jestesmy pewni czy tablica jest posortowana mozemy uzyc funkcji ponizej
*/
//wyswietltablice(tablica,rozmiar);
return 0;
}