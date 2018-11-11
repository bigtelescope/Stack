#include <string>

#ifndef HEAD_H_
#define HEAD_H_

/*! \brief Checks state of stack
	This define checks a correctness of size of a stack, amount of elements and so on 
	If there is an error in code, this error will be analysed by StackDump function*/
#define TESTING()											\
	do                                          			\
	{	if(!error)											\
		{													\
			error = StackOK();								\
			if(error != STACK_IS_OK)            			\
				StackDump();								\
		}													\
		else 												\
			std::cout << DESCRIPT[error] << std::endl;   	\
	}while(0)

/* MyType, you can change it on your own*/
typedef double Mytype;

/* Canary is a little bird, who will be proud of her death*/
const int CANARY = 42;

/* This array involve descriptions of errors*/
static std::string DESCRIPT[] = 
{
	"There are too many elements in your stack",
	"One of your canaries was broken",
	"Using incorrect values!",
	"Your hash was broken",
	"There are no elements in your stack",
	"Your stack is too small. Maybe ReSize() works incorrectly",
};

enum ERRORS
{
	STACK_IS_OK 	 = 0,
	STACK_OVERFLOWED = 1,
	CANARY_BROKED    = 2,
	INCORRECT_VALUES = 3,
	INCORRECT_HASH   = 4,
	STACK_IS_EMPTY   = 5,
	STACK_IS_TOO_SMALL = 6,
};

/* My stack*/
class Stack
{
private:
	int 		canary1; //< first canary
	int 		size;    //< size of a buffer for elements
	int 		amount;  //< means an amount of elements in a stack
	int 		hash;	 //< ¯\_(ツ)_/¯
	Mytype * 	data;	 //< pointer to an array of elements
	int 		error;	 //< involves a number of an error
	int 		canary2; //< second canary

public:
	Stack           	();
	Stack           	(int init_size);//< constructs stack with <init_size> size
	~Stack          	();
	int ReSize      	(double resize);//< changed a size of an array of elements
	int StackPush		(Mytype value); //< puts a <value> into a stack
	int StackPop		();				//< pulls out the last element
	Mytype StackTop		();				//< returns the last element of a stack
	int StackOK			();				//< checks a state of a stack
	int StackHash   	();				//< counts hash
	void StackDump		();				//< beautiful analyse of an error 
	int StackClear		();				//< clears an array
	void StackPrint 	();				//< prints all elements of an array
	Stack 				(const Stack & s) = delete;
	Stack & operator =  (const Stack & s) = delete;
};

#endif

