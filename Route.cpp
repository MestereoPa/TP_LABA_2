#include "Route.h"
Route::Route()
{
	cout << "����������� route"<< endl;
}
Route::Route(const Route& a)
{
	nameStart = a.nameStart;
	nameFinish = a.nameFinish;
	routNumber = a.routNumber;
	cout << "����������� route" << endl;
}
Route::Route(string newStart, string newFinish, int newRout)
{
	nameStart = newStart;
	nameFinish = newFinish;
	routNumber = newRout;
	cout << "����������� route" << endl;
}
Route::~Route()
{
	cout << "���������� route" << endl;
}
void Route::get()
{
	cout << "����� �������� : "<< routNumber<< endl;
	cout << "�������� ������ �������� : " << nameStart << endl;
	cout << "�������� ����� �������� : " << nameFinish << endl;
}
void Route::set()
{
	cout << "������� ����� �������� : " << endl;
	cin >> routNumber;
	cin.ignore(32767, '\n');
	cout << "������� �������� ������ �������� : " << endl;
	getline(cin, nameStart);
	cout << "������� �������� ����� �������� : " << endl;
	getline(cin, nameFinish);
}

void Route::red()
{
	int choise;
	cout << "�������� ��� ��������" << endl << "1 - ����� �������� " << endl << "2 - �������� ������ ��������" << endl << "3 - �������� ����� ��������" << endl;
	cin >> choise;
	if (choise == 1)
	{
		cout << "������� ����� �������� : " << endl;
		cin >> routNumber;
		cin.ignore(32767, '\n');
	}
	else
	{
		if (choise == 2)
		{
			cout << "������� �������� ������ �������� : " << endl;
			getline(cin, nameStart);
		}
		else
		{
			if (choise == 3)
			{
				cout << "������� �������� ����� �������� : " << endl;
				getline(cin, nameFinish);
			}
			else
			{
				cout << "�������� ����" << endl;
			}
		}
	}
}

void Route::redNumb(int newNumb) 
{
	routNumber = newNumb; 
}
int Route::number() 
{
	return routNumber; 
}
std::ostream& operator<< (std::ostream &out, const Route &Route)
{

	out << "����� �������� : " << Route.routNumber << endl << "�������� ������ �������� : " << Route.nameStart << endl << "�������� ����� �������� : " << Route.nameFinish << endl;
	return out;
}
std::istream& operator>> (std::istream &in, Route &Route)
{
	in >> Route.routNumber;
	in.ignore(32767, '\n');
	getline(in, Route.nameStart);
	getline(in, Route.nameFinish);
	return in;
}

