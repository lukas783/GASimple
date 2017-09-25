#include "globals.h"

void drawEditorSubWindow() {
	for (int i = 0; i < 1024 / getBoxSize(); i++) {
		for (int j = 0; j < 768 / getBoxSize(); j++) {
			if (getEditorValue(i, j) == true) {
				//cout << "x1: " << i*getBoxSize() << " y1: " << j*getBoxSize() 
				drawBox(i*getBoxSize(), j*getBoxSize(), (i + 1)*getBoxSize(), (j + 1)*getBoxSize(), black, black);
			}
		}
	}
	if (getStartX() != 0 && getStartY != 0) {
		drawCircle(10.0, 10.0, getStartX(), getStartY(), green);
	}
	if (getEndX() != 0 && getEndY() != 0) {
		drawCircle(10.0, 10.0, getEndX(), getEndY(), red);
	}
}

void mouseEditorSubWindow(int button, int state, int x, int y) {
	int col = 0, row = 0;
	if (x < 1024 && button == 0 && state == 0) {
		col = x / getBoxSize();
		row = y / getBoxSize();
		cout << "Column: " << col << " | Row: " << row << " | Value: " << getEditorValue(col, row) << endl;
		setEditorValue(col, row, !getEditorValue(col, row));
	}
	if (x < 1024 && button == 2 && state == 0) {
		if (getStartX() == 0 && getStartY() == 0)
			setStart(x, y);
		else if (getEndX() == 0 && getEndY() == 0)
			setEnd(x, y);
		else
			cout << "Start/End points already set.. sorry :/" << endl;
	}
}