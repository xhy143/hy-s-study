#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=30;
int n,k,r[maxn],all=0;
int js(int mark){
    vector<int>join;
    int u=0,d=0x3f3f3f3f3f3f3f3f,alljr=0;
    int qzh[maxn];
    memset(qzh,0,sizeof(qzh));
    int i=n;
    while(mark>=0){
        int now=mark&1;
        if(now==1){
            join.push_back(r[i]);
            alljr+=r[i];
        }else u+=r[i];
    cout<<1<<endl;
        i--;
        mark>>=1;
    }
    if(join.empty()){
        return all;
    }
    sort(join.begin(),join.end());
    qzh[0]=join[0];
    for(int i=1;i<n;i++){
        qzh[i]=qzh[i-1]+join[i];
    }
    d=alljr;
    for(int i=0;i<n;i++){
        int l=qzh[i],r=alljr-qzh[i];
        int nd=l-r;
        if(nd>=0&&nd<d){
            d=nd;
        }else if(-nd>=0&&-nd<d){
            d=-nd;
        }
    }
    return u+k*d;
}
signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>r[i];
        all+=r[i];
    }
    int ans=all;
    for(int i=1;i<=(1<<24);i++){
        ans=min(ans,js(i));
    }
    cout<<ans<<endl;
}