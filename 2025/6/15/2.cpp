#include<bits/stdc++.h>
using namespace std;

vector<int> v(55,0);
int f(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(v[n]!=0){
        return v[n];
    }
    v[n]=f(n-2)+f(n-3);
    return v[n];
}
int main(){
    int n;
    while(cin>>n&&n!=0){
        int k=f(n);
        cout<<k<<endl;
    }
}