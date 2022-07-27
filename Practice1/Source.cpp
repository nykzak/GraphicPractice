#include <glut.h> 
#include <cmath>

void Reshape(int w, int h);
void Display();

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);/*Инициализация glut*/
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);/*Включаем двойную буферизацию и четырехкомпонентный цвет*/

    glutInitWindowSize(700, 500);/*Окно*/
    glutCreateWindow("LR1_1"); /*Название*/

    glutReshapeFunc(Reshape); /*вызов*/
    glutDisplayFunc(Display); /*вызов*/

    glutMainLoop();
    return 0;
}
void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);/*отображение*/
    glMatrixMode(GL_PROJECTION);/*выбор матрицы, над которой будет производится работа*/
    glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
    gluOrtho2D(-100, 100, -100, 100);/*визуализируем графику в 2D режиме*/
    glMatrixMode(GL_MODELVIEW);/*выбор матрицы, над которой будет производится работа*/
    glLoadIdentity();/*- заменяет текущую матрицу на единичную*/
}
void Display()
{
    glClearColor(1, 1, 1, 0);/*RGBA цвет экрана*/
    glClear(GL_COLOR_BUFFER_BIT); /*Очищение окна установленным цветом очистки*/

    glBegin(GL_LINES); /*Комадная скобка для определение примитива*/
    glColor3f(0, 0, 0); /*Цвет*/
    glVertex2i(-100, 0);
    glVertex2i(100, 0);/*определение атрибутов вершины*/
    glVertex2i(0, -100);
    glVertex2i(0, 100);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
    for (float x = -100; x < 100; x += 0.5)/*Для построение кривых по оси*/
        glVertex2f(x, abs(.25 * x + 3 * cos(100 * x) * sin(x)));
        glEnd();

    glutSwapBuffers();
}