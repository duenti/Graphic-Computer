#include "details.h"

void basket(){
    glPushMatrix();
        glTranslatef(0.0,-3.0,0.0);
        glRotatef(270, 1, 0, 0);
        gluDisk(gluNewQuadric(), 0, 0.45, 25, 25);
        gluCylinder(gluNewQuadric(),0.45,0.45,1.5,40,40);
    glPopMatrix();
}

void basketsFirstFloor(){
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
        glTranslatef(27.5,0.0,6.5);
        basket();
        glTranslatef(0.0,0.0,20.2);
        basket();
        glTranslatef(0.5,0.0,-39.2);
        basket();
    glPopMatrix();
}

void officeTable(){
    glPushMatrix();
        glTranslatef(0.0,2.4,0);
        glScalef(1.4,1.5,1.4);
        glPushMatrix();
            glScalef(7.0, 0.15,3.5);
            glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glScalef(0.25, 3,0.25);
            glTranslatef(13.0,-0.5,5.5);
            glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glScalef(0.25, 3,0.25);
            glTranslatef(-13.0,-0.5,5.5);
            glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glScalef(0.25, 3,0.25);
            glTranslatef(13.0,-0.5,-5.5);
            glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
            glScalef(0.25, 3,0.25);
            glTranslatef(-13.0,-0.5,-5.5);
            glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

void officeTablesFirstFloor(){
    glColor3f(0.8, 0.6, 0.4);

    glPushMatrix();
        glTranslatef(50.0,-1.0,3.5);
        officeTable();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(50.0,-1.0,24.5);
        officeTable();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(50.0,-1.0,-15.0);
        officeTable();
    glPopMatrix();
}

void miniChair(){
    glColor3f(0.2, 0.2, 0.2);

    glPushMatrix();
        glPushMatrix();
            glRotatef(15, 0, 0, 1);
            glScalef(1.3,0.1,0.1);
            glutSolidCube(1.0);
        glPopMatrix();
            glTranslatef(-0.6,-0.3,0.0);
            glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glRotatef(72, 0, 1, 0);
        glTranslatef(-0.48,0.0,0.65);
        glPushMatrix();
            glRotatef(15, 0, 0, 1);
            glScalef(1.3,0.1,0.1);
            glutSolidCube(1.0);
        glPopMatrix();
            glTranslatef(-0.6,-0.3,0.0);
            glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glRotatef(144, 0, 1, 0);
        glTranslatef(-1.245,0.0,0.38);
        glPushMatrix();
            glRotatef(15, 0, 0, 1);
            glScalef(1.3,0.1,0.1);
            glutSolidCube(1.0);
        glPopMatrix();
            glTranslatef(-0.6,-0.3,0.0);
            glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glRotatef(216, 0, 1, 0);
        glTranslatef(-1.22,0.0,-0.42);
        glPushMatrix();
            glRotatef(15, 0, 0, 1);
            glScalef(1.3,0.1,0.1);
            glutSolidCube(1.0);
        glPopMatrix();
            glTranslatef(-0.6,-0.3,0.0);
            glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glRotatef(288, 0, 1, 0);
        glTranslatef(-0.47,0.0,-0.65);
        glPushMatrix();
            glRotatef(15, 0, 0, 1);
            glScalef(1.3,0.1,0.1);
            glutSolidCube(1.0);
        glPopMatrix();
            glTranslatef(-0.6,-0.3,0.0);
            glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glRotatef(270, 1, 0, 0);
        glTranslatef(0.7,0.0,0.2);
        gluCylinder(gluNewQuadric(),0.2,0.2,1.5,40,40);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.8, 0.6, 0.4);
        glScalef(1.3,0.5,1.3);
        glTranslatef(0.5,3.0,0.0);
        glutSolidSphere(0.8,30,30);
    glPopMatrix();
}

