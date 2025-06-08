#include<bits/stdc++.h>
using namespace std;
int ans=0,n;
int f(int x){
    if(x>3){
        return f(x-2)+f(x-3);
    }
    if(x==1){
        return 0;
    }
    if(x==2){
        return 1;
    }
    if(x==3){
        return 1;
    }
}
int main(){
    while(1){
        cin>>n;
        if((!n)) break;
        cout<<f(n)<<endl;
    }  
}//2222 332 323 233
