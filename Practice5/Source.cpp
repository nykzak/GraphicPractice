#include <Windows.h>
#include <vector>
#include <fstream>
#include <glut.h> /*Для Linux и Windows*/ 

using namespace std;

/*Вызов функций*/
void reshape(int w, int h);
void display();
int main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);/*Инициализация glut*/
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);/*Включаем двойную буферизацию и четырехкомпонентный цвет*/

	glutInitWindowSize(800, 600);/*Окно*/
	glutInitWindowPosition(100, 150);/*Позиция*/
	glutCreateWindow("LR2_2");/*Название*/
	glutReshapeFunc(reshape);/*Запуск функции*/
	glutDisplayFunc(display);/*Запуск функции*/
	glutMainLoop();/*Цикл*/
	return 0;
}
void reshape(int w, int h)
{
	
	glViewport(0, 0, w, h);/*отображение*/
	glMatrixMode(GL_PROJECTION);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
	gluOrtho2D(0, 200, 0, 100);/*визуализируем графику в 2D режиме*/
	glMatrixMode(GL_MODELVIEW);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
}
void display()
{
	glClearColor(1, 1, 1, 0);/*RGBA цвет экрана*/
	glClear(GL_COLOR_BUFFER_BIT);/*Очищение окна установленным цветом очистки*/
	glColor3d(1, 0, 0);/*Цвет*/
	glLineWidth(3); /*ширина линии*/

	/*задача точек*/
	/*левые точки*/
	GLfloat pointsLeft[4][3] = {
		{80, 10, 0},
		{40, 30, 0},
		{10, 80, 0},
		{80, 60, 0}
	};

	/*Функции сплайнов Безье*/
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &pointsLeft[0][0]); /*Задание параметров кривых*/
	glEnable(GL_MAP1_VERTEX_3);/*Включение*/
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)/*расстановка точек и соединение*/
		glEvalCoord1f((GLfloat)i / 30.0); /*Генерация кривых*/
	glEnd();


	/*задача точек*/
	/*правые точки*/
	GLfloat pointsRight[4][3] = {
		{80, 10, 0},
		{120, 30, 0},
		{150, 80, 0},
		{80, 60, 0}
	};

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &pointsRight[0][0]); /*Задание параметров кривых*/
	glEnable(GL_MAP1_VERTEX_3);/*Включение*/
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)/*расстановка точек и соединение*/
		glEvalCoord1f((GLfloat)i / 30.0);/*Генерация кривых*/
	glEnd();



	glFlush();/*вывод линий*/
}

