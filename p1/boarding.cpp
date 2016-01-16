#include<iostream>
#include<fstream>
#include"StackAr.h"
#include"QueueAr.h"

using namespace std;

class Row
{
  public:

	int checkr, stat, prow, current;
	
	char pseat;

	StackAr<char> ABC;

	StackAr<char> DEF;
	
	StackAr<char> temp;

	Row()
	{
		checkr = 0;
		
		stat = 0;

		prow = 0;

		pseat = ' ';				
		
		current = 0;

		StackAr<char> ABC(3);

		StackAr<char> DEF(3);
		
		StackAr<char> temp(3);
	}

	int setnewprow(int r)
	{
		prow = r;
		return prow;
	}

	int getnewprow()
	{
		return prow;
	}

	char setnewpseat(char l)
	{
		pseat = l;
		return pseat;
	}

	char getnewpseat()
	{
		return pseat;
	}

	int setCurrent(int c)
	{
		current = c;
		return current;
	}

	int getCurrent()
	{
		return current;
	}

	int setStatus(int s)
	{
		stat = s;
		return stat;
	}

	int getStatus()
	{
		return stat;
	}

	int setCheck(int rownum)
	{
		checkr = rownum;
		return checkr;
	}

	int getCheck()
	{
		return checkr;

	}

	int Sit(char letter, int match, int state)
	{
		switch(state)
		{
			case 0: break;
			case 1: cout << "waiting" << endl;
				if(match == 0)
				{
					state = 2;
					break;
				}
				break;
			case 2: cout << " store 1 " << endl;state = 3; break;
			case 3: cout << "store 2" << endl;
				if(letter == 'A')
				{
					if(!ABC.isEmpty())
					{
						state = 5; break;
					}
					else
					{
						state = 4; break;

					}
				}
				else if(letter == 'F')
				{
					if(!DEF.isEmpty())
					{
						state = 5; break;
					}
					else
					{
						state = 4; break;

					}
				}
				else if(letter == 'B')
				{
					if(!ABC.isEmpty())
					{
						if(ABC.top() == 'C')
						{
							state = 5; break;
						}
						else
						{
							state = 4; break;
						}
					}
					else
					{
						state = 4; break;

					}
				}
				else if(letter == 'E')
				{
					if(!DEF.isEmpty())
					{
						if(DEF.top() == 'D') state = 5; break;
					}

				}
				else
				{
					state = 4; break;
				}
			
			case 4: cout << "sitting " << endl;
				if( letter == 'A' || letter == 'B' || letter == 'C')
				{
					ABC.push(letter);
					if(!temp.isEmpty())
					{
						 state = 6; break;
					}
					else
					{
						 state = 7; break;
					}
				} 
				else
				{
					DEF.push(letter);
					if(!temp.isEmpty()) 
					{
						state = 6;
						break;
					}
					else
					{
						state = 7;
						break;
					}
				}
				
			case 5: cout << "out " << endl; 
				if(letter == 'A' || letter == 'B')
				{
					if(letter == 'A')
					{
						if(ABC.top() == 'C' || ABC.top() == 'B')
						{
							temp.push(ABC.topAndPop());								 
							if(!ABC.isEmpty())
							{
								state = 6;
								break;
							}
							else
							{
								state = 5;
								break;
							}
						}
					}

				
					else
					{
						temp.push(ABC.topAndPop());
						state = 4;
						break;
					}
				}
				else
				{
					if(letter == 'F')
					{
						if(DEF.top() == 'D' || ABC.top() == 'E')
						{
							temp.push(DEF.topAndPop());								 
							if(!DEF.isEmpty())
							{
								state = 6;
								break;
							}
							else
							{
								state = 5;
								break;
							}
						}
					}

				
					else
					{
						temp.push(DEF.topAndPop());
						state = 4;
						break;
	
					}
				}
			case 6:	
				cout << "In" << endl;
				while(!temp.isEmpty())
				{	
					if(letter =='A' || letter == 'B' || letter == 'C')
					{
						ABC.push(temp.topAndPop());

					}
					else
					{
						DEF.push(temp.topAndPop());
								
					}
				
				}	
				state = 7;
				break;
		}	
		return state;			
	}



};


