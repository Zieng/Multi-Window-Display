#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string.h>  // for memcmp()
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glut/glut.h>
#include <OpenGL/GL.h>

//#include "MyWindow.h"

using namespace std;

float fTranslate;
float fRotate;
float fScale     = 1.0f;	// set inital scale value to 1.0f


bool bAnim = false;
bool bWire = true;


float eye[] = {0, 0, 1};
float center[] = {0, 0, 0};
float tx=0,ty=0,tz=0;   // for translete the teapot
float tr;

int window1 = 0 , window2= 0, window3=0, window4=0,bigWindow=0;

void Draw_Scene()
{
    glPushMatrix();
    glTranslatef(tx+0, ty+0, tz+0);
    glRotatef(90, 1, 0, 0);
    glRotatef(tr, 0, 1, 0);
//    glutSolidCube(2.0);
    glutSolidTeapot(2.0f);
    glPopMatrix();


}

void updateView(int width, int height)
{
    glViewport(0,0,width,height);						// Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix

    glOrtho(-3 ,3, -3, 3,-100,100);

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
}


void bigWindow_reshape(int width,int height)
{
    glutSetWindow(bigWindow);

    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix

    glOrtho(-3 ,3, -3, 3,-100,100);

    glMatrixMode(GL_MODELVIEW);
}

void bigWindow_display()
{
    glutSetWindow(bigWindow);

    float myEye[]={eye[0],eye[1],eye[2]};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(myEye[0], myEye[1], myEye[2],
              center[0], center[1], center[2],
              0, 1, 0);

    if (bWire) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 1);
    Draw_Scene();						// Draw Scene

    if (bAnim) fRotate    += 0.5f;
    glutSwapBuffers();
}

