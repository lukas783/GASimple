/*******************************************
 * A file for includes/global defines and 
 * global variables, along with global 
 * declarations, etc..
*******************************************/

#ifndef __GLOBALS_H_
#define __GLOBALS_H_

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <Windows.h>
#include "Creature.h"
#include "glut.h"
#include "WindowManager.h"
using namespace std;

/** Global Declarations/Variables below **/
static int height = 768, width = 1024;
enum STAGE {
	PRELOGIN = -1,
	PRESTART = 0,
	RUNNING = 5,
	PAUSED = 1
};

struct point {
	point(int xx, int yy) { x = xx; y = yy; }
	int x = 0;
	int y = 0;
};
//static creature creeet;
static int stage = -1;
static int seed = 3522;
static int boxSize = 0;
static bool pixelValues[130][130];
static int startX = 0, startY = 0, endX = 0, endY = 0;
static int frame = 1, generation = 1;
static int mutatePercent = 75;
static int MAX_FRAMES = 40000;
const float white[] = { 1.0, 1.0, 1.0 };
const float black[] = { 0.0, 0.0, 0.0 };
const float green[] = { (float)0.1, (float)0.8, (float)0.1 };
const float red[] = { (float)0.8, (float)0.1, (float)0.1 };
const float blue[] = { (float)0.1, (float)0.1, (float)0.8 };
/** Function declarations for GASimple.cpp **/
static creature* creatures;
int getStage();
void setStage(int i);
int getBoxSize();
void setBoxSize(int i);
point getStart();
point getEnd();
void setStart(point p);
void setEnd(point p);
bool getRegionData(int x, int y);
void setRegionData(int x, int y, bool val);
int getGeneration();
void setGeneration(int i);
int getFrame();
void setFrame(int i);
char* currentGen();
char* currentFrame();
char* getSeedString();
int getSeed();
void setSeed(int i);
creature* getCreatures();
creature getCreature(int i);
void setCreatures(creature* c);

/** Function declarations for callbacks.cpp **/
void displayCallback(void); // declaration of function for when glutPostRedisplay() is called
void mouseCallback(int button, int state, int x, int y); // declaration of function for mouse actions
void keyboardCallback(unsigned char key, int x, int y);	 // declaration of function for keyboard actions
void reshapeCallback(int w, int h); // declaration of function for reshaping the screen
void idleCallback(void); // declaration of function for the idle loop, (happens if nothing else happens)

/** Function declarations for drawing.cpp **/
void drawText(char *str, int x, int y);
void drawBox(float x1, float y1, float x2, float y2, const float colorin[], const float colorout[]);
void drawCircle(float xR, float yR, int x, int y, const float color[]);

/** Function declarations for PRELOGIN.cpp **/
char* toString(int n);
void PreLoginDrawing();
void PreLoginKeyboard(unsigned char key, int x, int y);
void PreLoginMouse(int button, int state, int x, int y);
void loadMap();

/** Function declarations for PRESTART.cpp **/
void PrestartDrawing();
void PrestartMouse(int button, int state, int x, int y);

/** Function declarations for RUNNING.cpp **/
void RunningDrawing();
void RunningMouse(int button, int state, int x, int y);
void RunningIdle();

/** Function declarations for PAUSED.cpp **/
void PausedDrawing();
void PausedMouse(int button, int state, int x, int y);

#endif