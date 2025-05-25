#include<bits/stdc++.h>
using namespace std;
int main(){
    int mb,b,d,n,x,y;
    cin>>n>>x>>y;
    mb=n/x;
    for(int i=mb;i>=0;i--){
        b=i;
        d=(n-b*x)/y;
        if(x*b+y*d==n){
            cout<<b<<" "<<d;
            return 0;
        }
    }
}