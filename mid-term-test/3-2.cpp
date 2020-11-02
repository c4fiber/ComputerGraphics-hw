#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

#define NUM_OF_DRAWS 2

namespace A {
    static GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
    static GLint drawNum = 0;
    static GLfloat transPoint[2] = {0, 0};
    static GLfloat rotatePoint[2] = {0, 0};

    void changeColor() {
        for (int i = 0; i < 3; i++) {
            color[i] = (float)(rand() % 255) / 255.0f;
        }
    }

    void draw() {
        switch (drawNum) {
        case 0:
            glutWireTeapot(0.5);
            break;
        case 1:
            glutWireTorus(0.2, 0.5, 10, 50);
            break;
        }
    }
    void translate(GLfloat x, GLfloat y, GLfloat z) {
        transPoint[0] += x;
        transPoint[1] += y;
        glTranslatef(transPoint[0], transPoint[1], 0.0f);
    }
    void rotate(GLfloat angleX, GLfloat angleY) {
        glRotatef(angleX, 0.0f, 1.0f, 0.0f); // 가로 회전
        glRotatef(angleY, 1.0f, 0.0f, 0.0f); // 세로 회전
    }
}
namespace B {
    static GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
    static GLint drawNum = 0;

    void changeColor() {
        for (int i = 0; i < 3; i++) {
            color[i] = (float)(rand() % 255) / 255.0f;
        }
    }

    void draw() {
        switch (drawNum) {
        case 0:
            glutWireSphere(0.2, 10, 50);
            break;
        case 1:
            glutWireCone(0.2, 1.0, 10, 50);
            break;
        }
    }
}


// function when mouse Left click
void myMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x < 400) {
            A::changeColor();
            A::drawNum = (A::drawNum + 1) % NUM_OF_DRAWS;
        }
        else {
            B::changeColor();
            B::drawNum = (B::drawNum + 1) % NUM_OF_DRAWS;
        }
    }
    glutPostRedisplay();
}

void ReshapeGL(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Viewport A
    glViewport(0, 0, 400, 600); // GLUT좌표, 좌하단 원점기준
    glColor3f(A::color[0], A::color[1], A::color[2]);
    A::draw();

    // Viewport B
    glViewport(400, 0, 400, 600);
    glColor3f(B::color[0], B::color[1], B::color[2]);
    B::draw();


    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glRotatef(30, 1.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("신병철-201611815");

    glutMouseFunc(myMouse);

    glutDisplayFunc(display);
    glutReshapeFunc(ReshapeGL);
    init();
    glutMainLoop();
}