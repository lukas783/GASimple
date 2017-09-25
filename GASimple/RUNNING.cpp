#include "globals.h"

void RunningDrawing() {
	for (int i = 0; i < 1024 / getBoxSize(); i++) {
		for (int j = 0; j < 768 / getBoxSize(); j++) {
			if (getRegionData(i, j) == true) {
				drawBox(i*getBoxSize(), j*getBoxSize(), (i + 1)*getBoxSize(), (j + 1)*getBoxSize(), black, black);
			}
		}
	}
	if (getStart().x != 0 && getStart().y != 0) {
		drawCircle(10.0, 10.0, getStart().x, getStart().y, green);
	}
	if (getEnd().x != 0 && getEnd().y != 0) {
		drawCircle(10.0, 10.0, getEnd().x, getEnd().y, red);
	}
	drawText(getSeedString(), 5, 740);
	drawText(currentGen(), 5, 720);
	drawText(currentFrame(), 6, 700);

	creature* c = getCreatures();
	for (int i = 0; i < 100; i++) {
		drawCircle(4.0, 4.0, c[i].getX(), c[i].getY(), blue);
	}

	drawBox(5, 693, 90, 663, white, black);
	drawText("Pause", 12, 672);
}

void RunningMouse(int button, int state, int x, int y) {
	if (x > 5 && x < 90 && y > 663 && y < 693 && button == 0 && state == 0) {
		setStage(PAUSED);
	}
}

void sortBest() {
	creature* c = getCreatures();
	creature temp;
	for (int i = 0; i < 99; i++) {
		for (int j = 0; j < (100 - i - 1); j++) {
			if (c[j].getFitness() > c[j + 1].getFitness()) {
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
	cout << "Generation: " << getGeneration() << " at a fitness of.. " << c[0].getFitness() << " | (" << c[0].getX() << ", " << c[0].getY() << ")." << endl;
}

void birthGeneration() {
	creature* c = getCreatures();
	for (int i = 50; i < 100; i++) {
		for (int j = 0; j < (MAX_FRAMES+1); j++) {
			c[i].getPath()[j] = c[i - 50].getPath()[j];
		}
		c[i].mutate();
	}
	for (int i = 0; i < 100; i++) {
		c[i].setLocation(getStart().x, getStart().y);
	}
}

void RunningIdle() {
	creature* c = getCreatures();
	for (int i = 0; i < 100; i++) {
		c[i].moveCreature(getFrame() - 1);
	}
	setFrame(getFrame() + 1);
	if (getFrame() > MAX_FRAMES) {
		setFrame(1);
		setGeneration(getGeneration() + 1);
		sortBest();
		cout << endl << endl;
		birthGeneration();
	}
	if(getFrame() % 20 == 0) 
		glutPostRedisplay();
}