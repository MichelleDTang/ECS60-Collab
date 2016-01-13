
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
}
