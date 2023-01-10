#include <windows.h>
#include<iostream>
using namespace std;
#include <GL/gl.h>
#include<GL/glu.h>
#include <GL/freeglut.h>
#include <cmath>
#include<stdlib.h>
#include<mmsystem.h>
#define PI 3.1415927

GLfloat  rotate1=90,rotate2=180,rotate3=30,moveY=-0.65;
GLdouble base=0.25 ,moveX=-4.0;
GLdouble height=0.75;
GLint slices =50;
GLint stacks =50;
GLdouble radius=1, radius2=0.4,radius3=0.1;


void timer(int x) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    rotate2 += 1;
    rotate3 += 0.5;
    moveY+=-0.01;
    if(moveY<-3){
        moveY=-0.65;
    }
    if (moveX < 4) {
        moveX += 0.01;
        return;
    } else {
        moveX=-4;
    }
}
void mouse(int key, int state, int x, int y){ //By clicking right
    switch (key)
    {
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                glutTimerFunc(0,timer,0);
            }
            break;

        default:
            break;
    }
}

//Stars
void points(){
    glColor3f(1,1,1);
    glPointSize(2);
    glBegin ( GL_POINTS );

    for(int s=-10; s<=10; s++){
        for(int s2=-10; s2<=10; s2++){
            glVertex3f(s, s2, -20.0);
        }
    }
    glEnd ();
}

void sphere(){ //Main sphere
    glPushMatrix();
    glTranslatef(0,0,-12);
    glColor3f(0.5,0.9,0.11);
    glRotatef(90,1.0,0.0,0.0);
    glRotatef(rotate3, 0.0, 0.0, 1.0);
    glutSolidSphere(radius,25,25);
    glPopMatrix();
}
void sphere2(){
    glPushMatrix();
    glTranslatef(1.5,0,-12);
     glColor3f(0.8,0.13,0.6);
    glRotatef(rotate2, 0, 1, 0.0);
    glTranslatef(-3.5,0, 1);
    glutSolidSphere(radius2,25,25);
    glPopMatrix();

}
void sphere3(){
    glPushMatrix();


    glTranslatef(0.5,0,-12);
    glColor3f(0.3,0.2,0.7);
    glRotatef(rotate3, 0, 1, 0.0);
    glTranslatef(-3.5,0.5, 1);

    glutSolidSphere(radius3,25,25);
    glPopMatrix();

}

void cylinder(GLfloat rad, GLfloat HEIGHT){
    GLfloat x;
    GLfloat y;
    GLfloat angle;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = rad * cos(angle);
        y = rad * sin(angle);
        glVertex3f(x, y , HEIGHT);
        glVertex3f(x, y , 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(rad, 0.0, HEIGHT);
    glVertex3f(rad, 0.0, 0.0);
    glEnd();

    //Draw the circle on top of cylinder
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = rad * cos(angle);
        y = rad * sin(angle);
        glVertex3f(x, y , HEIGHT);
        angle = angle + angle_stepsize;
    }
    glVertex3f(rad, 0.0, HEIGHT);
    glEnd();
}
void pyramid(){
    glPushMatrix();
    glTranslatef(0, moveY, -6.5);
    glRotatef(rotate3, 0.0, 1.0, 0.0);
    glRotatef(180,0.0,0.0,1.0);
    glScalef(0.1,0.1,0.1);

    glBegin(GL_TRIANGLES);

    // New Triangle - Front
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    // New Triangle - Right
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);

    // New Triangle - Back
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);

    // New Triangle - left
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,1.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);

    // New Triangle - Bottom 1
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,1.0f);

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);

    // New Triangle - Bottom 2
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);      // Note: we're starting from the last point
    // of the previous triangle.

    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,-1.0f);

    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1.0f,-1.0f,1.0f);

    glEnd();
    glPopMatrix();
}

void rocket(){
    glPushMatrix();
    glTranslatef(moveX, 1, -4.5);
    glScalef(0.2,0.2,0.5);

    glPushMatrix();
    glTranslatef(0.0,1.0,-4.5);
    // Red color used to draw.
    glColor3f(0.8, 0.2, 0.1);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(rotate1, 1.0, 0.0, 0.0);
    // rotation about Y axis
    glRotatef(90,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(rotate3, 0.0, 0.0, 1.0);
    // built-in (glut library) function , draw you a Cone.
    glutSolidCone(base,height,slices,stacks);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.1, 0.2, 0.9);
    glTranslatef(-1,1,-4.5);
    glRotatef(90, 0.0, 1.0, 0.0);
    cylinder(0.25,1);
    glPopMatrix();
    glPopMatrix();
}



void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;
    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;

    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}
//reshape
void reshape (int w, int h)
{
    if (w==0||h==0)return;
    glViewport(0,0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    perspectiveGL(39,(GLdouble)w/(GLdouble)h,0.6,21);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,w,h);
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    sphere();

    sphere2();
    sphere3();
    rocket();
    pyramid();
    points();

    glutSwapBuffers();
}
void init(){
    const GLfloat light_ambient[]  = { 0.0, 0.0, 0.0, 1.0 };
    const GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    const GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    const GLfloat light_position[] = { 2.0, 5.0, 5.0, 0.0 };

    const GLfloat mat_ambient[]    = { 0.7, 0.7, 0.7, 1.0 };
    const GLfloat mat_diffuse[]    = { 0.8, 0.8, 0.8, 1.0 };
    const GLfloat mat_specular[]   = { 1.0, 1.0, 1.0, 1.0 };
    const GLfloat high_shininess[] = { 100.0};

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

//main
int main (int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutCreateWindow("solar system' 19101185");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    sndPlaySound("PM_SFA2_2.wav",SND_ASYNC |SND_LOOP);
    init();

    glutMainLoop();
    return 0;
}
