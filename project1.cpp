#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int p = 0;

//Creating a class containing variables and functions
class a
{
	char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
	  void avail();
	  void position(int i);
}

bus[10];

//Creates border while showing the data
void vline(char ch)
{
	for (int i=80;i>0;i--)
		cout<<ch;
}


//Installation of new bus information
void a::install()
{
	cout<<"\nEnter the bus number: ";
	cin>>bus[p].busn;

	cout<<"Enter the driver's name: ";
	cin>>bus[p].driver;

	cout<<"Enter the arrival time: ";
	cin>>bus[p].arrival;

	cout<<"Enter the departure time: ";
	cin>>bus[p].depart;

	cout<<"From: ";
	cin>>bus[p].from;

	cout<<"To: ";
	cin>>bus[p].to;

	bus[p].empty();
	p++;

}

//Booking a seat in a bus
void a::allotment()
{
	int seat;
	char number[5];

	top:
	cout<<"\nEnter the bus number: ";
	cin>>number;

	int n;
	for(n=0;n<=p;n++)
	{
	if(strcmp(bus[n].busn, number)==0)
		break;
	}

	while(n<=p)
	{
		cout<<"Enter the seat number: ";
		cin>>seat;
		
		if(seat>32)
		{
			cout<<"There are only 32 seats in this bus.\n";
		}
		else
		{
			if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
			{
				cout<<"Enter the passenger's name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
				cout<<"This seat number is already reserved\n\n";
		}
	}

	if(n>p)
	{
		cout<<"Enter the correct bus no.\n";
		goto top;
	}
}

//Marks the seats "Empty" which are not booked
void a::empty()
{
	for(int i=0; i<8;i++)
	{	
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j], "Empty");
		}
	}
}

//Shows details of a particular bus (like bus number, name of the driver, 
//ariival and departure time, registered passegers)
void a::show()
{
	int n;
	char number[5];
	cout<<"\nEnter the bus number: ";
	cin>>number;

	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn, number)==0)
			break;
	}

	while(n<=p)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busn
		<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
		<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
		<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
		bus[n].to<<"\n";
		vline('*');
	
		bus[0].position(n);

		int a=1;

		for (int i=0; i<8; i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
					cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
			}
		}		
		break;
	}

	if(n>p)
		cout<<"Enter the correct bus number: ";
}

void a::position(int l)
{
	int s=0;p=0;
	for (int i =0; i<8;i++)
	{
    	cout<<"\n";
    	for (int j = 0;j<4; j++)
    	{
     		s++;
      		if(strcmp(bus[l].seat[i][j], "Empty")==0)
        	{
          		cout.width(5);
          		cout.fill(' ');
          		cout<<s<<".";
          		cout.width(10);
          		cout.fill(' ');
          		cout<<bus[l].seat[i][j];
          		p++;
        	}
        else
        {
        	cout.width(5);
        	cout.fill(' ');
        	cout<<s<<".";
        	cout.width(10);
        	cout.fill(' ');
        	cout<<bus[l].seat[i][j];
        }
      }
    }
	cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}

//Shows buses that are available for transportation
void a::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
    	cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
    	<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
    	<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    	<<bus[n].to<<"\n";
    	vline('*');
    	vline('_');
  	}
}

int main()
{
	system("cls");
	int w;
	
	//Creating options for users to select
	while(1)
	{
		cout<<"\n\nMenu:\n\n";
		cout<<"1.Intsall";
		cout<<"\n2.Reservation";
		cout<<"\n3.Show";
		cout<<"\n4.Buses Available";
		cout<<"\n5.Exit\n\n";
		
		cout<<"Enter your choice: ";
		cin>>w;
		switch(w)
		{
			case 1: bus[p].install();
					break;
			case 2: bus[p].allotment();
					break;
			case 3: bus[0].show();
					break;
			case 4: bus[0].avail();
					break;
			case 5: exit(0);
			
		}
			
	}
	
	return 0;
}
