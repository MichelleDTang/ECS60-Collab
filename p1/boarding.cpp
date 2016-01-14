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
	
	int checkr, seconds;

	enum State {W,ST1,ST2,S,O,I};

	Queue<char> wait;

	StackAr<char> ABC;

	StackAr<char> DEF;

	StackAr<char> temp;
	
	
	Row (int rownum)
	{
		checkr = rownum;

		Queue<char> wait(1);

		StackAr<char> ABC(3);

		StackAr<char> DEF(3);

		StackAr<char> temp(3);
	
	}


	int Sit (char letter, int row, int seconds)
	{

		State state = W;
		while(true)
		{
			switch(state)
			{
				case W : seconds += 5; 
					if (row == checkr) //check that it's the correct row
					{
						cout << "i" << endl;	
						state = ST1;
						break;
					}
					else
					{
						return seconds;
					}
				case ST1 : seconds += 5; state = ST2; break;
				case ST2 : seconds += 5; 
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
						seconds += 5;
						if (!temp.isEmpty())
						{
							state = I;
							break;
						}
						else
						{
							return seconds;
						}

					}	
					else
					{
						DEF.push(letter);
						seconds += 5;
						if (!temp.isEmpty())
						{
							state = I;
							break;

						}
						else
						{					
							return seconds;
						}
					}
				case O : 
					if (letter == 'A' || letter == 'B')
					{
						if (letter == 'A')
						{						
							if (ABC.top() == 'C')
							{
								temp.push(ABC.topAndPop());
								seconds += 5;
								if (!ABC.isEmpty())
								{
									temp.push(ABC.topAndPop());
									seconds += 5;
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
							temp.push(ABC.topAndPop());
							seconds += 5;
							break;
						}
					}
					else
					{
						if (letter == 'F')
						{						
							if (ABC.top() == 'D')
							{
								temp.push(DEF.topAndPop());
								seconds += 5;
								if (!DEF.isEmpty())
								{
									temp.push(DEF.topAndPop());
									seconds += 5;
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
							temp.push(DEF.topAndPop());
							seconds += 5;
							break;
						}
						
						
					}

				case I : 
					while (!temp.isEmpty())
					{
						if (letter == 'A'|| letter == 'B' || letter == 'C')
						{
							ABC.push(temp.topAndPop());
							seconds += 5;
						}
						else
						{
							DEF.push(temp.topAndPop());
							seconds += 5;
						}
						
					}
					return seconds;

			}
		}
	}

};


int main(int argc, char * argv[])
{

	Queue<int> passrows(288);
	
	Queue<char> passseats(288);

	int row,seconds= 0, doopsec = 0, counter = 0, curr = 1, size = 0;

	char seat;

	ifstream inf(argv[1]);
	
	Queue<Row *> p(48);	

	Queue<Row *> tp(48);

	Queue<int> ar(48);
		
	Queue<char> as(48);

	Queue<int> cur(48); // holds respective person's current row number

	Queue<int> tar(48);

	Queue<int> print(3);

	// enqueue only takes in int

	for (int pt=1; pt <= 48; pt++)
	{
		p.enqueue(new Row(pt));
		
	}		

	while (!inf.eof()) //while the file hasn't ended
	{
			//fill queue with the 288 passengers
			for (int q = 0; q < 288; q++)
			{

				inf >> row >> seat;
			
				passrows.enqueue(row);

				passseats.enqueue(seat);			

			}

			// have a counter that ++ if two rows have someone sitting at the same time
			// subtract 15 seconds per person minus 1
			while (!passrows.isEmpty()) 
			{

				do { // each loop adds a person to aisle queue and goes through procedure for everyone in aisle
				
					// add a person to the aisle queue
					
					ar.enqueue(passrows.getFront());

					as.enqueue(passseats.getFront());

					passrows.dequeue();
				
					passseats.dequeue();

					while (!ar.isEmpty())
					{
						tar.enqueue(ar.getFront());
						ar.dequeue();
						size ++;
			
	
					}

					while (!tar.isEmpty())
					{
						ar.enqueue(tar.getFront());
						tar.dequeue();
						
					}	


					for (int loop = 0; loop < (size-1); loop++) // 
					{
						cout << "a" << endl;					
						cur.enqueue(curr);
	
						// get the proper pointer for the row a person is at
						for (int c = 0; c < cur.getFront(); c++)
						{
							cout << "0" << endl;
							tp.enqueue(p.getFront());
							cout << "1" << endl;
							p.dequeue();						
							p.enqueue(tp.getFront());
							tp.dequeue();
						}	
						cout << as.getFront() << endl;
						cout << ar.getFront() << endl;
						cout << "2" << endl;
						// takes front guy and checks him through row class
						p.getFront()->Sit(as.getFront(), ar.getFront(), seconds); // pointer at front of queue calls its sit function with seat letter as parameter
						cout << "c" << endl;
						
						for (int reset = 0; reset <= (48-size); reset++)
						{
							
							tp.enqueue(p.getFront()); // move front of point to temp point
														
							p.dequeue();

							p.enqueue(tp.getFront()); // 

							tp.dequeue();

						}						

						cout << "7" << endl;

						// if seconds - doopsec = 5, that person isn't in the right row so move him up
						// if != 5, he got seated so take him out and throw away
				
						if ((seconds-doopsec) == 5)
						{
							doopsec += 5;

							curr = cur.getFront();

							curr ++;

							cur.dequeue();
			
							cur.enqueue(curr);
						}
						else
						{
							ar.dequeue();

							as.dequeue();

							cur.dequeue();
						
							counter++;
						}
						cout << "b" << endl;	
						curr = 1;	
				}
					
					size = 0;

				} while (!ar.isEmpty());

				// update the pointer queue for each passenger that's in the aisle?

			}
		
			print.enqueue(seconds);			

	}
			cout << "Back to front: " << print.getFront() << endl;
			print.dequeue();
			cout << "Random: " << print.getFront() << endl;
			print.dequeue();
			cout << "Outside in: " << print.getFront() << endl;

	return 0;
}

