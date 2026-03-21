#include<bits/stdc++.h>
using namespace std;
int m[105][105],n[105][105];
int judge(int b,int c){
	if(c>b){
		return 0;
	}
	else{
		return 1;
	}
}
int j(string a){
	int cnt=0,sz=1;
	if(a=="0"){
		return cnt;
	}
	for(int j=a.size()-1;j>=0;j--){
		cnt+=(a[j]-48)*sz;
		sz*=10;
	}
	return cnt;
}
int hs(int a){
	int cnt=0;
	while(a){
		a/=10;
		cnt++;
	}
	return cnt;
}
int t(int lo){
	if(lo==0){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	string a,l;
	int b,c,d,cnt=0;
	int a1;
	cin>>a1;
	for(int i=1;i<=a1;i++){
		cin>>a>>b;
		if(a!="a"&&a!="b"&&a!="c"){
			if(l=="a"){
				d=j(a)+b;
				cout<<j(a)<<"+"<<b<<"="<<d<<endl;
				cout<<cnt+2+hs(j(a))+hs(b)+hs(d)+t(hs(j(a)))+t(hs(b))+t(hs(d))<<endl;
				l="a";
			}
			else if(l=="b"){
				//d=b-c;
				if(judge(j(a),b)==0){
					d=b-j(a);
					cout<<j(a)<<"-"<<b<<"=-"<<d<<endl;
					cout<<cnt+3+hs(j(a))+hs(b)+hs(d)+t(hs(j(a)))+t(hs(b))+t(hs(d))<<endl;
				}
				else{
					d=j(a)-b;
					cout<<j(a)<<"-"<<b<<"="<<d<<endl;
					cout<<cnt+2+hs(j(a))+hs(b)+hs(d)+t(hs(j(a)))+t(hs(b))+t(hs(d))<<endl;
				}
				l="b";
			}
			else{
				d=b*j(a);
				cout<<j(a)<<"*"<<b<<"="<<d<<endl;
				cout<<cnt+2+hs(j(a))+hs(b)+hs(d)+t(hs(j(a)))+t(hs(b))+t(hs(d))<<endl;
				l="c";
			}
		}
		else{
			cin>>c;
			if(a=="a"){
				d=b+c;
				cout<<b<<"+"<<c<<"="<<d<<endl;
				cout<<cnt+2+hs(b)+hs(c)+hs(d)+t(hs(b))+t(hs(c))+t(hs(d))<<endl;
				l="a";
			}
			else if(a=="b"){
				//d=b-c;
				if(judge(b,c)==0){
					d=c-b;
					cout<<b<<"-"<<c<<"=-"<<d<<endl;
					cout<<cnt+3+hs(b)+hs(c)+hs(d)+t(hs(b))+t(hs(c))+t(hs(d))<<endl;
				}
				else{
					d=b-c;
					cout<<b<<"-"<<c<<"="<<d<<endl;
					cout<<cnt+2+hs(b)+hs(c)+hs(d)+t(hs(b))+t(hs(c))+t(hs(d))<<endl;
				}
				l="b";
			}
			else{
				d=b*c;
				cout<<b<<"*"<<c<<"="<<d<<endl;
				cout<<cnt+2+hs(b)+hs(c)+hs(d)+t(hs(b))+t(hs(c))+t(hs(d))<<endl;
				l="c";
			}
		}
	}
	return 0;
}