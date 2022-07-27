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
	glutCreateWindow("LR2_3");/*��������*/
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


	GLfloat node[8] = { 0, 0, 0, 0, 1, 1, 1, 1 }; /*����*/

	/*������ �����*/
	/*����� �����*/
	GLfloat pointsLeft[4][3] = {
		{80, 10, 0},
		{40, 30, 0},
		{10, 80, 0},
		{80, 60, 0},
	};

	GLUnurbs* nurbs = gluNewNurbsRenderer(); /*������ �-�������*/
	gluBeginCurve(nurbs);/*������ ������*/
	gluNurbsCurve(nurbs, 8, &node[0], 3, &pointsLeft[0][0], 4, GL_MAP1_VERTEX_3); /*����������� ��������� ������*/
	gluEndCurve(nurbs);/*����� ������*/
	gluDeleteNurbsRenderer(nurbs);/*����������� ���������� �-�������*/

	/*������ �����*/
	GLfloat pointsRight[4][3] = {
		{80, 10, 0},
		{120, 30, 0},
		{150, 80, 0},
		{80, 60, 0}
	};


	GLUnurbs* nurbs2 = gluNewNurbsRenderer(); /*������ �-�������*/
	gluBeginCurve(nurbs2);/*������ ������*/
	gluNurbsCurve(nurbs2, 8, &node[0], 3, &pointsRight[0][0], 4, GL_MAP1_VERTEX_3);/*����������� ��������� ������*/
	gluEndCurve(nurbs2);/*����� ������*/
	gluDeleteNurbsRenderer(nurbs2);/*����������� ���������� �-�������*/


	glutSwapBuffers();
	glFlush();
}

