#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <conio.h>
#include <string>
#include <iostream>
#include <sstream>

#include "imageloader.h"

using namespace std;

GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{0.0,-1.2,-0.5},
	{1.0,-1.0,-1.0}, {0.0,0.0,1.0}, {-1.0,1.0,-1.0},
	{0.0,1.2,-0.5}, {1.0,1.0,-1.0}, {-2.5,-0.5,-1.5}, {2.5,-0.5,-1.5}};

//Retorna float entre 0 e 1 para gerar raio
float randomFloat() {
	return (float)rand() / ((float)RAND_MAX + 1);
}

struct Asteroid {
	float v; //Velocidade
	float x,y,z; //Posi��o
	float r; //Raio
};

struct Bonus{
    float v;
    float x,y,z;
    float r;
    bool onoff;
};

struct Penal{
    float v;
    float x,y,z;
    float r;
    bool onoff;
};

struct Nave{
    float v;
    float x,y,z;
    float angZ, angX;
    float r;
};

struct Particula{
    float v;
    float fi,teta;
    float r;
};

vector<Asteroid*> _astros;
vector<Particula*> _particulas;
Bonus* _bonus;
Nave* _nave;
Penal* _penal;
GLuint _textureId;
GLUquadric* _quad;
float _rotate;
int _pontos = 0;
int _vidas = 3;
int _melhor = 0;
float _raio = 5;
int _turboVal = 1;
float _turbo = 1;
float _explosaoX = 0;
float _explosaoY = 0;
float _explosaoZ = 0;
int _nivel = 0;
int _qtdAstros = 10;
const float JANELAD = 1.6;
const float JANELAE = -1.6;
const float JANELAN = 1.1;
const float JANELAS = -1.1;


void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);

    // fun��es desnecess�rias aqui, pois s�o default
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // posicionamento do observador em rela��o � cena. Posicao fixa.
    gluLookAt (0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    srand((unsigned int)time(0));
    // Cria 10 asteroids
    for(int i = 0; i < _qtdAstros; i++){
        Asteroid* asteroid = new Asteroid();
        asteroid->r = 0.1f * randomFloat() + 0.1f;
        asteroid->v = randomFloat()/18;
        asteroid->x = 3 * randomFloat() - 1.5;
        asteroid->y = 3 * randomFloat() - 1.5;
        asteroid->z = -18;
        _astros.push_back(asteroid);
    }

    //Modela Bonus

    _bonus = new Bonus();
    _bonus->r = 0.05;
    _bonus->v = randomFloat()/60;
    _bonus->x = 2 * randomFloat() - 1;
    _bonus->y = 2 * randomFloat() - 1;
    _bonus->z = -18;
    _bonus->onoff = false;

    //Modela Penal
    _penal = new Penal();
    _penal->r = 0.05;
    _penal->v = randomFloat()/10;
    _penal->x = 2 * randomFloat() - 1;
    _penal->y = 2 * randomFloat() - 1;
    _penal->z = -18;
    _penal->onoff = false;

    //Modela Navy Box
    _nave = new Nave();
    _nave->r = 0.12;
    _nave->v = 0.5;
    _nave->x = 0;
    _nave->y = 0;
    _nave->angX = 0;
    _nave->angZ = 0;
    _nave->z = -1;

    // Cria particulas para explos�o
    int i = 0;
    for(int teta = 0; teta < 360; teta +=30,i++){
        for(int fi = 0; fi < 360; fi +=30,i++){
            Particula* particula = new Particula();
            particula->r = 0.01;
            particula->v = randomFloat()/100;
            particula->fi = fi;
            particula->teta = teta;
            _particulas.push_back(particula);
        }
    }
}

void polygon(int a, int b, int c , int d)
{
	glBegin(GL_POLYGON);
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
	glEnd();
}

void triangle(int a, int b, int c )
{
	glBegin(GL_POLYGON);
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
	glEnd();
}

void nave()
{
    triangle(0,1,3);
    triangle(1,3,2);
    triangle(0,3,4);
    triangle(3,2,6);
    triangle(3,4,5);
    triangle(3,5,6);
    triangle(0,4,7);
    triangle(2,6,8);
    triangle(3,4,7);
    triangle(3,5,6);
    triangle(3,0,7);
    triangle(4,0,7);
    triangle(3,6,8);
    triangle(3,2,8);
    triangle(2,6,8);
    polygon(0,1,5,4);
    polygon(1,2,6,5);

}

