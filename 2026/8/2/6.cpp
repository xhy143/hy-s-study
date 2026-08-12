#include<bits/stdc++.h>
using namespace std;
int n,m,a[40],ans=0;
vector<int>lefts;
signed main(){
    cin>>n>>m;
    int mid=n/2;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int s=0;s<(1<<mid);s++){
        int sum=0;
        for(int i=0;i<mid;i++){
            if(s&(1<<i))(sum+=a[i])%=m;
        }
        lefts.push_back(sum);
    }
    sort(lefts.begin(),lefts.end());
    lefts.erase(unique(lefts.begin(),lefts.end()),lefts.end());
    for(int s=0;s<(1<<(n-mid));s++){
        int sum=0;
        for(int i=mid;i<n;i++){
            if(s&(1<<n-mid))(sum+=a[i])%=m;
        }
        auto it=upper_bound(lefts.begin(),lefts.end(),m-1-sum);
        if(it!=lefts.begin()){
            --it;
            ans=max(ans,sum+*it);
        }
        ans=max(ans,(sum+lefts.back())%m);
    }
    cout<<ans<<endl;
    return 0;
}