#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    if(n==1){
        cout<<fixed<<setprecision(1)<<n*m*0.0325+m<<endl;
    }
    else if(n==2){
        cout<<fixed<<setprecision(1)<<m*n*0.0375+m<<endl;
    }
    else if(n==3){
        cout<<fixed<<setprecision(1)<<m*n*0.0425+m<<endl;
    }
    else if(n==4){
        cout<<fixed<<setprecision(1)<<m*n*0.0425+m<<endl;
    }
    else if(n==5){
        cout<<fixed<<setprecision(1)<<m*n*0.0475+m<<endl;
    }
}