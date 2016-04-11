

int Rectangle(float x1, float y1, float z1, float x2, float y2, float z2,
              float x3, float y3, float z3, float x4, float y4, float z4, int texture)
//funkcja rysuje prostok¹t (poly) xyz wype³niony tekstur¹
{
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_TRIANGLE_STRIP);
	    glTexCoord2f(1,0);glVertex3f(x1,y1,z1);
	    glTexCoord2f(1,1);glVertex3f(x2,y2,z2);
	    glTexCoord2f(0,0);glVertex3f(x3,y3,z3);
	    glTexCoord2f(0,1);glVertex3f(x4,y4,z4);
    glEnd();
	return true;
}

int Sciana(float x, float y, float z, int typ)
//funkcja rysuje prostok¹ty (œciany)
{
	//zwyk³e œciany
	if (typ==1) Rectangle(x+3,y,z, x+3,y+4,z, x,y,z, x,y+4,z, textures[0]); 
	if (typ==2) Rectangle(x,y,z+3, x,y+4,z+3, x,y,z, x,y+4,z, textures[0]);
	if (typ==3) Rectangle(x+3,y,z+3, x+3,y+4,z+3, x+3,y,z, x+3,y+4,z, textures[0]);
	if (typ==4) Rectangle(x+3,y,z+3, x+3,y+4,z+3, x,y,z+3, x,y+4,z+3, textures[0]);
	
	//pod³oga i sufit
	if (typ==5) Rectangle(x+3,y,z, x+3,y,z+3, x,y,z, x,y,z+3, textures[1]);
	if (typ==6) Rectangle(x+3,y,z, x+3,y,z+3, x,y,z, x,y,z+3, textures[2]);
	
	//drzwi
	if (typ==7) Rectangle(x+3,y,z+3, x+3,y+4,z+3, x+3,y,z, x+3,y+4,z, textures[3]);

	//obrazy
	if (typ==8)
	{
		Rectangle(x+3,y,z, x+3,y+4,z, x,y,z, x,y+4,z, textures[0]);
		Rectangle(x+1.5f,y+1.1f,z+0.1f, x+1.5f,y+2.5f,z+0.1f, x,y+1.1f,z+0.1f, x,y+2.5f,z+0.1f, textures[4]);
	}

	if (typ==9)
	{
		Rectangle(x+3,y,z, x+3,y+4,z, x,y,z, x,y+4,z, textures[0]);
		Rectangle(x+1.6f,y+1.1f,z+0.1f, x+1.6f,y+2.55f,z+0.1f, x,y+1.1f,z+0.1f, x,y+2.55f,z+0.1f, textures[5]);
	}
	if (typ==10) 
	{
		Rectangle(x,y,z+3, x,y+4,z+3, x,y,z, x,y+4,z, textures[0]);
		Rectangle(x-0.1f,y+1.1f,z+1.1f, x-0.1f,y+2.6f,z+1.1f, x-0.1f,y+1.1f,z, x-0.1f,y+2.6f,z, textures[6]);
	}
	if (typ==11) 
	{
		Rectangle(x,y,z+3, x,y+4,z+3, x,y,z, x,y+4,z, textures[0]);
		Rectangle(x-0.1f,y+1.1f,z+1.1f, x-0.1f,y+2.6f,z+1.1f, x-0.1f,y+1.1f,z, x-0.1f,y+2.6f,z, textures[7]);
	}
	if (typ==12)
	{
		Rectangle(x+3,y,z+3, x+3,y+4,z+3, x+3,y,z, x+3,y+4,z, textures[0]);
		Rectangle(x+3.1f,y+1.3f,z+1.4f, x+3.1f,y+2.5f,z+1.4f, x+3.1f,y+1.3f,z, x+3.1f,y+2.5f,z, textures[8]);
	}
	if (typ==13) 
	{
		Rectangle(x+3,y,z+3, x+3,y+4,z+3, x,y,z+3, x,y+4,z+3, textures[0]);
		Rectangle(x+1.1f,y+1.1f,z+2.9f, x+1.1f,y+2.3f,z+2.9f, x,y+1.1f,z+2.9f, x,y+2.3f,z+2.9f, textures[9]);
	}

	
	
	return true;
}