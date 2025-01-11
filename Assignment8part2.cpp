#include <iostream>
#include <string>
using namespace std;
#include "ComboLock.h"
int main()
{
	ComboLock lock(17, 2, 9);
	lock.turn_right(10);
	lock.turn_right(7);
	lock.turn_left(10);
	lock.turn_left(5);
	lock.turn_right(7);
	cout << "Open: " << boolalpha << lock.open() << endl;
	return 0;
}


