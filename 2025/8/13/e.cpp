#include<bits/stdc++.h>
using namespace std;
int a[20000002],b[10000001];
int main(){
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }
    for(int i=0;i<q;i++){
        int l,r,f;
        cin>>l>>r>>f;
        b[l]+=f;
        b[r+1]-=f;
    }
    int minn=0xfffffff;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+b[i];
        if(a[i]<minn){
            minn=a[i];
        }
    }
    cout<<minn;
}