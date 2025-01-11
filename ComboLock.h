#ifndef COMBOLOCK_H
#define COMBOLOCK_H


#include <iostream>
#include <iomanip>

using namespace std;

const int VALUES = 40;
const int NTURNS = 3;

class ComboLock
{
public:
	ComboLock(int secret1, int secret2, int secret3);
	void reset();
	void turn_left(int ticks);
	void turn_right(int ticks);
	bool open() const;

private:
	int combination[NTURNS];
	int actual[NTURNS];
	int turns;
	int direction;
	int position;
};

#endif
