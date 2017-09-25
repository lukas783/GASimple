#include "globals.h"

/***
* This code was taken from Dr. Weiss's CSC300 Programs
* drawText(char*, int, int)
* - draws the text from char*, at pos (int, int)
***/
void drawText(char *str, int x, int y) {
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(x, y);
	while (*str)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *str++);
}

/***
* This code was taken from Dr. Weiss's CSC300 Programs
* drawBox(float, float, float, float)
* - draws a rectangle with diagonal corners at (float, float)
* - and (float, float)
***/
void drawBox(float x1, float y1, float x2, float y2, const float colorin[], const float colorout[]) {
	glColor3fv(colorin);
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	glFlush();

	glColor3fv(colorout);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	glFlush();
}

void drawCircle(float xR, float yR, int x, int y, const float color[]) {
	float radius = xR < yR ? xR : yR;
	glColor3fv(color);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glScalef(xR / radius, yR / radius, 1.0);
	GLUquadricObj *disk = gluNewQuadric();
	gluDisk(disk, 0, radius, int(radius), 1);
	gluDeleteQuadric(disk);
	glLoadIdentity();
	glFlush();

	glColor3fv(black);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glScalef(xR / radius, yR / radius, 1.0);
	GLUquadricObj *diske = gluNewQuadric();
	gluDisk(diske, radius - 1, radius, int(radius), 1);
	gluDeleteQuadric(diske);
	glLoadIdentity();
	glFlush();
}