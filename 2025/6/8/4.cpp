#include<bits/stdc++.h>
using namespace std;
int ans=0,n;
vector<int> visited(35,0);
int f(int x){
    if(x==0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if(!visited[n]){
        return visited[n];            //What the fuck??????? :D
    }
   visited[n] = f(x-1)+f(x-2);
   return visited[n];
}
int main(){
    while(cin>>n){
        cout<<f(n)<<endl;
    }
}//2222 332 323 233