void chair(){
    miniChair();

    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glColor3f(0.8, 0.6, 0.4);
        glScalef(1.3,0.5,1.3);
        glTranslatef(0.5,- 1.5,-2.2);

        glutSolidSphere(0.8,30,30);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(0.7,2.7,-1.12);
        glScalef(0.5,0.5,0.5);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(0.7,2.0,-1.2);
        glScalef(0.2,1.0,0.2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(0.7,1.5,-1.1);
        glScalef(0.2,0.2,0.5);
        glutSolidCube(1);
    glPopMatrix();
}

void firstFloorCharis(){
    glPushMatrix();
        glTranslatef(50.0,-2.51,0.0);
        glScalef(1.3,1.3,1.3);
        chair();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(50.0,-2.51,20.0);
        glScalef(1.3,1.3,1.3);
        chair();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(50.0,-2.51,-20.0);
        glScalef(1.3,1.3,1.3);
        chair();
    glPopMatrix();
}

void apagador(){
    glColor3f(0.7,0.7,0.7);
    glPushMatrix();
        glScalef(1,1.4,1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.7,0.7,0.0);
        glTranslated(0,0,0.5);
        glRotatef(-15, 1, 0, 0);
        glScalef(0.25,0.65,0.25);
        glutSolidCube(1);
    glPopMatrix();
}

void apagadoresPrimeiroAndar(){
    glPushMatrix();
        glTranslated(30,4,27.7);
        glRotatef(180, 0, 1, 0);
        glScalef(0.5,0.5,0.5);
        apagador();
    glPopMatrix();

    glPushMatrix();
        glTranslated(30,4,7.2);
        glRotatef(180, 0, 1, 0);
        glScalef(0.5,0.5,0.5);
        apagador();
    glPopMatrix();

    glPushMatrix();
        glTranslated(30,4,-11.85);
        glRotatef(180, 0, 1, 0);
        glScalef(0.5,0.5,0.5);
        apagador();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-52,5,44.7);
        glRotatef(180, 0, 1, 0);
        glScalef(0.5,0.5,0.5);
        apagador();
    glPopMatrix();
}

void baseLamp(){
    glPushMatrix();
        glColor3f(0.7,0.7,1.0);
        glutSolidSphere(0.7,30,30);
        glRotatef(270, 1, 0, 0);
        gluCylinder(gluNewQuadric(),0.6,0.3,1.2,20,20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glTranslatef(0,1.2,0);
        glRotatef(90, 1, 0, 0);
        gluDisk(gluNewQuadric(), 0, 1.35, 25, 25);
    glPopMatrix();
}

void lamp(){
    baseLamp();
    //Desenho da lâmpada
    glDisable(GL_LIGHTING);

    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glTranslatef(0,1.2,0);
        glRotatef(270, 1, 0, 0);
        gluCylinder(gluNewQuadric(),1.35,1.7,0.5,20,20);
    glPopMatrix();

    glEnable(GL_LIGHTING);
    //Criamos a luz 0 na posição e cor definidas
    float position[] = {0, 1.2, 0, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    float color[] = {0.8, 0.8, 0.8, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, color);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
}

void outerLamp(){
    baseLamp();

    glPushMatrix();
        glColor3f(0.9,0.9,0.9);
        glTranslatef(0,-0.3,0);
        glRotatef(270, 1, 0, 0);
        gluCylinder(gluNewQuadric(),2.7,1.35,1.5,20,20);
    glPopMatrix();
}

void firstFloorLamps(){
    glPushMatrix();
        glTranslatef(50,8.85,0);
        glScalef(0.4,0.4,0.4);
        lamp();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(50,8.85,17);
        glScalef(0.4,0.4,0.4);
        lamp();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(50,8.85,-21);
        glScalef(0.4,0.4,0.4);
        lamp();
    glPopMatrix();
}

void estante(){
    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glScalef(1.5,7,0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glTranslatef(0,0,6);
        glScalef(1.5,7,0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glTranslatef(0.7,0,3);
        glScalef(0.01,1.165,1);
        glutSolidCube(6);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glTranslatef(0,0,3);
        glScalef(1.5,0.1,6.0);
        glutSolidCube(1);
        glTranslatef(0,34,0);
        glutSolidCube(1);
        glTranslatef(0,-17,0);
        glutSolidCube(1);
        glTranslatef(0,-34,0);
        glutSolidCube(1);
    glPopMatrix();
}

void estantesPrimeiroAndar(){
glPushMatrix();
glTranslatef(-3,0,0);
    glPushMatrix();
        glTranslatef(73.6,0,-4);
        glScalef(1.5,1.5,1.5);
        estante();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(73.6,0,15);
        glScalef(1.5,1.5,1.5);
        estante();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(73.6,0,-25);
        glScalef(1.5,1.5,1.5);
        estante();
    glPopMatrix();
glPopMatrix();
}

void armario(){
    glPushMatrix();
        glColor3f(0.8,0.5,0.4);
        glTranslatef(0,0,0);
        glScalef(2,3,4);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(1,-1.6,2);
        glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(1,-1.6,-2);
        glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(-1,-1.6,2);
        glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(-1,-1.6,-2);
        glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.7,0.4,0.3);
        glTranslatef(-0.2,0,0);
        glScalef(1.8,0.8,3.8);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(-1.149,0,0);
        glScalef(0.5,1,1);
        glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(-1.149,1,0);
        glScalef(0.5,1,1);
        glutSolidSphere(0.12,30,30);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.7,0.4,0.3);
        glTranslatef(-0.2,-1,0);
        glScalef(1.8,0.8,3.8);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.7,0.4,0.3);
        glTranslatef(-0.2,1,0);
        glScalef(1.8,0.8,3.8);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(-1.149,-1,0);
        glScalef(0.5,1,1);
        glutSolidSphere(0.12,30,30);
    glPopMatrix();
}

void armariosPrimeiroAndar(){
    glPushMatrix();
        glTranslatef(35,-1.32,6);
        glRotatef(-90,0,1,0);
        armario();
        glTranslatef(20.7,0,-27);
        armario();
        glTranslatef(-39.5,0,27);
        armario();
    glPopMatrix();
}

void table1(){
    glColor3f(0.2, 0.2, 0.2);

    glPushMatrix();
        glTranslatef(0.0,-2.72,0.0);
        glPushMatrix();
            glScalef(1.5,1.5,1.5);
            glPushMatrix();
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(72, 0, 1, 0);
                glTranslatef(-0.48,0.0,0.65);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(144, 0, 1, 0);
                glTranslatef(-1.245,0.0,0.38);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(216, 0, 1, 0);
                glTranslatef(-1.22,0.0,-0.42);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(288, 0, 1, 0);
                glTranslatef(-0.47,0.0,-0.65);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(270, 1, 0, 0);
                glTranslatef(0.7,0.0,0.2);
                gluCylinder(gluNewQuadric(),0.1,0.1,3,40,40);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glRotatef(180,1,0,0);
            glTranslatef(0,-5,0);
            glScalef(1.5,1.5,1.5);
            glPushMatrix();
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(72, 0, 1, 0);
                glTranslatef(-0.48,0.0,0.65);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(144, 0, 1, 0);
                glTranslatef(-1.245,0.0,0.38);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(216, 0, 1, 0);
                glTranslatef(-1.22,0.0,-0.42);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glRotatef(288, 0, 1, 0);
                glTranslatef(-0.47,0.0,-0.65);
                glRotatef(15, 0, 0, 1);
                glScalef(1.3,0.1,0.1);
                glutSolidCube(1.0);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,1,0,0);
            glTranslatef(1,0,-5.4);
            gluCylinder(gluNewQuadric(),2.3,2.3,0.15,40,40);
            glColor3f(1, 0.8, 0.4);
            gluDisk(gluNewQuadric(), 0, 2.3, 40, 40);
            glTranslatef(0,0,0.15);
            gluDisk(gluNewQuadric(), 0, 2.3, 40, 40);
        glPopMatrix();
    glPopMatrix();
}

