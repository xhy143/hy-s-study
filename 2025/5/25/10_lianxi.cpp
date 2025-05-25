#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double prise[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>prise[i];
    }
    sort(prise,prise+n);
    prise[n-1]*=0.9;
    double ans=0;
    for(int i=0;i<n;i++){
        ans+=prise[i];
    }
    ans*=0.9;
    cout<<fixed<<setprecision(1)<<ans;
}//有趣の折扣