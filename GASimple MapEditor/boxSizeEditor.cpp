#include "globals.h"

char* toString(int n) {
	static char carr[4] = "000";
	char d = 'l';
	int count = 2, j = 0;
	while (n != 0) {
		j = n % 10;
		n = n / 10;
		j = j + 48;
		d = (char)j;
		carr[count] = d;
		count--;
	}
	while (count >= 0) {
		carr[count] = '0';
		count--;
	}
	return carr;
}

void drawBoxSizeEditor() {
	drawText("Grid Box Size", 1038, 723);
	drawBox(1170, 715, 1300, 745, white, black);
	drawText(toString(getBoxSize()), 1260, 723);
	drawBox(1305, 715, 1325, 728, black, black);
	drawBox(1305, 732, 1325, 745, black, black);

	drawTriangle(1307, 734, 1315, 743, 1323, 734, white);
	drawTriangle(1307, 726, 1323, 726, 1315, 717, white);
	glLineWidth(1.0);
	for (int i = 0; i < 1024;) {
		drawLine(i, height, i, height - 768, black);
		i += getBoxSize();
	}
	for (int i = 0; i < 768;) {
		drawLine(0, height - i, 1024, height - i, black);
		i += getBoxSize();
	}
	glLineWidth(1.5);
}

void mouseBoxSizeEditor(int button, int state, int x, int y) {
	if (button == 0 && state == 0) {
		if (x > 1305 && x < 1325) {
			if (y > 715 && y < 728) {
				if(getBoxSize() > 8)
					setBoxSize(getBoxSize()/2);
			}
			if (y > 732 && y < 745) {
				if(getBoxSize() < 128)
					setBoxSize(getBoxSize()*2);
			}
		}
	}
}