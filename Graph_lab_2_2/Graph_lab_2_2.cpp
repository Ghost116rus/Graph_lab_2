// Graph_lab_2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define PI 3.1459
GLfloat R = 640.0 / 480; //Форматное соотношение
GLfloat w = 40;  //Ширина мирового окна
GLfloat h; //Высота мирового окна
GLfloat l, r, b, t; //Параметры мирового окна
GLfloat f = 90.0;

GLfloat tX = 0;
GLfloat tY = 12.0;
GLint count = 0;

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
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	GLfloat R = 10;
	for (int ii = 0; ii < 360; ii++)
	{
		float theta = 2*3.1415926f * float(ii) / float(360);

		float x = R * cosf(theta);
		float y = R * sinf(theta);

		glVertex2f(x, y );
	}
	glEnd();

}

void fig0(void)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(8, 0);
	glVertex2f(15, 0);

	glEnd();

	glBegin(GL_LINES);
	glVertex2f(12.3, -5);
	glVertex2f(12.3, 5);

	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	GLfloat R = 1;
	float x;
	float y;
	for (int i = 0; i < 360; i++)
	{
		float theta = 2 * 3.1415926f * float(i) / float(360);

		x = 2 * R * cosf(theta);
		y = R * sinf(theta);

		glVertex2f(x + 12.1, y);
	}
	glEnd();
}

void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	showAxis();

	glPushMatrix();
		glRotatef(f, 0.0, 0.0, 1.0);
		fig0();

	glPopMatrix( );
	glFlush();
	glutSwapBuffers();

	f += 90;
	Sleep(3000);
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

