
//Micha³ 'REGi' Rygielski
//http://regi.gamedev.pl
//email: mrygielski@o2.pl


//biblioteki systemowe
#include <windows.h>
#include <math.h>	
#include <gl\gl.h>	


//biblioteki programu
#include "_include\api_.h"	
#include "_include\var_.h"	
#include "_include\bmp_.h"
#include "_include\init_.h"
#include "_include\procedure_.h"



void DrawGLScene(GLvoid)
//procedura rysuj¹ca scene
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();


	glRotatef(-ry,0,1,0);
	glTranslatef(transy,Ygrek,transx);

	glPushMatrix();	
  

		glPushMatrix();	 

		//rysowanie mapy
		for (i=0; i<8; i++)
		for (j=0; j<10; j++) 
		{
			Sciana((float)j*3,0,(float)i*3,MAPA[i][j]); // œciany
			Sciana((float)j*3,4,(float)i*3,6); // sufit
			Sciana((float)j*3,0,(float)i*3,5); // pod³oga

		}

		glPopMatrix();

	
	glPopMatrix();
}


int WINAPI WinMain(	HINSTANCE	hInstance,
					HINSTANCE	hPrevInstance,
					LPSTR		lpCmdLine,
					int			nCmdShow)
{
	MSG		msg;
	BOOL	done=FALSE;
	
	//ustawianie okna
	if (CreateGLWindow("MUZEUM 3D",640,480,16,fullscreen)==FALSE) return 0;

	//wczytywanie tekstur
	INITtextures();

	//istawianie oœwietlenia
	INITlights();

	//zerowanie zmiennych
	INITvariables();

	while(!done)
	{if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)){if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}else
	
	{
		DrawGLScene(); //rysowanie sceny
		SwapBuffers(hDC);
		
		ENGINE(); //obs³uga klawiszy i kolizji

		if (keys[VK_ESCAPE])
		{
			done=TRUE;
		}
	
	}}
	

	KillGLWindow();
	return (msg.wParam);
}