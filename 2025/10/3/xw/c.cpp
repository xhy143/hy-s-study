#include<bits/stdc++.h>
using namespace std;
void o(int n){
    cout<<n<<endl;
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            o(-1);
        }if(n==2){
            o(1);
        }if(n==3){
            o(7);
        }if(n==4){
            o(4);
        }if(n==5){
            o(2);
        }if(n==6){
            o(6);
        }if(n==7){
            o(8);
        }
        for(int i=0;i<=n/7;i++){
            cout<<8;
        }
    }
}