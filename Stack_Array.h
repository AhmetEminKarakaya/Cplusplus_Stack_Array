#pragma once

#include <iostream>
#include "stack.h"

template<class T>
class Stack_Array : public stack<T>
{
	int stackTop;
	int arrayLength;
	T* stack;

public:
	Stack_Array(int intial_capacity = 10)
	{
		if (intial_capacity < 1)
			printf("Stack_Array error...");
		else
		{
			arrayLength = intial_capacity;
			stack = new T[arrayLength];
			stackTop = -1;
		}

	}

	~Stack_Array() { delete[] stack; }

	bool empty() const { return stackTop == -1; }

	int size()const { return stackTop + 1; }

	T& top()
	{
		if (stackTop == -1)
		{
			cout << "Array is empty" << endl;
			return NULL;
		}
		return stack[stackTop];
	}

	void pop()
	{
		if (stackTop == -1)
			cout << "Array is empty" << endl;

		stack[stackTop--].~T();	
	}

	void push(const T& theElement)
	{
		if (stackTop == arrayLength - 1)
		{
			int newLength = 2 * arrayLength;
			T* temp = new T[newLength];
			copy(stack, arrayLength, temp);
			delete[] stack;
			stack = temp;
		}
		stack[++stackTop] = theElement;
	}
};