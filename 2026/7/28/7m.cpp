#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int a,pos;
};
const int maxn=1e5+100;
node a[maxn];
int pre[maxn];
int n,A,cf,cm,m;
bool cmp1(node a,node b){
    return a.a<b.a;
}
bool cmp2(node a,node b){
    return a.pos<b.pos;
}
int check(int mid, int limit){
    int l=1, r=limit, pos=limit+1;
    while(l<=r){
        int mid2=(l+r)>>1;
        if(a[mid2].a >= mid){
            pos=mid2;
            r=mid2-1;
        }else{
            l=mid2+1;
        }
    }
    int cnt = pos - 1;  
    int cost = cnt * mid - pre[cnt];  
    return cost;
}
signed main(){
    cin>>n>>A>>cf>>cm>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].a;
        a[i].pos=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i].a;
    }
    int cost=0;
    int fullCnt=0;
    for(int i=n;i>=1;i--){
        int dh=A-a[i].a;
        if(cost+dh>m){
            break;
        }
        cost+=dh;
        fullCnt++;
    }
    if(fullCnt==n){
        cout<<cf*n+cm*A<<endl;
        for(int i=1;i<=n;i++){
            cout<<A<<' ';
        }
        return 0;
    }
    m-=cost;
    int remaining = n - fullCnt;
    int l=0, r=A, ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        int costNeed=check(mid, remaining);
        if(costNeed<=m){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    for(int i=n-fullCnt+1; i<=n; i++){
        a[i].a = A;
    }
    for(int i=1;i<=remaining;i++){
        if(a[i].a < ans){
            a[i].a = ans;
        }
    }
    cout<<fullCnt*cf + ans*cm<<endl;
    sort(a+1,a+1+n,cmp2);
    for(int i=1;i<=n;i++){
        cout<<a[i].a<<' ';
    }
}