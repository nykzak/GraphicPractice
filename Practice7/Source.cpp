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
	gluOrtho2D(40, 80, 40, 80);/*������������� ������� �2D�������*/
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
	/*������ �����*/
	GLfloat pointsForFirstLetter[7][3] = {
		{50, 49, 0},
		{47, 53, 0},
		{44, 49, 0},
		{43, 48, 0},
		{44, 47, 0},
		{47, 42, 0},
		{50, 46, 0}
	};


	/*������ �����*/
	GLfloat pointsForSecondLetter1[7][3] = {
		{62, 54, 0},
		{60, 52, 0},
		{58, 51, 0},
		{56, 52, 0},
		{55, 54, 0},
		{55, 46, 0},
		{55, 48, 0},
	};

	GLfloat pointsForSecondLetter2[7][3] = {
		{58, 49, 0},
		{58, 47, 0},
		{58, 46, 0},
		{57, 44, 0},
		{55, 43, 0},
		{54, 41, 0},
		{52, 45, 0}
	};

	GLfloat pointsForSecondLetter3[7][3] = {
		{60, 49, 0},
		{60, 47, 0},
		{60, 46, 0},
		{61, 44, 0},
		{63, 43, 0},
		{64, 41, 0},
		{66, 45, 0}
	};


	GLfloat node[14] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,}; /*����*/
	GLfloat node2[14] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1}; /*����*/

	GLUnurbs* nurbs = gluNewNurbsRenderer(); /*������ �-�������*/
	gluBeginCurve(nurbs);/*������ ������*/
	gluNurbsCurve(nurbs, 14, &node[0], 3, &pointsForFirstLetter[0][0], 7, GL_MAP1_VERTEX_3); /*����������� ��������� ������*/
	gluEndCurve(nurbs);/*����� ������*/
	gluDeleteNurbsRenderer(nurbs);/*����������� ���������� �-�������*/

	GLUnurbs* nurbs1 = gluNewNurbsRenderer(); /*������ �-�������*/
	gluBeginCurve(nurbs1);/*������ ������*/
	gluNurbsCurve(nurbs1, 14, &node[0], 3, &pointsForSecondLetter1[0][0], 7, GL_MAP1_VERTEX_3); /*����������� ��������� ������*/
	gluEndCurve(nurbs1);/*����� ������*/
	gluDeleteNurbsRenderer(nurbs1);/*����������� ���������� �-�������*/

	GLUnurbs* nurbs2 = gluNewNurbsRenderer(); /*������ �-�������*/
	gluBeginCurve(nurbs2);/*������ ������*/
	gluNurbsCurve(nurbs2, 14, &node2[0], 3, &pointsForSecondLetter2[0][0], 7, GL_MAP1_VERTEX_3); /*����������� ��������� ������*/
	gluEndCurve(nurbs2);/*����� ������*/
	gluDeleteNurbsRenderer(nurbs2);/*����������� ���������� �-�������*/

	GLUnurbs* nurbs3 = gluNewNurbsRenderer(); /*������ �-�������*/
	gluBeginCurve(nurbs3);/*������ ������*/
	gluNurbsCurve(nurbs3, 14, &node2[0], 3, &pointsForSecondLetter3[0][0], 7, GL_MAP1_VERTEX_3); /*����������� ��������� ������*/
	gluEndCurve(nurbs3);/*����� ������*/
	gluDeleteNurbsRenderer(nurbs3);/*����������� ���������� �-�������*/




	glutSwapBuffers();
	glFlush();
}

