#include<bits/stdc++.h>
using namespace std;
#define int long long
void exgcd(int a,int b,int & d,int &x,int& y){
    if(b==0){
        d=a;x=1;y=0;
        return ;
    }
    int nx,ny;
    exgcd(b,a%b,d,nx,ny);
    x=ny;
    y=nx-(a/b)*ny;
}
signed main(){
    int a,b,x,y,d;
    cin>>a>>b;
    exgcd(a,b,d,x,y);
    int ans=(x%b+b)%b;
    if(ans==0)ans=b;
    cout<<ans<<endl;
}