#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <cmath>

#include "head.h"

Stack::Stack(int init_size) :
	canary1			(CANARY),
	size			(init_size),
	amount 			(0),
	hash 			(0),
	data  			((Mytype *)calloc(size + 2, sizeof(Mytype))),
	error   		(0),
	canary2 		(CANARY)
{
	if(!data)
		error = INCORRECT_VALUES;
	data[0] = canary1;
	data[size + 1] = canary2;
	hash = StackHash();
}

Stack::~Stack()
{
	if(size != 0)
		free(data);
	data = NULL;
}

int Stack::ReSize(double resize)
{
	TESTING();

	size = (unsigned int)(size * resize);
	data = (Mytype *)realloc((Mytype *)data, (size + 2)*sizeof(Mytype));
	if(!data)
		return error = INCORRECT_VALUES;

	for(int i = amount + 1; i < size + 1; i++)
		data[i] = 0;
	*(data + size + 1) = canary2; 
	
	hash = StackHash();

	TESTING();
	return 0;
}

int Stack::StackPush(Mytype value)
{
	TESTING();

	if(!size)
		return error = STACK_IS_EMPTY;

	if(size < (2 * amount))
		ReSize(2);

	data[amount + 1] = value;
	amount++;
	hash = StackHash();

	TESTING();
	return 0;
}

int Stack::StackPop()
{
	TESTING();

	if(amount == 0)
		return error = STACK_IS_EMPTY;

	if(size == 0)
		return error = STACK_IS_TOO_SMALL;

	if(size > (4 * amount))
		ReSize(0.5);

	data[amount] = 0;
	amount--;
	hash = StackHash();

	TESTING();
	return 0;
}

Mytype Stack::StackTop()
{
	TESTING();

	if(amount == 0)
		error = STACK_IS_EMPTY; 

	if(!size)
		error = STACK_IS_TOO_SMALL;

	TESTING();
	return data[amount];
}

int Stack::StackOK()
{
	#pragma GCC diagnostic ignored "-Wfloat-equal"

	if(canary2 != CANARY || canary1 != CANARY)
		return CANARY_BROKED;
	if(*(data + size + 1) != CANARY || *(data) != CANARY)
		return CANARY_BROKED;
	if(size <= 0 || amount < 0 || data == NULL)
		return INCORRECT_VALUES;
	/*if(!size || !amount)
		return STACK_IS_EMPTY;*/
	if(hash != StackHash())
		return INCORRECT_HASH;
	return 0;

	#pragma GCC diagnostic warning "-Wfloat-equal"
}


int Stack::StackHash()
{
	int sum = 0;
	for(int i = 1; i < amount + 1; i++)
		sum += (int)data[i];
	sum ^= size;
	sum &= amount;
	return sum;
}

void Stack::StackDump()
{
	std::cout << "Information:" << std::endl;
	std::cout << "Size  =  " << size << std::endl;
	std::cout << "Amount of elements  =  " << amount << std::endl  << std::endl;
	std::cout << "Canary #1  =  " << canary1 << std::endl;
	std::cout << "Canary #2  =  " << canary2 << std::endl;
	std::cout << "Canary #3  =  " << data[0] << std::endl;
	std::cout << "Canary #4  =  " << data[size + 1] << std::endl << std::endl;
	std::cout << "Hash  =  " << hash << std::endl << std::endl;
	for(int i = 0; i < size; i++)
	{
		std::cout << data + i + 1 << "  :  ";
		std::cout << "data[" << i + 1 << "]  =  " << data[i + 1] << std::endl;
	}
	std::cout  << std::endl;
	std::cout << DESCRIPT[error - 1] << std::endl << std::endl;
	std::cout  << std::endl;
}

void Stack::StackPrint()
{
	for(int i = 0; i < size; i++)
		std::cout << "The " << i + 1 << " element of a stack is " << data[i + 1] << std::endl;
	std::cout  << std::endl;
}
