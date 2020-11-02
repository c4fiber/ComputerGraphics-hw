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

// function when mouse Left click
void myMouse(int button, int state, int x, int y) {
    // �̵� or ȸ�� flag�� �ʱ�ȭ
    A::init();
    B::init();
    std::cout << "func mouse" << std::endl;

    initX = x;
    initY = y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x < 400) {
            A::isMove = true;
            A::changeColor();
            A::drawNum = (A::drawNum + 1) % NUM_OF_DRAWS;
        }
        else {
            B::isMove = true;
            B::changeColor();
            B::drawNum = (B::drawNum + 1) % NUM_OF_DRAWS;
        }

    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        if (x < 400) {
            A::isRotate = true;
        }
        else {
            B::isRotate = true;
        }

    }
    glutPostRedisplay();
}
void myMotion(int x, int y) {
    // �ʱ���ġ�� �������� ����� ���콺 �̵��Ÿ����
    moveX = x - initX;
    moveY = y - initY;

    initX = x;
    initY = y;

    // std::cout << moveX << ", " << moveY << std::endl;
    glutPostRedisplay();
}

void ReshapeGL(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Viewport <A>
    glViewport(0, 0, 400, 600); // GLUT��ǥ, ���ϴ� ��������
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glColor3f(A::color[0], A::color[1], A::color[2]);
    A::draw();
    if (A::isMove) {
        glTranslatef((float)moveX * 0.001f, -(float)moveY * 0.001f, 0.0f);
    }
    else if (A::isRotate) {
        glRotatef(moveX, 0.0f, 1.0f, 0.0f);
        glRotatef(moveY, 1.0f, 0.0f, 0.0f);

    }

    // Viewport <B>
    glViewport(400, 0, 400, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glColor3f(B::color[0], B::color[1], B::color[2]);
    B::draw();
    if (B::isMove) {
        glTranslatef((float)moveX * 0.001f, -(float)moveY * 0.001f, 0.0f);
        std::cout << "WTF" << std::endl;
    }
    else if (B::isRotate) {
        glRotatef(moveX, 0.0f, 1.0f, 0.0f);
        glRotatef(moveY, 1.0f, 0.0f, 0.0f);
    }
   
    glFlush();
}

void init() {
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f); // �������� 'blue' �� ����

}
// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("�ź�ö-201611815");

    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);

    glutDisplayFunc(display);
    glutReshapeFunc(ReshapeGL);
    init();
    glutMainLoop();
}