#include "class.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;

int main() {

	Management * Test = new Management;
	bool option = help(*Test);
	while (option != false)
	{
		cout << endl << endl;
		option = help(*Test);
	}
	delete Test;

    system("PAUSE");
};