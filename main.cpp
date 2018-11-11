#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>

#include "head.h"

int main()
{
	Stack * stackpoint = new Stack(10);

	for(int i = 0; i < 8; i++)
	{
		stackpoint->StackPush(i + 1);
		stackpoint->StackDump();
	}

	printf("first\n\n");

	for (int i = 8; i < 21; i++)
		stackpoint->StackPush(i + 1);
	stackpoint->StackPrint();

	printf("second\n\n\n");

	for (int i = 0; i < 10; i++)
		stackpoint->StackPop();
	stackpoint->StackPrint(); 

	Mytype top = stackpoint->StackTop();
	std::cout << "2The highest element is " << top << std::endl << std::endl;

	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPop();
	stackpoint->StackPrint();  

	top = stackpoint->StackTop();
	std::cout << "3The highest element is " << top << std::endl;

	stackpoint->StackPop();
	stackpoint->StackPrint(); 

	top = stackpoint->StackTop();
	//std::cout << "4The highest element is " << top << std::endl;
	return 0;
}
