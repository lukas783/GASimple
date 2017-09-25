#include "globals.h"

int main(int argc, char*argv[]) {
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			setEditorValue(i, j, false);
		}
	}
	srand(time(NULL));
	//Custom GLUTWindow class, opens a window using GLUT
	GLUTWindow window;
	window.setSize(width, height);	// sets window size (width and height are in globals.h)
	window.setTitle("GASimple Map Editor");	// sets the title of the window
	window.setupWindow(argc, argv);	// required GLUT function
	window.setDisplayFunction(displayCallback);		// declares the display callback
	window.setMouseFunction(mouseCallback);			// declares the mouse callback
	window.setKeyboardFunction(keyboardCallback);	// declares the keyboard callback
	window.setReshapeFunction(reshapeCallback);		// declares the reshape function callback
	window.setIdleFunction(idleCallback);			// declares the idle callback
	window.init();
	return 0;
}

int getBoxSize() {
	return boxSize;
}

void setBoxSize(int i) {
	boxSize = i;
}

bool getEditorValue(int x, int y) {
	return editorWindow[x][y];
}

void setEditorValue(int x, int y, bool value) {
	editorWindow[x][y] = value;
}

const char* getFileName() {
	return fileName.c_str();
}

void setFileName(string s) {
	fileName = s;
}

int getStartX() {
	return startX;
}

int getStartY() {
	return startY;
}

int getEndX() {
	return endX;
}

int getEndY() {
	return endY;
}

void setStart(int x, int y) {
	startX = x;
	startY = y;
}

void setEnd(int x, int y) {
	endX = x;
	endY = y;
}

bool getShifted() {
	return shifted;
}

void setShifted(bool val) {
	shifted = val;
}