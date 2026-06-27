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

int M=1,m[1000001],a[1000001];
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>a[i];
        M=M*m[i];
    }
    int X=0;
    for(int i=1;i<=n;i++){
        int x,y,d;
        exgcd(M/m[i],m[i],d,x,y);
        x=((M/m[i])*x)%M;
        X=(X+x*a[i])%M;
        if(X<0){
            X+=M;
        }
    }
    cout<<X<<endl;
}