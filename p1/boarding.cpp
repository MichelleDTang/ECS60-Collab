// Michelle Tang
// 912026295
//

#include<iostream>
#include<fstream>
#include"StackAr.h"
#include"QueueAr.h"

using namespace std;

class Row
{
  public:
	int time = 0;

	Queue<char> wait(1);

	Stack<char> ABC(3);

	Stack<char> DEF(3);

	Stack<char> temp(3);

	typedef enum State {W,ST1,ST2,S,O,I};
	
	Row (char letter)
	{
		State state = W;
		while(true)
		{
			switch(state)
			{
				case W : time += 5; 
					if ( ) //check that it's the correct row) 
					{
						state = ST1;
						break;
					}
					else
					{
						return false;
					}
				case ST1 : time += 5; state = ST2; break;
				case ST2 : time += 5; 
					if ( ) // if the stack needs to be popped
					{
						state = O;
						break;
					}
					else
					{
						state = S; 
						break;
					}
				case S : time += 5; 
					if (letter == 'A' || letter == 'B' || letter == 'C')
					{
						ABC.push(letter);
					}	
					else
					{
						DEF.push(letter);
					}
					if

						return false;
				case O : time += 10; state = I; break;
				case I : time += 5; return false;
			}
		}
	}

}


int main(argc, char * argv[])
{
	Queue<int> passrows(288);
	
	Queue<char> passseats(288);

	int row;

	char seat;

	ifstream inf(argv[1]);

	Queue<int> p(48);	

	for (int pt=1; pt <= 48; pt++)
	{
		p.enqueue(new Row)
	}		

	while (!inf.eof())
	{
		if(inf=="/n")
		{
			while(inf >> row >> seat)
			{
			
				passrows.enqueue(row);

				passseats.enqueue(seat);			

			}

			while (!passrows.isEmpty())
			{	
				int front = passrows.getFront();
				for (int match=1; match <=48; match++)
				{
					if ( front == match)
					{
						p.getFront();
						break;
					}
					else
					{
						p.getFront() ++ ;
					}
					
				}

			}
		}
		
		
		
	}


// check the status of the person in the row
/*	switch(state)
	{
		case W : time += 5; 
			if ( ) //check that it's the correct row) 
			{
				state = ST1;
				break;
			}
			else
			{
				return false;
			}
		case ST1 : time += 5; state = ST2; break;
		case ST2 : time += 5; state = S; break;
		case S : time += 5; return false;
		case O : time += 5; state = I; break;
		case I : time += 5; return false;
	}
*/
//
//	cout << "Back to front: " <<
//	cout << "Random: " <<
//	cout << "Outside in: " << 

}
