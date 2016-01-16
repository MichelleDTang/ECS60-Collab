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
	
	int checkr, sec;

	char state;

	enum State {W,ST1,ST2,S,O,I};

	Queue<char> wait;

	StackAr<char> ABC;

	StackAr<char> DEF;

	StackAr<char> temp;
	
	
	Row ()
	{
		checkr = 0;

		Queue<char> wait(1);

		StackAr<char> ABC(3);

		StackAr<char> DEF(3);

		StackAr<char> temp(3);
	
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

	int Sit (char letter, int m, int state)
	{

						
		
			switch(state)
			{

				case 0 : 
					if(m == 0)
					{
						state = 2;
						 break;
					}
					else state = 0; break;
				case 1 : sec += 5; 
			

					if (m == 0) //check that it's the correct row
					{
					//	state = ST1;
						cout << " rows match" << endl;	
						state = 2;
						cout << " state 2" << endl;
						break;
					}
					else
					{
						state = 1; break;
					}
				case 2 : sec += 5; state = 3; cout<< "sto1 " << endl; break;
				case 3 : sec += 5; 
					cout << "sto2" << endl;
					if (letter == 'A' ) // if the stack needs to be popped
					{
						if (!ABC.isEmpty()) // B or C is sitting down in that row
						{						

//							state = O;
							state = 5; break;
						}
						else // no one blocking 
						{
										
//							state = S;
							state =  4; break;
						}								

					}
					else if (letter == 'F')
					{
						if (!DEF.isEmpty()) // D or E is sitting down
						{
//							state = O;
							state = 5; break;	
						}
						else // no one blocking
						{
//							state = S;
							state = 4; break;
						}
	
					}
					else if (letter == 'B') 
					{

						if (!ABC.isEmpty()) // A or C
						{
							if (ABC.top() == 'C') // stack must be popped
							{
//								state = O;
								state = 5; break;
							}
							else // stack doesn't need to be popped
							{
//								state = S;
								state = 4; break;
							}
						}
						else // no one blocking
						{
//							state = S; 
							state = 4;
							break;
						}
					}
					else if (letter == 'E')
					{

						if (!DEF.isEmpty()) // D or F 
						{
							if (DEF.top() == 'D') // pop stack
							{
//								state = O;
								state = 5; break;							
							}
							else // stack doesn't need popping
							{
//								state = S;
								state = 4; break;
							}
							
						}
						else // no one blocking
						{
//							state = S;
							state =  4; break;
						}
					}
					else //C or D
					{
//						state = S;
						state = 4;
						break;
					}

				case 4 :  

					if (letter == 'A' || letter == 'B' || letter == 'C')
					{
						ABC.push(letter);
						sec += 5;
						if (!temp.isEmpty()) // if someone had to be popped
						{
//							state = I;
							state = 6;
							break;
						}
						else
						{
//							cout << "sitting" << sec << endl;
							state =  7;
							break;
						}

					}	
					else
					{
						DEF.push(letter);
						sec += 5;
						if (!temp.isEmpty())
						{
//							state = I;
							state =  6;
							break;

						}
						else
						{					
//							cout << "sitting" << sec << endl;
							
							state =  7;
							break;
						}
					}
				case 5 : 
					

					if (letter == 'A' || letter == 'B')
					{
						if (letter == 'A')
						{						
							if (ABC.top() == 'C')
							{

								temp.push(ABC.top()); // move out C
								ABC.pop();
								sec += 5;
								if (!ABC.isEmpty()) // if B was also in
								{
									temp.push(ABC.top()); // move out A
									ABC.pop();
									sec += 5;
//									state = S;
									state =  4;
									break;	
								}
								else
								{
//									state = S; // if only C, go to sit
									state = 4;
									break;
								}
							}
						}
						else
						{
							temp.push(ABC.top()); // if letter B
							ABC.pop(); // pop off top which would be C
							sec += 5;
//							state = S;
							state =  4;
							break;
						}
					}
					else // E or F
					{
						if (letter == 'F')
						{						
							if (ABC.top() == 'D')
							{
								temp.push(DEF.top());
								DEF.pop();
								sec += 5;
								if (!DEF.isEmpty())
								{
									temp.push(DEF.top());
									DEF.pop();
									sec += 5;
//									state = S;
									state = 4;	
									break;
								}
								else
								{
//									state = S;
									state = 4;			
									break;
								}
							}
						}
						else
						{
							temp.push(DEF.top());
							DEF.pop();
							sec += 5;
							state = 4;
							break;
						}
						
						
					}

				case 6 : 
					while (!temp.isEmpty())
					{
						if (letter == 'A'|| letter == 'B' || letter == 'C')
						{
							ABC.push(temp.top());
							temp.pop();
							sec += 5;
						}
						else
						{
							DEF.push(temp.top());
							temp.pop();
							sec += 5;
						}
						
					}
//					cout << " blocked " << sec << endl;
					state = 7;
					break;
					
			}
		return state;
	}

};


