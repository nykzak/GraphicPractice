#include<Windows.h> 
#include <glut.h>    /*Для Linux и Windows*/ 
#include<vector> 
#include<fstream> 


using namespace std;

struct Point
{
	int x, y;
};
/*Вызов функций*/
void reshape(int w, int h);
void display();
void readFromFile();
void lineto(Point p);
void moveto(Point p);
/*Работа с векторной графикой*/
vector<Point> point;
vector<int>code;
Point currentPoint;
int main(int argc, char* argv[])
{
	currentPoint.x = 0; currentPoint.y = 0;
	glutInit(&argc, argv);/*Инициализация glut*/
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);/*Включаем двойную буферизацию и четырехкомпонентный цвет*/

	glutInitWindowSize(800, 600);/*Окно*/
	glutInitWindowPosition(100, 150);/*Позиция*/
	glutCreateWindow("LR1_3");/*Название*/
	glutDisplayFunc(display);/*Запуск функции*/
	glutReshapeFunc(reshape);/*Запуск функции*/
	glutMainLoop();/*Цикл*/
	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);/*отображение*/
	glMatrixMode(GL_PROJECTION);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
	gluOrtho2D(0, 150, 0, 150);/*визуализируем графику в 2D режиме*/
	glMatrixMode(GL_MODELVIEW);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
}

void display() {
	glClearColor(1, 1, 1, 0);/*RGBA цвет экрана*/
	glClear(GL_COLOR_BUFFER_BIT);/*Очищение окна установленным цветом очистки*/
	glColor3f(0, 0, 0);/*Цвет*/
	readFromFile();/*Вызов функции*/
	glColor3d(1, 0, 0);/*Цвет*/
	for (int i = 0; i < code.size(); i++)/*расстановка точек и соединение*/
		if (code[i] < 0)
		{
			code[i] = code[i] * -1;
			moveto(point[code[i] - 1]);
		}
		else {
			lineto(point[code[i] - 1]);
		}  glFlush();
}
void readFromFile() {/*Пуш данных в код*/
	fstream f("points.txt", ios::in);/*Чтение файла*/
	int pointNumber;
	int x, y;
	Point p;
	f >> pointNumber;
	for (int i = 0; i < pointNumber; i++)
	{
		f >> p.x >> p.y;
		point.push_back(p);
	}
	int movesNumber, m;
	f >> movesNumber;
	for (int i = 0; i < movesNumber; i++)
	{
		f >> m; code.push_back(m);
	}
	f.close();
}
void moveto(Point p) {/*Расстановка вершин*/
	currentPoint.x = p.x;
	currentPoint.y = p.y;
}
void lineto(Point p) {/*соединение с вершинами*/
	glBegin(GL_LINES);
	glVertex2i(currentPoint.x, currentPoint.y);
	glVertex2i(p.x, p.y);
	glEnd();
	currentPoint.x = p.x;
	currentPoint.y = p.y;
}