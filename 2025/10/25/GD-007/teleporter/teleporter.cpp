#include<bits/stdc++.h>
using namespace std;
int vis[100001]={0};
int a[100001];
queue<int>travel;
int main(){
    freopen("teleporter.in","r",stdin);
    freopen("teleporter.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=1;
    for(int i=1;i<=k;i++){
        vis[ans]=1;
        int asdf=ans;
        ans=a[asdf];

        if(vis[ans]==1){
            while(travel.front()!=ans){
                travel.pop();
            }
            int xhj=(k-i+travel.size()+1)%travel.size();
            if(xhj==0){
                cout<<travel.back();
            }
            else{
                while(xhj>1){
                    travel.pop();
                    xhj--;
                }
                cout<<travel.front();
            }
            return 0;
        }
        else{
            travel.push(ans);
        }
    }
}