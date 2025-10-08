#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long v,p,qzv;
}a[100001];
int chu(int a,int b){
    return (a%b==0)?a/b:(a/b+1);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i].v;
    }
    for(int i=1;i<n;i++){
        a[i].qzv=a[i-1].qzv+a[i].v;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].p;
    }
    a[n].p=a[n-1].p;
    int ans=0,s=0,oil=0,minp=114514;
    queue<int>lx;
    for(int i=0;i<=n;i++){
        if(a[i].p<minp){
            minp=a[i].p;
            lx.push(i);
        }
    }
    while(!lx.empty()){
        int q=lx.front();
        lx.pop();

        if(lx.empty()){
            break;
        }
        ans+=(chu((a[lx.front()].qzv-a[q].qzv+1),d)-oil)*a[q].p;
        oil=chu((a[lx.front()].qzv-a[q].qzv+1),d)-(a[lx.front()].qzv-a[q].qzv+1)/d;
    }
    cout<<ans;
    return 0;
}