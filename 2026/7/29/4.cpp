#include<bits/stdc++.h>
using namespace std;
int n,h;
vector<int>a;
bool check(int mid){
    int k=mid;
    vector<int>b;
    for(int i=0;i<k;i++){
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end(),greater<int>());
    int ans=0;
    for(int i=0;i<b.size();i+=2){
        ans+=b[i];
        if(ans>h||ans<0)return false;
    }
    return (ans>h?false:true);
}
int main(){
    cin>>n>>h;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        a.push_back(p);
    }
    int l=0,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}