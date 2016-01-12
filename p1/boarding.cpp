// Michelle Tang
//912026295
//
//need container for waiting, seated, and move out

#include<iostream>
#include<fstream>
#include"StackAr.h"
#include"QueueAr.h"

using namespace std;

class Row
{
  public:
	int time = 0;

	typedef enum{A, B, C, D, E, F} letters;

	StackAr<letters> lseated(144);

	StackAr<int> lseatedr(144);

	StackAr<letters> rseated(144);

	StackAr<int> rseatedr(144);

// holds and keeps track of the passengers

	QueueAr<int> raisle(288);

	QueueAr<letters> saisle(288);

// fill in containers with all passengers
	Row(line)
	{
		int row;
		char seat;
		while(line >> row >> seat)
		{
			raisle.enqueue(row);
			saisle.enqueue(seat);
		}
	}	
	
//waiting, seated, and out
//seat the first passenger
	//left
	if (saisle.getFront() == 'A' || saisle.getFront() == 'B' || 
		saisle.getFront() =='C')	
	{

		//must wait in each row for 5 seconds
		for (int r=1 ; r <= raisle.getFront() ; r++)
		{
			time = time + 5;
		}
		
		//luggage
		time = time + 10;
		//passenger now seated
		lseated.push(saisle.getFront());
		lseatedr.push(raisle.getFront());
		
		saisle.dequeue();
		raisle.dequeue();
		
	}
	//right
	else
	{
		
		for (int r=1 ; r <= raisle.getFront() ; r++)
		{
			time = time + 5	
		}

		time = time + 10;

		rseated.push(saisle.getFront());
		rseatedr.push(raisle.getFront());
		
		saisle.dequeue();
		raisle.dequeue();
		
	}

//start seating everyone else
	
	//go through every remaining passenger
	// compare first in queue to top of stack

	for (int i = 1 ; i < 288; i++)
	{
		//if front guy is D and second guy's row is bigger

		//if front guy is D and second guy's row is smaller

		//simultaneous seating
		
		//someone is closer to aisle

			 
		

	}  		


	return time;
}

int main(int argc, char * argv[1])
{
	ifstream seats(argv[1]);			

	


	Row strat1(line), strat2(line), strat3(line);

	cout << "Back to front: " << strat1(seats.getline()) << endl;
	cout << "Random: " << strat2(seats.getline()) << endl;
	cout << "Outside in:" << strat3(seats.getline()) << endl;

}
