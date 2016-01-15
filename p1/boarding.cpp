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

	int Sit (char letter, int m, int seconds)
	{

			sec = seconds;

//			cout << row << endl;

//			cout << "checkr" << checkr << endl;

			State state = W;
		
			switch(state)
			{
				case W : sec += 5; 

					
					if (m == 0) //check that it's the correct row
					{
						state = ST1;
						cout << " rows match" << endl;	
					}
					else
					{
						return sec;
					}
				case ST1 : sec += 5; state = ST2; 
				case ST2 : sec += 5; 
					if (letter == 'A' ) // if the stack needs to be popped
					{
						if (!ABC.isEmpty())
						{						

							state = O;
							
						}
						else
						{
							state = S;
							
						}								

					}
					else if (letter == 'F')
					{
						if (!DEF.isEmpty())
						{
							state = O;
							
						}
						else
						{
							state = S;
							
						}
	
					}
					else if (letter == 'B')
					{

						if (!ABC.isEmpty())
						{
							if (ABC.top() == 'C')
							{
								state = O;
								
							}
							else
							{
								state = S;
								
							}
						}
						else
						{
							state = S; 
							
						}
					}
					else if (letter == 'E')
					{

						if (!DEF.isEmpty())
						{
							if (DEF.top() == 'D')
							{
								state = O;
								
							}
						}
						else
						{
							state = S;
							
						}
					}
					else //C or D
					{
						state = S;
						
					}

				case S :  

					if (letter == 'A' || letter == 'B' || letter == 'C')
					{
						ABC.push(letter);
						sec += 5;
						if (!temp.isEmpty())
						{
							state = I;
							
						}
						else
						{
							cout << "sitting" << sec << endl;
							return sec;
						}

					}	
					else
					{
						DEF.push(letter);
						sec += 5;
						if (!temp.isEmpty())
						{
							state = I;
							

						}
						else
						{					
							cout << "sitting" << sec << endl;
							
							return sec;
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
								sec += 5;
								if (!ABC.isEmpty())
								{
									temp.push(ABC.topAndPop());
									sec += 5;
									state = S;
									
								}
								else
								{
									state = S;
									
								}
							}
						}
						else
						{
							temp.push(ABC.topAndPop());
							sec += 5;
							state = S;
							
						}
					}
					else
					{
						if (letter == 'F')
						{						
							if (ABC.top() == 'D')
							{
								temp.push(DEF.topAndPop());
								sec += 5;
								if (!DEF.isEmpty())
								{
									temp.push(DEF.topAndPop());
									sec += 5;
									state = S;
									
								}
								else
								{
									state = S;
									
								}
							}
						}
						else
						{
							temp.push(DEF.topAndPop());
							sec += 5;
							
						}
						
						
					}

				case I : 
					while (!temp.isEmpty())
					{
						if (letter == 'A'|| letter == 'B' || letter == 'C')
						{
							ABC.push(temp.topAndPop());
							sec += 5;
						}
						else
						{
							DEF.push(temp.topAndPop());
							sec += 5;
						}
						
					}
					cout << " blocked " << sec << endl;
					return sec;

			}
		return 0;
	}

};