void chair1(){
    glPushMatrix();
        glColor3f(0.2, 0.2, 0.2);
        glScalef(1.2,0.1,1.2);
        glutSolidCube(1);
        glColor3f(1, 0.8, 0.4);
        glScalef(0.99,1.01,0.99);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2, 0.2, 0.2);
        glTranslatef(0.53,-1.5,0.53);
        glScalef(0.1,3.1,0.1);
        glutSolidCube(1);
        glTranslatef(-10.7,0,0);
        glutSolidCube(1);
        glTranslatef(0,0,-10.7);
        glutSolidCube(1);
        glTranslatef(10.7,0,0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glRotatef(12,1,0,0);
        glTranslatef(0,2.19,0);
        glPushMatrix();
            glColor3f(0.2, 0.2, 0.2);
            glTranslatef(0.53,-1.5,0.53);
            glScalef(0.1,1.1,0.1);
            glutSolidCube(1);
            glTranslatef(-10.7,0,0);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.2, 0.2, 0.2);
            glTranslatef(0,-1.5,0.53);
            glScalef(1.1,0.1,0.1);
            glutSolidCube(1);
            glTranslatef(0,5,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
}

void completeTable1(){
    glPushMatrix();
        table1();
        glScalef(1.5,1.5,1.5);
        glTranslatef(0,1,1.5);
        glRotatef(-20,0,1,0);
        chair1();
        glRotatef(120,0,1,0);
        glTranslatef(1.5,0,2.5);
        chair1();
        glRotatef(120,0,1,0);
        glTranslatef(1.5,0,2.3);
        chair1();
    glPopMatrix();
}

