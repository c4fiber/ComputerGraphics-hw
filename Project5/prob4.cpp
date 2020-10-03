#include <GL/glut.h>

GLvoid drawScene(GLvoid) { // ������ 3���� ��ü
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�

	glFinish();

	glViewport(0, 0, 300, 300); // ������ �� �׸� ��ġ
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f); // �׸��� ���� 'green' ���� ����
	glutWireTeapot(0.5);

	glFlush(); // ȭ�鿡 ����ϱ� // glFinish() ��� ����

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

	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop();

	return 0;
}
