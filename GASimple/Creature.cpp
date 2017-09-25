#include "Creature.h"
#include "globals.h"
creature::creature() {/*
	point p = getStart();
	posX = p.x;
	posY = p.y;
	path = new char[1200]; */
}

creature::~creature() {
//delete path;
}

char* creature::getPath() { return path; }

char creature::getMovement(int i) { return path[i]; } // WARNING: this can cause out of bounds issues!

void creature::setLocation(int x, int y) { posX = x; posY = y; }

int creature::getX() { return posX; }

int creature::getY() { return posY; }

void creature::setPath(char* newPath) { path = newPath; }

void creature::mutate() {
	for (int i = 0; i < (MAX_FRAMES+1); i++) {
		if ((rand() % 1000) < (mutatePercent*10)) {
			path[i] = (char)((rand() % 8) + 48);
		}
	}
}

void creature::moveCreature(int currFrame) {
	switch (path[currFrame]) {
	case '0': // 0 is north ( 0x, 1y )
		posY += 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize())== true) {
			posY -= 1;
		}
		break;
	case '1': // 1 is north east (1x, 1y)
		posX += 1;
		posY += 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize()) == true) {
			posY -= 1;
			posX -= 1;
		}
		break;
	case '2': // 2 is east (1x, 0y)
		posX += 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize()) == true) {
			posX -= 1;
		}
		break;
	case '3': // 3 is south east (1x, -1y)
		posX += 1;
		posY -= 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize()) == true) {
			posY += 1;
			posX -= 1;
		}
		break;
	case '4': // 4 is south (0x, -1y)
		posY -= 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize()) == true) {
			posY += 1;
		}
		break;
	case '5': // 5 is south west (-1x, -1y)
		posX -= 1;
		posY -= 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize()) == true) {
			posY += 1;
			posX += 1;
		}
		break;
	case '6': // 6 is west (-1x, 0y)
		posX -= 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize()) == true) {
			posX += 1;
		}
		break;
	case '7': // 7 is north west (-1x, 1y)
		posX -= 1;
		posY += 1;
		if (getRegionData(posX / getBoxSize(), posY / getBoxSize()) == true) {
			posY -= 1;
			posX += 1;
		}
		break;
	}
}

double creature::getFitness() {
	double d = 0.0;
	point p = getEnd();
	d = pow((p.x-posX), 2) + pow((p.y-posY), 2);
	return sqrt(d);
}