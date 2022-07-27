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
	gluOrtho2D(40, 80, 40, 80);/*визуализируем графику в 2D режиме*/
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
	/*Первая буква*/
	GLfloat pointsForFirstLetter[7][3] = {
		{50, 49, 0},
		{47, 53, 0},
		{44, 49, 0},
		{43, 48, 0},
		{44, 47, 0},
		{47, 42, 0},
		{50, 46, 0}
	};


	/*Первая буква*/
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


	GLfloat node[14] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,}; /*узлы*/
	GLfloat node2[14] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1}; /*узлы*/

	GLUnurbs* nurbs = gluNewNurbsRenderer(); /*рендер Б-сплайна*/
	gluBeginCurve(nurbs);/*начало работы*/
	gluNurbsCurve(nurbs, 14, &node[0], 3, &pointsForFirstLetter[0][0], 7, GL_MAP1_VERTEX_3); /*определение атрибутов кривой*/
	gluEndCurve(nurbs);/*конец работы*/
	gluDeleteNurbsRenderer(nurbs);/*прекращение рендеринга Б-сплайна*/

	GLUnurbs* nurbs1 = gluNewNurbsRenderer(); /*рендер Б-сплайна*/
	gluBeginCurve(nurbs1);/*начало работы*/
	gluNurbsCurve(nurbs1, 14, &node[0], 3, &pointsForSecondLetter1[0][0], 7, GL_MAP1_VERTEX_3); /*определение атрибутов кривой*/
	gluEndCurve(nurbs1);/*конец работы*/
	gluDeleteNurbsRenderer(nurbs1);/*прекращение рендеринга Б-сплайна*/

	GLUnurbs* nurbs2 = gluNewNurbsRenderer(); /*рендер Б-сплайна*/
	gluBeginCurve(nurbs2);/*начало работы*/
	gluNurbsCurve(nurbs2, 14, &node2[0], 3, &pointsForSecondLetter2[0][0], 7, GL_MAP1_VERTEX_3); /*определение атрибутов кривой*/
	gluEndCurve(nurbs2);/*конец работы*/
	gluDeleteNurbsRenderer(nurbs2);/*прекращение рендеринга Б-сплайна*/

	GLUnurbs* nurbs3 = gluNewNurbsRenderer(); /*рендер Б-сплайна*/
	gluBeginCurve(nurbs3);/*начало работы*/
	gluNurbsCurve(nurbs3, 14, &node2[0], 3, &pointsForSecondLetter3[0][0], 7, GL_MAP1_VERTEX_3); /*определение атрибутов кривой*/
	gluEndCurve(nurbs3);/*конец работы*/
	gluDeleteNurbsRenderer(nurbs3);/*прекращение рендеринга Б-сплайна*/




	glutSwapBuffers();
	glFlush();
}

