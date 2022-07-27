#include <Windows.h>
#include <vector>
#include <fstream>
#include <glut.h> /*��� Linux � Windows*/ 

using namespace std;

/*����� �������*/
void reshape(int w, int h);
void display();
int main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);/*������������� glut*/
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);/*�������� ������� ����������� � ������������������� ����*/

	glutInitWindowSize(800, 600);/*����*/
	glutInitWindowPosition(100, 150);/*�������*/
	glutCreateWindow("LR2_2");/*��������*/
	glutReshapeFunc(reshape);/*������ �������*/
	glutDisplayFunc(display);/*������ �������*/
	glutMainLoop();/*����*/
	return 0;
}
void reshape(int w, int h)
{
	
	glViewport(0, 0, w, h);/*�����������*/
	glMatrixMode(GL_PROJECTION);/*����� �������, ��� ������� ����� ������������ ������*/
	glLoadIdentity();/*- �������� ������� ������� �� ���������*/
	gluOrtho2D(0, 200, 0, 100);/*������������� ������� �2D�������*/
	glMatrixMode(GL_MODELVIEW);/*����� �������, ��� ������� ����� ������������ ������*/
	glLoadIdentity();/*- �������� ������� ������� �� ���������*/
}
void display()
{
	glClearColor(1, 1, 1, 0);/*RGBA ���� ������*/
	glClear(GL_COLOR_BUFFER_BIT);/*�������� ���� ������������� ������ �������*/
	glColor3d(1, 0, 0);/*����*/
	glLineWidth(3); /*������ �����*/

	/*������ �����*/
	/*����� �����*/
	GLfloat pointsLeft[4][3] = {
		{80, 10, 0},
		{40, 30, 0},
		{10, 80, 0},
		{80, 60, 0}
	};

	/*������� �������� �����*/
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &pointsLeft[0][0]); /*������� ���������� ������*/
	glEnable(GL_MAP1_VERTEX_3);/*���������*/
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)/*����������� ����� � ����������*/
		glEvalCoord1f((GLfloat)i / 30.0); /*��������� ������*/
	glEnd();


	/*������ �����*/
	/*������ �����*/
	GLfloat pointsRight[4][3] = {
		{80, 10, 0},
		{120, 30, 0},
		{150, 80, 0},
		{80, 60, 0}
	};

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &pointsRight[0][0]); /*������� ���������� ������*/
	glEnable(GL_MAP1_VERTEX_3);/*���������*/
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)/*����������� ����� � ����������*/
		glEvalCoord1f((GLfloat)i / 30.0);/*��������� ������*/
	glEnd();



	glFlush();/*����� �����*/
}

