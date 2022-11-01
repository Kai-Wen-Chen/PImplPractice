#include <iostream>
#include <time.h>
#include "Foo.h"

#pragma comment(linker, "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")
int main() {
	Foo foo;
	srand(time(nullptr));
	for (int i=0; i<10; ++i) {
		int n = rand() % 3;
		foo.print(n);
	}

	std::cout << "press Enter to continue" << std::endl;
	getc(stdin);
	return 0;
}