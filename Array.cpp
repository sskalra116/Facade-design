
#include <stdexcept>
#include "Array.h"

//base member initialization
Array::Array (void)

	:cur_size_(0),
	max_size_(0),
	data_(0)
{

}
//base member initialization with parameters
Array::Array (size_t length)

	:data_(new char[length]),
	cur_size_(length),
	max_size_(length)
{
	
}

Array::Array (size_t length, char fill)

	:data_(new char[length]),
	cur_size_(length),
	max_size_(length)

{
    for(int i=0;i<cur_size_;i++)
		data_[i]=fill;
}


Array::Array (const Array & array)

    :cur_size_(array.size()),
    max_size_(array.max_size())

{
    Array::assign(array);
}

Array::~Array (void)
{
	delete[] data_;
	data_=0;
}

const Array & Array::operator = (const Array & rhs)
{
	if(data_!=rhs.data_)
	{
		resize(rhs.cur_size_);
		assign(rhs);
	}
	return *this;

}

char & Array::operator [] (size_t index)
{
	if(index<cur_size_)
		return data_[index];
	else
		throw std::out_of_range("exception");
}

const char & Array::operator [] (size_t index) const
{
	return data_[index];
}

char Array::get (size_t index) const
{
	if(index<cur_size_)
		return data_[index];
	else
		throw std::out_of_range("exception");
}

void Array::set (size_t index, char value)
{
	if(index<max_size_)
		data_[index]=value;
	else
		throw std::out_of_range("exception");
}

void Array::resize (size_t new_size)
{
    if(max_size_ < new_size)
        max_size_=new_size;
	char * arr=new char[new_size];
    for(int i=0;i<cur_size_;i++)
        arr[i]=this->data_[i];
    for(size_t i=cur_size_;i<new_size;i++)
        arr[i]='-';
	cur_size_=new_size;
	delete[] data_;
	this->data_=arr;
}

int Array::find (char ch) const
{
	int i,flag=0;
	for(i=0;i<cur_size_;i++)
	{
		if(data_[i]==ch)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return i;
	else
		return -1;
}


int Array::find (char ch, size_t start) const
{
	int flag=0;
	size_t i;
	if(start<cur_size_)
	{
		for(i=start;i<cur_size_;i++)
		{
			if(data_[i]==ch)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			return i;
		else
			return -1;
	}
	else
		throw std::out_of_range("invalid");
}

bool Array::operator == (const Array & rhs) const
{
	int counter=0;
	for(int i=0;i<cur_size_;i++)
	{
		if(data_[i]==rhs.data_[i])
			counter++;
	}
	if(counter==cur_size_)
		return true;
	else
		return false;
}

bool Array::operator != (const Array & rhs) const
{
	int counter=0;
	for(int i=0;i<cur_size_;i++)
	{
		if(data_[i]!=rhs.data_[i])
			counter++;
	}
	if(counter==0)
		return false;
	else
		return true;
}

void Array::fill (char ch)
{
	for(int i=0;i<cur_size_;i++)
		data_[i]=ch;
}

void Array::shrink (void)
{
	char * arr=new char[cur_size_];
	for(int i=0;i<cur_size_;i++)
		arr[i]=this->data_[i];
	max_size_=cur_size_;
	delete[] data_;
	this->data_=arr;
}

void Array::reverse (void)
{
	int i,j;
	char c;
	for(i=0,j=cur_size_-1;i<cur_size_/2;i++,j--)
	{
		c=data_[i];
		data_[i]=data_[j];
		data_[j]=c;
	}
}
void Array::assign(const Array & rhs)
{
    data_=new char[cur_size_];
    for(size_t i=0;i<cur_size_;i++)
        data_[i]=rhs.data_[i];
}
