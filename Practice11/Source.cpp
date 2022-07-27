#include <glut.h>    /*Для Linux и Windows*/
#include <iostream>

/*Вызов функций*/
void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);/*Инициализация glut*/
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);/*Включаем двойную буферизацию и четырехкомпонентный цвет*/

	glutInitWindowSize(800, 800);/*Окно*/
	glutCreateWindow("LAB4_1");/*Название*/
	glutDisplayFunc(display);/*Запуск функции*/
	glutReshapeFunc(reshape);/*Запуск функции*/
	glutKeyboardFunc(processNormalKeys);/*Запуск функции*/
	glutSpecialFunc(processSpecialKeys);/*Запуск функции*/
	glutMainLoop();/*Цикл*/

	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);/*отображение*/

	glMatrixMode(GL_PROJECTION);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
	gluPerspective(60, 1, 0, 20);/*визуализируем графику в 3D режиме ,центральная проекция*/
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);/*точки наблюдения*/
	glMatrixMode(GL_MODELVIEW);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
	glTranslated(0, 0, -15);/*размерность*/
	glClearColor(1, 1, 1, 0);/*RGBA цвет экрана*/
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0); /*цвет куба*/

	glutWireCube(5); /*рендеринг куба ,статичная задача размерности куба*/
	glBegin(GL_LINES);/*работа с осями ox oy oz*/
	glColor3f(1.0, 0.0, 0.0);/*рисовка оси x*/
	glVertex3i(-1000, 0, 0);/*рисовка оси*/
	glVertex3i(1000, 0, 0);/*рисовка оси*/
	glColor3f(0.0, 1.0, 0.0);/*рисовка оси y*/
	glVertex3i(0, -1000, 0);/*рисовка оси*/
	glVertex3i(0, 1000, 0);/*рисовка оси*/
	glColor3f(0.0, 0.0, 1.0);/*рисовка оси z*/
	glVertex3i(0, 0, -1000);/*рисовка оси*/
	glVertex3i(0, 0, 1000);/*рисовка оси*/
	glEnd();

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)/*работа с клавишами*/
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

void processSpecialKeys(int key, int x, int y) { /*работа с клавишами*/
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