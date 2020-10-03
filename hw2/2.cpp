#include <stdlib.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void myWireSphere(GLfloat radius, int slices, int stacks) {
    glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glutWireSphere(radius, slices, stacks);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw a white grid "floor" for the tetrahedron to sit on.
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
        glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
        glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
    }
    glEnd();
    glFlush();

    // sphear part
    glPushMatrix();

    // Draw sun: a yellow sphere of radius 1 centered at the origin.
    glColor3f(1.0, 1.0, 0.0);
    myWireSphere(1.0, 15, 15);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.1, 0.39, 0.88, 1.0);
    glColor3f(1.0, 1.0, 1.0);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1.5, 1.5, 1, 40);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -3);
    glRotatef(50, 1, 0, 0);
    glRotatef(70, 0, 1, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("A Simple Tetrahedron");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}