// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//

#include "Stack.h"

template <typename T>
Stack <T>::Stack(void)
:array_(SIZE),
top_(0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack & stack)
:array_(stack.array_),
top_(0)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack(void)
{
}

//
// push
//
template <typename T>
void Stack <T>::push(T element)
{
	size_t max = this->array_.max_size_;
	if (top_ + 1 == max)
	{
		this->array_.resize(max + 1);
	}
	this->array_.set(top_, element);
	top_++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop(void)
{
	if (is_empty())
	{
		throw new empty_exception();
	}
	else
	{
		top_--;
	}
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this = &rhs)
		return *this;

	Array<T>::copy(rhs);
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear(void)
{
	while (!is_empty())
	{
		pop();
	}
}
