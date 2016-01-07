// Michelle Tang
// 912026295
// Driver program that asks for a filename and repeatedly asks the user for the ADT to which he/she wishes to apply the ammands from the specified file.

#include<iostream>
#include<fstream>
#include"vector.h"
#include"LinkedList.h"
#include"dsexceptions.h"
#include"StackAr.h"
#include"CursorList.h"
#include"QueueAr.h"
#include"StackLi.h"
#include"SkipList.h"
#include"CPUTimer.h"

using namespace std;

vector<CursorNode <int> cursorSpace(500000);

int getChoice(void)
{
	int i;
	cout << "      ADT Menu" << endl;
	cout << "0. Quit" << endl;
	cout << "1. LinkedList" << endl;
	cout << "2. CursorList" << endl;
	cout << "3. StackAr" << endl;
	cout << "4. StackLi" << endl;
	cout << "5. QueueAr" << endl;
	cout << "6. SkipList" << endl;
	cin >> i;	

	return i;
}

void RunList(char * filename)
{
	char command;
	int num;
	ifstream read(filename);
	while (read >> command >> num)
	{
		if (command == 'i')
		{

		}
		if (command == 'd')
		{
			
		}
	}	
}

void RunCursorList(char * filename)
{
	char command;
	int num;
	CursorList<int> object(cursorSpace);
	CursorListItr<int> cursItr = object.zeroth();
	ifstream read(filename);
	while (read >> command >> num)
	{
		if (command == 'i')
		{
			object.insert(num, cursItr)
		}
		if (command == 'd')
		{
			object.remove(num);
		}
	}	
}

void RunStackAr(char * filename)
{
	char command;
	int num;
	ifstream read(filename);
	StackAr<int> object;
	while (read >> command >> num)
	{
		if (command == 'i')
		{
			object.push(num);	
		}
		if (command == 'd')
		{
			object.pop();	
		}
	}	
}

void RunStackLi(char * filename)
{
	char command;
	int num;
	StackLi<int> object;
	ifstream read(filename);	
	while (read >> command >> num)
	{
		if (command == 'i')
		{
			object.push(num);
		}
		if (command == 'd')
		{
			object.pop();
		}	
	}
}

void RunQueueAr(char * filename)
{
	char command;
	int num;
	QueueAr<int> object;
	ifstream read(filename);	
	while (read >> command >> num)
	{
		if (command == 'i')
		{
			object.enqueue(num);
		}
		if (command == 'd')
		{
			object.dequeue();
		}
	}
}

void RunSkipList(char * filename)
{
	char command;
	int num;
	ifstream read(filename);
	while (read >> command >> num);
	{
		if (command == 'i')
		{

		}
		if (command == 'd')
		{

		}
	}	
}

int main()
{
	char argv[1];	
	cout << "Filename >> ";
	cin >> argv[1];
	
	do
	{
		CPUTimer ct;
		choice = getChoice();
		ct.reset();
		switch (choice)
		{
			case 1: RunList(argv[1]); break;
			case 2: RunCursorList(argv[1]); break;
			case 3:	RunStackAr(argv[1]); break;
			case 4:	RunStackLi(argv[1]); break;
			case 5:	RunQueueAr(argv[1]); break;
			case 6:	RunSkipList(argv[1]); break;
		}

		cout << "CPU time: " << ct.cur_CPUTime() << endl;
	}	

} 


