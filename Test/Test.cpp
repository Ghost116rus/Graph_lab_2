#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


#define PI 3.1459
GLfloat R = 640.0 / 480; //Форматное соотношение
GLfloat w = 70;  //Ширина мирового окна
GLfloat h; //Высота мирового окна
GLfloat l, r, b, t; //Параметры мирового окна
GLfloat f = 45.0;
GLfloat scale = 1;
GLfloat delta = 0.2;
GLfloat tX = 10.0;
GLfloat tY = 10.0;
GLint count = 0;

void init(void)
{
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2; //Расчет параметров мирового окна
	glClearColor(1.0, 1.0, 1.0, 1.0);
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

void fig0(void)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-10.0, -10.0);
	glVertex2f(10.0, -10.0);
	glVertex2f(10.0, 10.0);
	glVertex2f(-10.0, 10.0);

	glEnd();
}

void fig1(void)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 0.0);
	glVertex2f(7.0, 0.0);
	glVertex2f(7.0, 3.0);
	glVertex2f(0.0, 3.0);
	glEnd();
}
void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	//fig0();
	glTranslatef(tX, tY, 0.0);
	glRotatef(f, 0.0, 0.0, 1.0);
	if (count == 0)
	{
		tY -= 20;
		f += 255;
		count++;
	}
	else if (count == 1)
	{
		tX -= 26.2;
		tY -= 3.5;
		f += 90;
		count++;
	}
	else if (count == 2)
	{
		tY += 24.9;
		tX += 8.8;
		f += 90;
		count++;
	}
	else if (count == 3)
	{
		tX = 10;
		tY = 10;
		f = 45;
		count = 0;
	}
	fig1();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	Sleep(1000);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
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