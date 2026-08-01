#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
bool check(int mid){
    int len=mid;
    int last=0,move=0;
    for(int i=0;i<=n;i++){
        if(a[i]-last<mid){
            move++;
        }else{
            last=a[i];
        }
    }
    if(move<=m)return 1;
    return 0;
}
int main(){
    int ll;
    cin>>ll>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    a[n]=ll;
    int ans=0;
    int l=0,r=ll;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}