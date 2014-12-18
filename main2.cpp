#include <windows.h>
#include <GL/glut.h>
#include <Gl/gl.h>
#include <Gl/glu.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include "Camera.hpp"
#include "details.h"
#include "metalStructure.hpp"

using namespace std;

#define WHITE_COLOR 1.0, 1.0, 1.0
#define BLUE_COLOR 0.2, 0.2, 1.0
#define GRAY_COLOR 0.7, 0.7, 0.7
#define BROWN_COLOR 0.6, 0.45, 0.05
#define DARK_GREEN 0.0, 1.0, 0.0

#define FLOOR_COORD 25.0
#define TILE_COORD 25.0

#define WALL_WIDTH 0.25
#define WALL_HEIGHT 15.0
#define WALL_FIRST_FLOOR 2.0
#define WALL_SECOND_FLOOR 17.0

#define PI 3.14159265

Camera cam(0.0,0.0,5.0,
           0.0,0.0,0.0,
           0.0,0.0,0.0,
           90,1,0.0,100.0);

void Wall(float x, float y, float z, float width, float height, float depth, float teta, float *color)
{
	glColor4f(color[0], color[1], color[2], 0.3f);
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(teta, 0, 1, 0);
		glScalef(width, height, depth);
		glutSolidCube(1.0);
	glPopMatrix();
}

void Glass_One(float x, float y, float z, double i, double j)
{
    glColor4f( 0, 0.5, 1.0, 0.7f );
    glBegin(GL_QUADS);
        glVertex3f (x, y, z);
        glVertex3f (x+i, y, z);
        glVertex3f (x+i, y+j, z);
        glVertex3f (x, y+j, z);
    glEnd();
}

void Glass_Two(float x, float y, float z, double i, double j)
{
    glColor4f( 0, 0.5, 1.0, 0.7f );
    glBegin(GL_QUADS);
        glVertex3f (x, y, z);
        glVertex3f (x, y, z+i);
        glVertex3f (x, y+j, z+i);
        glVertex3f (x, y+j, z);
    glEnd();
}

void drawCylinder(int numMajor, int numMinor, float height, float radius, int k, float *color)
{
   double majorStep = height/numMajor;
   double minorStep = 2.0*M_PI/numMinor;
   int i, j;

   glColor4f(color[0], color[1], color[2], 0.3f);

   for (i = 0; i < numMajor; ++i)
   {
       float z0 = 0.5 * height - i * majorStep;
       float z1 = z0 - majorStep;

       glBegin(GL_TRIANGLE_STRIP);
       for (j = 0; j <= int(numMinor/k); ++j)
       {
           double a = j * minorStep;
           float x = radius * cos(a);
           float y = radius * sin(a);
           glNormal3f(x/radius, y/radius, 0.0);
           glTexCoord2f(j/numMinor, i/numMajor);
           //for(int m=0; m<1; m++)
                glVertex3f(x, y, z0);

           glTexCoord2f(j/numMinor, (i + 1)/numMajor);
           //for(int m=0; m<1; m++)
                glVertex3f(x, y, z1);
       }
       glEnd();
   }
}

void circle(float x, float y, float r, int segments, double i, double rx, double ry)
{
    glBegin( GL_TRIANGLE_FAN );
        glVertex2f(x, y);
        //for( int n = int(segments/2+i); n <= segments; ++n )
        double n = (segments/2+i);
        while(n <= segments)
         {
            float const t = 2*M_PI*(float)n/(float)segments;
            glVertex2f((x+sin(t)*r/rx), (y+cos(t)*r/ry));
            n= n +1.0;
        }
    glEnd();
}

double pInclinacao = 0.0;
bool perRodando = false;
bool fechado = false;

void persianas(double pInclinacao){
glPushMatrix();
glTranslatef(73.5,3,-9.6);
glScalef(1,1,2.2);
glPushMatrix();
    glPushMatrix();
        glColor3f(0.0,0.0,0.0);
        glRotatef(-90,1,0,0);
        gluCylinder(gluNewQuadric(),0.02,0.02,6.75,40,40);
        glTranslatef(0,-7,0);
        gluCylinder(gluNewQuadric(),0.02,0.02,6.75,40,40);
    glPopMatrix();

    glPushMatrix();
        glPushMatrix();
            glColor3f(0.8,0.7,0.6);
            glTranslatef(0,0,3.5);
            glRotatef(20+pInclinacao,0,0,1);
            glScalef(0.5,0.01,7.8);
            glutSolidCube(1);
        glPopMatrix();

        for(int i = 0; i < 22; i++){
            glTranslatef(0,0.28,0);
            glPushMatrix();
                glTranslatef(0,0,3.5);
                glRotatef(20+pInclinacao,0,0,1);
                glScalef(0.5,0.01,7.8);
                glutSolidCube(1);
            glPopMatrix();
        }
    glPopMatrix();
glPopMatrix();
glPopMatrix();
}

