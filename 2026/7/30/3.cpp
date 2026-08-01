#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+100;
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n,t;
        cin>>n>>t;
        vector<int>a;
        for(int i=1;i<=n;i++){
            int p;
            cin>>p;
            a.emplace_back(p);
        }
        int ans=1;
        while(t--){
            for(auto pos:a){
                if(pos<=ans){
                    ans++;
                }else{
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}