#include<bits/stdc++.h>
using namespace std;
long long  n,a[10000001],m;
bool check(int h){
        long long sum=0;
        for(int j=1;j<=n;j++){
            sum+=(a[j]>h)?(a[j]-h):0;
        }
        return sum>=m;
    
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+1+n);
    
    int l=0,r=a[n];
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<r;
}