int main(int argc, char ** argv)
{

	Queue<int> passrows(288);
	
	Queue<char> passseats(288);

	int row, print = 0, stat = 0, plane = 0, aislecount =0;

	char seats;

	ifstream inf(argv[1]);
	
	Queue<Row *> p(48);	

	Queue<Row *> tp(48);

	Queue<int> aisle(48);

	Queue<int> aisleL(48);

	Queue<int> status(48);

	Queue<int> current(48);

	StackAr<int> tmphold(1);

	// enqueue only takes in int

	status.enqueue(1);



	for (int pt = 1; pt <= 48; pt++)
	{
		Row *r = new Row;

		r -> setCheck(pt);

		p.enqueue(r);
	}	

	for (int u = 1; u < 48; u++)
	{
		status.enqueue(stat);

		stat = status.getFront();

		status.dequeue();
	}
	

	cout << " start "<< endl;
	while (print != 3) //while the file hasn't ended
	{
		for(int q = 0; q < 288; q++)
		{
			inf >> row >> seats;
			passrows.enqueue(row);
			passseats.enqueue(seats);

		}	
		
		aisle.enqueue(passrows.getFront());
		aisleL.enqueue(passseats.getFront());
		passrows.dequeue();
		passseats.dequeue();
		aislecount ++;
		current.enqueue(1);


		while (!aisle.isEmpty())
		{
			cout << " while aisle isn't empty"<< endl;

			if(p.getFront()->Sit(aisleL.getFront(), 0, status.getFront()) == 0)
			{
				aisle.enqueue(passrows.getFront());
				cout << "ad" << endl;
				aisleL.enqueue(passseats.getFront());
				passrows.dequeue();
				passseats.dequeue();
				aislecount ++;	
				current.enqueue(1);

			}
			cout << "new aisle run" << endl;
			for(int g = 1; g < current.getFront(); g++)
			{
				tp.enqueue(p.getFront());
				p.dequeue();
				p.enqueue(tp.getFront());
				tp.dequeue();


			} 
		//	cout << "3" << endl;
			for(int a =0 ; a < aislecount; a++)
			{
			//	cout << " 4" << endl;
				cout << " at row " << p.getFront() -> getCheck() << endl;
				cout << "person's row " << aisle.getFront() << endl;
				if (p.getFront() -> getCheck() == aisle.getFront()) //if current row is right, update status for this row
				{
					cout << "7" << endl;
					stat = p.getFront() -> Sit(aisleL.getFront(), 0, status.getFront());
					cout << "working on sitting" << endl;
					cout << status.getFront() << endl;
					if( stat == 7)
					{	
						aisle.dequeue();
						aisleL.dequeue();
						status.enqueue(0);
						status.dequeue();
						current.dequeue();
						tp.enqueue(p.getFront());
						p.dequeue();
						p.enqueue(tp.getFront());
						tp.dequeue();
						aislecount --;
					}
					
					else
					{					
						cout << "5" << endl;
						tmphold.push(current.getFront());
						current.dequeue();
						current.enqueue(tmphold.topAndPop());

						status.enqueue(stat);
						status.dequeue();
						cout << p.getFront() -> getCheck() << endl;
						tp.enqueue(p.getFront());
						p.dequeue();
						p.enqueue(tp.getFront());
						tp.dequeue();
						cout<< p.getFront() -> getCheck() << endl;
						cout << "done " << endl;
					}	

				}	
				else // row isn't right so look to next row to see if empty
				{
					cout << "move up" << endl;
					tp.enqueue(p.getFront());
					p.dequeue();
					p.enqueue(tp.getFront());
					tp.dequeue();
					cout << "checking row in front" << endl;
					if(p.getFront() -> getCheck() == 0)
					{
						cout << "can move " << endl;
						current.enqueue((p.getFront() -> getCheck()) + 1);
						current.dequeue();
						status.enqueue(0); // row it was in is status 0
						status.dequeue();
						status.enqueue(1); // row it will move to is 1
						status.dequeue();	
						tp.enqueue(p.getFront());
						p.dequeue();
						p.enqueue(tp.getFront());
						tp.dequeue();
					}				
					else
					{
						cout << "stuck" << endl;
						tmphold.push(current.getFront());
						current.dequeue();
						current.enqueue( tmphold.topAndPop());
						status.enqueue(1);
						status.dequeue();
					}							
	
				}
				cout << "6" << endl;	
				while(p.getFront() -> getCheck() > 1)			
				{
					tp.enqueue(p.getFront());
					p.dequeue();
					p.enqueue(p.getFront());
					tp.dequeue();
				//	cout << p.getFront() -> getCheck() << endl;
				}
				cout << p.getFront() -> getCheck() << endl;				
			}
			plane += 5;

		}	

		switch(print)
		{
			case 0: cout << "Back to front: " <<  plane <<  endl; break;
			case 1: cout << "Random: " << plane << endl; break;
			case 2: cout << "Outside in: " << plane << endl; break;
		}
	
		print++;
		plane = 0;
	}

}

