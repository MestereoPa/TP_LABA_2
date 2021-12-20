#pragma once
#include <iostream>
#include <new>
#include <string>
using namespace std;
class Route
{
	string nameStart;
	string nameFinish;
	int routNumber;
public:
	Route();
	Route(const Route& a);
	Route(string newStart, string newFinish, int newRout);
	~Route();
	void get();
	void set();
	void red();
	void redNumb(int newNumb);
	int number();
	friend std::ostream& operator<< (std::ostream &out, const Route &Route);
	friend std::istream& operator>> (std::istream &in, Route &Route);
	Route& operator= (const Route &Route)
	{
		nameStart = Route.nameStart;
		nameFinish = Route.nameFinish;
		routNumber = Route.routNumber;
		return *this;
	}
};

