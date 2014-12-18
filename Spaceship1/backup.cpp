#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

float year = 0, day = 0, sun = 0;
int teste = 1;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // funções desnecessárias aqui, pois são default
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

   // posicionamento do observador em relação à cena. Posicao fixa.
   gluLookAt (0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void astro(double raio, int fatiasLong, int fatiasLat)
{
    glPushMatrix();
      // mudar o eixo da esfera de Z (original da funcao
      // glutWireSphere) para Y
    //glTranslatef(1.0, 0.0, 0.0);
	glColor3f (0.36, 0.25, 0.23);
      glutWireSphere(raio, fatiasLong, fatiasLat);
    glPopMatrix();
}
float z=0,z2=0,z3=0,z4=0,z5=0,z6=0,z7=0,z8=0,z9=0, teta=0.0;
float dz=0.1, dz2=0.15,dz3=0.2,dz4=0.11,dz5=0.12,dz6=0.16,dz7=0.18,dz8=0.07,dz9=0.01;   //direcao inicial de movimento
void display(void)
// Ao executar esta função, a matriz modelview já contém as
// transformações produzidas pela gluLookAt
{
int i;
double d1,d2,d3,d4,d5,d6,d7,d8,d9;

    glClear (GL_COLOR_BUFFER_BIT);
   	glColor3f (1.0, 1.0, 1.0);
   	z += dz;if ( z>20) z=-20.0;
	z2 += dz2;if ( z2>20) z2=-20.0;
	z3 += dz3;if ( z3>20) z3=-20.0;
    z4 += dz4;if ( z4>20) z4=-20.0;
	z5 += dz5;if ( z5>20) z5=-20.0;
	z6 += dz6;if ( z6>20) z6=-20.0;
	z7 += dz7;if ( z7>20) z7=-20.0;
	z8 += dz8;if ( z8>20) z8=-20.0;
	z9 += dz9;if ( z9>20) z9=-20.0;
   	teta += 0.0;

    glPushMatrix();
   	glTranslatef (0, 0, 0);
   	//glRotatef (teta, 1.0, 1.0, 0.0);
   	glColor3f(teste,0,0);
	glutWireSphere(0.1,200,200);
	glPopMatrix();

   	glPushMatrix();
   	glTranslatef (-2, -1.5, z);
   	glRotatef (teta, 1.0, 1.0, 0.0);
	astro(0.2, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glTranslatef (-1.0, 0.0, z2);
   	glRotatef (teta, 4.0, 0.0, 0.0);
	astro(0.1, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glTranslatef (-0.5, 0, z3);
   	glRotatef (teta, 4.0, 0.0, 0.0);
	astro(0.3, 200, 200);
	glPopMatrix();

	glPushMatrix();
   	glTranslatef (1.5, 0, z4);
   	glRotatef (teta, 1.0, 1.0, 0.0);
	astro(0.2, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glTranslatef (-2.0, 0.0, z5);
   	glRotatef (teta, 4.0, 0.0, 0.0);
	astro(0.1, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glTranslatef (2.0, 0, z6);
   	glRotatef (teta, 4.0, 0.0, 0.0);
	astro(0.3, 200, 200);
	glPopMatrix();

    glPushMatrix();
   	glTranslatef (-2, -1.5, z7);
   	glRotatef (teta, 1.0, 1.0, 0.0);
	astro(0.2, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glTranslatef (-0.5, -1.5, z8);
   	glRotatef (teta, 4.0, 0.0, 0.0);
	astro(0.1, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glTranslatef (2.0, -1.5, z9);
   	glRotatef (teta, 4.0, 0.0, 0.0);
	astro(0.3, 200, 200);
	glPopMatrix();

    //Colisão
    d1 = sqrt(6.25 + z*z);
    d2 = sqrt(1 + z2*z2);
    d3 = sqrt(0.25 + z3*z3);
    d4 = sqrt(2.25 + z4*z4);
    d5 = sqrt(4 + z5*z5);
    d6 = sqrt(4 + z6*z6);
    d7 = sqrt(6.25 + z7*z7);
    d8 = sqrt(2.5 + z8*z8);
    d9 = sqrt(6.25 + z9*z9);

    if(d1 < 0.3)  teste = 0;
    if(d2 < 0.2)  teste = 0;
    if(d3 < 0.4)  teste = 0;
    if(d4 < 0.3)  teste = 0;
    if(d5 < 0.2)  teste = 0;
    if(d6 < 0.4)  teste = 0;
    if(d7 < 0.3)  teste = 0;
    if(d8 < 0.2)  teste = 0;
    if(d9 < 0.4)  teste = 0;

   	glutSwapBuffers();

}

void teclado(unsigned char c, int x, int y) {
   if (c=='q') exit(EXIT_SUCCESS);
}

void reshape (int w, int h)
//executada no inicio e quando a janela for
//reformatada
{
   glViewport (0, 0, w, h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   if (h>0)
     gluPerspective(60.0, (double)w/(double)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
}

void move (void)
{
   sun = (sun +3 );
   day = (day + 0.6);
   year = (year + 0.2);
   glutPostRedisplay();  // ou display()
}

int main(int argc, char** argv)
{
   int i;
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (1000, 700);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);

   glutReshapeFunc(reshape);
   glutIdleFunc(move);
   glutKeyboardFunc(teclado);
   glutMainLoop();
   return 0;
}
