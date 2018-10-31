#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define TESTING()								\
	do                                          \
	{											\
		error = StackOK();						\
		if(error != 0)                          \
			StackDump();						\
	}while(0)

typedef double Mytype;

const int CANARY = 42;

std::string ERRORS[] = 
{
	"There are too many elements in your stack",
	"One of your canaries was broken",
	"Using incorrect values!",
	"Your hash was broken",
	"There are no elements in your stack",
	"Your stack is too small",
};

enum ERRORS
{
	STACK_OVERFLOWED = 1,
	CANARY_BROKED    = 2,
	INCORRECT_VALUES = 3,
	INCORRECT_HASH   = 4,
	STACK_IS_EMPTY   = 5,
	STACK_IS_TOO_SMALL = 6,
};

class Stack
{
private:
	int 		canary1;
	int 		size;     
	int 		amount;
	int 		hash;	
	Mytype * 	data;
	int 		error;
	int 		canary2;

public:
	Stack           ();
	Stack           (int init_size);
	~Stack          ();
	int ReSize      (double resize);
	int StackPush	(Mytype value);
	int StackPop	();
	int StackOK		();
	int StackHash   ();
	void StackDump	();
	int StackClear	();
	void StackPrint ();
	Stack 			(const Stack & s) = delete;
	Stack & operator = (const Stack & s) = delete;
};

Stack::Stack(int init_size) :
	canary1(CANARY),
	size(init_size),
	amount(0),
	hash(0),
	data((Mytype *)calloc(size + 2, sizeof(Mytype))),
	error(0),
	canary2(CANARY)
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

	if(resize >= 1)
		size = (int)(size * resize);
	if(resize < 1)
		size = (int)(size / 2);
	data = (Mytype *)realloc((Mytype *)data, (size + 2)*sizeof(Mytype));
	*(data + size / 2 + 1) = 0;
	*(data + size + 1) = canary2; 
	hash = StackHash();

	if(data != NULL)
		return 0;
	else
		return error = INCORRECT_VALUES;

	TESTING();
	return 0;
}

int Stack::StackPush(Mytype value)
{
	TESTING();
	/*if(!std::isfinite(value))
		return error = INCORRECT_VALUES;*/

	if(size == 0)
		return error = STACK_IS_EMPTY;

	if(size < (2 * amount))
		ReSize(2);
	if(size > (4 * amount))
		ReSize(1/2);

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

	data[amount + 1] = 0;
	amount--;
	hash = StackHash();

	TESTING();
	return 0;
}

int Stack::StackOK()
{
	#pragma GCC diagnostic ignored "-Wfloat-equal"

	if(canary2 != CANARY || canary1 != CANARY)
		return CANARY_BROKED;
	if(*(data + size + 1) != CANARY || *(data) != CANARY)
		return CANARY_BROKED;
	if(size < 0 || amount < 0 || data == NULL)
		return INCORRECT_VALUES;
	if(hash != StackHash())
		return INCORRECT_HASH;
	return 0;

	#pragma GCC diagnostic warning "-Wfloat-equal"
}


int Stack::StackHash()
{
	int sum = 0;
	for(int i = 1; i < amount + 1; i++)
	{
		sum += *(char*)&data[i];

	}
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
	std::cout << ERRORS[error -1];
	std::cout  << std::endl;
}

void Stack::StackPrint()
{
	for(int i = 0; i < size; i++)
		std::cout << "The " << i + 1 << " element of a stack is " << data[i + 1] << std::endl;
	std::cout  << std::endl;
}

int main()
{
	Stack * stackpoint = new Stack(6);

/*	Stack stk(10);

	stk.SayHello();
	stk.StackPush(32123);
	stk.StackPrint();
	// *((int*)(&stk) + 2) = 0;

	stk.StackPush(1);

	stk.SayHello();

	printf("%d\n", *(int*)&stackpoint);
	printf("%d\n", *((int*)&stackpoint + 1));
	printf("%d\n", *((int*)&stackpoint + 2));
*/

	stackpoint->StackPrint();
	stackpoint->StackPush(15);
	stackpoint->StackPush(14);
	stackpoint->StackPush(13);
	stackpoint->StackPop();
	stackpoint->StackPush(12);
	stackpoint->StackPrint();
	//stackpoint->ReSize(2);
	stackpoint->StackPrint();
	return 0;
}
