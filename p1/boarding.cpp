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

typedef enum{A, B, C, D, E, F} letters;

	StackAr<letters> lseated;

	StackAr<letters> rseated;

// holds and keeps track of the passengers

	QueueAr<letters> raisle;

	QueueAr<letters> saisle;

// fill in containers with all passengers
	Row(line)
	{
		int row;
		char seat;
		while(line >> row >> seat)
		{
			raisle.insert(row);
			saisle.insert(seat)
		}
	}	

}

int main(int argc, char * argv[1])
{
	int time;
	ifstream seats(argv[1]);			

	Row strat1(line), strat2(line), strat3(line);

	cout << "Back to front: " << strat1(seats.getline()) << endl;
	cout << "Random: " << strat2(seats.getline()) << endl;
	cout << "Outside in:" << strat3(seats.getline());

}
