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
	int time = 0, checkr;

	Queue<char> wait(1);

	Stack<char> ABC(3);

	Stack<char> DEF(3);

	Stack<char> temp(3);

	typedef enum State {W,ST1,ST2,S,O,I};
	
	Row (int rownum)
	{
		checkr = rownum;
	}


	Sit (char letter, int row)
	{
		State state = W;
		while(true)
		{
			switch(state)
			{
				case W : time += 5; 
					if (row == checkr) //check that it's the correct row
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
					if (letter == 'A' ) // if the stack needs to be popped
					{
						if (!ABC.isEmpty())
						{						
							state = O;
							break;
						}
						else
						{
							state = S;
							break;
						}								

					}
					else if (letter == 'F')
					{
						if (!DEF.isEmpty())
						{
							state = O;
							break;
						}
						else
						{
							state = S;
							break;
						}
	
					}
					else if (letter == 'B')
					{
						if (!ABC.isEmpty())
						{
							if (ABC.top() == 'C')
							{
								state = O;
								break;
							}
							else
							{
								state = S;
								break;
							}
						}
						else
						{
							state = S; 
							break;
						}
					}
					else if (letter == 'E')
					{
						if (!DEF.isEmpty())
						{
							if (DEF.top() == 'D')
							{
								state = O;
								break;
							}
						}
						else
						{
							state = S;
							break;
						}
					}
					else //C or D
					{
						state = S;
						break;
					}

				case S :  
					if (letter == 'A' || letter == 'B' || letter == 'C')
					{
						ABC.push(letter);
						time += 5;
						if (!temp.isEmpty())
						{
							state = I;
							break;
						}
						else
						{
							return false;
						}

					}	
					else
					{
						DEF.push(letter);
						time += 5;
						if (!temp.isEmpty())
						{
							state = I;
							break;

						}
						else
						{					
							return false;
						}
				case O : 
					if (letter == 'A' || letter == 'B')
					{
						if (letter == 'A')
						{						
							if (ABC.top() == 'C')
							{
								temp.push(ABC.topAndPop);
								time += 5;
								if (!ABC.isEmpty())
								{
									temp.push(ABC.topAndPop);
									time += 5;
									state = S;
									break;
								}
								else
								{
									state = S;
									break;
								}
							}
						}
						else
						{
							temp.push(ABC.topAndPop);
							time += 5;
							break;
						}
					}
					else
					{
						if (letter == 'F')
						{						
							if (ABC.top() == 'D')
							{
								temp.push(DEF.topAndPop);
								time += 5;
								if (!DEF.isEmpty())
								{
									temp.push(DEF.topAndPop);
									time += 5;
									state = S;
									break;
								}
								else
								{
									state = S;
									break;
								}
							}
						}
						else
						{
							temp.push(DEF.topAndPop);
							time += 5;
							break;
						}
						
						
					}

				case I : 
					while (!temp.isEmpty())
					{
						if (letter == 'A'|| letter == 'B' || letter 'C')
						{
							ABC.push(temp.topAndPop);
							time += 5;
						}
						else
						{
							DEF.push(temp.topAndPop);
							time += 5;
						}
						
					}
					return false;

			}
		}
	}

}


int main(argc, char * argv[])
{

	Queue<int> passrows(288);
	
	Queue<char> passseats(288);

	int row, print = 0;

	char seat;

	ifstream inf(argv[1]);

	Queue<int> p(48);	

	for (int pt=1; pt <= 48; pt++)
	{
		p.enqueue(new Row(pt))
	}		

	while (!inf.eof()) //need to update the rows
	{
		if(inf=="/n")
		{
			while(inf >> row >> seat)
			{
			
				passrows.enqueue(row);

				passseats.enqueue(seat);			

			}

			while (!passrows.isEmpty()) //if guy infront is getting seated and second guy is row # > him, second must wait; if smaller it can happen at the same time
			{
				// takes first guy and checks him through row class
				p.getFront() = Row::Sit(passseats.getFront(), passrows.getFront()); // pointer at front of queue calls its sit function with seat letter as parameter
				// once done take him out of queue
				passseats.dequeue(passseats.getFront());
				passrows.dequeue(passrows.getFront();
				// update the pointer queue for each passenger that's in the aisle?

			}
		}
		//print out the results
		switch(print)
		{
			case 0 : cout << "Back to front: " << time << endl;
			case 1 : cout << "Random: " << time << endl;
			case 2 : cout << "Outside in: " << time << endl;
		}	
		//case for switch altered
		print ++;
		
	}

}

