#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>

#include "head.h"

int main()
{
	Stack * stackpoint = new Stack(6);

	for(int i = 0; i < 8; i++)
	{
		stackpoint->StackPush(i + 1);
		stackpoint->StackPrint();
	}

	for (int i = 8; i < 21; i++)
		stackpoint->StackPush(i);
	stackpoint->StackPrint();

	for (int i = 0; i < 10; i++)
		stackpoint->StackPop();
	stackpoint->StackPrint(); 
	
	return 0;
}
