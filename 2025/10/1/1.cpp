#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    stack<int>num;
    cin>>n;
    if(n%2!=0){
        cout<<-1;
        return 0;
    }
    int sw=1;
    while(n>=1){
        n=n>>1;
        sw*=2;
        if((n&1)==1){
            num.push(sw);
        }
    }
    if(num.empty()){
        cout<<-1;
        return 0;
    }
    while(!num.empty()){
        cout<<num.top()<<' ';
        num.pop();
    }
}