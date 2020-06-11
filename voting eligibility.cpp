#include<iostream>
using namespace std;
void eligibility(int age);

int main()
{
	int age;
	cout<<"Enter your age:";
	cin>>age;
	eligibility(age);
	return 0;
 }
 
 void eligibility(int age)
 {
 	if(age>=18)
 		cout<<"You are eligible to vote";
 	else if((age>-1)&&(age<18))
 		cout<<"You are not eligible to vote";
 	else
 		cout<<"Invalid input since age cannot be negative";
 }
 
