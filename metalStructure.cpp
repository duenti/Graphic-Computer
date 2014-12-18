#include "metalStructure.hpp"

void metalStructure(){
    metalBase();
    top();
}

void metalBase(){
    glColor3f(0,0.3,0);

    glPushMatrix();
        glTranslatef(-79.0,-3.0,47.0);
        glRotatef(270, 1, 0, 0);
            glPushMatrix();
                glTranslatef(0.0,0.0,0.19);
                gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
            glPopMatrix();
        gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
        gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);

        glTranslatef(0.0,27,0.0);
        glPushMatrix();
                glTranslatef(0.0,0.0,0.19);
                gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
            glPopMatrix();
        gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
        gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);

        glTranslatef(0.0,27,0.0);
        glPushMatrix();
                glTranslatef(0.0,0.0,0.19);
                gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
            glPopMatrix();
        gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
        gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);

        glTranslatef(0.0,37,0.0);//Metal que fica em cima da lanchonete
            glPushMatrix();
                glTranslatef(0.0,0.0,0.19);
                gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
            glPopMatrix();
        gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
        gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);

    glPopMatrix();

    glPushMatrix();
        glTranslatef(-77.5,25.0,-46.0);
        gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
        glPushMatrix();
            glTranslatef(0.0,0.0,96.0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
        glPopMatrix();
        gluCylinder(gluNewQuadric(),0.8,0.8,96,40,40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(160,0,0);
        glPushMatrix();
            glTranslatef(-79.0,-3.0,47.0);
            glRotatef(270, 1, 0, 0);
                glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);

            glTranslatef(0.0,27,0.0);
            glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);

            glTranslatef(0.0,27,0.0);
            glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);

            glTranslatef(0.0,31.75,0.0);
            glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,30,40,40);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-80.5,25.0,-46.0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,96.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,96,40,40);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(18.45,-3.2,47.0);
        glRotatef(270, 1, 0, 0);
            glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,47.2,40,40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(18.45,-3.1,21.0);
        glRotatef(270, 1, 0, 0);
            glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,47.2,40,40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(18.45,-3.1,-6.0);
        glRotatef(270, 1, 0, 0);
            glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,47.2,40,40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(18.45,-3.25,-46.65);
        glRotatef(270, 1, 0, 0);
            glPushMatrix();
                    glTranslatef(0.0,0.0,0.19);
                    gluDisk(gluNewQuadric(), 0, 1.5, 25, 25);
                glPopMatrix();
            gluCylinder(gluNewQuadric(),1.5,1.5,0.2,40,40);
            gluCylinder(gluNewQuadric(),0.8,0.8,47.2,40,40);
    glPopMatrix();
}

void top(){

    glPushMatrix();
        glTranslatef(-80,26.5,48);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();

        glColor3f(0,0.3,0);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();


    //Segunda leva
    glPushMatrix();

        glTranslatef(-64.5,26.5,48);
        glRotatef(8,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();

    //Terceira Leva
    glPushMatrix();
        glTranslatef(-49,28.7,48);
        glRotatef(14,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();

    //Quarta leva
    glPushMatrix();
        glTranslatef(-33.5,32.6,48);
        glRotatef(20.5,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();

    //Quinta leva
    glPushMatrix();
        glTranslatef(-19.1,38,48);
        glRotatef(14.8,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();


    //Sexta leva
    //Quinta leva
    glPushMatrix();
        glTranslatef(-4,42,48);
        glRotatef(6.3,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();

//Setima leva
    glPushMatrix();
        glTranslatef(11.7,43.7,48);
        glRotatef(-2.5,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();

    //Oitava leva
    glPushMatrix();
        glTranslatef(27.5,43,48);
        glRotatef(-11.35,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();


    //Nona leva
    glPushMatrix();
        glTranslatef(43,39.85,48);
        glRotatef(-19.8,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();

    //Décima leva
    glPushMatrix();
        glTranslatef(57.9,34.45,48);
        glRotatef(-24,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(82,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,16,40,40);
        glPopMatrix();
    glPopMatrix();

    //Décima Primeira leva
    glPushMatrix();
        glTranslatef(72.4,27.9,48);
        glRotatef(-11,0,0,1);

        glColor3f(0.6,0.6,0.6);
        glPushMatrix();
            glTranslatef(8,2,-48.5);
            glScalef(73,1,530);
            glutSolidCube(0.2);
        glPopMatrix();
        glColor3f(0,0.3,0);

        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10.0);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();

        glTranslatef(0,0,-13.5);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();

        glTranslatef(0,0,-12);
        glPushMatrix();
            glRotatef(90,0,1,0);
            gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPushMatrix();
                glTranslatef(0.0,0.0,10);
                gluDisk(gluNewQuadric(), 0,0.8, 40, 40);
            glPopMatrix();
            gluCylinder(gluNewQuadric(),0.8,0.8,10,40,40);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-77,27.8,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-65,27.8,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-65,27.8,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-49,30,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-33,34,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-20,38.9,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,43.1,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,44.9,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glTranslatef(26,44.3,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(43,41.2,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(58,35.7,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(70,30.5,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(80,27.7,0);
        glScalef(1,1,980);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.5,8,0);
        glScalef(1,1,960);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
/*
    glPushMatrix();
    glTranslatef(50.4,9,-6);
    glRotatef(90,0,1,0);
        glScalef(1,1,630);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50.4,9,21);
    glRotatef(90,0,1,0);
        glScalef(1,1,630);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(47,9,-25.6);
    glRotatef(90,0,1,0);
        glScalef(1,1,560);
        glPushMatrix();
            glScalef(0.1,1,0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90,0,0,1);
            glScalef(0.1,1,0.1);
            glTranslatef(5,0,0);
            glutSolidCube(1);
            glTranslatef(-10,0,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();*/
}