void tables1FirstFloor(){
    glPushMatrix();
        glTranslatef(-35,0,-30);
        completeTable1();
        glTranslatef(12,0,0);
        completeTable1();
        glTranslatef(12,0,0);
        completeTable1();
        glTranslatef(6,0,12);
        completeTable1();
        glTranslatef(-12,0,0);
        completeTable1();
        glTranslatef(-12,0,0);
        completeTable1();
        glTranslatef(-12,0,0);
        completeTable1();
        glTranslatef(-6,0,12);
        completeTable1();
        glTranslatef(12,0,0);
        completeTable1();
        glTranslatef(12,0,0);
        completeTable1();
    glPopMatrix();
    firstFloorCups();
}

void cup(){
    glPushMatrix();
        glColor3f(0.4,0.6,0.8);
        glRotatef(-90,1,0,0);
        gluDisk(gluNewQuadric(), 0, 0.2, 25, 25);
        gluCylinder(gluNewQuadric(),0.2,0.3,0.5,25,25);
    glPopMatrix();
}

void firstFloorCups(){
    glPushMatrix();
        glTranslatef(-10,2.69,-29);
        cup();
        glTranslatef(-23,0,0);
        cup();
        glTranslatef(5,0,10);
        cup();
        glTranslatef(-7,0,12);
        cup();
        glTranslatef(-10,0,0);
        cup();
    glPopMatrix();
}

