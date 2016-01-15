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

//			sec = seconds;
						
		
			switch(state)
			{

				case 1 : sec += 5; 
			
/*					if (!ABC.isEmpty())
					{
						cout << ABC.top() << endl;
									
					}
					
					if (!DEF.isEmpty())
					{
						cout << DEF.top() << endl;
					}

*/					if (m == 0) //check that it's the correct row
					{
					//	state = ST1;
						cout << " rows match" << endl;	
						state = 2; break;
					}
					else
					{
						state = 1; break;
					}
				case 2 : sec += 5; state = 3; break;
				case 3 : sec += 5; 
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

	int row, print = 0, stat = 1, curr = 1, size = 0, plane = 0, tmpcurr = 3, c;

	char seat;

	ifstream inf(argv[1]);
	
	Queue<Row *> p(48);	

	Queue<Row *> tp(48);

	Queue<int> ar(48);
		
	Queue<char> as(48);

	Queue<int> cur(48); // holds respective person's current row number

	Queue<int> tcur(48);

	Queue<int> tar(48);

	Queue<char> tas(48);

	StackAr<int> tmp(1);

	Queue<int> tmpcur(48);

	Queue<int> status(48);


	// enqueue only takes in int

	for (int pt = 1; pt <= 48; pt++)
	{
		Row *r = new Row;

		r -> setCheck(pt);

		p.enqueue(r);
	}
/*
	for (int g = 1; g <= 48; g++)
	{
		cout << p.getFront() -> getCheck() << endl;
		
		tp.enqueue(p.getFront());

		p.dequeue();

		p.enqueue(tp.getFront());
		
		tp.dequeue();
	}
*/
//	for (int pt=1; pt < 48; pt++)
//	{	
//		r = tp.getFront()++;
//		tp.getFront() -> setCheck(pt+1);		
//		p.enqueue(r);
//	}


/*	for (int pt=1; pt <= 48; pt++)
	{
		Row *r = new Row;
		p.enqueue(r);
		r -> setCheck(pt);
	}		
*/


	while (print != 3) //while the file hasn't ended
	{
			cur.makeEmpty();

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
//				cout << "1" << endl;

				do { // each loop adds a person to aisle queue and goes through procedure for everyone in aisle
				
					// add a person to the aisle queue
					
					//cout << " add next person to the aisle" << endl;					

					if (cur.isEmpty()) curr = 0;
					

					if(!ar.isFull() && !passrows.isEmpty() && c > 1 )
					{

//						cout << " aisle isn't full yet" << endl;

						ar.enqueue(passrows.getFront());

						as.enqueue(passseats.getFront());

						passrows.dequeue();
				
						passseats.dequeue();

						cur.enqueue(1);

						tmpcur.enqueue(3);
						
						tmpcurr = tmpcur.getFront();

						status.enqueue(1);

						//cout << " another person enters the aisle" << endl;
					}

					
					while (!ar.isEmpty())  // when aisle still has people
					{
						tar.enqueue(ar.getFront()); // add first person in aisle to temp
						ar.dequeue(); // take out first person
						size ++;
//						cout << "3" << endl;
	
					}

					while (!tar.isEmpty())  // when temp isn't empty
					{
						ar.enqueue(tar.getFront()); // add person in temp to back of aisle line up
						tar.dequeue();  // take out person we just put back into line up
//						cout << "4" << endl;	
					}	


					for (int loop = 0; loop < size; loop++) // iterate through all the people in the aisle
					{
/*						while(!cur.isEmpty())
						{
							cout << "in cur queue" << cur.getFront() << endl;
							
							tcur.enqueue(cur.getFront());
							cur.dequeue();
						}

						while(!tcur.isEmpty())
						{
							cur.enqueue(tcur.getFront());
							tcur.dequeue();

						}
*/
	
						// get the proper pointer for the row a person is at


						for (int g = 1; g < cur.getFront(); g++)
						{

							cout << "row of pointer " << p.getFront() -> getCheck() << " for " << ar.getFront() << as.getFront() << endl;
			
							tp.enqueue(p.getFront());

							p.dequeue();

							p.enqueue(tp.getFront());
		
							tp.dequeue();
						}

						cout << " row of pointers " << p.getFront() -> getCheck() << " for " << ar.getFront() << as.getFront() << endl;


/*						for (int c = 1; c <= cur.getFront(); c++) // find the pointer to the row that the first person in the aisle queue needs to check
						{
//							cout << "6" << endl;
							
							tp.enqueue(p.getFront()); // add the pointer to the row to the temp
							p.dequeue();			// take pointer out of front			
							p.enqueue(tp.getFront()); // add first pointer in temp back into original
							tp.dequeue();  // take out of temp
						}	
*/						// takes front guy and checks him through row class
						cout << stat << endl;

						if (p.getFront() -> getCheck() == ar.getFront())
						{
							cout << p.getFront() -> getCheck() << "  match" << ar.getFront();
						
							stat = p.getFront()->Sit(as.getFront(), 0, status.getFront()); // pointer at front of queue calls its sit function with seat letter as parameter
							
							tmp.push(ar.getFront());
						
				//			cout << "sec " << seconds << endl;
						}
						else
						{
							stat = p.getFront()-> Sit(as.getFront(), 1, status.getFront());

//							cout << p.getFront() -> getCheck() << "<- point's row  move along  person's row ->" << ar.getFront() << endl;

						}						
						
						
						cout << "returned " << stat << endl;

						

						while (p.getFront() -> getCheck() != 1) // for rest of pointers that should be behind the checked rows
						{
						
							tp.enqueue(p.getFront()); // move front of point to temp point
														
							p.dequeue();

							p.enqueue(tp.getFront()); // 

							tp.dequeue();

						}						

						cout << p.getFront() -> getCheck() << endl;

						
				
						if (stat == 1) // if the person wasn't in their proper row and no one is blocking their front
						{
							if (tmpcurr - cur.getFront() != 1) // they can move up
							{
								cout << "moving " << endl;

								status.dequeue();
								status.enqueue(stat);
								stat = status.getFront();
							
								curr = cur.getFront(); // curr is the number corresponding to the row the person is in
	
								curr ++; // add 1 meaning person goes onto next row
	
								cur.dequeue(); // get rid of old row value
			
								cur.enqueue(curr); // add the new row value for person to back to the current status queue

								tmpcurr = cur.getFront() + 1;				

								tmpcur.dequeue();								
							
								tmpcur.enqueue(tmpcurr);							

//							cout << "old cur removed " << cur.getFront() << endl;

							// refresh aisle
								tar.enqueue(ar.getFront()); // tmp takes first in aisle
								ar.dequeue();	// aisle queue deletes 
								ar.enqueue(tar.getFront()); // aisle queues adds to back
								tar.dequeue(); // tmp deletes
								tas.enqueue(as.getFront()); // does same except with letters
								as.dequeue();
								as.enqueue(tas.getFront());
								tas.dequeue();
						
							cout << "c" << endl;
							if (!cur.isEmpty())
							{
								c = cur.getFront();					
							}
							else
							{
								c = 2;
							}
	

//							cout << " aisle refreshed " << endl;
							}
							else //someone is in the way
							{
								cout << "blocked " << endl;

								curr = cur.getFront();
								cur.dequeue();
								cur.enqueue(curr);
								tmpcurr = tmpcur.getFront();
								tmpcur.dequeue();
								tmpcur.enqueue(tmpcur.getFront());

								status.dequeue();
								status.enqueue(stat);
								stat = status.getFront();

								// refresh aisle
								tar.enqueue(ar.getFront()); // tmp takes first in aisle
								ar.dequeue();	// aisle queue deletes 
								ar.enqueue(tar.getFront()); // aisle queues adds to back
								tar.dequeue(); // tmp deletes
								tas.enqueue(as.getFront()); // does same except with letters
								as.dequeue();
								as.enqueue(tas.getFront());
								tas.dequeue();
								
								c = 1;
							}

						}
						else if (stat == 7)
						{
							
							ar.dequeue(); // person's row number is tossed out

							as.dequeue(); // person's seat is tossed out

							cur.dequeue(); // person's current row # is taken out
								
						//	tmpcurr = tmpcur.getFront();

							cout << "someone sits " << endl;
							cout << "t" << endl;

							tmpcur.dequeue();
							cout << "s" << endl;
							status.dequeue();
							cout << "r" << endl;	
							if (!status.isEmpty())
							{
								stat = status.getFront();
							}	
							size --;					
							
							cout << "c" << endl;
							if (!cur.isEmpty())
							{
								c = cur.getFront();					
							}
							else
							{
								c = 2;
							}
		

						}

						else 
						{
							cout << " sitting " << endl;
							curr = cur.getFront();
							cur.dequeue();
							cur.enqueue(curr);

							cout << "cur " << endl;

							tmpcurr = tmpcur.getFront();
							tmpcur.dequeue();
							tmpcur.enqueue(tmpcurr);

							cout << " tmpcur" << endl;
						
							status.dequeue();
							status.enqueue(stat);
							
							cout << " status " << endl;
							stat = status.getFront();

							tar.enqueue(ar.getFront()); // tmp takes first in aisle
							ar.dequeue();	// aisle queue deletes 
							ar.enqueue(tar.getFront()); // aisle queues adds to back
							tar.dequeue(); // tmp deletes
							tas.enqueue(as.getFront()); // does same except with letters
							as.dequeue();
							as.enqueue(tas.getFront());
							tas.dequeue();						
	
							cout << "c" << endl;
							if (!cur.isEmpty())
							{
								c = cur.getFront();					
							}
							else
							{
							c = 2;
							}
						}
	
						
//							doopsec += (seconds - doopsec);

/*						cout << "c" << endl;
						if (!cur.isEmpty())
						{
							c = cur.getFront();					
						}
						else
						{
							c = 2;
						}
*/						cout << " d" << endl;
						if (!tmpcur.isEmpty())
						{
							tmpcurr = tmpcur.getFront();
						}
						curr = 1;	
						tmp.makeEmpty();
					//	stat = status.getFront();	
						cout << "tmp" << endl;
					}	
					
					
					plane += 5;
/*					if(counter > 0) // if there was someone who sat down without being blocked
					{					
						plane += 15;

						if(counter1block > 0) // if someone else was sitting too but got blocked
						{
							plane += 10;
						}
						else if(counter2block > 0) // if there were 2 people blocking 
						{
							plane += 20;
						}

					}
					else // if no one had to sit down without blockage
					{
						if(counter1block > 0) // if someone had to sit and got blocked by 1
						{
							plane += 25;
							if(counter2block > 0) // if at same time someone was blocked by 2
							{
								plane += 10;

							}
						}
						else if(counter2block > 0) // if only people sitting are ones who get blocked by 2
						{	
							plane += 35;
						}
						
					}
*/					size = 0;
	//				counter = 0;
	//				counter1block = 0;
	//				counter2block = 0;

				} while (!ar.isEmpty());

	//			plane += 5;
/*				if(counter > 0) // if there was someone who sat down without being blocked
				{					
					plane += 15;
					if(counter1block > 0) // if someone else was sitting too but got blocked
					{
						plane += 10;
					}
					else if(counter2block > 0) // if there were 2 people blocking 
					{
						plane += 20;
					}

				}
				else // if no one had to sit down without blockage
				{
					if(counter1block > 0) // if someone had to sit and got blocked by 1
					{
						plane += 25;
						if(counter2block > 0) // if at same time someone was blocked by 2
						{
							plane += 10;

						}
					}
					else if(counter2block > 0) // if only people sitting are ones who get blocked by 2
					{	
						plane += 35;
					}
						
				}
*/	
				// update the pointer queue for each passenger that's in the aisle?

			}
			

		switch(print)
		{
			case 0: cout << "Back to front: " <<  plane <<  endl; break;
			case 1: cout << "Random: " << plane << endl; break;
			case 2: cout << "Outside in: " << plane << endl; break;
		}
	
		print++;
//		seconds = 0;
	//	doopsec = 0;
		plane = 0;
		}

}

