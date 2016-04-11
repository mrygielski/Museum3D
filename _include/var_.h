
//sta³a PI
#define PI 3.1415926535897932	

//sta³a mapy, tutaj budujemy sobie nasz¹ mapê za pomoc¹ œcian
const int MAPA[8][10] = {{3,1,1,8,1,1,1,9,1,2},
                          {3,0,0,0,0,0,0,0,0,2}, 
                          {7,0,0,0,0,0,0,0,0,10}, 
                          {3,0,0,0,0,0,0,0,0,2}, 
                          {3,4,4,13,4,4,0,0,0,2}, 
                          {6,6,6,6,6,3,0,0,0,11}, 
                          {6,6,6,6,6,12,0,0,0,2}, 
                          {6,6,6,6,6,3,4,4,4,2}};
/*  LEGENDA

1   -  œciana lewa
2   |  œciana przednia
3   |  œciana tylnia
4   -  œciana prawa
-- nie u¿ywane do budowania mapy --
5   pod³oga
6   sufit
-----------------------------------
7   drzwi
8   obraz 1
9   obraz 2
10  obraz 3
11  obraz 4
12  obraz 5
13  obraz 6

*/

int i, j; //zmienne pomocnicze

float ry; // obrót kamery do oko³a 
float transx,transy; //pozycja na mapie X i Z
float Ygrek; // wysokoœæ npm :)
float wart,kat; // k¹t obrotu kamery
float tmpx, tmpy; // zmienne pomocnicze do obliczania wektora przesuniêcia
float szybkosc_chodu; // szybkoœæ poruszania siê

GLuint textures[10]; // tekstury

bool BadajTablice(int xx, int yy, int nr)
//funkcja badaj¹ca co w danym miejscu znajduje siê na mapie, gdy funkcja równa siê podawanemu
//elementowi zwraca TRUE a jak nie FALSE
{
	if (MAPA[xx][yy]==nr) return FALSE; else return TRUE;
}