void table2(){
    glPushMatrix();
        glColor3f(0.3,0.3,0.3);
        glRotatef(90,0,1,0);
        glTranslatef(0,0.1,1.5);
        glScalef(6,0.1,4);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0,2.5);
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(0,-1.5,0);
            glScalef(0.1,3,0.1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glRotatef(90,0,0,1);
            glRotatef(90,0,1,0);
            glTranslatef(0,-1.5,0);
            glScalef(0.1,3,0.1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(3,-1.5,0);
            glScalef(0.1,3,0.1);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0,-2.5);
        glPushMatrix();
            glTranslatef(0,-1.5,0);
            glScalef(0.1,3,0.1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glRotatef(90,0,0,1);
            glRotatef(90,0,1,0);
            glTranslatef(0,-1.5,0);
            glScalef(0.1,3,0.1);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(3,-1.5,0);
            glScalef(0.1,3,0.1);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
}

void chair2(){
    glPushMatrix();
        glRotatef(180,1,0,0);
        glTranslatef(0,2.9,0);
        glPushMatrix();
        glTranslatef(0,0,2.5);
            glPushMatrix();
                glColor3f(0.1,0.1,0.1);
                glTranslatef(0,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,0,0,1);
                glRotatef(90,0,1,0);
                glTranslatef(0,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(3,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0,0,-0);
            glPushMatrix();
                glTranslatef(0,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,0,0,1);
                glRotatef(90,0,1,0);
                glTranslatef(0,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(3,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.6, 0.4, 0.2);
        glRotatef(90,0,1,0);
        glTranslatef(1.27,0.1,1.5);
        glScalef(2.7,0.1,3.15);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glRotatef(10,1,0,0);
        glTranslatef(0,3.1,-2.5);
        glPushMatrix();
            glTranslatef(0,0,2.5);
            glPushMatrix();
                glColor3f(0.1,0.1,0.1);
                glTranslatef(0,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glRotatef(90,0,0,1);
                glRotatef(90,0,1,0);
                glTranslatef(0,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(3,-1.5,0);
                glScalef(0.1,3,0.1);
                glutSolidCube(1);
            glPopMatrix();


            glPushMatrix();
                glTranslatef(1.5,-1.35,0);
                glRotatef(90,0,1,0);
                glColor3f(0.6, 0.4, 0.2);
                glScalef(0.1,2.6,2.9);
                glutSolidCube(1);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void completeTable2(){
    table2();
    glPushMatrix();
        glTranslatef(0,-1.245,0);
        glPushMatrix();
            glTranslatef(4,0,-0.5);
            glRotatef(90,0,1,0);
            glScalef(0.6,0.6,0.6);
            chair2();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(4,0,2.2);
            glRotatef(90,0,1,0);
            glScalef(0.6,0.6,0.6);
            chair2();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(3,0,0);
            glRotatef(180,0,1,0);
            glPushMatrix();
                glTranslatef(4,0,-0.5);
                glRotatef(90,0,1,0);
                glScalef(0.6,0.6,0.6);
                chair2();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(4,0,2.2);
                glRotatef(90,0,1,0);
                glScalef(0.6,0.6,0.6);
                chair2();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void tablesSecondFloor(){
    glPushMatrix();
        glTranslatef(26,13.585,-35);
        glScalef(1.3,1.3,1.3);
        glRotatef(90,0,1,0);
        completeTable2();

        glTranslatef(0,0,10);
        completeTable2();

        glTranslatef(0,0,10);
        completeTable2();

        glTranslatef(-8,0,0);
        completeTable2();

        glTranslatef(0,0,-10);
        completeTable2();

        glTranslatef(0,0,-10);
        completeTable2();

        glTranslatef(-8,0,0);
        completeTable2();

        glTranslatef(0,0,10);
        completeTable2();

        glTranslatef(0,0,10);
        completeTable2();

        glTranslatef(-8,0,0);
        completeTable2();

        glTranslatef(0,0,-10);
        completeTable2();

        glTranslatef(0,0,-10);
        completeTable2();

        glTranslatef(-8,0,0);
        completeTable2();

        glTranslatef(0,0,10);
        completeTable2();

        glTranslatef(32,0,20);
        completeTable2();

        glTranslatef(-8,0,0);
        completeTable2();

    glPopMatrix();
}

void dish(){
    glColor3f(0.8,0.8,0.8);
    glPushMatrix();
        glRotatef(-90,1,0,0);
        gluDisk(gluNewQuadric(), 0, 0.6, 25, 25);
        gluCylinder(gluNewQuadric(),0.6,0.8,0.15,25,25);
    glPopMatrix();
}

void firstFloorDishes(){
    glPushMatrix();
        glTranslatef(-34.5,2.681,-5);
        dish();
    glPopMatrix();
}

void pipe(double a){
    glPushMatrix();
        glColor3f(0.8,0.8,0.8);
        glRotatef(270,1,0,0);
        gluCylinder(gluNewQuadric(),0.1,0.1,a,25,25);
    glPopMatrix();
}

void outerLamps(){
    glPushMatrix();
        glTranslatef(-50,15,-5.9);
        pipe(14.0);
        outerLamp();
        glTranslatef(0,0,27);
        pipe(14.0);
        outerLamp();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5,15,-5.9);
        pipe(27.0);
        outerLamp();
        glTranslatef(0,0,27);
        pipe(27.0);
        outerLamp();
        glTranslatef(0,0,-54);
        pipe(27.0);
        outerLamp();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(35,25,-5.9);
        pipe(17.0);
        outerLamp();
        glTranslatef(0,0,27);
        pipe(17.0);
        outerLamp();
        glTranslatef(0,0,-54);
        pipe(17.0);
        outerLamp();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(60,25,-5.9);
        pipe(9.0);
        outerLamp();
        glTranslatef(0,0,-27);
        pipe(9.0);
        outerLamp();
    glPopMatrix();
}

void noteBook(){
    glColor3f(0.9,0.9,0.9);
    glPushMatrix();
        glScalef(1.8,0.1,1.4);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.85,0.02,0);
        glScalef(0.1,0.1,1.4);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.85,0.02,0);
        glScalef(0.1,0.1,1.4);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.02,0.65);
        glScalef(1.8,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.02,-0.65);
        glScalef(1.8,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.93,0,0.7);
        glRotatef(90,0,0,1.5);
        pipe(1.85);
    glPopMatrix();

    //Tela
glPushMatrix();
    glTranslatef(0,0.35,1.3);
    glRotatef(-30,1,0,0);
        glPushMatrix();
            glTranslatef(0,-0.01,0);
            glScalef(1.8,0.05,1.4);
            glutSolidCube(1);
        glPopMatrix();

    glPushMatrix();
        glColor3f(0.2,0.2,0.2);
        glTranslatef(0,0.01,0);
        glScalef(1.74,0.05,1.38);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9,0.9,0.9);
        glTranslatef(0.85,0.02,0);
        glScalef(0.1,0.1,1.4);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.85,0.02,0);
        glScalef(0.1,0.1,1.4);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.02,0.65);
        glScalef(1.8,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.02,-0.65);
        glScalef(1.8,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(7.0,0.18,4.7);
        glutSolidCube(1);

        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);

        glTranslatef(15.6,0.0,-1.5);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);

        glTranslatef(15.6,0.0,-1.5);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);

        glTranslatef(15.6,0.0,-1.5);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);

        glTranslatef(15.6,0.0,-1.5);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);

        glTranslatef(15.6,0.0,-1.5);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);

        glTranslatef(15.6,0.0,-1.5);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);
        glTranslatef(-1.3,0.0,0.0);
        glutSolidCube(1);

    glPopMatrix();
}

void noteBooks(){
    glPushMatrix();
        glTranslatef(51,1.6,3);
        noteBook();

        glTranslatef(0,0,21);
        noteBook();

        glTranslatef(0,0,-40);
        noteBook();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-10,2.75,-31);
        glRotatef(30,0,1,0);
        noteBook();
    glPopMatrix();
}
