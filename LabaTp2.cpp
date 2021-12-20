#include "Menu.h"
int main()
{
	setlocale(LC_ALL, "rus");
	int choise;
	do
	{
		cout << "Выберите задание \n1 - работа с классом Route \n2 - работа с потоком \n0 - выход"<<endl;
		cin >> choise;
		if (choise == 1)
		{
			menuForRoute();
		}
		else
		{
			if (choise == 2)
			{
				menuForFile();
			}
			else
			{
				
			}
		}
	}while (choise != 0);
	return 0;
}

