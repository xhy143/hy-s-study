#include<bits/stdc++.h>
using namespace std;
#define int long long
void exgcd(int a,int b,int &d,int& x,int&y){
    if(b==0){
        x=1,y=0,d=a;
        return ;
    }
    int nx,ny;
    exgcd(b,a%b,d,nx,ny);
    x=ny;
    y=nx-(a/b)*ny;
}
signed main(){
    int a,b,ans,x,y,d;
    cin>>a>>b;
    exgcd(a,b,d,x,y);
    ans=(x%b+b)%b;
    cout<<ans<<endl;
}