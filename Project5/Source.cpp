#include <GL/glut.h>
void display1() {

    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glEnd();  // 도형 그리기 끝
    glFinish();
}

GLvoid display2(GLvoid){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // (0,0,255)
	glClear(GL_COLOR_BUFFER_BIT); // 컬러버퍼 지우기
	glFlush(); // 화면에 출력하기(버퍼코드 실행) 오류발생 -> 결과 창 크기조절 or glFinish()로 변경 후 해결
}

GLvoid display3(GLvoid){
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); //background color
	glClear(GL_COLOR_BUFFER_BIT); 

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ractangle color
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush(); // 화면에 출력하기 // 웃긴게 이건 잘되네 2번은 안되는데

}

GLvoid display4(GLvoid) { // 주전자 3차원 물체
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	
	glViewport(0, 0, 300, 300); // 윈도우 안 그림 위치
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // 그리기 색을 'green' 으로 지정
	glutWireTeapot(0.5);
	
	glFlush(); // 화면에 출력하기 // 웃긴게 이건 잘되네 2번은 안되는데

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

	glutDisplayFunc(display4); // 출력 함수의 지정
	glutMainLoop();

	return 0;
}
