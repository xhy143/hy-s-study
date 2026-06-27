#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=200100;
int n,q,a[10],b[10],c;
int f[mx];
signed main(){
    cin>>n;
    f[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=a[i];j<=200000;j++){
            f[j]+=f[j-a[i]];
        }
    }
    cin>>q;
    while(q--){
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cin>>c;
        int ans=f[c];
        for(int s=1;s<(1<<n);s++){
            int now=c,bit=0;
            for(int i=0;i<n;i++){
                if(s&(1<<i)){
                    now-=a[i]*(b[i]+1);
                    bit++;
                }
            }
            if(now<0)continue;
            if(bit%2==1)ans-=f[now];
            else ans+=f[now];
        }
        cout<<ans<<endl;
    }
}