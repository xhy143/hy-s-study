#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>w;
    int pre=0;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        pre+=p;
        w.push_back(p);
    }
    if(pre<=m){
        cout<<pre<<endl;
        return 0;
    }
    sort(w.begin(),w.end(),greater<int>());
    int ans=0;
    for(int j=0;j<k;j++){
        ans+=w[j];
    }
    int sy=m,i=n-1;
    int lw=m;
    while(lw>0&&i>k){
        ans+=w[i];
        lw-=w[i];
        if(lw<0){
            ans-=w[i];
            lw+=w[i];
        }
        i--;
    }
    ans+=w[k];
    cout<<ans<<endl;
}