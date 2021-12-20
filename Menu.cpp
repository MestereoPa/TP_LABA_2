
#include "Menu.h"
#include <fstream>
void menuForRoute()
{
	Route *newRout;
	Keeper routVec;
	int choise, index;
	do
	{
		system("cls");
		cout << "�������� ��������:" << endl;
		
		cout << "1 - �������� ����� �������" << endl;
		cout << "2 - ������������� ������������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ���������� �� �������� ������ ��������" << endl;
		cout << "5 - ����� �� ������ ��������" << endl;
		cout << "6 - ����� ���� ��������� �� �����" << endl;
		cout << "0 - �����" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "������� �����, ����� ������ �������� � ����� ����� ��������" << endl;
			newRout = new Route;
			cin >> *newRout;
			routVec.push(newRout);
			break;
		case 2:
			routVec.get();
			cout << "������� ������ �������� ��� ��������������" << endl;
			cin >> index;
			routVec[index - 1]->red();
			break;
		case 3:
			routVec.get();
			cout << "������� ������ �������� ��� ��������" << endl;
			cin >> index;
			routVec.del(index);
			break;
		case 4:
			routVec.numberSort();
			break;
		case 5:
			cout << "������� ����� �������� ��� �������" << endl;
			cin >> index;
			routVec.numberSerch(index);
			break;
		case 6:
			routVec.get();
			break;
		case 0:
			break;
		default:
			cout << "��������� ����" << endl;
			break;
		}
		system("pause");
	}while (choise != 0);
}

void menuForFile()
{
	ifstream fin("TEXT.txt", ios_base::in);
	char sim = ' ', prewSim;
	int flag = 0, flag2 = 0, flag3 = 0;
	int i = 0;
	string word = "";
	cout << "��������� ������������ ������" << endl;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			prewSim = sim;
			fin.get(sim);
			if (checkSim(sim) != 0)
			{
				if (flag2 == 0)
				{
					if (checkSim(sim) == 1)
					{
						flag = 1;
					}
					flag2 = 1;
				}
				word += sim;
			}
			else
			{
				if (flag2 == 1)
				{
					if ((checkSim(prewSim) == 1) && (flag == 1))
					{
						cout << word << ' ';
						flag3 = 1;
					} 
					
				}
				flag = 0;
				flag2 = 0;
				if (sim == '\n' && flag3 == 1)
				{
					cout << endl;
					flag3 = 0;
				}
				word = "";
			}	
		}
		fin.close();
	}

}
int checkSim(char sim)
{
	if ((sim == 'a') | (sim == 'e') | (sim == 'u') | (sim == 'i') | (sim == 'o') | (sim == 'y') | (sim == 'A') | (sim == 'E') | (sim == 'U') | (sim == 'I') | (sim == 'O') | (sim == 'Y'))
	{
		return 1;
	}
	if ((sim == 'q') | (sim == 'w') | (sim == 'r') | (sim == 't') | (sim == 'p') | (sim == 's') | (sim == 'd') | (sim == 'f') | (sim == 'g') | (sim == 'h') | (sim == 'j') | (sim == 'k') | (sim == 'l') | (sim == 'z') | (sim == 'x') | (sim == 'c') | (sim == 'v') | (sim == 'b') | (sim == 'n') | (sim == 'm') | (sim == 'Q') | (sim == 'W') | (sim == 'R') | (sim == 'T') | (sim == 'P') | (sim == 'S') | (sim == 'D') | (sim == 'F') | (sim == 'G') | (sim == 'H') | (sim == 'J') | (sim == 'K') | (sim == 'L') | (sim == 'Z') | (sim == 'X') | (sim == 'C') | (sim == 'V') | (sim == 'B') | (sim == 'N') | (sim == 'M'))
	{
		return 2;
	}
	return 0;
}