#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
queue<int>ds;
int a[maxn];
int main(){
    int n;
    cin>>n;
    int ans=n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int mid=n/2;
    int l=0,r=mid;
    while(l<mid&&r<n){
        if(a[r]>=a[l]*2){
            ans--;
            l++;r++;
        }else{
            r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}