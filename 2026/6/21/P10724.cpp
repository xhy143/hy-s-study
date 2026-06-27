#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>prime={2,3,5,7,11,13,17,19,23,29};
int n,a[1000001],b[31],prexor,cnt[1000086];
void prew(){
    for(int i=1;i<=30;i++){
        int j=i;
        for(int k=0;k<10;k++){
            while(j%prime[k]==0){
                b[i]^=1<<k;
                j/=prime[k];
            }
        }
    }
}
signed main(){
    cin>>n;
    int ans=0;
    prew();
    cnt[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        prexor^=b[a[i]];
        ans+=cnt[prexor]++;
    }
    cout<<ans;
}