void window1_reshape(int width, int height)
{
    glutSetWindow(window1);
    cout<<"Window1::width="<<width<<",height="<<height<<endl;

//    glViewport(width/2,-height/2,width,height);						// Reset The Current Viewport
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix


//    glOrtho(-3 ,3, -3, 3,-100,100);
    glOrtho(-3,0,0,3,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

void window1_display()
{
    glutSetWindow(window1);

    float myEye[]={eye[0]-1,eye[1]-1,eye[2]};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(eye[0], eye[1], eye[2],
              center[0], center[1], center[2],
              0, 1, 0);

    if (bWire) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }



    glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
    glRotatef(-90, 1, 0, 0);
    Draw_Scene();						// Draw Scene

    if (bAnim) fRotate    += 0.5f;

    glutSwapBuffers();
}

void window2_reshape(int width, int height)
{
    glutSetWindow(window2);
    cout<<"Window2::width="<<width<<",height="<<height<<endl;

//    glViewport(-width/2,-height/2,width,height);						// Reset The Current Viewport
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix

//    glOrtho(-3 ,3, -3, 3,-100,100);
    glOrtho(0,3,0,3,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

void window2_display()
{
    glutSetWindow(window2);

    float myEye[]={eye[0]-1,eye[1]+1,eye[2]};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(eye[0],eye[1], eye[2],
              center[0], center[1], center[2],
              0, 1, 0);

    if (bWire) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }



    glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 1);
    Draw_Scene();						// Draw Scene

    if (bAnim) fRotate    += 0.5f;
    glutSwapBuffers();
}

void window3_reshape(int width, int height)
{
    glutSetWindow(window3);
    cout<<"Window3::width="<<width<<",height="<<height<<endl;

//    glViewport(width/2,height/2,width,height);						// Reset The Current Viewport
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix

//    glOrtho(-3 ,3, -3, 3,-100,100);
    glOrtho(-3,0,-3,0,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

void window3_display()
{
    glutSetWindow(window3);

    float myEye[]={eye[0]+1,eye[1]-1,eye[2]};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(eye[0], eye[1], eye[2],
              center[0], center[1], center[2],
              0, 1, 0);

    if (bWire) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }


    glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
    glRotatef(-90, 1, 0, 0);
    Draw_Scene();						// Draw Scene

    if (bAnim) fRotate    += 0.5f;

    glutSwapBuffers();
}

void window4_reshape(int width, int height)
{
    glutSetWindow(window4);
    cout<<"Window4::width="<<width<<",height="<<height<<endl;

//    glViewport(-width/2,height/2,width,height);						// Reset The Current Viewport
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix

//    glOrtho(-3 ,3, -3, 3,-100,100);
    glOrtho(0,3,-3,0,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

void window4_display()
{
    glutSetWindow(window4);

    float myEye[]={eye[0]+1,eye[1]+1,eye[2]};


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(eye[0], eye[1], eye[2],
              center[0], center[1], center[2],
              0, 1, 0);

    if (bWire) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }


    glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
    glRotatef(-90, 1, 0, 0);
    Draw_Scene();						// Draw Scene

    if (bAnim) fRotate    += 0.5f;

    glutSwapBuffers();

}

void key(unsigned char k, int x, int y)
{
    switch(k)
    {
        case 27:
        case 'q': {exit(0); break; }
        case ' ': {bAnim = !bAnim; break;}
        case 'o': {bWire = !bWire; break;}

        case 'a': {//todo, hint: eye[] and center[] are the keys to solve the problems
            // printf("aaa\n");
            eye[0]-=1;
            break;
        }
        case 'd': {//todo
            eye[0]+=1;
            break;
        }
        case 'w': {//todo
            eye[1]+=1;
            break;
        }
        case 's': {//todo
            eye[1]-=1;
            break;
        }
        case 'z': {//todo
            eye[2]+=1;
            printf("eye.z=%f\n", eye[2]);
            break;
        }
        case 'c': {//todo
            eye[2]-=1;
            printf("eye.z=%f\n", eye[2]);
            break;
        }

            //²èºøÏà¹Ø²Ù×÷
        case 'l': {//todo, hint:use the ARRAY that you defined, and notice the teapot can NOT be moved out the range of the table.
            tx+=1;
            break;
        }
        case 'j': {//todo
            tx-=1;
            break;
        }
        case 'i': {//todo
            ty+=1;
            break;
        }
        case 'k': {//todo
            ty-=1;
            break;
        }
        case 'e': {//todo
            tr+=1;
            break;
        }
    }
}

void idle()
{
    window1_display();
    window2_display();
    window3_display();
    window4_display();
    bigWindow_display();

    glutReshapeFunc(bigWindow_reshape);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(400, 400);

    // glEnable(GL_DEPTH_TEST);

    bigWindow = glutCreateWindow("Big Window");
    // glutInitWindowSize(800,800);
    glutReshapeWindow(800,800);
    glutPositionWindow(900,100);
    glutDisplayFunc(bigWindow_display);
    glutReshapeFunc(bigWindow_reshape);
    glutKeyboardFunc(key);

    // create the first window
    window1 = glutCreateWindow("window1");
    glutPositionWindow(100,100);
    glutDisplayFunc(window1_display);
    glutReshapeFunc(window1_reshape);
    glutKeyboardFunc(key);


    //create the second  window
    window2 = glutCreateWindow("window2");
    glutPositionWindow(500,100);
    glutDisplayFunc(window2_display);
    glutReshapeFunc(window2_reshape);
    glutKeyboardFunc(key);

    window3 = glutCreateWindow("window3");
    glutPositionWindow(100,520);
    glutDisplayFunc(window3_display);
    glutReshapeFunc(window3_reshape);
    glutKeyboardFunc(key);

    window4 = glutCreateWindow("window4");
    glutPositionWindow(500,520);
    // window4 = glutCreateSubWindow(window1,400,400,400,400);
    glutDisplayFunc(window4_display);
    glutReshapeFunc(window4_reshape);
    glutKeyboardFunc(key);


    glutIdleFunc(idle);


    glutMainLoop();
}

