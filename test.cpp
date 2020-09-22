#include <GL/glut.h>
void display1() {

    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd(); 
    glFinish();
}

GLvoid display2(GLvoid){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT); 
	glFlush(); 
}

GLvoid display3(GLvoid){
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //background color
	glClear(GL_COLOR_BUFFER_BIT); 

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ractangle color
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush(); // ȭ�鿡 ����ϱ� // ����� �̰� �ߵǳ� 2���� �ȵǴµ�

}

GLvoid display4(GLvoid) { // ������ 3���� ��ü
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // �������� 'blue' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	
	glViewport(0, 0, 300, 300); // ������ �� �׸� ��ġ
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // �׸��� ���� 'green' ���� ����
	glutWireTeapot(0.5);
	
	glFlush(); // ȭ�鿡 ����ϱ� // ����� �̰� �ߵǳ� 2���� �ȵǴµ�

}

int main(int argc, char* argv[])
{
	// �ʱ�ȭ �Լ��� 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100); // ������ ���� ��ġ
	glutInitWindowSize(350, 350); // ������ ũ��
	glutCreateWindow("�л��̸�"); // ������ �̸����� �� ����

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(display4); // ��� �Լ��� ����
	glutMainLoop();

	return 0;
}