void display(void) {

	float color[][3] = { { 0.9, 0.9, 0.9 }, { 1, 0, 0 }, { 0.7, 0.7, 0.7 }, { 0, 0, 1 }, { 1, 1, 0 }, {0.9, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.1, 0.6, 0.1}};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor (0.7, 0.9, 1.0, 0.0);

    cam.film();

	/* Inicio do universo */
	glPushMatrix();

		/* Terra */
		glColor3f(0.6, 0.45, 0.05);

		glPushMatrix();
			glTranslatef(0.0, -3.5, 0.0);
			glScalef(260.0, 0.5, 140.0);
			glutSolidCube(1.0);
		glPopMatrix();

/*
 * PRIMEIRO ANDAR
 */
		glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			glTranslatef(0.0, -3.1, 0.0);
			glScalef(150.0, 0.15, 90.0);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			glTranslatef(47.5, -3.1, -48.5);
			glScalef(55.0, 0.15, 7.0);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

        /*---------------------------detalhe verde----------------------------------------*/
		glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(47.3, 8.1, -51.8);
			glScalef(55.4, 0.1, 0.7);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(47.3, 10.5, -51.8);
			glScalef(55.4, 0.1, 0.7);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(20.0, 8.1, -48.6);
			glScalef(0.7, 0.1, 7);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(20.0, 10.5, -48.6);
			glScalef(0.7, 0.1, 7);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

        Wall(47.5, WALL_FIRST_FLOOR+7.0, -51.6, 54.65, 1.6, 0.15, 0, color[7]);
        Wall(47.4, WALL_FIRST_FLOOR+8.1, -51.6, 54.35, 0.8, 0.15, 0, color[7]);
        Wall(20.1, WALL_FIRST_FLOOR+7.2, -48.34, 0.15, 2.4, 6.4, 0, color[7]);

        Wall(74.55, WALL_SECOND_FLOOR-6.8, -3.5, 0.15, 1.0, 96.1, 0, color[7]);

        glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(74.8, WALL_FIRST_FLOOR+7.8, -3.4);
			glScalef(0.7, 0.1, 96.6);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(74.8, WALL_FIRST_FLOOR+7.8+1.0, -3.3);
			glScalef(0.7, 0.1, 96.6);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

        glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(40.0, 8.1, 44.8);
			glScalef(70.0, 0.1, 0.7);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.1, 0.5, 0.1);
			glTranslatef(40.0, 10.5, 45.0);
			glScalef(70.0, 0.1, 0.7);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

        Wall(40.0, WALL_FIRST_FLOOR+7.0, 44.6, 70.0, 1.6, 0.15, 0, color[7]);
        Wall(39.7, WALL_FIRST_FLOOR+8.1, 44.6, 69.7, 0.8, 0.15, 0, color[7]);

        /*--------------------------------------------------------------------------------*/

		/* Detalhes primeiro andar*/
        basketsFirstFloor();
        officeTablesFirstFloor();
        firstFloorCharis();
        apagadoresPrimeiroAndar();
        firstFloorLamps();
        estantesPrimeiroAndar();
        armariosPrimeiroAndar();
        tables1FirstFloor();
        tablesSecondFloor();
        firstFloorDishes();
        outerLamps();
        noteBooks();

        /*Estrutura de Metal*/
        metalStructure();

        /*Persianas*/
        persianas(pInclinacao);
        glPushMatrix();
            glTranslatef(0,0,19.5);
            persianas(pInclinacao);
            glTranslatef(0,0,-39);
            persianas(pInclinacao);
            glTranslatef(0,0,-19.5);
            persianas(pInclinacao);
        glPopMatrix();


		GLUquadricObj *disk;
        disk = gluNewQuadric();
        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        glTranslatef(-74.8, -3.0, -35.1);
        glRotatef(90, 1, 0, 0);
        gluDisk(disk, 0, 27, 30, 30);
        glPopMatrix();


        glPushMatrix();
        glColor3f(0.6, 0.45, 0.05);
		glTranslatef(-71.4, -3.0, -62.0);
		glRotatef(45, 0, 1, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(0.1, WALL_HEIGHT-5, 9.0);
		glutSolidCube(1.0);
        glPopMatrix();


        GLUquadricObj *disk2;
        disk2 = gluNewQuadric();
        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        glTranslatef(-51.4, -2.9, -35.6);
        glRotatef(90, 1, 0, 0);
        gluDisk(disk2, 0, 28.8, 30, 30);
        glPopMatrix();

        /*segundo andar*/

		glPushMatrix();
			glColor3f(0.7, 0.7, 0.7 );
			glTranslatef(47.4, 9.6, -3.5);  //ou 9.5
			glScalef(54.5, 0.15, 96.0);   //alterado
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.9, 0.9, 0.9 );
		glTranslatef(-35.0, 16.5, -45.0);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		//glRotatef(180, 0, 0, 1);
		circle(0.0, 16, 31.0, 34,0.0, 1.6, 1.2);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.9, 0.9, 0.9 );
		glTranslatef(-75.0, 16.5, -49.9);
		glRotatef(90, 1, 0, 0);
		circle(0.0, 15, 27, 50, 1, 1, 1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.9, 0.3, 0.3);
		glTranslatef(-75.0, 16.5, -54.0);
		glRotatef(90, 1, 0, 0);
		//glRotatef(240, 0, 0, 1);
		//glRotatef(180, 0, 0, 1);
		circle(0.0, 16, 28.8, 50,11, -0.79, 1.0);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
        glVertex3f (-77, 16.5, -45.5);
        glVertex3f (-77+2.0, 16.5, -45.5);
        glVertex3f (-77+2.0, 16.5, -45.5 +12.0);
        glVertex3f (-77, 16.5, -45.5 +12.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
		glColor3f(0.9, 0.3, 0.3);
		glBegin(GL_QUADS);
        glVertex3f (-75, 16.5, -44.9);
        glVertex3f (-75+36.0, 16.5, -44.9);
        glVertex3f (-75+36.0, 16.5, -44.9 +9.0);
        glVertex3f (-75, 16.5, -44.9 +9.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
		glColor3f(0.9, 0.9, 0.9);
		glTranslatef(-56.5, 0, 24.9 );
		glRotatef(-45, 0, 1, 0);
		glBegin(GL_QUADS);
        glVertex3f (-77, 16.5, -45.5);
        glVertex3f (-77+12.0, 16.5, -45.5);
        glVertex3f (-77+12.0, 16.5, -45.5 +12.0);
        glVertex3f (-77, 16.5, -45.5 +12.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
        glVertex3f (-28.5, 16.5, -51.5);
        glVertex3f (-28.5+1.8, 16.5, -51.5);
        glVertex3f (-28.5+6.0, 16.5, -51.5 +7.0);
        glVertex3f (-28.5, 16.5, -51.5 +7.0);
        glEnd();
        glPopMatrix();

        /*----------------------ESCADA-------------------------*/

        for (int i = 0; i < 7; i++)
            Wall(-37.5+i*3.5, -3.0+i*0.8, 35.0, 3.5, 0.15, 10.0, 0, color[6]);

        for (int i = 0; i < 7; i++)
            Wall(-35.5+i*3.5, -2.7+i*0.8, 35.0, 1.5, 1.0, 10.0, 0, color[0]);

        Wall(-9.5, 3.1, 35.0, 11.0, 0.15, 10.0, 0, color[6]);

        for (int i = 0; i < 7; i++)
            Wall(-2+i*3.5, 3.9+i*0.8, 35.0, 3.5, 0.15, 10.0, 0, color[6]);

        for (int i = 0; i < 8; i++)
            Wall(-3.5+i*3.5, 3.4+i*0.8, 35.0, 1.5, 1.0, 10.0, 0, color[0]);

        /* Corrimão da Escada */
        for (int i = 0; i < 2; i++){
            glBegin(GL_POLYGON);
                glColor3f( 0.7, 0.7, 0.7 );
                glVertex3f (-15.4, 5.8, 30.0+i*10);
                glVertex3f (-15.4, 2.8, 30.0+i*10);
                glVertex3f (-39, -3, 30.0+i*10);
                glVertex3f (-39, 0, 30.0+i*10);
            glEnd();
        }

        for (int i = 0; i < 2; i++){
            glBegin(GL_POLYGON);
                glColor3f( 0.7, 0.7, 0.7 );
                glVertex3f (-15.4, 6.1, 30.0+i*10);
                glVertex3f (-15.4, 3.1, 30.0+i*10);
                glVertex3f (-4.4, 3.1, 30.0+i*10);
                glVertex3f (-4.4, 6.1, 30.0+i*10);
            glEnd();
        }

        for (int i = 0; i < 2; i++){
            glBegin(GL_POLYGON);
                glColor3f( 0.7, 0.7, 0.7 );
                glVertex3f (20, 12.5, 30.0+i*10);
                glVertex3f (20, 9.5, 30.0+i*10);
                glVertex3f (-4.4, 4, 30.0+i*10);
                glVertex3f (-4.4, 7, 30.0+i*10);
            glEnd();
        }

        for (int i = 0; i < 7; i++){
            glBegin(GL_TRIANGLES);
                glColor3f( 0.7, 0.7, 0.7 );
                glVertex3f (20-i*3.5, 9.7-i*0.8, 30.0);
                glVertex3f (20-i*3.5, 8.7-i*0.8, 30.0);
                glVertex3f (16.5-i*3.5, 8.7-i*0.8, 30.0);
            glEnd();
        }

        for (int i = 0; i < 7; i++){
            glBegin(GL_TRIANGLES);
                glColor3f( 0.7, 0.7, 0.7 );
                glVertex3f (-15-i*3.5, 3-i*0.8, 30.0);
                glVertex3f (-15-i*3.5, 1.9-i*0.8, 30.0);
                glVertex3f (-19-i*3.5, 1.9-i*0.8, 30.0);
            glEnd();
        }

        for (int i = 0; i < 7; i++){
            glBegin(GL_TRIANGLES);
                glColor3f( 0.7, 0.7, 0.7 );
                glVertex3f (20-i*3.5, 9.7-i*0.8, 40.0);
                glVertex3f (20-i*3.5, 8.7-i*0.8, 40.0);
                glVertex3f (16.5-i*3.5, 8.7-i*0.8, 40.0);
            glEnd();
        }

        for (int i = 0; i < 7; i++){
            glBegin(GL_TRIANGLES);
                glColor3f( 0.7, 0.7, 0.7 );
                glVertex3f (-15-i*3.5, 3-i*0.8, 40.0);
                glVertex3f (-15-i*3.5, 1.9-i*0.8, 40.0);
                glVertex3f (-19-i*3.5, 1.9-i*0.8, 40.0);
            glEnd();
        }

        /*------------------------------------------------------*/

		/* PRIMEIRO ANDAR
		   Parede da faxada direita */
		Wall(-35.0, WALL_FIRST_FLOOR, 45.0, 40.0, WALL_HEIGHT, WALL_WIDTH, 0, color[5]);
        Wall(40.0, WALL_FIRST_FLOOR, 45.0, 70.0, WALL_HEIGHT-3, WALL_WIDTH, 0, color[0]);

		/*Porta lateral direita*/
        Wall(-72.5, WALL_FIRST_FLOOR+1, 45.0, 5.0, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(-57.5, WALL_FIRST_FLOOR+1, 45.0, 5.0, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(-60.0, WALL_FIRST_FLOOR, 45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);
        Wall(-70.0, WALL_FIRST_FLOOR, 45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);

        /* Estrutura de vidro lateral direita - II*/
		for (int i = 0; i < 3; i++)
            Wall(-10.0+i*5, WALL_FIRST_FLOOR, 45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);

		/* Estrutura de vidro frontal */
		for (int i = 0; i < 11; i++)  //18
            Wall(-75.0, WALL_FIRST_FLOOR, 45-i*5, WALL_WIDTH, WALL_HEIGHT, 0.5, 0, color[0]);
        Wall(-75.0, WALL_FIRST_FLOOR, 45-(11*5)+2, WALL_WIDTH, WALL_HEIGHT, 0.5, 0, color[0]);

		/* Parede da faxada esquerda*/
		Wall(22.0, WALL_FIRST_FLOOR, -52.0, 4.5, WALL_HEIGHT-3, WALL_WIDTH, 0, color[0]);
		Wall(20.0, WALL_FIRST_FLOOR, -48.5, WALL_WIDTH, WALL_HEIGHT-3, 7.0, 0, color[0]);
		Wall(28.8, WALL_FIRST_FLOOR-3.5, -52.0, 10, WALL_HEIGHT-10, WALL_WIDTH, 0, color[0]);
		Wall(36.6, WALL_FIRST_FLOOR, -52.0, 6.0, WALL_HEIGHT-3, WALL_WIDTH, 0, color[0]);
		Wall(44.3, WALL_FIRST_FLOOR-3.5, -52.0, 9.5, WALL_HEIGHT-10, WALL_WIDTH, 0, color[0]);
		Wall(62.0, WALL_FIRST_FLOOR, -52.0, 26.0, WALL_HEIGHT-3, WALL_WIDTH, 0, color[0]);

		/*estrutura de vidro da parede*/
		Wall(27.5, WALL_FIRST_FLOOR+2.5, -52.0, 0.5, WALL_HEIGHT/2 - 0.5 , WALL_WIDTH, 0, color[0]);
		Wall(30.5, WALL_FIRST_FLOOR+2.5, -52.0, 0.5, WALL_HEIGHT/2 - 0.5 , WALL_WIDTH, 0, color[0]);
		Wall(43.0, WALL_FIRST_FLOOR+2.5, -52.0, 0.5, WALL_HEIGHT/2 - 0.5 , WALL_WIDTH, 0, color[0]);
		Wall(46.0, WALL_FIRST_FLOOR+2.5, -52.0, 0.5, WALL_HEIGHT/2 - 0.5 , WALL_WIDTH, 0, color[0]);
		Wall(29.0, WALL_FIRST_FLOOR+2.5, -52.0, 9.5, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(44.3, WALL_FIRST_FLOOR+2.5, -52.0, 9.5, 0.5, WALL_WIDTH, 0, color[0]);

		/* Paredes de divisao dos escritorios */
		Wall(51.0, WALL_FIRST_FLOOR, -31.5, 48.0, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);
		Wall(51.0, WALL_FIRST_FLOOR, -11.5, 48.0, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);
		Wall(51.0, WALL_FIRST_FLOOR,  7.5, 48.0, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);
		Wall(47.5, WALL_FIRST_FLOOR,  28.0, 55.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);



		/* Estrutura de Vidro das divisorias */
		for (int i = 0; i < 3; i++){
            Wall(27.0, WALL_FIRST_FLOOR+1, 10.0-i*19.5, WALL_WIDTH, 0.5, 5.0, 0, color[2]);
            Wall(27.0, WALL_FIRST_FLOOR+1, 25.0-i*19.5, WALL_WIDTH, 0.5, 5.0, 0, color[2]);
            Wall(27.0, WALL_FIRST_FLOOR, 12.5-i*19.5, WALL_WIDTH, WALL_HEIGHT, 0.5, 0, color[2]);
            Wall(27.0, WALL_FIRST_FLOOR, 27.5-i*19.5, WALL_WIDTH, WALL_HEIGHT, 0.5, 0, color[2]);
            Wall(27.0, WALL_FIRST_FLOOR, 7.5-i*19.5, WALL_WIDTH, WALL_HEIGHT, 0.5, 0, color[2]);
            Wall(27.0, WALL_FIRST_FLOOR, 22.5-i*19.5, WALL_WIDTH, WALL_HEIGHT, 0.5, 0, color[2]);
		}

        /* Parede ao lado das portas da divisoria */
        Wall(20.0, WALL_FIRST_FLOOR, 36.5, 0.5, WALL_HEIGHT-3, 16.65, 0, color[0]);
        Wall(20.0, WALL_FIRST_FLOOR+7.5, 36.2, 0.5, 3.0, 16.5, 0, color[0]);


        /* Parede da faixada Trazeira */
		Wall(75.0, WALL_FIRST_FLOOR-2, -3.5, WALL_WIDTH, (WALL_HEIGHT/2)-1, 97.0, 0, color[0]);

        /*---------------estrutura de vidro da faixada trazeira-----------------------------*/
        Wall(75.0, WALL_FIRST_FLOOR+4.5, -51.8, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
		for(int i=1; i<8; i++)
		    Wall(75.0, WALL_FIRST_FLOOR+4.5, -52.0+i*2.9, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        for(int i=8; i<15; i++)
		    Wall(75.0, WALL_FIRST_FLOOR+4.5, -52.2+i*2.9, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        for(int i=15; i<23; i++)
		    Wall(75.0, WALL_FIRST_FLOOR+4.5, -51.3+i*2.8, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        for(int i=23; i<34; i++)
		    Wall(75.0, WALL_FIRST_FLOOR+4.5, -53.5+i*2.9, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        Wall(75.0, WALL_FIRST_FLOOR+4.5, 44.8, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);

         Wall(75.0, WALL_FIRST_FLOOR+4.5, -3.5, WALL_WIDTH, 0.5, 97.0, 0, color[0]);
         Wall(75.0, WALL_FIRST_FLOOR+7.5, -3.5, WALL_WIDTH, 0.5, 97.0, 0, color[0]);
         Wall(75.0, WALL_FIRST_FLOOR+1.5, -3.5, WALL_WIDTH, 0.5, 97.0, 0, color[0]);

		/* SEGUNDO ANDAR
		   Parede da faxada direita*/
		Wall(-35.0, WALL_SECOND_FLOOR, 45.0, 40.0, WALL_HEIGHT, WALL_WIDTH, 0, color[5]);
		Wall(40.0, WALL_SECOND_FLOOR+0.4, 45.2, 70.0, WALL_HEIGHT-1.5, WALL_WIDTH, 0, color[0]);

        /* Estrutura de Vidro lateral direita - I*/
        Wall(-65, WALL_FIRST_FLOOR+22, 45.0, 20.0, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(-65, WALL_FIRST_FLOOR+15, 45.0, 20.0, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(-65, WALL_FIRST_FLOOR+8, 45.0, 20.0, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(-60.0, WALL_SECOND_FLOOR, 45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);
        Wall(-65.0, WALL_SECOND_FLOOR, 45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);
        Wall(-70.0, WALL_SECOND_FLOOR, 45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);

        /* Estrutura de Vidro lateral direita - II*/
		for (int i = 0; i < 3; i++)
            Wall(-10.0+i*5, WALL_SECOND_FLOOR, 45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);

        for (int i = 0; i < 3; i++)
            Wall(-5.0, WALL_SECOND_FLOOR-i*7, 45.0, 20.0, 0.5, WALL_WIDTH, 0, color[0]);

        Wall(-5.0, WALL_SECOND_FLOOR+7, 45.0, 20.0, 0.5, WALL_WIDTH, 0, color[0]);

         /* Estrutura de Vidro da faxada esquerda...1 e 2 andar*/
        for (int i = 0; i <20; i++)
            Wall(-75.0+i*5, WALL_SECOND_FLOOR+3.8, -45.0, 0.5, WALL_HEIGHT/2, WALL_WIDTH, 0, color[0]);

        Wall(-27.5, WALL_SECOND_FLOOR+7, -45.0, 95.0, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(-27.5, WALL_SECOND_FLOOR, -45.0, 95.0, 0.5, WALL_WIDTH, 0, color[0]);
        Wall(-75.0+(10*5)+2, WALL_SECOND_FLOOR-3.8, -45.0, 0.5, WALL_HEIGHT/2, WALL_WIDTH, 0, color[0]);
        Wall(-75.0+(10*5)+2, WALL_FIRST_FLOOR, -45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);

        for (int i = 1; i < 3; i++)
            Wall(-1.5, WALL_SECOND_FLOOR-i*7, -45.0, 43.0, 0.5, WALL_WIDTH, 0, color[0]);

        for (int i = 11; i <20; i++)
        {
            Wall(-75.0+i*5, WALL_SECOND_FLOOR-3.8, -45.0, 0.5, WALL_HEIGHT/2, WALL_WIDTH, 0, color[0]);
            Wall(-75.0+i*5, WALL_FIRST_FLOOR, -45.0, 0.5, WALL_HEIGHT, WALL_WIDTH, 0, color[0]);
        }
		/* Parede da faxada esquerda*/

		Wall(20.0, WALL_SECOND_FLOOR+0.3, -48.5, WALL_WIDTH, WALL_HEIGHT-1.5, 7.0, 0, color[0]);
		Wall(47.5, WALL_SECOND_FLOOR-3.1, -52.0, 55.0, (WALL_HEIGHT/2)-1, WALL_WIDTH, 0, color[0]);
		Wall(73.2, WALL_SECOND_FLOOR+3.6, -52.0, 3.5, (WALL_HEIGHT/2)-0.5, WALL_WIDTH, 0, color[0]);
		Wall(21.9, WALL_SECOND_FLOOR+3.6, -52.0, 3.7, (WALL_HEIGHT/2)-0.5, WALL_WIDTH, 0, color[0]);
		Wall(32.15, WALL_SECOND_FLOOR+3.6, -52.0, 3.8, (WALL_HEIGHT/2)-0.5, WALL_WIDTH, 0, color[0]);
		Wall(42.45, WALL_SECOND_FLOOR+3.6, -52.0, 3.8, (WALL_HEIGHT/2)-0.5, WALL_WIDTH, 0, color[0]);
		Wall(52.75, WALL_SECOND_FLOOR+3.6, -52.0, 3.8, (WALL_HEIGHT/2)-0.5, WALL_WIDTH, 0, color[0]);
		Wall(63.05, WALL_SECOND_FLOOR+3.6, -52.0, 3.8, (WALL_HEIGHT/2)-0.5, WALL_WIDTH, 0, color[0]);

        /*estrutura de vidro da faixada esquerda*/
        for(int i=0; i<5; i++)
            for(int j=0; j<3; j++)
            {
                Wall(27.0+10.3*i, WALL_SECOND_FLOOR+0.3+j*3.3, -52.0, WALL_HEIGHT/2-1, 0.5, WALL_WIDTH, 0, color[0]);
                Wall(24.0+3*j+i*10.3, WALL_SECOND_FLOOR+3.8, -52.0, 0.5, WALL_HEIGHT/2-1, WALL_WIDTH, 0, color[0]);
            }

		/* Meia parede */
        Wall(20.0, WALL_SECOND_FLOOR-6, -7.5, WALL_WIDTH, WALL_HEIGHT-12, 75.0, 0, color[2]);

        /* Parede da faixada Trazeira */
        Wall(75.0, WALL_SECOND_FLOOR-3.0, -3.5, WALL_WIDTH, (WALL_HEIGHT/2)-1, 97.0, 0, color[0]);

		/*estrutura de vidro da faixada traseira*/
		Wall(75.0, WALL_SECOND_FLOOR+4.5-1, -51.8, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
		for(int i=1; i<8; i++)
		    Wall(75.0, WALL_SECOND_FLOOR+4.5-1, -52.0+i*2.9, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        for(int i=8; i<15; i++)
		    Wall(75.0, WALL_SECOND_FLOOR+4.5-1, -52.2+i*2.9, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        for(int i=15; i<23; i++)
		    Wall(75.0, WALL_SECOND_FLOOR+4.5-1, -51.3+i*2.8, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        for(int i=23; i<34; i++)
		    Wall(75.0, WALL_SECOND_FLOOR+4.5-1, -53.5+i*2.9, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);
        Wall(75.0, WALL_SECOND_FLOOR+4.5-1, 44.8, WALL_WIDTH, WALL_HEIGHT/2-2, 0.5, 0, color[0]);

         Wall(75.0, WALL_SECOND_FLOOR+4.5-1, -3.5, WALL_WIDTH, 0.5, 97.0, 0, color[0]);
         Wall(75.0, WALL_SECOND_FLOOR+7.5-1, -3.5, WALL_WIDTH, 0.5, 97.0, 0, color[0]);
         Wall(75.0, WALL_SECOND_FLOOR+1.5-1, -3.5, WALL_WIDTH, 0.5, 97.0, 0, color[0]);


		/* Estrutura de vidro frontal - I */
		for (int i = 0; i < 11; i++)
            Wall(-75.0, WALL_SECOND_FLOOR, 45-i*5, WALL_WIDTH, WALL_HEIGHT, 0.5, 0, color[0]);
        Wall(-75.0, WALL_SECOND_FLOOR-3.5, 45-(11*5)+2, WALL_WIDTH, WALL_HEIGHT/2, 0.5, 0, color[0]);


        for (int i = 11; i < 18; i++)
            Wall(-75.0, WALL_SECOND_FLOOR+3.8, 45-i*5, WALL_WIDTH, WALL_HEIGHT/2, 0.5, 0, color[0]);

        Wall(-75.0, WALL_SECOND_FLOOR, 0.0, WALL_WIDTH, WALL_HEIGHT-14.5, 90.0, 0, color[0]);
        for (int i = 0; i < 3; i++)
            Wall(-75.0, WALL_SECOND_FLOOR-i*7, 18.5, WALL_WIDTH, WALL_HEIGHT-14.5, 53.0, 0, color[0]);

        Wall(-75.0, WALL_SECOND_FLOOR+7, 0.0, WALL_WIDTH, WALL_HEIGHT-14.5, 90.0, 0, color[0]);


        /*-----parede cilindrica--------*/

        glPushMatrix();
        glTranslatef(-75, 6.5, -35);
        glRotatef(90, 1, 0, 0);
        glRotatef(90, 0, 0, 1);
        drawCylinder(25, 25, 20, 27, 2, color[5]);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-75, 6.5, -35.0);
        glRotatef(90, 1, 0, 0);
        glRotatef(90, 0, 0, 1);
        drawCylinder(25, 25, 20, 26, 2, color[0]);
        glPopMatrix();

        Wall(-75.5, WALL_FIRST_FLOOR+13, -58.7, WALL_WIDTH, 3.0, 8.5, 45, color[5]);
        Wall(-77.35, WALL_FIRST_FLOOR+3.0, -60.9, WALL_WIDTH, WALL_HEIGHT+2.5, 3.0, 45, color[5]);
        Wall(-72.5, WALL_FIRST_FLOOR+1.9, -55.0, WALL_WIDTH, 25.2, 1.0, 45, color[5]);
        Wall(-37.5, WALL_FIRST_FLOOR+2.1, -44.0, 5.0, 25.3, 2.0, 0, color[5]);
        Wall(-29.0, WALL_FIRST_FLOOR+2.1, -45.0, 12.0, 25.3, WALL_WIDTH, 0, color[0]);
        Wall(-74.0, WALL_FIRST_FLOOR+2.1, -10.7, 2.0, 25.3, 5.0, 0, color[5]);


        glPushMatrix();
        glTranslatef(-51.3, 6.5, -34.5);
        glRotatef(90, 1, 0, 0);
        glRotatef(224, 0, 0, 1);
        drawCylinder(25, 25, 20, 30, 3, color[5]);
        glPopMatrix();


        glPushMatrix();
        glTranslatef(-51.3, 6.5, -34.5);
        glRotatef(90, 1, 0, 0);
        glRotatef(224, 0, 0, 1);
        drawCylinder(25, 25, 20, 29, 3, color[0]);
         glPopMatrix();

        for(int i=1; i<170; i++)
        {
            glPushMatrix();
            glTranslatef(-66.3, 15.3, -39.0+0.01*i);
            glRotatef(90, 1, 0, 0);
            glRotatef(170, 0, 0, 1);
            drawCylinder(31, 31, 3, -27.0-0.01*i, 3, color[5]);
            glPopMatrix();
        }

        for(int i=1; i<170; i++)
        {
            glPushMatrix();
            glTranslatef(-66.3, 1.0, -39.0+0.01*i);
            glRotatef(90, 1, 0, 0);
            glRotatef(170, 0, 0, 1);
            drawCylinder(31, 31, 7, -27.0-0.01*i, 3, color[1]);
            glPopMatrix();
        }

        /*-----------------------------------*/
       // Wall(-65, WALL_FIRST_FLOOR, 45.0, 20.0, 0.5, WALL_WIDTH, 0, color[0]);

		/* --------- VIDRAÇA ---------- */
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE);

        /*  Vidraça Frontal */
        for (int i = 0; i < 18; i++)
        {
            Glass_Two(-75, -3.7+3*7.0, 40-i*5.0, 5, 6.5);
            for (int j = 0; j < 3; j++)
                Glass_Two(-75, -3.7+j*7.0, 42-(i*2.95),2.95, 6.5);
        }

        /*-------------------------vidraça dos fundos-----------------------*/
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 2; j++)
            {
                Glass_Two(75, WALL_FIRST_FLOOR+1.5+j*3, -52+i*2.9, 2.9, 3);
                Glass_Two(75, WALL_SECOND_FLOOR+1.5+j*3-1, -52+i*2.9, 2.9, 3);
            }
        for (int i = 8; i < 14; i++)
            for (int j = 0; j < 2; j++)
            {
                Glass_Two(75, WALL_FIRST_FLOOR+1.5+j*3, -52.2+i*2.9, 2.9, 3);
                Glass_Two(75, WALL_SECOND_FLOOR+1.5+j*3-1, -52.2+i*2.9, 2.9, 3);
            }
        for (int i = 14; i < 23; i++)
            for (int j = 0; j < 2; j++)
            {
                Glass_Two(75, WALL_FIRST_FLOOR+1.5+j*3, -51.3+i*2.8, 2.8, 3);
                Glass_Two(75, WALL_SECOND_FLOOR+1.5+j*3-1, -51.3+i*2.8, 2.8, 3);
            }
        for (int i = 23; i < 33; i++)
            for (int j = 0; j < 2; j++)
            {
                Glass_Two(75, WALL_FIRST_FLOOR+1.5+j*3, -53.5+i*2.9, 2.9, 3);
                Glass_Two(75, WALL_SECOND_FLOOR+1.5+j*3-1, -53.5+i*2.9, 2.9, 3);
            }
        for (int j = 0; j < 2; j++)
        {
             Glass_Two(75, WALL_FIRST_FLOOR+1.5+j*3, -53.5+34*2.8, 2.8, 3);
             Glass_Two(75, WALL_SECOND_FLOOR+1.5+j*3-1, -53.5+34*2.8, 2.8, 3);
        }


        /*---------------------------------------------------------------------------*/
        /* Vidraça lateral direita */
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                Glass_One(-15.0+i*5, -3.7+j*7.0, 45.0, 5, 6.5);

        /* Vidraça lateral esquerda */
        for (int i = 0; i < 19; i++)
            Glass_One(-75.0+i*5, -3.7+3*7.0, -45.0, 5, 6.5);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 3; j++)
                Glass_One(-23.0+i*4.75, -3.7+j*7.0, -45.0, 5, 6.5);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2; j++)
            {
                Glass_One(24.0+i*3.5,0.8+j*3.6, -52.0, 3.5, 3.6);
                Glass_One(39.0+i*3.5,0.8+j*3.6, -52.0, 3.5, 3.6);
            }


        for(int i=0; i<5; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<2; k++)
                    Glass_One(24.0+3*j+i*10.3,WALL_SECOND_FLOOR+0.35+3.45*k, -52.0, 3.0, 3.0);

        /* Vidraça da porta lateral Direita */
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
                Glass_One(-75.0+i*5, 10.2+j*7.0, 45.0, 5, 6.5);

        Glass_One(-75.0, -3.7, 45.0, 5, 6.5);
        Glass_One(-75.0, 3.3, 45.0, 5, 6.5);
        Glass_One(-60.0, -3.7, 45.0, 5, 6.5);
        Glass_One(-60.0, 3.3, 45.0, 5, 6.5);

        /* Vidraça das divisorias */
        for (int i = 0; i < 3; i++){
            Glass_Two(27.0, -3.8, 7.5-i*19.5, 5, 6.5);
            Glass_Two(27.0, 3.1, 7.5-i*19.5, 5, 6.5);
            Glass_Two(27.0, -3.8, 22.5-i*19.5, 5, 6.5);
            Glass_Two(27.0, 3.1, 22.5-i*19.5, 5, 6.5);
        }

        //Wall(27.0, WALL_FIRST_FLOOR+1, 10.0-i*19.5, WALL_WIDTH, 0.5, 5.0, 0, color[2]);

        glDisable(GL_BLEND);
        /* ------------------------------------------------- */

	glPopMatrix();/* Fim do universo - origem volta para o sistema de coordenadas original */
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -15.0);
}

void teclado(unsigned char c, int x, int y){
    cam.keyboardListener(c,x,y);

    switch(c)
    {
        case 'p':
            perRodando = true;
            break;
        default:
            break;
    }
}

void mouse(int x, int y){
    cam.mouseMotionListener(x,y);
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	cam.setPerspective();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	/*Habilitando a Iluminação*/
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);

    GLfloat mat_ambient[]={0.7, 0.7, 0.7, 1.0};
    GLfloat mat_diffuse[]={0.5, 0.5, 0.5, 1.0};
    GLfloat mat_specular[]={0.3, 0.3, 0.3, 1.0};
    GLfloat mat_shininess={50.0};

    GLfloat light_ambient[]={0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[]={0.6, 0.6, 0.6, 1.0};
    GLfloat light_specular[]={0.6, 0.6, 0.6, 1.0};

    GLfloat light_position[]={3.0,3.0,3.0,1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

}

void idle(){
    glutPostRedisplay();

    if(perRodando){
        if(!fechado){
            pInclinacao = pInclinacao + 1;
            if(pInclinacao == 60){
                perRodando = false;
                fechado = true;
            }
        }
        else{
            pInclinacao = pInclinacao - 1;
            if(pInclinacao == 0){
                perRodando = false;
                fechado = false;
            }
        }
    }
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
    glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(teclado);
    glutPassiveMotionFunc(mouse);
	glutMainLoop();
	return 0;
}
