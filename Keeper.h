#pragma once
#include "Route.h"

class elem
{
public:
	elem* ptr;
	Route* element;
};

class Keeper
{
public:
	Keeper();
	Keeper(Route *newElem);
	~Keeper();
	Route pop();
	Route* operator[] (const int ind);
	void del(int ind);
	void get();
	void push(Route* a);
	int sizeGet();
	void numberSort();
	int numberSerch(int serchNumb);
	
private:
	elem* head = new elem;
	int size;
};



