#include "globals.h"

void drawLoadSaveOps() {
	drawBox(1038, 590, 1200, 635, white, black);
	drawBox(1210, 590, 1372, 635, white, black);
	drawBox(1038, 640, 1372, 685, white, black);
	drawText("Load Map", 1075, 605);
	drawText("Save Map", 1247, 605);
	drawText((char*)getFileName(), 1075, 655);
}


void keyboardLoadSaveOps(unsigned char key, int x, int y) {
	if (key == 8) {
		string s = getFileName();
		if (s.size() > 0) {
			s = s.substr(0, s.size() - 1);
			setFileName(s);
		}
	}
	else {
		string s = getFileName();
		s.push_back(key);
		setFileName(s);
	}
}

void mouseLoadSaveOps(int button, int state, int x, int y) {
	if (x > 1038 && x < 1200 && y > 590 && y < 635 && button == 0 && state == 0) {
		//handle load button
		cout << "Loading " << getFileName() << " from system..." << endl;
	}

	if (x > 1210 && x < 1372 && y > 590 && y < 635 && button == 0 && state == 0) {
		// handle save button
		cout << "Saving " << getFileName() << " to system..." << endl;
		ofstream out;
		out.open(getFileName());
		out << getBoxSize() << " " << getStartX() << " " << getStartY() << " " << getEndX() << " " << getEndY() << endl;
		/*for (int i = 767; i >= 0; i--) { // i is y (rows)
			for (int j = 0; j < 1024; j++) { // j is x (columns)
				if (getEditorValue(j / getBoxSize(), i/getBoxSize()) == true) {
					out << "t";
				}
				else {
					out << "f";
				}
			}
			out << endl;
		}*/
		for (int i = (767 / getBoxSize()); i >= 0; i--) { // y value
			for (int j = 0; j < (1024 / getBoxSize()); j++) { // x value
				out << getEditorValue(j, i);
			}
			out << endl;
		}
		out.close();
		cout << "Saved " << getFileName() << "." << endl;
	}
}