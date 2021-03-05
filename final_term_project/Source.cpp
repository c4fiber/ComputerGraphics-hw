#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

#define NUM_OF_DRAWS 4

static GLfloat color[3] = { 0.0f, 0.0f, 0.0f };
static GLint initX = 0, initY = 0;
static GLint moveX = 0, moveY = 0;


// function when mouse Left click
void myMouse(int button, int state, int x, int y) {


    glutPostRedisplay();
}


void myMotion(int x, int y) {

    glutPostRedisplay();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glutWireTorus(0.2, 0.5, 10, 50);


    glTranslatef(0.0f, 0.0f, -0.1f);



    
    


    glFlush(); // 화면에 출력하기 // glFinish() 사용 가능
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    GLfloat WidthFactor = (GLfloat)w / (GLfloat)600;
    GLfloat HeightFactor = (GLfloat)h / (GLfloat)800;

    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    //glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
    //    -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
    ///glViewport(100, 100, 200, 200); // GLUT좌표, 좌하단 원점기준

    glMatrixMode(GL_MODELVIEW);

}
// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(600, 800);
    glutCreateWindow("신병철-201611815");

    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
}