#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
static int size=0;


double CharToDouble(char* address)//假设数字不超过100位 
{
	int digit[100];
	double sum=0;
	int dot=0;
	int temp=0;
	sum=digit[size]=*address-48;
	while(*(address+size+1)!='\0')
	{
		if(*(address+(size+1))=='.')
		{
			sum=0;
			for(int i=size++;i>=0;i--)
			{
				sum+=digit[size-1-i]*pow(10,i);
			}
			dot=1;
			continue;
		}
		if(dot==0)
		{
			digit[size+1]=*(address+(size+1))-48;
			size++;
		} 
		else
		{
			digit[99+(temp--)]=*(address+(++size))-48;
		}
	} 
	
	if(dot==1)
	{
		for(int i=temp;i<0;i++)
		{
			sum+=digit[100+i]*pow(10,i);
		}
	}
	else if(dot==0)
	{
		sum=0;
		for(int i=size++;i>=0;i--)
		{
			sum+=digit[size-1-i]*pow(10,i);
		}
	}
	return sum;
}
int main()
{
	char ch[15];
	cin>>ch;
	double temp=CharToDouble(ch);
	cout<<temp<<endl;
	return 0;
}
