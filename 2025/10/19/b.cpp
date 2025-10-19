#include<bits/stdc++.h>
using namespace std;
bool js(int n){
    int hc[10]={6,2,5,5,4,5,6,3,7,6};
    int ans=0;
    while(n>0){
        
        ans+=hc[n%10];
        n/=10;
        if(ans>6){
            return 0;
        }
    }
    if(ans==6){
        return 1;
    }
    return 0;
}
int main(){
    int n;
    for(int i=0;i<=111;i++){
        if(js(i)==1) cout<<i<<endl;
    }
}