#include "Keeper.h"
Keeper::Keeper()
{
	head->ptr = 0;
	size = 0;
	cout << "конструктор Keper " << endl;
};
Keeper::Keeper(Route *newElem)
{
	head->element = newElem;
	head->ptr = 0;
	size = 1;
};
Keeper::~Keeper()
{
	elem* bufHead = head;
	
	for (int i = 0; i < size - 2; i++)
	{	
		head = head->ptr;
		delete bufHead->element;
		delete bufHead;
		bufHead = head;
	}
	delete head;
	cout << "диструктор Keeper " << endl;
}
Route Keeper::pop()
{
	try
	{
		elem *bufHead = head;
		if (size == 0)
		{
			throw "Нет элементов";
		}
		Route a( *(head->element));
		if (head->ptr != 0)
		{
			delete(bufHead->element);
			head = head->ptr;
			size--;
			delete(bufHead);
		}
		else
		{
			delete(head->element);
			size--;
		}
		return a;
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
};

Route* Keeper::operator[] (const int ind)
{
	try
	{
		
		if ((ind >= size) || (ind < 0))
		{
			throw "неверный индекс";
		}
		elem* buf = head;
		for (int i = 0; i < size - ind - 1; i++)
		{
			buf = buf->ptr;
		}
		return (buf->element);
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
}
void Keeper::del(int ind)
{
	elem* buf = head, *buf2 = head;
	if (size == 0)
	{
		cout << "нет элементов" << endl;
	}
	else
	{
		if (ind == 0)
		{
			cout << "нет элемента" << endl;
		}
		else
		{
			if (ind == size)
			{
				pop();
			}
			else
			{
				for (int i = 1; i < size - ind; i++)
				{
					buf = buf->ptr;
				}
				buf2 = buf->ptr;
				if (ind == 1)
				{
					delete(buf2->element);
					delete(buf2);
					buf->ptr = 0;
					size--;
				}
				else
				{
					if (ind < size || ind > 0)
					{
						buf2 = buf2->ptr;
						delete(buf->ptr->element);
						delete(buf->ptr);
						buf->ptr = buf2;
						size--;
					}
					else
					{
						cout << " Нет такого элемента" << endl;
					}
				}
			}
		}

	}
}
void Keeper::get()
{
	cout << "Количество элементов size = " << size << endl;
	cout << "Элементы : " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "элемент номер " << i + 1 << endl;
		cout << "___________________________________________________________" << endl;
		(*this)[i]->get();
		cout << "___________________________________________________________" << endl;
	}
	cout << endl;
}
void Keeper::push(Route *a)
{
	elem* newHead;
	newHead = new elem;
	newHead->element = a;
	if (size == 0)
	{
		newHead->ptr = 0;
	}
	else
	{
		newHead->ptr = head;
	}
	head = newHead;
	size++;
};
void Keeper::numberSort()
{
	 Route buf;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i-1; j++)
		{
			if ((*this)[j]->number() < (*this)[j+1]->number())
			{
				buf = *(*this)[j];
				*(*this)[j] = *(*this)[j + 1];
				*(*this)[j + 1] = buf;
			}
		}
	}
}
int Keeper::numberSerch(int serchNumb)
{
	for (int i = 0; i < size; i++)
	{
		if ((*this)[i]->number() == serchNumb)
		{
			cout << "Искомый номер " << endl << *(*this)[i] << endl;
			return i;
		}
	}
	cout << "Искомый номер не был найден ";
	return 0;
}
int Keeper::sizeGet()
{
	return size;
}