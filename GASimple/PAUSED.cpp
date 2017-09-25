#include "globals.h"

void PausedDrawing() {
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
	drawText("Resume", 12, 672);
}


void PausedMouse(int button, int state, int x, int y) {
	if (x > 5 && x < 90 && y > 663 && y < 693 && button == 0 && state == 0) {
		setStage(RUNNING);
	}
}