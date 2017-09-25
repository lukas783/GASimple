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
}

/*** displayCallback(void) | function to handle drawing to the screen (called whenever glutPostRedisplay() is called ***/
void displayCallback(void) {
	glClearColor(0.78, 0.75, 0.78, 1.0); // make a nice, light gray, background, for pre-login.
	glClear(GL_COLOR_BUFFER_BIT);	// clear the screen
	glLineWidth(1.5);
	drawBox(1, height-1, 1025, height-769, white, black); // the outline of our 'editor' sub-window

	drawBoxSizeEditor();
	drawEditorSubWindow();
	drawLoadSaveOps();
									// Swap the buffer (display everything created above)
	glutSwapBuffers();
}

/*** mouseCallback(int, int, int, int) | function to handle mouse actions in the GLUT window ***/
void mouseCallback(int button, int state, int x, int y) {
	y = height - y;	// reverse the y with the current height
	cout << x << ", " << y << endl;
	mouseBoxSizeEditor(button, state, x, y);
	mouseEditorSubWindow(button, state, x, y);
	mouseLoadSaveOps(button, state, x, y);
	glutPostRedisplay();
}

/*** keyboardCallbakc(unsigned char, int, int) | function that handles keyboard actions in the GLUT window ***/
void keyboardCallback(unsigned char key, int x, int y) {
	keyboardLoadSaveOps(key, x, y);
	glutPostRedisplay(); // call the display function
}

/*** reshapeCallback(int, int) | function to handle when the screen reshapes ***/
void reshapeCallback(int w, int h) {
	// I didn't add a resize function, so the window will always be set to 1024, 768
	glutReshapeWindow(1400, 770);
	glMatrixMode(GL_PROJECTION);	// sets up a projection view
	glLoadIdentity();
	gluOrtho2D(0.0, 1400, 0.0, 770);		// sets the coords of the orthogonal plane
	glViewport(0, 0, 1400, 770);			// sets the viewed coords
}