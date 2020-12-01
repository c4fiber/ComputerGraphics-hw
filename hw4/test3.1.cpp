// answer2 베지어 곡선을 이용해서 surface 유도
// 

#include <stdlib.h>
#include <GL/glut.h>

class Point {
public:
    Point(float x=0, float y=0, float z=0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float* getValues() {
        float arr[3] = { this->x, this->y, this->z };
        return arr;
    }

private:
    float x, y, z;
};



Point wholePoints[4][4] = {
{
    Point(-0.9, 0.8, -0.8),
    Point(-0.6, 1.5, -1.4),
    Point(-0.4, 0.4, 1.0),
    Point(0.7, 0.5, -0.4)
},
{
    Point(-0.8, 0.6, -0.4),
    Point(),
    Point(),
    Point(),
},
{
    Point(-0.6, 0.2, 0.4),
    Point(),
    Point(),
    Point(),
},
{
    Point(-0.5, -0.4, 0.9),
    Point(),
    Point(),
    Point()
} };

void drawCurve(GLfloat points[]) {
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, points);
    glEnable(GL_MAP1_VERTEX_3);

    float i;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (i = 0.0; i <= 1.0; i = i + 0.02)
        glEvalCoord1f(i);
    glEnd();
}

void reshape(int w, int h)
{
    float ratio = 1.5;
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
    glutCreateWindow("201611815");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();

    return 0;
}