#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<0){
    	cout<<"N";
    	return 0; 
	} 
    if(int(sqrt(n))*int(sqrt(n))==n){
        cout<<"Y";
        return 0;
    }
    cout<<"N";
}
