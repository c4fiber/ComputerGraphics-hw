#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

#define NUM_OF_DRAWS 4

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기

    glutWireTeapot(0.5);
    glFlush(); // 화면에 출력하기 // glFinish() 사용 가능
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glViewport(100, 100, 200, 200); // GLUT좌표, 좌하단 원점기준


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
    init();
    glutMainLoop();
}