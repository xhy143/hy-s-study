#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cout<<"o";
	for(int i=1;i<=n;i++)
	cout<<"*";
	cout<<"--"<<endl;	  
	for(int i=2;i<=n-3;i++)
	{							
		for(int j=n;j>=i;j--)   
		cout<<"o";
		cout<<"--";				
		for(int j=n;j>=i;j--)  
		cout<<"*";
		for(int j=1;j<i;j++)	
		cout<<"o*";
		cout<<endl;
		for(int j=n;j>=i;j--)
		cout<<"o";
		for(int j=n;j>=i;j--)
		cout<<"*";
		cout<<"--";
		for(int j=1;j<i;j++)
		cout<<"o*";		
		cout<<endl;
	}
	if(n>4)
	{
		cout<<"ooo--***";
		for(int i=1;i<=n-3;i++)
		cout<<"o*";
		cout<<endl;		
	}
	cout<<"ooo*o**--*";
	for(int i=1;i<=n-4;i++)
	cout<<"o*";
	cout<<endl;
	cout<<"o--*o**o";
	for(int i=1;i<=n-3;i++)
	cout<<"o*";
	cout<<endl;
	cout<<"o*o*o*--";
	for(int i=1;i<=n-3;i++)
	cout<<"o*";
	cout<<endl;
	cout<<"--";
	for(int i=1;i<=n;i++)
	cout<<"o*";
   return 0;
}