int main(int argc, char **argv)
{
	Row * r;
	int curr = 1, stat =0, people =0, print = 0, row, plane =0;

	char seat;

	Queue<int> passN(288);

	Queue<char> passL(288);

	Queue<int> track(48);

	Queue<Row *> p(48);
			
	StackAr<int> In(48);

	ifstream inf(argv[1]);

	for (int pt =1; pt <=48 ; pt++)
	{
		Row *r = new Row;

		r -> setCheck(pt);

		p.enqueue(r);

		p.getFront() -> setStatus(0);
	}

	while (print != 3)
	{
		for(int q = 0; q < 288; q++)
		{
			inf >> row >> seat;
			passN.enqueue(row);
			passL.enqueue(seat);
		}
		cout << " the line was read" << endl;
		do 
		{
			if( p.getFront() -> getStatus() == 0)
			{
				p.getFront() -> setnewprow(passN.getFront());
				passN.dequeue();
				p.getFront() -> setnewpseat(passL.getFront());
				passL.dequeue();
				people ++;	
				p.getFront() -> setStatus(1);			
				p.getFront() -> setCurrent(1);
				cout << "someone into aisle" << endl;		
				track.enqueue(1);
			}
		// loop for how ever many aisles ahead of row 1 this person is
			

			for (int v = 1; v <= people; v++)
			{
				curr = track.getFront();
			//	cout << curr << endl;
				//get the row the current person is in
				if(In.isEmpty())
				{
					
				}
				for(int g = 1; g < In.topAndPop(); g++)
				{
					r = p.getFront();
					p.dequeue();
					p.enqueue(r);		
			
				}
											
				cout << "who are you" << p.getFront() -> getnewprow() << p.getFront() -> getnewpseat() << endl;
				cout << "current row " << p.getFront() -> getCheck() << endl;
				cout << " current person's row number " << p.getFront() -> getnewprow() << endl;
				if (p.getFront() -> getCheck() == p.getFront() -> getnewprow())
				{
					cout << "a match! " << endl;
					stat = p.getFront() -> Sit(p.getFront() -> getnewpseat(), 0, p.getFront() -> getStatus());
					if (stat == 7)
					{
						p.getFront() -> setStatus(0);	
						p.getFront() -> setnewprow(0);
						p.getFront() -> setnewpseat(' ');
						people --;
						cout << "someone left" << endl;
						
					}	
					else
					{
						p.getFront() -> setStatus(stat);
						
					}
				}
				else
				{
					cout << "no match " << endl;
					r = p.getFront();
					p.dequeue();
					p.enqueue(r);
					stat = p.getFront() -> getStatus();
					if(stat == 0)
					{
						cout << "moved " << endl;
						p.getFront() -> setStatus(1);
						p.getFront() -> setnewprow(r -> getnewprow());
						p.getFront() -> setnewpseat(r -> getnewpseat());
						r -> setStatus(0);
						r -> setnewprow(0);
						r -> setnewpseat(' '); 
						track.dequeue();
						track.enqueue(curr + 1);
					}
					else
					{
						//nothing changes?
					}
				}
		
			}
			for(int m = 1; m <=48 ; m++)
			{
				if(p.getFront() -> getStatus() != 0)
				{
					In.push(p.getFront()-> getCheck()); 
					r = p.getFront();
					p.dequeue();
					p.enqueue(r);

				}

			}

			plane += 5;
			//refresh
	
			while(p.getFront() -> getCheck() != 1)
			{
				r = p.getFront();
				p.dequeue();
				p.enqueue(r);
			}		
			if(passN.isEmpty() && people == 0)
			{
				people = -1;
			}	

		} while (people != -1);	
/*		curr = p.getFront() -> getCheck();

		//refresh

		w	hile(p.getFront() -> getCheck() != 1)
		{
			r = p.getFront();
			p.dequeue();
			p.enqueue(r);
		}		
*/		
		switch(print)
		{
			case 0:cout << "Back to front: " << plane << endl; break;
			case 1: cout << "Random: " << plane << endl; break;
			case 2: cout << "Outside in: "<< plane << endl; break;
		}	
		print ++;
		plane = 0;

	}

	

	return 0;
}


