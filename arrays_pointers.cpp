#include <iostream> 
using namespace std; 

int main()
{
	int i,n;
	cout<<"Enter the size of the array:";
	cin>>n;
	int a[n];
	int *ptr;
	ptr=a;
	cout<<"Enter the elements:";
	for(i=0;i<n;i++)
		cin>>*(ptr+i);
	cout<<"The elements are:\n";
	for(i=0;i<n;i++)
		cout<<*(ptr+i)<<"\n";
	
	return 0;
}
