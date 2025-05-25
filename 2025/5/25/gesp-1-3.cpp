#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    double s=y*1.0/x*1.0;               
    if(int(s)!=s){
        s=int(s)+1;
    }
    cout<<n-s;
}
