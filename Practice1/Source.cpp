#include <glut.h> 
#include <cmath>

void Reshape(int w, int h);
void Display();

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);/*������������� glut*/
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);/*�������� ������� ����������� � ������������������� ����*/

    glutInitWindowSize(700, 500);/*����*/
    glutCreateWindow("LR1_1"); /*��������*/

    glutReshapeFunc(Reshape); /*�����*/
    glutDisplayFunc(Display); /*�����*/

    glutMainLoop();
    return 0;
}
void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);/*�����������*/
    glMatrixMode(GL_PROJECTION);/*����� �������, ��� ������� ����� ������������ ������*/
    glLoadIdentity();/*- �������� ������� ������� �� ���������*/
    gluOrtho2D(-100, 100, -100, 100);/*������������� ������� �2D�������*/
    glMatrixMode(GL_MODELVIEW);/*����� �������, ��� ������� ����� ������������ ������*/
    glLoadIdentity();/*- �������� ������� ������� �� ���������*/
}
void Display()
{
    glClearColor(1, 1, 1, 0);/*RGBA ���� ������*/
    glClear(GL_COLOR_BUFFER_BIT); /*�������� ���� ������������� ������ �������*/

    glBegin(GL_LINES); /*�������� ������ ��� ����������� ���������*/
    glColor3f(0, 0, 0); /*����*/
    glVertex2i(-100, 0);
    glVertex2i(100, 0);/*����������� ��������� �������*/
    glVertex2i(0, -100);
    glVertex2i(0, 100);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
    for (float x = -100; x < 100; x += 0.5)/*��� ���������� ������ �� ���*/
        glVertex2f(x, abs(.25 * x + 3 * cos(100 * x) * sin(x)));
        glEnd();

    glutSwapBuffers();
}