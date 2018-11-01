#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>

#include "head.h"

int main()
{
	Stack * stackpoint = new Stack(6);

	stackpoint->StackPrint();
	stackpoint->StackPush(15);
	stackpoint->StackPrint();
	stackpoint->StackPush(15);
	stackpoint->StackPrint();
	stackpoint->StackPush(15);
	stackpoint->StackPrint();
	stackpoint->StackPush(15);
	stackpoint->StackPrint();
	stackpoint->StackPush(15);
	stackpoint->StackPrint();
	return 0;
}

