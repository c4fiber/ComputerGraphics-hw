#include <GL/glut.h>

GLvoid drawScene(GLvoid) {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //background color
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ractangle color
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush(); // ȭ�鿡 ����ϱ�, glFinish()�� Ȯ����

}

int main(int argc, char* argv[])
{
	// �ʱ�ȭ �Լ��� 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100); // ������ ���� ��ġ
	glutInitWindowSize(250, 250); // ������ ũ��
	glutCreateWindow("�л��̸�"); // ������ �̸����� �� ����

	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop();

	return 0;
}
