#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3,i=0,k;
char ch[300],be,af,f,j,p;
int main() {
	cin>>p1>>p2>>p3>>ch;
	while(ch[i]){
		be=ch[i-1];af=ch[i+1];f=ch[i]; 
		if(f=='-'&&af>be&&(be>='0'&&af<='9'||be>='a'&&af<='z')){ 
			for(p3==1?j=be+1:j=af-1; p3==1?j<af:j>be; p3==1?j++:j--){
				p=j; 
				if(p1==2)
					p=(p>='a')?p-32:p; 
				else if(p1==3) p='*';
				for(k=0; k<p2; k++)
					cout<<p;
			}
		} 
		else
			cout<<f;
		i++;
	}
	return 0;
}
