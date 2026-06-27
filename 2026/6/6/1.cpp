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
        int x,y,d,a,b,c;
        cin>>a>>b>>c;
        exgcd(a,b,d,x,y);
        if(c%d!=0){
            cout<<-1<<endl;
            continue;
        }
        x*=c/d;
        y*=c/d;
        cout<<x<<' '<<y<<endl;
    }
}