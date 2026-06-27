#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
void exgcd(int a,int b,int &d,int &x,int& y){
    if(b==0){
        d=a,x=1,y=0;
        return;
    }
    int nx,ny;
    exgcd(b,a%b,d,nx,ny);
    x=ny;
    y=nx-(a/b)*ny;
}
signed main(){
    cin>>T;
    while(T--){
        int x,y,d,a,b,c,m;
        cin>>a>>m;
        exgcd(a,m,d,x,y);
        if(d!=1){
            cout<<-1<<endl;
            continue;
        }
        x=x%m;
        if(x<0) x+=m;
        cout<<x<<endl;
    }
}