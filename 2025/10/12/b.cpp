#include<bits/stdc++.h>
using namespace std;
struct node{
    int bh;
    double cj;
}a[1000001];

bool cnp(node b,node c){
    return b.cj>c.cj;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].bh;
        int cjl=0;
        int p[5];
        int cjs=5;
        for(int j=0;j<5;j++){
            cin>>p[j];
            cjl+=p[j];
        }
        sort(p,p+5);
        a[i].cj=(cjl-p[0]-p[4])/3.000;
        
    }
    sort(a,a+n,cnp);
    for(int i=0;i<3;i++){
        cout<<a[i].bh<<' ';
        cout<<fixed<<setprecision(3)<<a[i].cj<<endl;
    }
}