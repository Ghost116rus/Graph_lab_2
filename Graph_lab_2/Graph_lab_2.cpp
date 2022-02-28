// Graph_lab_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define PI 3.1459
GLfloat R = 640.0 / 480; //Форматное соотношение
GLfloat w = 40;  //Ширина мирового окна
GLfloat h; //Высота мирового окна
GLfloat l, r, b, t; //Параметры мирового окна
GLfloat f = 2;
bool plus = true;

void init(void)
{
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2; //Расчет параметров мирового окна
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(l, r, b, t);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void reshape(GLsizei W, GLsizei H)
{
	if (R > W / H) glViewport(0, 0, W, W / R);
	else glViewport(0, 0, H * R, H);
}

void showAxis(void)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(0, b);
	glVertex2f(0, t);

	glEnd();
}

void fig0(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(3.0, -1.0);
	glVertex2f(3.0, 3.0);
	glVertex2f(9.0, 3.0);
	glVertex2f(9.0, -1.0);
	glEnd();
}

void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	showAxis();
	
	glPushMatrix();
		
		glScalef(f, f, 1.0);
		fig0();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(f, -f, 1.0);
		fig0();
	glPopMatrix( );
	glFlush();
	glutSwapBuffers();

	if (plus)
	{
		if (f < 0)
		{
			plus = false;
		}
		f = f - 0.1;

	}
	else
	{
		if (f > 2)
		{
			plus = true;
		}
		f = f + 0.1;

	}
	Sleep(20);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);

	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Myprog");

	glutReshapeFunc(reshape);

	glutDisplayFunc(scene);
	glutIdleFunc(scene);
	init();
	glutMainLoop();
}
