#include <GL/glut.h>

GLvoid drawScene(GLvoid) {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // (0,0,255)
	glClear(GL_COLOR_BUFFER_BIT); // �÷����� �����
	glFlush(); // ȭ�鿡 ����ϱ�(�����ڵ� ����) �����߻� -> ��� â ũ������ or glFinish()�� ���� �� �ذ�
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // Init
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100); // ������ ���� ��ġ
	glutInitWindowSize(250, 250); // ������ ũ��
	glutCreateWindow("�л��̸�"); // ������ �̸����� �� ����

	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutMainLoop();

	return 0;
}
