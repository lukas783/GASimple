#include "globals.h"

char* toString(int n) {
	static char carr[10] = "000000000";
	char d = 'l';
	int count = 8, j = 0;
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

void PreLoginDrawing() {
		drawBox(300, 475, 700, 525, white, black);
		drawBox(325, 425, 475, 350, white, black);
		drawBox(525, 425, 675, 350, white, black);
		drawText("Random Seed", 340, 380);
		drawText("Continue", 560, 380);
		drawText("Please enter a starting seed (0 - 200,000,000)", 320, 550);
		drawText(toString(getSeed()), 455, 492);
}

void PreLoginKeyboard(unsigned char key, int x, int y) {
	static int se = getSeed();
	if (key >= 48 && key <= 57) {
		setSeed(getSeed() * 10);
		setSeed(getSeed() + key - 48);
		if (getSeed() > 200000000)
			setSeed(200000000);
	}
	if (key == 8) {
		setSeed(getSeed() / 10);
	}
}

void PreLoginMouse(int button, int state, int x, int y) {
	if( x > 325 && x < 475 && y > 350 && y < 425 && button == 0 && state == 0) {
		setSeed((rand() * rand()) % 200000000);
	}
	if (x > 525 && x < 675 && y > 350 && y < 425 && button == 0 && state == 0) {
		loadMap();
		srand(getSeed());
		setStage(PRESTART);
		creature* c = new creature[100];
		for (int i = 0; i < 100; i++) {
			cout << "Creature " << i << ": ";
			char* p = new char[MAX_FRAMES+1];
			for (int j = 0; j < MAX_FRAMES+1; j++) {
				p[j] = (char)((rand() % 8)+48);
				//cout << p[j] << ", ";
			}
			//cout << endl << endl;
			c[i].setPath(p);
			c[i].setLocation(getStart().x, getStart().y);
		}
		setCreatures(c);
	}
}

void loadMap() {
	ifstream in;
	in.open("mapdata.gas");
	if (in.is_open()) {
		int x, y;
		in >> x;
		setBoxSize(x);
		in >> x >> y;
		point pS(x, y);
		setStart(pS);
		in >> x >> y;
		point pE(x, y);
		setEnd(pE);
		char c;
		for (int i = (767/getBoxSize()); i >= 0; i--) {
			for (int j = 0; j < (1024/getBoxSize()); j++) {
				in >> c;
				if (c == '1')
					setRegionData(j, i, true);
				else if (c == '0')
					setRegionData(j, i, false);

			}
		}
		in.close();
	}
}