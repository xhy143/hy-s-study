#include<bits/stdc++.h>
using namespace std;
int zh(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return x/i;
    }
    return 1;
}
// a=2*
void solve(int a,int b){
    int ans=0;
    while(a!=b){ // 25
        if(a>b){
            swap(a,b);
        }
        b=zh(b);// 30000
        ans++;
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){ //1000
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }
}