#ifndef __CREATURE_H_
#define __CREATURE_H_

class creature {
public:
	creature();
	~creature();
	char* getPath();
	char getMovement(int i);
	void setLocation(int x, int y);
	int getX();
	int getY();
	void setPath(char* newPath);
	void mutate();
	void moveCreature(int currFrame);
	double getFitness();

private:
	int posX;
	int posY;
	char* path;
	double fitness; // <-- prob don't need to store this.. owell
};

#endif