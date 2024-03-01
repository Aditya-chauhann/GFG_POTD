#include <iostream>
using namespace std;

int main() 
{
	int n,x,even=0,odd=0;
cout<<"\n enter a number ";
cin>>n;

	for(x=1;x<=n;x++)
{
		if(x%2==0)
	even=even+1;
	else
	odd=odd+1;}
cout<<"\n number of odd numbers from 1 to "<<n<<" is "<<odd<<"\n number of even numbers from 1 to "<<n<<" is "<<even;

}
