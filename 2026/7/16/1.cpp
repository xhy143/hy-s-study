#include<bits/stdc++.h>
using namespace std;
multiset<int>ms;
const int maxn=4e4+100;
struct line{
    int x,h,type;
    bool operator <(const line &b) const{
        return x<b.x;
    }
};
int n;
vector<line> event;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x1,x2,h;
        cin>>x1>>x2>>h;
        event.push_back({x1,h,1});
        event.push_back({x2,h,-1});
    }
    long long ans=0;
    sort(event.begin(),event.end());
    for(int i=0;i+1<event.size();i++){
        if(event[i].type==1) ms.insert(event[i].h);
        else ms.erase(ms.find(event[i].h));
        int dx=event[i+1].x-event[i].x;
        int maxh;
        if(ms.empty())maxh=0;
        else maxh=*(--ms.end());
        ans+=1LL*dx*maxh;
    }
    cout<<ans<<endl;
}