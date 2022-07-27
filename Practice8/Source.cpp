#include <glut.h> /*Для Linux и Windows*/
#include <iostream>
using namespace std;


int posX = 0, posY = 0;
int sizeX, sizeY;
/*Вызов функций*/
void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);/*Инициализация glut*/
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);/*Включаем двойную буферизацию и четырехкомпонентный цвет*/

	glutInitWindowSize(800, 600);/*Окно*/
	glutCreateWindow("Lab3_1");/*Название*/
	glutReshapeFunc(reshape);/*Запуск функции*/
	glutDisplayFunc(display);/*Запуск функции*/
	glutKeyboardFunc(processNormalKeys);/*Запуск функции*/
	glutSpecialFunc(processSpecialKeys);/*Запуск функции*/
	glutMainLoop();/*Цикл*/
	return 0;
}
void reshape(int w, int h)
{
	sizeX = w; sizeY = h;
	glViewport(0, 0, w, h);/*отображение*/
	glMatrixMode(GL_PROJECTION);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
	gluOrtho2D(0, w, 0, h);/*визуализируем графику в 2D режиме*/
	glMatrixMode(GL_MODELVIEW);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
}
void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS); /*прорисовка квадрата*/
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(250, 450);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(250, 150);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(550, 150);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550, 450);
	glEnd();

	glBegin(GL_LINES);/*оси OX и OY*/
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

void processNormalKeys(unsigned char key, int x, int y) /*Показ матрицы и закрытие окна*/
{
	if (key == 27)
		exit(0);

	if (key == 65)
	{
		glMatrixMode(GL_MODELVIEW);/*выбор матрицы, над которой будет производится работа*/
		translator(20, 20, 0);
		display();
	}
}

void processSpecialKeys(int key, int x, int y) { /*Работа с клавишами клавиатуры*/
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
