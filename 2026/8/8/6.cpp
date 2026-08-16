#include<bits/stdc++.h>
using namespace std;
#define int long long
void exgcd(int a,int b,int &d,int& x,int&y){
    if(b==0){
        d=a;
        x=1,y=0;
        return;
    }
    int nx,ny;
    exgcd(b,a%b,d,nx,ny);
    x=ny;
    y=nx-(a/b)*ny;
}
int fav_exgcd(int a,int m){
    int d,x,y;
    exgcd(a,m,d,x,y);
    if(d!=1)return -1;
    return (x%m+m)%m;
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        int a,m;
        cin>>a>>m;
        cout<<fav_exgcd(a,m)<<endl;
    }
}