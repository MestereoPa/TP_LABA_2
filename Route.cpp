#include "Route.h"
Route::Route()
{
	cout << "Конструктор route"<< endl;
}
Route::Route(const Route& a)
{
	nameStart = a.nameStart;
	nameFinish = a.nameFinish;
	routNumber = a.routNumber;
	cout << "Конструктор route" << endl;
}
Route::Route(string newStart, string newFinish, int newRout)
{
	nameStart = newStart;
	nameFinish = newFinish;
	routNumber = newRout;
	cout << "Конструктор route" << endl;
}
Route::~Route()
{
	cout << "Диструктор route" << endl;
}
void Route::get()
{
	cout << "номер маршрута : "<< routNumber<< endl;
	cout << "Название начала маршрута : " << nameStart << endl;
	cout << "Название конца маршрута : " << nameFinish << endl;
}
void Route::set()
{
	cout << "Введите номер маршрута : " << endl;
	cin >> routNumber;
	cin.ignore(32767, '\n');
	cout << "Введите название начала маршрута : " << endl;
	getline(cin, nameStart);
	cout << "Введите название конца маршрута : " << endl;
	getline(cin, nameFinish);
}

void Route::red()
{
	int choise;
	cout << "Выберите что поменять" << endl << "1 - Номер маршрута " << endl << "2 - название начала маршрута" << endl << "3 - название конца маршрута" << endl;
	cin >> choise;
	if (choise == 1)
	{
		cout << "Введите номер маршрута : " << endl;
		cin >> routNumber;
		cin.ignore(32767, '\n');
	}
	else
	{
		if (choise == 2)
		{
			cout << "Введите название начала маршрута : " << endl;
			getline(cin, nameStart);
		}
		else
		{
			if (choise == 3)
			{
				cout << "Введите название конца маршрута : " << endl;
				getline(cin, nameFinish);
			}
			else
			{
				cout << "Неверный ввод" << endl;
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

	out << "номер маршрута : " << Route.routNumber << endl << "Название начала маршрута : " << Route.nameStart << endl << "Название конца маршрута : " << Route.nameFinish << endl;
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

