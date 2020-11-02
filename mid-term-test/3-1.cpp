#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

#define NUM_OF_DRAWS 2

namespace A {
    static GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
    static GLint drawNum = 0;
    static bool isMove = false;
    static bool isRotate = false;

    void init() {
        isMove = false;
        isRotate = false;
    }

    void changeColor() {
        for (int i = 0; i < 3; i++) {
            color[i] = (float)(rand() % 255) / 255.0f;
        }
    }

    void draw() {
        glPushMatrix();
        switch (drawNum) {
        case 0:
            glutWireTeapot(0.5);
            break;
        case 1:
            glutWireTorus(0.2, 0.5, 10, 50);
            break;
        }
        glPopMatrix();
    }
}
namespace B {
    static GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
    static GLint drawNum = 0;
    static bool isMove = false;
    static bool isRotate = false;

    void init() {
        isMove = false;
        isRotate = false;
    }

    void changeColor() {
        for (int i = 0; i < 3; i++) {
            color[i] = (float)(rand() % 255) / 255.0f;
        }
    }

    void draw() {
        glPushMatrix();
        switch (drawNum) {
        case 0:
            glutWireSphere(0.2, 10, 50);
            break;
        case 1:
            glutWireCone(0.2, 1.0, 10, 50);
            break;
        }
        glPopMatrix();
    }
}

static GLint initX = 0, initY = 0;
static GLint moveX = 0, moveY = 0;


void ReshapeGL(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Viewport <A>
    glViewport(0, 0, 400, 600); // GLUT좌표, 좌하단 원점기준
    glColor3f(A::color[0], A::color[1], A::color[2]);
    A::draw();

    // Viewport <B>
    glViewport(400, 0, 400, 600);
    glColor3f(B::color[0], B::color[1], B::color[2]);
    B::draw();
    gluLookAt(0, 2.0, 3.0, 0, 0, 0, 0, 1, 0);

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
    glRotatef(30, 1.0f, 1.0f, 0.0f);
}
// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("신병철-201611815");

    glutDisplayFunc(display);
    glutReshapeFunc(ReshapeGL);
    init();
    glutMainLoop();
}