#include<bits/stdc++.h>
using namespace std;
int a[1000001],tot;
void up(int n){
    while(n!=1){
        int fa=n/2;
        if(a[fa]>a[n]) {
            swap(a[fa],a[n]);
            n=fa;
        }
        else break;
    }
    cout<<n<<endl;
}
void down(){
    int n=1;
    while(n*2<=tot){
        int ls=n*2;
        if((ls+1<=tot)&&a[ls]>a[ls+1]) ls++;
        swap(a[n],a[ls]);
        n=ls;
    }
}
int main(){
    int n;
    cin>>n;
    int T;
    cin>>T;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    tot=n;
    while(T--){
        int op;
        cin>>op;
        if(op==1){
            int l;
            cin>>l;
            tot++;
            a[tot]=l;
            up(tot);
        }
        if(op==2){
            cout<<a[1]<<endl;
            swap(a[1],a[tot]);
            tot--;
            down();
        }
    }
}