#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

#define NUM_OF_DRAWS 4

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�

    glutWireTeapot(0.5);
    glFlush(); // ȭ�鿡 ����ϱ� // glFinish() ��� ����
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
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

    glutDisplayFunc(display);
    init();
    glutMainLoop();
}