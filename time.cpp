#include<iostream>
#include <iomanip>
using namespace std;

class time{
	public:
		int hrs;
		int min;
		int scd;
};

class calculate : public time{
	public:
		int input();
		int display();
};

int calculate::input(){
	cout<<"Hours? ";
	cin>>hrs;
	cout<<"Minutes? ";
	cin>>min;
	cout<<"Seconds? ";
	cin>>scd;
}

int calculate::display(){
	cout<<"The time is = "<<setw(2)<<setfill('0')<<hrs;
	cout<<":"<<setw(2)<<setfill('0')<<min;
	cout<<":"<<setw(2)<<setfill('0')<<scd;
	cout<<"\nTime in total seconds: "<<(scd+(min*60)+(hrs*60*60));
}

int main()
{
	calculate c;
	c.input();
	c.display();
	return 0;
}
