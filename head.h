#include <string>

#ifndef HEAD_H_
#define HEAD_H_

#define TESTING()								\
	do                                          \
	{											\
		error = StackOK();						\
		if(error != 0)                          \
			StackDump();						\
	}while(0)

typedef double Mytype;

const int CANARY = 42;

static std::string DESCRIPT[] = 
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

#endif

