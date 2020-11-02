#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

#define NUM_OF_DRAWS 2

namespace A {
    static GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
    static GLint drawNum = 0;
    static bool isMove = false;
    static bool isRotate = false;
    static GLfloat transPoint[2] = { 0, 0 };
    static GLfloat rotatePoint[2] = { 0, 0 };

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
        switch (drawNum) {
        case 0:
            glutWireTeapot(0.5);
            break;
        case 1:
            glutWireTorus(0.2, 0.5, 10, 50);
            break;
        }
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

static GLint initX = 0, initY = 0;
static GLint moveX = 0, moveY = 0;
GLfloat matrixA[16] = {0.0, };
GLfloat matrixB[16] = {0.0, };

// function when mouse Left click
void myMouse(int button, int state, int x, int y) {
    // 이동 or 회전 flag값 초기화
    A::init();
    B::init();

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
            
            
        }

    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        if (x < 400) {
            A::isRotate = true;
        }
        else {
            B::isRotate = true;
            B::drawNum = (B::drawNum + 1) % NUM_OF_DRAWS;
            
        }
    }
    glutPostRedisplay();
}
void myMotion(int x, int y) {
    // 초기위치를 기준으로 상대적 마우스 이동거리계산
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
    glViewport(0, 0, 400, 600); // GLUT좌표, 좌하단 원점기준
    glLoadMatrixf(matrixA);
    
    glColor3f(A::color[0], A::color[1], A::color[2]);
    if (A::isMove) {
        glTranslatef((float)moveX * 0.001f, -(float)moveY * 0.001f, 0.0f);
    }
    else if (A::isRotate) {
        glRotatef(moveX, 0.0f, 1.0f, 0.0f); // 가로 회전
        glRotatef(moveY, 1.0f, 0.0f, 0.0f); // 세로 회전  
    }
    A::draw();
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixA);

    // Viewport <B>
    glViewport(400, 0, 400, 600);
    glLoadMatrixf(matrixB);

    glColor3f(B::color[0], B::color[1], B::color[2]);
    if (B::isMove) {
        glTranslatef((float)moveX * 0.001f, -(float)moveY * 0.001f, 0.0f);
    }
    else if (B::isRotate) {
        glRotatef(moveX, 0.0f, 1.0f, 0.0f);
        glRotatef(moveY, 1.0f, 0.0f, 0.0f);
    }
    B::draw();
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixB);

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glRotatef(30, 1.0f, 1.0f, 0.0f);

   // glLoadIdentity();
   // glPushMatrix();
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixA);
    glGetFloatv(GL_MODELVIEW_MATRIX, matrixB);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("신병철-201611815");

    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);

    glutDisplayFunc(display);
    glutReshapeFunc(ReshapeGL);
    init();
    glutMainLoop();
}