#include <iostream>
using namespace std;

int main() 

{
int ch,a,b,c;
char h;
do
{
cout<<"\n Main Menu";
cout<<"\n 1. Add two numbers";
cout<<"\n 2. Multiply two numbers";
cout<<"\n 3. subract two numbers ";
cout<<"\n 4. Exit ";
cout<<"\n Enter your choice ";
cin>>ch;
switch(ch)
{1
	case 1:
		cout<<"\n Enter 2 number ";
		cin>>a>>b;
		c=a+b;
		cout<<"\n Sum ="<<c;
		break;
case 2:
		cout<<"\n Enter 2 number ";
		cin>>a>>b;
		c=a*b;
		cout<<"\n Multiplication ="<<c;
		break;
case 3:
		cout<<"\n Enter 2 number ";
		cin>>a>>b;
		c=a-b;
		cout<<"\n Subtract ="<<c;
		break;
case 4:	break;
}
cout<<"\n Continue y/n ";
cin>>h;
}while(h!='n');

}
