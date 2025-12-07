#include<bits/stdc++.h>
using namespace std;
long long n;
string six="0123456789ABCDEF";
void out(int i){
	cout<<six[i/16]<<six[i%16]<<" ";
}
int main(){
	cin>>n;
    if(n==0) {cout<<"00";return 0;}
	while(n>0){
        int d=pow(2,7);
		int k=n%d;
		n/=128;
		if(n>0)out(k+d);
		else out(k);
	}
	return 0;
}
