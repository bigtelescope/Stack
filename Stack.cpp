#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define TESTING()									    \
	do{													\
	if(StackOK() != 0) printf("Something wrong!\n");	\
	}while(0)

const int CANARY = 42;

typedef double Mytype;

enum ERRORS
{
	STACK_OVERFLOWED = 1,
	CANARY_BROKED = 2,
	INCORRECT_VALUES = 3,
	INCORRECT_HASH = 4,
};

class Stack
{
private:
	int 		canary1;
	int 		size;     
	int 		amount;
	int 		hash;	
	Mytype * 	data;
	int 		canary2;

public:
	Stack();
	Stack(int init_size);
	~Stack();
	int ReSize();
	int StackPush	(Mytype value);
	int StackPop	();
	int StackOK		();
	int StackHash   ();
	int StackDump	();
	int StackClear	();
	void StackPrint ();
};

Stack::Stack(int init_size)
{
	canary2 = CANARY;
	canary1 = CANARY;
	size = init_size;
	amount = 0;
	hash = 0;
	data = (Mytype *)calloc(size + 2, sizeof(Mytype));
	data[0] = canary1;
	data[size + 1] = canary2;
}

Stack::~Stack()
{
	if(size != 0)
		delete[] data;///null
}

int Stack::ReSize()
{
	this->size *= 2;
	this->data = (Mytype *)realloc((Mytype *)this->data, (this->size + 2)*sizeof(Mytype));
	*(this->data + this->size / 2 + 1) = 0;
	*(this->data + this->size + 1) = canary2; 

	if(this->data != NULL)
		return 0;
	else
		perror("Shit happened");                     ////////////////wtf?
	return 0;
}

int Stack::StackPush(Mytype value)
{
	TESTING();

	if(!std::isfinite(value))
		perror("Shit happened");					////////////////wtf?

	if(this->size == 0)
		perror("Shit happened");

	this->data[this->amount + 1] = value;
	this->amount++;

	this->hash = StackHash();

	return 0;
}

int Stack::StackPop()
{
	if(this->amount == 0)
		perror("Stack is empty");                    ////////////////wtf?

	if(this->size == 0)
		perror("Too few space");                    ////////////////wtf?

	this->data[this->amount + 1] = 0;
	this->amount--;

	return 0;
}

int Stack::StackOK()
{

	if(this->canary2 != CANARY || this->canary1 != CANARY)
		return CANARY_BROKED;
	if(*(this->data + this->size + 1) != CANARY || *(this->data) != CANARY)
		return CANARY_BROKED;
	if(this->size < 0 || this->amount < 0 || this->data == NULL)
		return INCORRECT_VALUES;
	if(this->hash != StackHash())
		return INCORRECT_HASH;
	return 0;
}

int Stack::StackHash()
{
	int sum = 0;
	for(int i = 0; i < amount; ++i)
	{
		sum += *(char*)&data[i];

	}
	sum ^= size;
	sum &= amount;
	return sum;
}

void Stack::StackPrint()
{
	for(int i = 0; i < this->size; i++)
		std::cout << "The " << i + 1 << " element of a stack is " << this->data[i + 1] << std::endl;
	std::cout  << std::endl;
}

int main()
{
	Stack * stackpoint = new Stack(6);
	stackpoint->StackPrint();
	stackpoint->StackPush(15);
	stackpoint->StackPush(14);
	stackpoint->StackPush(13);
	stackpoint->StackPop();
	stackpoint->StackPush(12);
	stackpoint->StackPush(11);
	stackpoint->StackPrint();
	stackpoint->ReSize();
	stackpoint->StackPrint();
	return 0;
}

