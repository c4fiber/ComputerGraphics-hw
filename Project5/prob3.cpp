#include <GL/glut.h>

GLvoid drawScene(GLvoid) {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //background color
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ractangle color
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush(); // 화면에 출력하기, glFinish()가 확실함

}

int main(int argc, char* argv[])
{
	// 초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100); // 윈도우 시작 위치
	glutInitWindowSize(250, 250); // 윈도우 크기
	glutCreateWindow("학생이름"); // 윈도우 이름지정 및 생성

	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutMainLoop();

	return 0;
}
