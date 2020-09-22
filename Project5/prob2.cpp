#include <GL/glut.h>

GLvoid drawScene(GLvoid) {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // (0,0,255)
	glClear(GL_COLOR_BUFFER_BIT); // 컬러버퍼 지우기
	glFlush(); // 화면에 출력하기(버퍼코드 실행) 오류발생 -> 결과 창 크기조절 or glFinish()로 변경 후 해결
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // Init
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100); // 윈도우 시작 위치
	glutInitWindowSize(250, 250); // 윈도우 크기
	glutCreateWindow("학생이름"); // 윈도우 이름지정 및 생성

	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutMainLoop();

	return 0;
}
