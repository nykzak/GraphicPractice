#include <glut.h>    /*��� Linux � Windows*/
#include <iostream>

/*����� �������*/
void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);/*������������� glut*/
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);/*�������� ������� ����������� � ������������������� ����*/

	glutInitWindowSize(800, 800);/*����*/
	glutCreateWindow("LAB4_1");/*��������*/
	glutDisplayFunc(display);/*������ �������*/
	glutReshapeFunc(reshape);/*������ �������*/
	glutKeyboardFunc(processNormalKeys);/*������ �������*/
	glutSpecialFunc(processSpecialKeys);/*������ �������*/
	glutMainLoop();/*����*/

	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);/*�����������*/

	glMatrixMode(GL_PROJECTION);/*����� �������, ��� ������� ����� ������������ ������*/
	glLoadIdentity();/*- �������� ������� ������� �� ���������*/
	gluPerspective(60, 1, 0, 20);/*������������� ������� �3D������� ,����������� ��������*/
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);/*����� ����������*/
	glMatrixMode(GL_MODELVIEW);/*����� �������, ��� ������� ����� ������������ ������*/
	glLoadIdentity();/*- �������� ������� ������� �� ���������*/
	glTranslated(0, 0, -15);/*�����������*/
	glClearColor(1, 1, 1, 0);/*RGBA ���� ������*/
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0); /*���� ����*/

	glutWireCube(5); /*��������� ���� ,��������� ������ ����������� ����*/
	glBegin(GL_LINES);/*������ � ����� ox oy oz*/
	glColor3f(1.0, 0.0, 0.0);/*������� ��� x*/
	glVertex3i(-1000, 0, 0);/*������� ���*/
	glVertex3i(1000, 0, 0);/*������� ���*/
	glColor3f(0.0, 1.0, 0.0);/*������� ��� y*/
	glVertex3i(0, -1000, 0);/*������� ���*/
	glVertex3i(0, 1000, 0);/*������� ���*/
	glColor3f(0.0, 0.0, 1.0);/*������� ��� z*/
	glVertex3i(0, 0, -1000);/*������� ���*/
	glVertex3i(0, 0, 1000);/*������� ���*/
	glEnd();

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)/*������ � ���������*/
{
	if (key == 27)
	{
		exit(0);
	}

	if (key == '+') {
		glMatrixMode(GL_MODELVIEW);
		glScaled(1.1, 1.1, 0);
		display();
	}

	if (key == '-') {
		glMatrixMode(GL_MODELVIEW);
		glScaled(0.9, 0.9, 0);
		display();
	}

	if (key == 127) {
		glMatrixMode(GL_MODELVIEW);
		glRotated(-10, 0, 0, 1);
		display();
	}

}

void processSpecialKeys(int key, int x, int y) { /*������ � ���������*/
	switch (key) {
	case GLUT_KEY_UP:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, 1, 0);
		display();
		break;
	case GLUT_KEY_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, -1, 0);
		display();
		break;
	case GLUT_KEY_LEFT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-1, 0, 0);
		display();
		break;
	case GLUT_KEY_RIGHT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(1, 0, 0);
		display();
		break;
	case GLUT_KEY_HOME:
		glMatrixMode(GL_MODELVIEW);
		glRotated(-5, 1, 0, 0);
		display();
		break;
	case GLUT_KEY_END:
		glMatrixMode(GL_MODELVIEW);
		glRotated(-5, 0, 1, 0);
		display();
		break;
	case GLUT_KEY_PAGE_UP:
		glMatrixMode(GL_MODELVIEW);
		glRotated(5, 1, 1, 1);
		display();
		break;
	case GLUT_KEY_PAGE_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glRotated(-5, 1, 1, 1);
		display();
		break;
	}
}