/*********************************************************************************************
* File: callbacks.cpp
* Author: Lucas Carpente
* Creation Date: 07/02/2017
* Last Modified: 07/02/2017
* Bugs: none that I could find, if you find one, let me know.
*
* Notes:
*  = This file handles functions for handling callbacks that go off when something happens in
*    the GLUT window
**********************************************************************************************/
#include "globals.h"

/*** idleCallback(void) | function to handle the loop when no other callback is occurring ***/
void idleCallback(void) {
	switch (getStage()) {
	case RUNNING:
		RunningIdle();
		break;
	}
	stage = 3;
}

/*** displayCallback(void) | function to handle drawing to the screen (called whenever glutPostRedisplay() is called ***/
void displayCallback(void) {
	switch (getStage()) {
	case PRELOGIN:
		glClearColor(0.78, 0.75, 0.78, 1.0); // make a nice, light gray, background, for pre-login.
		glClear(GL_COLOR_BUFFER_BIT);	// clear the screen
		PreLoginDrawing();
		break;

	case PRESTART:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		PrestartDrawing();
		break;

	case RUNNING:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		RunningDrawing();
		break;

	case PAUSED:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		PausedDrawing();
		break;

	default:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		drawText("An error has occured", 400, 400);
		break;
	}
	// Swap the buffer (display everything created above)
	glutSwapBuffers();
}

/*** mouseCallback(int, int, int, int) | function to handle mouse actions in the GLUT window ***/
void mouseCallback(int button, int state, int x, int y) {
	y = height - y;	// reverse the y with the current height
	switch (getStage()) {
	case PRELOGIN:
		PreLoginMouse(button, state, x, y);
		break;
	case PRESTART:
		PrestartMouse(button, state, x, y);
		break;
	case RUNNING:
		RunningMouse(button, state, x, y);
		break;
	case PAUSED:
		PausedMouse(button, state, x, y);
		break;

	}
	glutPostRedisplay();
}

/*** keyboardCallbakc(unsigned char, int, int) | function that handles keyboard actions in the GLUT window ***/
void keyboardCallback(unsigned char key, int x, int y) {
	switch (getStage()) {
	case PRELOGIN:
		PreLoginKeyboard(key, x, y);
		break;

	}
	glutPostRedisplay(); // call the display function
}

/*** reshapeCallback(int, int) | function to handle when the screen reshapes ***/
void reshapeCallback(int w, int h) {
	// I didn't add a resize function, so the window will always be set to 1024, 768

	glutReshapeWindow(1024, 768);
	glMatrixMode(GL_PROJECTION);	// sets up a projection view
	glLoadIdentity();
	gluOrtho2D(0.0, 1024, 0.0, 768);		// sets the coords of the orthogonal plane
	glViewport(0, 0, 1024, 768);			// sets the viewed coords
}


