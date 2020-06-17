#include<iostream>
using namespace std;
bool check_prime(int num);

int main()
{
	int num,i;
	cout<<"Enter the number:";
	cin>>num;
	check_prime(num);
	bool result= true;
	
	if (check_prime(num) && check_prime(num - 2))
		result=true;
	else
		result=false;
		
	if(result==true)
		cout<<num<<" is a sum of two prime numbers";
	else
		cout<<num<<" is not a sum of two prime numbers";
		
	return 0;
}

bool check_prime(int n)
{
	int i;
	bool result=true;
	
	if(n<=1)
		result=false;
		
	for(i=2;i<=n;i++)
	{
		if((n%2)==0)
			result=false;
			break;
	}
	
	return result;;
}
