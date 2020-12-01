#include <stdlib.h>
#include <GL/glut.h>


GLfloat p[7][3] = {
    {-1.0, 0.2, 1.0},
    {-0.8, 1.0, -0.6},
    {-0.6, -0.3, 0.5},
    {-0.3, 0.2, -0.9},
    {0.1, 0.8, 0.9},
    {0.4, 0.4, -0.3},
    {0.6, -0.3, -0.2},
};

void drawCurve(GLfloat points[]) {
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, points);
    glEnable(GL_MAP1_VERTEX_3);

    float i;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (i = 0.0; i <= 1.0; i=i+0.02)
        glEvalCoord1f(i);
    glEnd();
}

void reshape(int w, int h)
{
    float ratio = 1.2;
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
void display() {
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    drawCurve(p[0]);
    drawCurve(p[3]);

    /* The following code displays the control points as dots. */
    glPointSize(5.0);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (i = 0; i < 7; i++)
        glVertex3fv(&p[i][0]);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("½Åº´Ã¶_201611815");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();

    return 0;
}