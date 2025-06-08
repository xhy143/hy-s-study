#include<bits/stdc++.h>
using namespace std;

vector<int> visited(55,0);
int f(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(visited[n]!=0){
        return visited[n];
    }
    visited[n]=f(n-2)+f(n-3);
    return visited[n];
}
int main(){
    int n;
    while(cin>>n&&n!=0){
        int k=f(n);
        cout<<k<<endl;
    }
}//2222 332 323 233
