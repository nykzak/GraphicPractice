#include <glut.h> /*��� Linux � Windows*/
#include <iostream>
using namespace std;


int posX = 0, posY = 0;
int sizeX, sizeY;
/*����� �������*/
void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);/*������������� glut*/
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);/*�������� ������� ����������� � ������������������� ����*/

	glutInitWindowSize(800, 600);/*����*/
	glutCreateWindow("Lab3_1");/*��������*/
	glutReshapeFunc(reshape);/*������ �������*/
	glutDisplayFunc(display);/*������ �������*/
	glutKeyboardFunc(processNormalKeys);/*������ �������*/
	glutSpecialFunc(processSpecialKeys);/*������ �������*/
	glutMainLoop();/*����*/
	return 0;
}
void reshape(int w, int h)
{
	sizeX = w; sizeY = h;
	glViewport(0, 0, w, h);/*�����������*/
	glMatrixMode(GL_PROJECTION);/*����� �������, ��� ������� ����� ������������ ������*/
	glLoadIdentity();/*- �������� ������� ������� �� ���������*/
	gluOrtho2D(0, w, 0, h);/*������������� ������� �2D�������*/
	glMatrixMode(GL_MODELVIEW);/*����� �������, ��� ������� ����� ������������ ������*/
	glLoadIdentity();/*- �������� ������� ������� �� ���������*/
}
void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS); /*���������� ��������*/
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(250, 450);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(250, 150);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(550, 150);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550, 450);
	glEnd();

	glBegin(GL_LINES);/*��� OX � OY*/
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(0, sizeY - posY);
	glVertex2i(0, -posY);
	glVertex2i(sizeX - posX, 0);
	glVertex2i(-posX, 0);
	glEnd();

	glutSwapBuffers();
	glDisable(GL_CLIP_PLANE0);
}

void translator(int x, int y, int z) { 
	glTranslated(x, y, 0);
	posX += x;
	posY += y;
}

void processNormalKeys(unsigned char key, int x, int y) /*����� ������� � �������� ����*/
{
	if (key == 27)
		exit(0);

	if (key == 65)
	{
		glMatrixMode(GL_MODELVIEW);/*����� �������, ��� ������� ����� ������������ ������*/
		translator(20, 20, 0);
		display();
	}
}

void processSpecialKeys(int key, int x, int y) { /*������ � ��������� ����������*/
	switch (key) {
	case GLUT_KEY_UP:
		glMatrixMode(GL_MODELVIEW);
		translator(0, 20, 0);
		display();
		break;

	case GLUT_KEY_DOWN:
		glMatrixMode(GL_MODELVIEW);
		translator(0, -20, 0);
		display();
		break;

	case GLUT_KEY_LEFT:
		glMatrixMode(GL_MODELVIEW);
		translator(-20, 0, 0);
		display();
		break;

	case GLUT_KEY_RIGHT:
		glMatrixMode(GL_MODELVIEW);
		translator(20, 0, 0);
		display();
		break;
	}
}