int main(int argc, char ** argv)
{

	Queue<int> passrows(288);
	
	Queue<char> passseats(288);

	int row, print = 0, seconds= 0, doopsec = 0, counter = 0, curr = 1, size = 0;

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

	// enqueue only takes in int

	for (int pt = 1; pt <= 48; pt++)
	{
		Row *r = new Row;

		r -> setCheck(pt);

//		cout << pt << endl;

//		cout << r -> getCheck() << endl;

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

//	Row *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *r10, *r11, *r12, *r13, *r14, *r15, *r16, *r17, *r18, *r19, *r20, *r21, *r22, *r23, *r24, *r25, *r26, *r27, *r28, *r29, *r30, 
//	*r31, *r32, *r33, *r34, *r35, *r36, *r37, *r38, *r39, *r40,*r41, *r42, *r43, *r44, *r45, *r46, *r47, *r48;



	

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

					if(!ar.isFull() && !passrows.isEmpty())
					{

						cout << " aisle isn't full yet" << endl;

						ar.enqueue(passrows.getFront());

						as.enqueue(passseats.getFront());

						passrows.dequeue();
				
						passseats.dequeue();

						cur.enqueue(curr);
						
						cout << " another person enters the aisle" << endl;
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


						for (int g = 0; g < cur.getFront(); g++)
						{
	//						cout << "row of pointer " << p.getFront() -> getCheck() << " for " << ar.getFront() << as.getFront() << endl;
			
							tp.enqueue(p.getFront());

							p.dequeue();

							p.enqueue(tp.getFront());
		
							tp.dequeue();
						}




/*						for (int c = 1; c <= cur.getFront(); c++) // find the pointer to the row that the first person in the aisle queue needs to check
						{
//							cout << "6" << endl;
							
							tp.enqueue(p.getFront()); // add the pointer to the row to the temp
							p.dequeue();			// take pointer out of front			
							p.enqueue(tp.getFront()); // add first pointer in temp back into original
							tp.dequeue();  // take out of temp
						}	
*/						// takes front guy and checks him through row class
						if (p.getFront() -> getCheck() == ar.getFront())
						{
//							cout << p.getFront() -> getCheck() << "  match" << ar.getFront();
						
							seconds = p.getFront()->Sit(as.getFront(), 0, seconds); // pointer at front of queue calls its sit function with seat letter as parameter
						
							cout << "sec " << seconds << endl;
						}
						else
						{
							seconds = p.getFront()-> Sit(as.getFront(), 1, seconds);

//							cout << p.getFront() -> getCheck() << "<- point's row  move along  person's row ->" << ar.getFront() << endl;

						}						


//						cout << "reset" << endl;

						while (p.getFront() -> getCheck() != 1) // for rest of pointers that should be behind the checked rows
						{
							

							tp.enqueue(p.getFront()); // move front of point to temp point
														
							p.dequeue();

							p.enqueue(tp.getFront()); // 

							tp.dequeue();

						}						

//						cout << p.getFront() -> getCheck() << endl;

						
						// if seconds - doopsec = 5, that person isn't in the right row so move him up
						// if != 5, he got seated so take him out and throw away
				
						if ((seconds-doopsec) == 5) // if the person wasn't in their proper row
						{
							cout << "wait" << endl;
							
							doopsec += 5;

							curr = cur.getFront(); // curr is the number corresponding to the row the person should be in

							curr ++; // add 1 meaning person goes onto next row

							cur.dequeue(); // get rid of old row value
			
							cur.enqueue(curr); // add the new row value for person to back to the current status queue

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
						
//							cout << " aisle refreshed " << endl;

						}
						else
						{
							cout << "sit" << endl;
					
							doopsec += (seconds - doopsec); // doopsec adds on the time it too for the person to sit
							
							ar.dequeue(); // person's row number is tossed out

							as.dequeue(); // person's seat is tossed out

							cur.dequeue(); // person's current row # is taken out
						
							size --;					

							counter++;
						}
						curr = 1;	
				/*	// refresh aisle
						tar.enqueue(ar.getFront()); // tmp takes first in aisle
						ar.dequeue();	// aisle queue deletes 
						ar.enqueue(tar.getFront()); // aisle queues adds to back
						tar.dequeue(); // tmp deletes
						tas.enqueue(as.getFront()); // does same except with letters
						as.dequeue();
						as.enqueue(tas.getFront());
						tas.dequeue(); */
					}
/*					for(int s =0;s < (48-size); s++)
					{
						tar.enqueue(ar.getFront());
						ar.dequeue();
						ar.enqueue(tar.getFront());
						tar.dequeue();
						tas.enqueue(as.getFront());
						as.dequeue();
						as.enqueue(tas.getFront());
						tas.dequeue();


					}
					
*/					size = 0;

				} while (!ar.isEmpty());

				// update the pointer queue for each passenger that's in the aisle?

			}
			

	/*		cout << "add to print" << endl;
			cout << seconds << endl;	
	//		print.enqueue(seconds);			
			cout << print.getFront();
			cout << seconds << endl; */

	
		switch(print)
		{
			case 0: cout << "Back to front: " << seconds << endl; break;
			case 1: cout << "Random: " << seconds << endl; break;
			case 2: cout << "Outside in: " << seconds << endl; break;
		}
	
		print++;
		seconds = 0;
		doopsec = 0;

	}
	/*		cout << " please " << endl;

			cout << "Back to front: " << print.getFront() << endl;
	//		print.dequeue();
			cout << "Random: " << print.getFront() << endl;
	//		print.dequeue();
			cout << "Outside in: " << print.getFront() << endl;
	*/
	return 0;
}

