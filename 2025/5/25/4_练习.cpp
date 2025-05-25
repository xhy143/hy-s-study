#include<bits/stdc++.h>
using namespace std;
int main(){
    double mb,b,d,n,x,y;
    cin>>n>>x>>y;
    mb=n/x;
    for(int i=mb;i>=1;i--){
        b=i;
        d=(n-b*x)/y;
        if(int(d)==d&&int(b)==b&&d>0){
            cout<<b<<" "<<int(d);
            return 0;
        }
          
    }
}