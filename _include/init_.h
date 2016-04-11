

int INITtextures()
{
	//wgrywanie tekstur
	textures[0]=LoadTexture("grafika/sciana.bmp");
	textures[1]=LoadTexture("grafika/podloga.bmp");
	textures[2]=LoadTexture("grafika/sufit.bmp");
	textures[3]=LoadTexture("grafika/drzwi.bmp");
	textures[4]=LoadTexture("grafika/obraz1.bmp");
	textures[5]=LoadTexture("grafika/obraz2.bmp");
	textures[6]=LoadTexture("grafika/obraz3.bmp");
	textures[7]=LoadTexture("grafika/obraz4.bmp");
	textures[8]=LoadTexture("grafika/obraz5.bmp");
	textures[9]=LoadTexture("grafika/obraz6.bmp");

	return true;
}

int INITlights()
{
	//tworzenie zmiennych
	float swiatlo_otoczenia[] = { 0.4f, 0.4f, 0.4f, 0.4f};
	float swiatlo_rozproszone[] = { 0.7f, 0.7f, 0.7f, 0.7f};
	float swiatlo_odbite[] = { 1.0f, 0.0f, 0.0f, 1.0f};
	float swiatlo_pozycja[] = { 0.01f,0.01f,0.02f,0.01f};

	
	glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, 1);// przeliczaj kolor obydwu
	glEnable( GL_LIGHTING);// w��cz analiz� o�wietlenia
	glLightfv( GL_LIGHT0, GL_AMBIENT, swiatlo_otoczenia);// �wiat�o oblewaj�ce
	glLightfv( GL_LIGHT0, GL_POSITION, swiatlo_pozycja);// Ustawienie �ar�wki w okre�lonym miejscu 
	glEnable( GL_LIGHT0);	// w��czenie �ar�wki nr 0
	glEnable( GL_COLOR_MATERIAL);// aktywowanie analizy w�a�ciwo�ci materia�u
	glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT);
	glColorMaterial( GL_FRONT_AND_BACK, GL_DIFFUSE);
	glColorMaterial( GL_FRONT, GL_SPECULAR);
	glMateriali( GL_FRONT, GL_SHININESS, 128);
    
	glClearColor( 1.0, 1.0, 1.0, 1.0); //czyszcznie buforu na dany kolor

	return true;
}

int INITvariables()
{
	//kat obrotu kamery
	wart=90;
	kat=90;

	ry=-90;

	transx=-2*3; //po�o�enie X
	transy=-2*3; //po�o�enie Z
	Ygrek=-1.5;  // wysoko��

	szybkosc_chodu=10;

	return true;
}

int ENGINE()
{
	//ob�rt kamery w lewo i prawo
	if (keys[VK_LEFT]) {wart+=1; ry+=1;}
	if (keys[VK_RIGHT]) {wart-=1; ry-=1;}


	kat=wart*((float)PI/180); // obliczanie obrotu wartosc*RADIAN=kat

	//poszuszanie kamer� w ty� wraz z wykrywaniem kolizji wszystkich �cian
	if (keys[VK_DOWN] && BadajTablice(-((int)transx)/3,-((int)transy+1)/3,3) &&
		BadajTablice(-((int)transx)/3,-((int)transy-1)/3,2) &&
		BadajTablice(-((int)transx-2)/3,-((int)transy)/3,1) &&
		BadajTablice(-((int)transx+2)/3,-((int)transy)/3,4) &&
		BadajTablice(-((int)transx)/3,-((int)transy+1)/3,7) &&
		BadajTablice(-((int)transx)/3,-((int)transy+1)/3,12) &&
		BadajTablice(-((int)transx-2)/3,-((int)transy)/3,8) &&
		BadajTablice(-((int)transx-2)/3,-((int)transy)/3,9) &&
		BadajTablice(-((int)transx)/3,-((int)transy-1)/3,10) &&
		BadajTablice(-((int)transx)/3,-((int)transy-1)/3,11) &&
		BadajTablice(-((int)transx+2)/3,-((int)transy)/3,13))
	{	
		tmpx=cosf(kat)/szybkosc_chodu;
		tmpy=sinf(kat)/szybkosc_chodu;
		transx+=tmpx;
		transy+=tmpy;
	}  else
	{
		//odbijanie od �ciany
		tmpx=cosf(kat)/szybkosc_chodu;
		tmpy=sinf(kat)/szybkosc_chodu;
		transx-=tmpx;
		transy-=tmpy;
	}

	//poszuszanie kamer� do przodu wraz z wykrywaniem kolizji wszystkich �cian
	if (keys[VK_UP] && BadajTablice(-((int)transx)/3,-((int)transy+1)/3,3) &&
		BadajTablice(-((int)transx)/3,-((int)transy-1)/3,2) &&
		BadajTablice(-((int)transx-2)/3,-((int)transy)/3,1) &&
		BadajTablice(-((int)transx+2)/3,-((int)transy)/3,4) &&
		BadajTablice(-((int)transx)/3,-((int)transy+1)/3,7) &&
		BadajTablice(-((int)transx)/3,-((int)transy+1)/3,12) &&
		BadajTablice(-((int)transx-2)/3,-((int)transy)/3,8) &&
		BadajTablice(-((int)transx-2)/3,-((int)transy)/3,9) &&
		BadajTablice(-((int)transx)/3,-((int)transy-1)/3,10) &&
		BadajTablice(-((int)transx)/3,-((int)transy-1)/3,11) &&
		BadajTablice(-((int)transx+2)/3,-((int)transy)/3,13)) 

	{	
		tmpx=cosf(kat)/szybkosc_chodu;
		tmpy=sinf(kat)/szybkosc_chodu;
		transx-=tmpx;
		transy-=tmpy;
	} else
	{
		//odbijanie od �ciany
		tmpx=cosf(kat)/szybkosc_chodu;
		tmpy=sinf(kat)/szybkosc_chodu;
		transx+=tmpx;
		transy+=tmpy;
	}

	return true;
}