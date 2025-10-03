#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b?(gcd(b,a%b)):a;
}
int main(){
    int T,m,a,b,c;
    cin>>T>>m;
    while(T--){
        cin>>a>>b>>c;
        if(a<b) a=-a,b=-b,c=-c;
        int d=b*b-4*a*c;
        int k=1;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        int t;
        if(d==0||d==1){
            t=abs(gcd(2*a,-b+k*d));
            cout<<-(b+k*d)/t;
            if(2*a/t!=1)cout<<'/'<<2*a/t;
            cout<<"\n";
            continue;
        }
        t=abs(gcd(-b,2*a));
        if(-b/t!=0){
            cout<<-b/t;
            if(2*a/t!=1) cout<<'/'<<2*a-t;
            cout<<"+";
        }
        t=abs(gcd(k,2*a));
        if(k/t!=1) cout<<k/t<<"*";
        printf("sqrt(%d)",d);
        if(2*a/t!=1) cout<<'/'<<2*a-t;
        cout<<"\n";
    }
}