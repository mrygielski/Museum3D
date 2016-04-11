
//sta�a PI
#define PI 3.1415926535897932	

//sta�a mapy, tutaj budujemy sobie nasz� map� za pomoc� �cian
const int MAPA[8][10] = {{3,1,1,8,1,1,1,9,1,2},
                          {3,0,0,0,0,0,0,0,0,2}, 
                          {7,0,0,0,0,0,0,0,0,10}, 
                          {3,0,0,0,0,0,0,0,0,2}, 
                          {3,4,4,13,4,4,0,0,0,2}, 
                          {6,6,6,6,6,3,0,0,0,11}, 
                          {6,6,6,6,6,12,0,0,0,2}, 
                          {6,6,6,6,6,3,4,4,4,2}};
/*  LEGENDA

1   -  �ciana lewa
2   |  �ciana przednia
3   |  �ciana tylnia
4   -  �ciana prawa
-- nie u�ywane do budowania mapy --
5   pod�oga
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

float ry; // obr�t kamery do oko�a 
float transx,transy; //pozycja na mapie X i Z
float Ygrek; // wysoko�� npm :)
float wart,kat; // k�t obrotu kamery
float tmpx, tmpy; // zmienne pomocnicze do obliczania wektora przesuni�cia
float szybkosc_chodu; // szybko�� poruszania si�

GLuint textures[10]; // tekstury

bool BadajTablice(int xx, int yy, int nr)
//funkcja badaj�ca co w danym miejscu znajduje si� na mapie, gdy funkcja r�wna si� podawanemu
//elementowi zwraca TRUE a jak nie FALSE
{
	if (MAPA[xx][yy]==nr) return FALSE; else return TRUE;
}