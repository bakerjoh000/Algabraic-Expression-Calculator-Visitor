// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
#include <stdexcept>

#include "Array.h"

template <typename T>
Array<T>::Array(void)
:cur_size_(0),
max_size_(0),
data_(nullptr)
{

}

template <typename T>
Array<T>::Array(size_t length)
:cur_size_(length),
max_size_(length),
data_(new T[length])
{

}

template <typename T>
Array<T>::Array(size_t length, T fill)
:cur_size_(length),
max_size_(length),
data_(new T[length])
{
	Array::fill(fill);
}


template <typename T>
Array<T>::Array(const Array & arr)

:cur_size_(arr.size()),
max_size_(arr.max_size()),
data_(new T[arr.max_size()])
{


	for (int i = 0; i < cur_size_; i++)
		data_[i] = arr.data_[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] data_;
}

template <typename T>
const Array<T> & Array<T>::operator = (const Array & rhs)
{

	if (data_ != rhs.data_) {
		copy(rhs);
	}

	return *this;
}

template <typename T>
T & Array<T>::operator [] (size_t index)
{

	if (index >= cur_size_)
		throw std::out_of_range("Index out of range.");

	return data_[index];
}

template <typename T>
const T & Array<T>::operator [] (size_t index) const
{

	if (index >= cur_size_)
		throw std::out_of_range("Index out of range.");

	return data_[index];
}

template <typename T>
T Array<T>::get(size_t index) const
{

	if (index < cur_size_)
		return data_[index];

	else
		throw std::out_of_range("Index out of range.");


}

template <typename T>
void Array<T>::set(size_t index, T value)
{

	if (index < cur_size_)
		data_[index] = value;

	else
		throw std::out_of_range("Index out of range.");
}

template <typename T>
void Array <T>::resize(size_t new_size)
{

	if (new_size > this->max_size())
	{
		T *n_data = new T[new_size];

		for (size_t i = 0; i < this->cur_size_; i++)
		{
			n_data[i] = this->data_[i];
		}
		delete[] this->data_;

		this->cur_size_ = new_size;
		this->max_size_ = new_size;

		this->data_ = n_data;

	}
	else if (new_size < this->size())
	{
		this->cur_size_ = new_size;


	}

}

template <typename T>
int Array<T>::find(T element) const
{
	for (int i = 0; i < cur_size_; i++)
	{
		if (element == Array<T>::get(i))
			return i;

	}
	return -1;
}

template <typename T>
int Array<T>::find(T element, size_t start) const
{

	if (start > cur_size_)
		throw std::out_of_range("Index out of range.");

	else {
		for (size_t i = start; i < cur_size_; i++)
		{
			if (element == Array<T>::get(i))
				return i;

		}
	}

	return -1;
}

template <typename T>
bool Array<T>::operator == (const Array & rhs) const
{

	if (cur_size_ != rhs.size())
		return false;

	for (int i = 0; i < cur_size_; i++)
	{
		if (data_[i] != rhs.data_[i])
			return false;
	}

	return true;

}

template <typename T>
bool Array<T>::operator !=(const Array & rhs) const
{
	return !(*this == rhs);
}

template <typename T>
void Array<T>::fill(T element)
{
	for (int i = 0; i < cur_size_; i++)
		data_[i] = element;

}

//template <typename T>
//void Array<T>::shrink()
//{
//
//
//	T * temp = new char[cur_size_];
//
//	for (int i = 0; i < cur_size_; i++)
//	{
//		temp[i] = data_[i];
//	}
//
//	max_size_ = cur_size_;
//
//	delete[] data_;
//	data_ = temp;
//
//
//}

//template <typename T>
//void Array<T>::reverse()
//{
//
//
//	for (int i = 0; i < (cur_size_ / 2); i++) {
//		T temp = data_[i];
//		data_[i] = data_[(cur_size_ - 1) - i];
//		data_[(cur_size_ - 1) - i] = temp;
//	}
//
//};


template <typename T>
void Array<T>::copy(const Array& arr)
{
	if (cur_size_ > 0)
	{
		delete[] data_;
		data_ = new T[cur_size_];

		for (int i = 0; i < cur_size_; i++)
			data_[i] = arr.data_[i];

	}
	else
		data_ = nullptr;

}
