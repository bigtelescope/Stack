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
	stackpoint->StackPush(1);
	stackpoint->StackPrint();
	stackpoint->StackPush(2);
	stackpoint->StackPrint();
	stackpoint->StackPush(3);
	stackpoint->StackPrint();
	stackpoint->StackPush(4);
	stackpoint->StackPrint();
	stackpoint->StackPush(5);
	stackpoint->StackPrint();
	stackpoint->StackPush(6);
	stackpoint->StackPrint();
	stackpoint->StackPush(7);
	stackpoint->StackPrint();
	stackpoint->StackPush(8);
	stackpoint->StackPrint();
	stackpoint->StackPush(9);
	//stackpoint->StackDump();
	stackpoint->StackPush(10);
	stackpoint->StackPrint();
	stackpoint->StackPush(11);
	stackpoint->StackPrint();
	stackpoint->StackPush(12);
	stackpoint->StackPush(13);
	stackpoint->StackPush(14);
	stackpoint->StackPush(15);
	stackpoint->StackPush(16);
	stackpoint->StackPush(17);
	stackpoint->StackPush(18);
	stackpoint->StackPush(19);
	stackpoint->StackPush(20);
	stackpoint->StackPush(21);
	stackpoint->StackPush(22);
	stackpoint->StackPush(23);
	stackpoint->StackPush(24);
	stackpoint->StackPush(25);
	stackpoint->StackPush(26);
	stackpoint->StackPush(27);
	stackpoint->StackPush(28);
	stackpoint->StackPush(29);
	stackpoint->StackDump();
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
	stackpoint->StackDump();
	return 0;
}
