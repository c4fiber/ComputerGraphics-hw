#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

#define NUM_OF_DRAWS 4

static GLfloat color[3] = {0.0f, 0.0f, 0.0f};
static GLint initX = 0, initY = 0;
static GLint moveX = 0, moveY = 0;
static GLint drawNum = 0;
static bool isMove = false;

// function when mouse Left click
void myMouse(int button, int state, int x, int y) {
    // ������ rgb�� ���� �� color�� ����
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isMove = true;
        initX = x;
        initY = y;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        isMove = false;
        for (int i = 0; i < 3; i++) {
            color[i] = (float)(rand() % 255) / 255.0f;
        }
        drawNum = (drawNum + 1) % NUM_OF_DRAWS;
    }
    std::cout << "colors: " << color[0] << color[1] << color[2] << std::endl;

    glutPostRedisplay();
}
void myMotion(int x, int y) {
    // �ʱ���ġ�� �������� ����� ���콺 �̵��Ÿ����
    moveX = x - initX;
    moveY = y - initY;

    initX = x;
    initY = y;

    std::cout << moveX << ", " << moveY << std::endl;
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
    glColor4f(color[0], color[1], color[2], 0.0f); // ������ ������    
    
    // select draw
    switch (drawNum) {
    case 0:
        glutWireTeapot(0.5);
        break;
    case 1:
        glutWireTorus(0.2, 0.5, 10, 50);
        break;
    case 2:
        glutWireCone(0.5, 1.0, 10, 50);
        break;
    case 3:
        glutWireSphere(0.2, 10, 50);
        break;
    }

    if (isMove) {
        glTranslatef((float)moveX * 0.001f, -(float)moveY * 0.001f, 0.0f);
        std::cout << "good" << std::endl;
    }
    else {
        glRotatef(moveX, 0.0f, 1.0f, 0.0f);
        glRotatef(moveY, 1.0f, 0.0f, 0.0f);
    }


    // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glFlush(); // ȭ�鿡 ����ϱ� // glFinish() ��� ����
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // �������� 'blue' �� ����

    glViewport(100, 100, 200, 200); // GLUT��ǥ, ���ϴ� ��������


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
    init();
    glutMainLoop();
}