void naveT()
{
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
     glPushMatrix();
        glTranslatef(_nave->x,_nave->y,_nave->z);
        glRotatef(_nave->angZ, 0.0,0.0,1.0);
        glRotatef(_nave->angX, 1.0,0.0,0.0);
        glPushMatrix();
            glScalef(0.075, 0.0375, 0.07);
            nave();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,0,-0.05);
            glScalef(0.05,0.05,0.05);
            glColor3f(1,0,0);
            glutWireSphere(0.5, 50, 50);
        glPopMatrix();
     glPopMatrix();
}

void explosao(float x1, float y1, float z1){
    for(int i = 0; i < _particulas.size(); i++){
        Particula* particula = _particulas[i];

        float x =  x1 + _raio*sin(particula->fi)*cos(particula->teta);
        float y = y1 + _raio*sin(particula->fi)*sin(particula->teta);
        float z = z1 + _raio*cos(particula->fi);

        glPushMatrix();
        glTranslatef(x,y,z);
        glColor3f(1,1,0);
        glutSolidSphere(particula->r,12,12);
        glPopMatrix();
    }
}

void display(void)
// Ao executar esta fun��o, a matriz modelview j� cont�m as
// transforma��es produzidas pela gluLookAt
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	glColor3f (1.0, 1.0, 1.0);

    //Subir de nivel
    if(_pontos > 0){
        int last = _nivel * 1000;
        if (_pontos - last > 1000){
            _nivel++;

            Asteroid* asteroid = new Asteroid();
            asteroid->r = 0.1f * randomFloat() + 0.1f;
            asteroid->v = randomFloat()/18;
            asteroid->x = 3 * randomFloat() - 1.5;
            asteroid->y = 3 * randomFloat() - 1.5;
            asteroid->z = -18;
            _astros.push_back(asteroid);
        }
    }

    //Ajustar angulo da nave
    if(_nave->angX > 0) _nave->angX -= 0.1;
    if(_nave->angX < 0) _nave->angX += 0.1;
    if(_nave->angZ > 0) _nave->angZ -= 0.1;
    if(_nave->angZ < 0) _nave->angZ += 0.1;

    //Explosao quando morrer
    _raio += 0.01;
    if(_raio < 0.5) explosao(_explosaoX, _explosaoY, _explosaoZ);

    //Fim de jogo
    if(_vidas == 0){
        _explosaoX = _nave->x;
        _explosaoY = _nave->y;
        _explosaoZ = _nave->z;
        _raio = 0;
        if(_pontos > _melhor) _melhor = _pontos;
        _vidas = 3;
        _pontos = 0;
        _nivel = 0;
        _bonus->onoff = false;
        _penal->onoff = false;

        for(int i = 0; i < _astros.size()-10; i++)
            _astros.pop_back();

        for(int i = 0; i < _astros.size(); i++){
            Asteroid* astro = _astros[i];

            astro->z = -20;
        }

    }

    //Tratamento de colis�o para cada asteroid
    for(int i = 0; i < _astros.size(); i++){
        float c1,c2,c3,dist,raios;
        Asteroid* astro = _astros[i];

        c1 = (astro->x - _nave->x);
        c2 = (astro->y - _nave->y);
        c3 = (astro->z - _nave->z);
        dist = c1*c1 + c2*c2 + c3*c3;
        dist = sqrt(dist);
        raios = astro->r + _nave->r;

        if(dist < raios){
            _vidas --;
            astro->x = 3 * randomFloat() - 1.5;
            astro->y = 3 * randomFloat() - 1.5;
            astro->z = -20;
        }
    }

    //Tratamento de colis�o para bonus e penais
    //Bonus
    float c1,c2,c3,dist,raios;

    c1 = (_bonus->x - _nave->x);
    c2 = (_bonus->y - _nave->y);
    c3 = (_bonus->z - _nave->z);
    dist = c1*c1 + c2*c2 + c3*c3;
    dist = sqrt(dist);
    raios = _bonus->r + _nave->r;

    if(dist < raios){
        _pontos += 1000;
        _bonus->z = -20;
        _bonus->onoff = false;
        _bonus->x = 2 * randomFloat() - 1;
        _bonus->y = 2 * randomFloat() - 1;
        }

    //Penal
    c1 = (_penal->x - _nave->x);
    c2 = (_penal->y - _nave->y);
    c3 = (_penal->z - _nave->z);
    dist = c1*c1 + c2*c2 + c3*c3;
    dist = sqrt(dist);
    raios = _penal->r + _nave->r;

    if(dist < raios){
        _pontos -= 500;
        _penal->z = -20;
        _penal->onoff = false;
        _penal->x = 2 * randomFloat() - 1;
        _penal->y = 2 * randomFloat() - 1;
    }

    //Navy Box
    /*glPushMatrix();
    glTranslatef(_nave->x, _nave->y, _nave->z);
	glColor3f(0,1,0);
	glutSolidSphere(_nave->r, 200, 200);
	glPopMatrix();*/

    glPushMatrix();
	//glRotatef(90,1,1,1);
	//glScalef(0.075, 0.0375, 0.07);
	glColor3f(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	naveT();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f (0.0, 0.25, 0.7);
	naveT();
    glPopMatrix();

    //Bonus de pontua��o
    int chance = rand() % 200;
    if (chance < 5) _bonus->onoff = true;

    if(_bonus->onoff){
        _bonus->z += _bonus->v;
        if(_bonus->z > 20){
            _bonus->onoff = false;
            _bonus->x = 2 * randomFloat() - 1;
            _bonus->y = 2 * randomFloat() - 1;
            _bonus->z = -20;
        }

        glPushMatrix();
		glTranslatef(_bonus->x, _bonus->y, _bonus->z);
		glColor3f(0,0,1);
		glutSolidSphere(_bonus->r, 12, 12);
		glPopMatrix();
    }

    //Penalidades na pontua��o
    int chance2 = rand() % 100;
    if (chance2 < 5) _penal->onoff = true;

    if(_penal->onoff){
        _penal->z += _penal->v;
        if(_penal->z > 20){
            _penal->onoff = false;
            _penal->x = 2 * randomFloat() - 1;
            _penal->y = 2 * randomFloat() - 1;
            _penal->z = -20;
        }

        glPushMatrix();
		glTranslatef(_penal->x, _penal->y, _penal->z);
		glColor3f(1,0,0);
		glutSolidSphere(_penal->r, 12, 12);
		glPopMatrix();
    }

    //Asteroides

    for(int i = 0; i < _astros.size(); i++){
        Asteroid* asteroid = _astros[i];

        asteroid->z += _turbo * asteroid->v;
        if(asteroid->z > 20){
            asteroid->x = 3 * randomFloat() - 1.5;
            asteroid->y = 3 * randomFloat() - 1.5;
            asteroid->z = -20;
            _pontos += 10;
        }

        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTranslatef(asteroid->x, asteroid->y, asteroid->z);
		glColor3f (0.36, 0.25, 0.23);
		gluQuadricTexture(_quad,1);
		gluSphere(_quad,asteroid->r, 12, 12);
		//glutSolidSphere(asteroid->r, 12, 12);
		glPopMatrix();
    }

    //Pontua��o no canto direito
    string s = "Pontos: ";
    std::ostringstream ss;
    ss << _pontos;
    string s2 = ss.str();

    glLoadName(5);
    glPushMatrix();
    glTranslatef(1.6,1.4,-2.0);
    glScalef(0.001,0.001,0.001);
    glColor3f(1,1,1);
    for (int i = 0; i < s.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
    for (int i = 0; i < s2.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s2[i]);
    glPopMatrix();

    //Vidas no canto esquerdo
    string s3 = "Vidas: ";
    std::ostringstream ss2;
    ss2 << _vidas;
    string s4 = ss2.str();

    glLoadName(5);
    glPushMatrix();
    glTranslatef(-2.3,1.4,-2.0);
    glScalef(0.001,0.001,0.001);
    glColor3f(1,1,1);
    for (int i = 0; i < s3.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s3[i]);
    for (int i = 0; i < s4.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s4[i]);
    glPopMatrix();

    //Melhor pontua��o no meio
    string s5 = "Melhor: ";
    std::ostringstream ss3;
    ss3 << _melhor;
    string s6 = ss3.str();

    glLoadName(5);
    glPushMatrix();
    glTranslatef(-0.7,1.4,-2.0);
    glScalef(0.001,0.001,0.001);
    glColor3f(1,1,1);
    for (int i = 0; i < s5.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s5[i]);
    for (int i = 0; i < s6.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s6[i]);
    glPopMatrix();

    //Placar de Turbo
    string s7 = "Turbo: ";
    std::ostringstream ss4;
    ss4 << _turboVal;
    string s8 = ss4.str();

    glLoadName(5);
    glPushMatrix();
    glTranslatef(-2.3,-1.4,-2.0);
    glScalef(0.001,0.001,0.001);
    glColor3f(1,1,1);
    for (int i = 0; i < s7.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s7[i]);
    for (int i = 0; i < s8.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s8[i]);
    glPopMatrix();

    //Placar de Turbo
    string s9 = "Nivel: ";
    std::ostringstream ss5;
    ss5 << _nivel;
    string s10 = ss5.str();

    glLoadName(5);
    glPushMatrix();
    glTranslatef(1.8,-1.4,-2.0);
    glScalef(0.001,0.001,0.001);
    glColor3f(1,1,1);
    for (int i = 0; i < s9.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s9[i]);
    for (int i = 0; i < s10.length(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s10[i]);
    glPopMatrix();

   	glutSwapBuffers();

}

void teclado(unsigned char c, int x, int y) {
    if (c=='q') exit(EXIT_SUCCESS);

    //Turbos
    else if (c=='a'){
        if(_turbo < 5){ _turbo ++; _turboVal ++;}
    }
    else if (c=='s'){
        if(_turbo > 1){ _turbo --; _turboVal --;}
    }

    //Movimento
    else if(c=='i'){
        if(_nave->y < JANELAN) _nave->y += 0.02;
        if (_nave->angX >-45.0)
            _nave->angX-=10;
    }
    else if(c=='k'){
        if(_nave->y > JANELAS) _nave->y -= 0.02;
        if (_nave->angX <45.0)
            _nave->angX+=10;
    }
    else if(c=='j'){
        if(_nave->x > JANELAE) _nave->x -= 0.02;
        if (_nave->angZ <45.0)
            _nave->angZ+=10;
    }
    else if(c=='l'){
        if(_nave->x < JANELAD) _nave->x += 0.02;
        if (_nave->angZ >-45.0)
            _nave->angZ-=10;
    }
    else if(c=='u'){
        if(_nave->y < JANELAN) _nave->y += 0.02;
        if(_nave->x > JANELAE) _nave->x -= 0.02;
        if (_nave->angX >-45.0)
            _nave->angX-=10;
        if (_nave->angZ <45.0)
            _nave->angZ+=10;
    }
    else if(c=='o'){
        if(_nave->y < JANELAN) _nave->y += 0.02;
        if(_nave->x < JANELAD) _nave->x += 0.02;
        if (_nave->angX >-45.0)
            _nave->angX-=10;
        if (_nave->angZ >-45.0)
            _nave->angZ-=10;
    }
    else if(c=='.'){
        if(_nave->y > JANELAS) _nave->y -= 0.02;
        if(_nave->x < JANELAD) _nave->x += 0.02;
        if (_nave->angX <45.0)
            _nave->angX+=10;
        if (_nave->angZ <45.0)
            _nave->angZ+=10;
    }
    else if(c=='m'){
        if(_nave->y > JANELAS) _nave->y -= 0.02;
        if(_nave->x > JANELAE) _nave->x -= 0.02;
        if (_nave->angX <45.0)
            _nave->angX+=10;
        if (_nave->angZ >-45.0)
            _nave->angZ-=10;
    }
}

void teclado2(int tecla, int x, int y){
    switch(tecla){
        case GLUT_KEY_UP:
            if(_nave->y < JANELAN) _nave->y += 0.02;
            if (_nave->angX >-45.0)
                _nave->angX-=10;
            break;
        case GLUT_KEY_DOWN:
            if(_nave->y > JANELAS) _nave->y -= 0.02;
            if (_nave->angX <45.0)
                _nave->angX+=10;
            break;
        case GLUT_KEY_LEFT:
            if(_nave->x > JANELAE) _nave->x -= 0.02;
            if (_nave->angZ <45.0)
                _nave->angZ+=10;
            break;
        case GLUT_KEY_RIGHT:
            if(_nave->x < JANELAD) _nave->x += 0.02;
            if (_nave->angZ >-45.0)
                _nave->angZ-=10;
            break;
        case 27: exit(EXIT_SUCCESS);  // tecla ESC para sair
    }
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
   glutPostRedisplay();  // ou display()
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void menu(int item){
    glutPostRedisplay();
    return;
}

int main(int argc, char** argv)
{
    int i;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1000, 700);
    glutInitWindowPosition (100, 50);
    glutCreateWindow ("TRABALHO DE COMPUTA��O GRAFICA");

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);

    _quad = gluNewQuadric();
    Image *image = loadBMP("C:/Users/Matheus/Dropbox/Aulas/Computa��o Grafica/Nave1/Nave1/tex001.bmp");
    _textureId = loadTexture(image);
	delete image;

    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(move);

    glutCreateMenu(menu);
    glutAddMenuEntry("Adicionar Jogador",1);
    glutAddMenuEntry("Ranking",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutKeyboardFunc(teclado);
    glutSpecialFunc(teclado2);
    glutMainLoop();
    return 0;
}

