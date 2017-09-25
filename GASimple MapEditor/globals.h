/*******************************************
 * A file for includes/global defines and 
 * global variables, along with global 
 * declarations, etc..
*******************************************/

#ifndef __GLOBALS_H_
#define __GLOBALS_H_

#include <fstream>
#include <iostream>
#include <math.h>
#include <random>
#include <string>
#include <time.h>
#include "glut.h"
#include "WindowManager.h"
using namespace std;

/** Global Declarations/Variables below **/
static int height = 770, width = 1400;
static int boxSize = 16;
static int startX = 0, startY = 0, endX = 0, endY = 0;
static bool shifted = false;
static string fileName = "file.gas";
static bool editorWindow[130][130];
const float white[] = { 1.0, 1.0, 1.0 };
const float black[] = { 0.0, 0.0, 0.0 };
const float green[] = { (float)0.1, (float)0.8, (float)0.1 };
const float red[] = { (float)0.8, (float)0.1, (float)0.1 };
const float blue[] = { (float)0.1, (float)0.1, (float)0.8 };


/** Function declarations for GASimple.cpp **/
int getBoxSize();
void setBoxSize(int i);
bool getEditorValue(int x, int y);
void setEditorValue(int x, int y, bool value);
const char* getFileName();
void setFileName(string s);
int getStartX();
int getStartY();
int getEndX();
int getEndY();
void setStart(int x, int y);
void setEnd(int x, int y);
bool getShifted();
void setShifted(bool val);

/** Function declarations for callbacks.cpp **/
void displayCallback(void); // declaration of function for when glutPostRedisplay() is called
void mouseCallback(int button, int state, int x, int y); // declaration of function for mouse actions
void keyboardCallback(unsigned char key, int x, int y);	 // declaration of function for keyboard actions
void reshapeCallback(int w, int h); // declaration of function for reshaping the screen
void idleCallback(void); // declaration of function for the idle loop, (happens if nothing else happens)

/** Function declarations for drawing.cpp **/
void drawText(char *str, int x, int y);
void drawBox(float x1, float y1, float x2, float y2, const float colorin[], const float colorout[]);
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, const float color[]);
void drawLine(float x1, float y1, float x2, float y2, const float color[]);
void drawCircle(float xR, float yR, int x, int y, const float color[]);

/** Function declarations for boxSizeEditor.cpp **/
void drawBoxSizeEditor();
void mouseBoxSizeEditor(int button, int state, int x, int y);

/** Function declarations for editorSubWindow.cpp **/
void drawEditorSubWindow();
void mouseEditorSubWindow(int button, int state, int x, int y);

/** Function declarations for loadSaveOps.cpp **/
void drawLoadSaveOps();
void keyboardLoadSaveOps(unsigned char key, int x, int y);
void mouseLoadSaveOps(int button, int state, int x, int y);

#endif