#include "Creature.h"
#include "globals.h"

int main(int argc, char*argv[]) {
	srand(time(NULL));
	
	//Custom GLUTWindow class, opens a window using GLUT
	GLUTWindow window;
	window.setSize(width, height);	// sets window size (width and height are in globals.h)
	window.setTitle("GASimple v0.1");	// sets the title of the window
	window.setupWindow(argc, argv);	// required GLUT function
	window.setDisplayFunction(displayCallback);		// declares the display callback
	window.setMouseFunction(mouseCallback);			// declares the mouse callback
	window.setKeyboardFunction(keyboardCallback);	// declares the keyboard callback
	window.setReshapeFunction(reshapeCallback);		// declares the reshape function callback
	window.setIdleFunction(idleCallback);			// declares the idle callback
	window.init();
	return 0;
}

int getStage() {
	return stage;
}

void setStage(int i) {
	stage = i;
}

int getBoxSize() {
	return boxSize;
}

void setBoxSize(int i) {
	boxSize = i;
}

point getStart() {
	point p(startX, startY);
	return p;
}

point getEnd() {
	point p(endX, endY);
	return p;
}

void setStart(point p) {
	startX = p.x;
	startY = p.y;
}

void setEnd(point p) {
	endX = p.x;
	endY = p.y;
}

bool getRegionData(int x, int y) {
	return pixelValues[x][y];
}

void setRegionData(int x, int y, bool val) {
	pixelValues[x][y] = val;
}

int getGeneration() {
	return generation;
}
void setGeneration(int i) {
	generation = i;
}

int getFrame() {
	return frame;
}

void setFrame(int i) {
	frame = i;
}

char* currentGen() {
	static char text[18] = "Generation: 00000";
	int gen = getGeneration();
	int ending = 12, j = 0;
	while (gen > 0) {
		gen /= 10;
		j++;
	}
	gen = getGeneration();
	char num[6];
	_itoa_s(gen, num, 10);
	for (int i = 12; i < 12 + j; i++) {
		text[i] = num[i - 12];
		ending = i + 1;
	}
	text[ending] = '\0';
	return text;
}

char* currentFrame() {
	static char text[13] = "Frame: 00000";
	int fram = getFrame();
	int ending = 7, j = 0;
	while (fram > 0) {
		fram /= 10;
		j++;
	}
	fram = getFrame();
	char num[6];
	_itoa_s(fram, num, 10);
	for (int i = 7; i < 7 + j; i++) {
		text[i] = num[i - 7];
		ending = i + 1;
	}
	text[ending] = '\0';
	return text;
}

char* getSeedString() {
	static char text[16] = "Seed: 000000000";
	int i = 14;
	int se = getSeed();
	while (se > 0) {
		text[i] = (char)((se % 10)+48);
		se /= 10;
		i--;
	}
	return text;
}

int getSeed() { return seed; }
void setSeed(int i) { seed = i; }

creature* getCreatures() {
	return creatures;
}
creature getCreature(int i) {
	return creatures[i];
}
void setCreatures(creature* c) {
	creatures = c;
}