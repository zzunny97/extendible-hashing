#include "bucket.h"

/* Bucket class functions */
Bucket::Bucket(int depth, int size)
{
	this->depth = depth;
	this->size = size;
}

int Bucket::insert(int key, std::string value)
{
	std::map<int,std::string>::iterator it;
	it = values.find(key);
	if(it!=values.end())
		return -1;
	if(isFull())
		return 0;
	values[key] = value;
	return 1;
}

int Bucket::remove(int key)
{
	std::map<int,std::string>::iterator it;
	it = values.find(key);
	if(it!=values.end())
	{
		values.erase(it);
		return 1;
	}
	else
	{
		std::cout<<"Cannot remove : This key does not exists"<<std::endl;
		return 0;
	}
}

int Bucket::update(int key, std::string value)
{
	std::map<int,std::string>::iterator it;
	it = values.find(key);
	if(it!=values.end())
	{
		values[key] = value;
		std::cout<<"Value updated"<<std::endl;
		return 1;
	}
	else
	{
		std::cout<<"Cannot update : This key does not exists"<<std::endl;
		return 0;
	}
}

void Bucket::search(int key)
{
	std::map<int,std::string>::iterator it;
	it = values.find(key);
	if(it!=values.end())
	{
		std::cout<<"Value = "<<it->second<<std::endl;
	}
	else
	{
		std::cout<<"This key does not exists"<<std::endl;
	}
}

int Bucket::isFull(void)
{
	if(values.size()==size)
		return 1;
	else
		return 0;
}

int Bucket::isEmpty(void)
{
	if(values.size()==0)
		return 1;
	else
		return 0;
}

int Bucket::getDepth(void)
{
	return depth;
}

int Bucket::increaseDepth(void)
{
	depth++;
	return depth;
}

int Bucket::decreaseDepth(void)
{
	depth--;
	return depth;
}

std::map<int, std::string> Bucket::copy(void)
{
	std::map<int, std::string> temp(values.begin(),values.end());
	return temp;
}

void Bucket::clear(void)
{
	values.clear();
}

void Bucket::display()
{
	std::map<int,std::string>::iterator it;
	for(it=values.begin();it!=values.end();it++)
		std::cout<<it->first<<" ";
	std::cout<<std::endl;
}
