#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k%10<5){
            cout<<k/10*10<<endl;
        }else{
            cout<<k/10*10+10<<endl;
        }
    }
}