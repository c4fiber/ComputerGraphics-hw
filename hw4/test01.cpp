#include <stdlib.h>
#include <GL/glut.h>


GLfloat p[4][4][3] = {
{
    {-0.9, 0.8, -0.8},
    {-0.6, 1.5, -1.4},
    {-0.4, 0.4, 1.0},
    {0.7, 0.5, -0.4}
},{
    {-0.8, 0.6, 0.4},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}
},{
    {-0.6, 0.2, -0.4},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}
},{
    {-0.5, -0.4, 0.9},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}
}
};

static bool isRotate = true;
static GLint initX = 0, initY = 0;
static GLint moveX = 0, moveY = 0;
void myMouse(int button, int state, int x, int y) {
    // 이동 or 회전 flag값 초기화
    isRotate = false;

    initX = x;
    initY = y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isRotate = true;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

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

void reshapeGL(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}
void display() {
    int i, j;

    glClear(GL_COLOR_BUFFER_BIT);

    // color base line
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(1.0, 0.0, 0.0); glVertex3f(-1.0, 0.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.0, 1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.0, 0.0, 1.0); glVertex3f(0.0, 0.0, -1.0);
    glEnd();
    glFlush();

    // bezier curve (4point + draw curve)
    for (int i = 0; i < 4; i++) {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINE_STRIP);
        for (i = 0; i <= 30; i++) {
            glEvalCoord1f((GLfloat)i / 30.0);
        }
        glEnd();

        /* display points as dot */
        glPointSize(5.0);
        glColor3f(1.0, 1.0, 0.0);

        // line 00 to 03
        glBegin(GL_POINTS);
        for (i = 0; i < 4; i++) {
            glVertex3fv(p[0][i]);
        }
        glEnd();

        // line 00 to 30
        glBegin(GL_POINTS);
        for (i = 0; i < 4; i++) {
            glVertex3fv(p[i][0]);
        }
        glEnd();

        // rotate
        if (isRotate) {
            glRotatef(moveX, 0.0f, 1.0f, 0.0f);
            glRotatef(moveY, 1.0f, 0.0f, 0.0f);
        }
    }
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glShadeModel(GL_FLAT);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, p[0][0]);
    glEnable(GL_MAP1_VERTEX_3);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glRotatef(30, 0, 1, 0);
    //glRotatef(30, 1, 0, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("201611815");

    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);

    glutDisplayFunc(display);
    glutReshapeFunc(reshapeGL);
    init();
    glutMainLoop();

    return 0;
}