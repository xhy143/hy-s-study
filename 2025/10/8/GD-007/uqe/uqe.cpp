#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i,j,n,m;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    char f[101];
    cin>>f;
    sscanf(f,"(%lldx+%d)(%lldx+%lld)",&i,&j,&n,&m);
    long long a=i*n,b=i*m+j*n,c=j*m,flag=0;
    if(a==0&&b==0&&c==0){
        return 0;
    }
    if(a!=0){
        printf("%dx^2",a);
        if(b!=0||c!=0){
            cout<<"+";
        }
    }
    if(b!=0){
        cout<<b<<"x";
        if(c!=0) cout<<"+";
    }
    if(c!=0){
        cout<<c;
    }
}