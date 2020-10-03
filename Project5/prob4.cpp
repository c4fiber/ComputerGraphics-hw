#include <GL/glut.h>

GLvoid drawScene(GLvoid) { // 주전자 3차원 물체
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기

	glFinish();

	glViewport(0, 0, 300, 300); // 윈도우 안 그림 위치
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f); // 그리기 색을 'green' 으로 지정
	glutWireTeapot(0.5);

	glFlush(); // 화면에 출력하기 // glFinish() 사용 가능

}

int main(int argc, char* argv[])
{
	// 초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100); // 윈도우 시작 위치
	glutInitWindowSize(350, 350); // 윈도우 크기
	glutCreateWindow("학생이름"); // 윈도우 이름지정 및 생성

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutMainLoop();

	return 0;
}
