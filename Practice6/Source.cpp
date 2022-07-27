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
	glutCreateWindow("LR2_3");/*Название*/
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


	GLfloat node[8] = { 0, 0, 0, 0, 1, 1, 1, 1 }; /*узлы*/

	/*задача точек*/
	/*левые точки*/
	GLfloat pointsLeft[4][3] = {
		{80, 10, 0},
		{40, 30, 0},
		{10, 80, 0},
		{80, 60, 0},
	};

	GLUnurbs* nurbs = gluNewNurbsRenderer(); /*рендер Б-сплайна*/
	gluBeginCurve(nurbs);/*начало работы*/
	gluNurbsCurve(nurbs, 8, &node[0], 3, &pointsLeft[0][0], 4, GL_MAP1_VERTEX_3); /*определение атрибутов кривой*/
	gluEndCurve(nurbs);/*конец работы*/
	gluDeleteNurbsRenderer(nurbs);/*прекращение рендеринга Б-сплайна*/

	/*правые точки*/
	GLfloat pointsRight[4][3] = {
		{80, 10, 0},
		{120, 30, 0},
		{150, 80, 0},
		{80, 60, 0}
	};


	GLUnurbs* nurbs2 = gluNewNurbsRenderer(); /*рендер Б-сплайна*/
	gluBeginCurve(nurbs2);/*начало работы*/
	gluNurbsCurve(nurbs2, 8, &node[0], 3, &pointsRight[0][0], 4, GL_MAP1_VERTEX_3);/*определение атрибутов кривой*/
	gluEndCurve(nurbs2);/*конец работы*/
	gluDeleteNurbsRenderer(nurbs2);/*прекращение рендеринга Б-сплайна*/


	glutSwapBuffers();
	glFlush();
}

