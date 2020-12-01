/*  polyint.cpp
 *  This program demonstrates using polynomial interpretation to draw a curve
 *  using Lagrange's method.
 */
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;

GLfloat ctrlpoints[4][3] = {
    { -4.0, -4.0, 0.0},
    { -3.0, 4.0, 0.0},
    {-2.0, -4.0, 0.0},
    {0.0, 4.0, 0.0} };

GLfloat ctrlpointsB[4][3] = {
    {0.0, 4.0, 0.0},
    {1.0, -2.0, 0.0},
    {2.0, 1.0, 0.0},
    {3.0, -1.0, 0.0}  };

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}


//polynomial interpretation for N points
float polyint(float  points[][3], float x, int N)
{
    float y;

    float num = 1.0, den = 1.0;
    float sum = 0.0;

    for (int i = 0; i < N; ++i) {
        num = den = 1.0;
        for (int j = 0; j < N; ++j) {
            if (j == i) continue;

            num = num * (x - points[j][0]);		 	//x - xj
        }
        for (int j = 0; j < N; ++j) {
            if (j == i) continue;
            den = den * (points[i][0] - points[j][0]);	//xi - xj
        }
        sum += num / den * points[i][1];
    }
    y = sum;

    return y;
}

void display(void)
{
    int i;
    float x, y;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (i = -40; i <= 40; i++) {
        x = (float)i / 10.0;
        y = polyint(ctrlpoints, x, 4);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (i = -40; i <= 40; i++) {
        x = (float)i / 10.0;
        y = polyint(ctrlpointsB, x, 4);
        glVertex2f(x, y);
    }
    glEnd();


    /* The following code displays the control points as dots. */
    glPointSize(5.0);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (i = 0; i < 4; i++) {
        glVertex3fv(ctrlpoints[i]);
        glVertex3fv(ctrlpointsB[i]);
    }
    glEnd();
    glFlush();
}

void reshape(int w, int h)
{
    float ratio = 7.0;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-ratio, ratio,
            -ratio * (GLfloat)h / (GLfloat)w,
            ratio * (GLfloat)h / (GLfloat)w,
            -ratio, ratio);
    else
        glOrtho(-ratio * (GLfloat)w / (GLfloat)h,
            ratio * (GLfloat)w / (GLfloat)h,
            -ratio, ratio,
            -ratio, ratio);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("201611815");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}