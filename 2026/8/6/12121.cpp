#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>prime;
const int maxy=1e14,sqy=1e8+10;
bool vis[10000010];int pre[sqy],f[sqy];
int cnt=0,ans=0;
void init(){
    for(int i=2;i<=sqy;i++){
        if(vis[i]==0){
            prime.push_back(i);
            cnt+=i;
            if(cnt>=maxy){
                cout<<i<<endl<<prime.size();
                return ;
            }

        }
        for(auto p:prime){
            if(p*i>sqy)break;
            vis[i*p]=1;
            if(i%p==0)break;
        }
    }
    
}
signed main(){
    init();
    
}