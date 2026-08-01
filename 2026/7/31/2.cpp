#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10,inf=0x3f3f3f3f3f3f3f3f;
int n,m,q,lg[maxn],a[maxn],b[maxn],mxa[maxn][25],mxb[maxn][25],mna[maxn][25],mnb[maxn][25],mnz[maxn][25],mxf[maxn][25];
int qmax(int st[][25],int l,int r){
    int len=r-l+1;
    return max(st[l][lg[len]],st[r-(1<<lg[len])+1][lg[len]]);
}
int qmin(int st[][25],int l,int r){
    int len=r-l+1;
    return min(st[l][lg[len]],st[r-(1<<lg[len])+1][lg[len]]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=2;i<=max(n,m);i++) lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mxa[i][0]=mna[i][0]=a[i];
        mnz[i][0]=(a[i]>=0?a[i]:inf);
        mxf[i][0]=(a[i]<0?a[i]:-inf);
    }
    for(int j=1;j<=lg[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            mxa[i][j]=max(mxa[i][j-1],mxa[i+(1<<(j-1))][j-1]);
            mna[i][j]=min(mna[i][j-1],mna[i+(1<<(j-1))][j-1]);
            mnz[i][j]=min(mnz[i][j-1],mnz[i+(1<<(j-1))][j-1]);
            mxf[i][j]=max(mxf[i][j-1],mxf[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        mxb[i][0]=mnb[i][0]=b[i];
    }
    for(int j=1;j<=lg[m];j++){
        for(int i=1;i+(1<<j)-1<=m;i++){
            mxb[i][j]=max(mxb[i][j-1],mxb[i+(1<<(j-1))][j-1]);
            mnb[i][j]=min(mnb[i][j-1],mnb[i+(1<<(j-1))][j-1]);
        }
    }
    while(q--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int maxa=qmax(mxa,l1,r1);
        int mina=qmin(mna,l1,r1);
        int maxb=qmax(mxb,l2,r2);
        int minb=qmin(mnb,l2,r2);
        int ans = -inf;
        if(maxa >= 0) {
            ans = max(ans, maxa * minb);
        }
        if(mina < 0) {
            ans = max(ans, mina * maxb);
        }
        int minz = qmin(mnz, l1, r1);
        if(minz != inf) {
            ans = max(ans, min(minz * minb, minz * maxb));
        }
        int maxf = qmax(mxf, l1, r1);
        if(maxf != -inf) {
            ans = max(ans, min(maxf * minb, maxf * maxb));
        }
        
        cout<<ans<<'\n';
    }
    
    return 0;
}