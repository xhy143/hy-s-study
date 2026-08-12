#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
struct bm{
    int a,b,c;
};
void solve(){
    int n;
    cin>>n;
    vector<bm>a(n+5);
    vector<int>b(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
    }
    int res=0;
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++){
        if(a[i].a>=max(a[i].b,a[i].c)){
            b[i]=1;
            cnt1++;
            res+=a[i].a;
        }
        else if(a[i].b>=max(a[i].a,a[i].c)){
            b[i]=2;
            cnt2++;
            res+=a[i].b;
        }
        else if(a[i].c>=max(a[i].a,a[i].b)){
            b[i]=3;
            res+=a[i].c;
            cnt3++;
        }
    }
    vector<int>cj;
    for(int i=1;i<=n;i++){
        if(cnt1>n/2&&b[i]==1){
            cj.push_back(a[i].a-max(a[i].b,a[i].c));
        }
        if(cnt2>n/2&&b[i]==2){
            cj.push_back(a[i].b-max(a[i].a,a[i].c));
        }
        if(cnt3>n/2&&b[i]==3){
            cj.push_back(a[i].c-max(a[i].b,a[i].a));
        }
    }
    sort(cj.begin(),cj.end());
    int i=0;
    while(cnt1>n/2){
        res-=cj[i];
        cnt1--;
        i++;
    }
    while(cnt2>n/2){
        res-=cj[i];
        cnt2--;
        i++;
    }
    while(cnt3>n/2){
        res-=cj[i];
        cnt3--;
        i++;
    }
    cout<<res<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}