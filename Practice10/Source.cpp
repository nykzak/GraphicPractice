#include<windows.h>
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
void readFromFile(string root);
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void lineto(Point p);
void moveto(Point p);
void lTyping(string fName);
/*Работа с векторной графикой*/
vector<Point>point;
vector<int>code;
Point currentPoint;
int countR = 0;

int main(int argc, char* argv[]){
	currentPoint.x = 0; currentPoint.y = 0;
	glutInit(&argc, argv);/*Инициализация glut*/
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);/*Включаем двойную буферизацию и четырехкомпонентный цвет*/

	glutInitWindowSize(800, 600);/*Окно*/
	glutInitWindowPosition(100, 150);/*Позиция*/
	glutCreateWindow("LR1_3");/*Название*/
	glutDisplayFunc(display);/*Запуск функции*/
	glutReshapeFunc(reshape);/*Запуск функции*/
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();/*Цикл*/
	return 0;
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);/*отображение*/
	glMatrixMode(GL_PROJECTION);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
	gluOrtho2D(0, 150, 0, 150);/*визуализируем графику в 2D режиме*/
	glMatrixMode(GL_MODELVIEW);/*выбор матрицы, над которой будет производится работа*/
	glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
}

void display(){
	glClearColor(1, 1, 1, 0);/*RGBA цвет экрана*/
	glClear(GL_COLOR_BUFFER_BIT);/*Очищение окна установленным цветом очистки*/
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glRotatef(countR * -2, 0, 0, 1);
	lTyping("points1.txt");
	glPopMatrix();

	glPushMatrix();
	glRotatef(countR * 2, 0, 0, 1);
	lTyping("points2.txt");
	glPopMatrix();

	glutSwapBuffers();
}

void lTyping(string fName){
	readFromFile(fName);
	for (int i = 0; i != code.size(); i++)/*расстановка точек и соединение*/
		if (code[i] < 0)
		{
			code[i] = code[i] * -1;
			moveto(point[code[i] - 1]);
		}
		else
		{
			lineto(point[code[i] - 1]);
		}
	point.clear();
	code.clear();
}

void readFromFile(string root){/*Пуш данных в код*/
	fstream f(root, ios::in);/*Чтение файла*/
	int pointNumber;
	int x, y; Point p;
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
		f >> m;
		code.push_back(m);
	}
	f.close();
}

void moveto(Point p){/*Расстановка вершин*/
	currentPoint.x = p.x;
	currentPoint.y = p.y;
}

void lineto(Point p){/*соединение с вершинами*/
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex2i(currentPoint.x, currentPoint.y);
	glVertex2i(p.x, p.y);
	glEnd();
	currentPoint.x = p.x;
	currentPoint.y = p.y;
}

void processNormalKeys(unsigned char key, int x, int y){
	if (key == 27)
	{
		exit(0);
	}
	if (key == '+')
	{
		glMatrixMode(GL_MODELVIEW);
		glTranslated(15, 15, 0);
		glScalef(1.3, 1.3, 0);
		glTranslated(-15, -15, 0);
		display();
	}
	if (key == '-')
	{
		glMatrixMode(GL_MODELVIEW);
		glTranslated(15, 15, 0);
		glScalef(0.7, 0.7, 0);
		glTranslated(-15, -15, 0);
		display();
	}
}

void processSpecialKeys(int key, int x, int y){
	switch (key)
	{
	case GLUT_KEY_UP:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, 10, 0);
		display();
		break;
	case GLUT_KEY_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, -10, 0);
		display();
		break;
	case GLUT_KEY_LEFT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-10, 0, 0);
		display();
		break;
	case GLUT_KEY_RIGHT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(10, 0, 0);
		display();
		break;
	case GLUT_KEY_HOME:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(50, 0, 0);
		glRotatef(5, 0, 0, 1);
		glTranslated(-50, 0, 0);
		display();
		break;
	case GLUT_KEY_END:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(50, 0, 0);
		glRotatef(-5, 0, 0, 1);
		glTranslated(-50, 0, 0);
		display();
		break;
	case GLUT_KEY_PAGE_UP:
		countR--;
		display();
		break;
	}
	
}

