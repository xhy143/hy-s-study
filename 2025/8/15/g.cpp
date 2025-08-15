#include <bits/stdc++.h>
using namespace std;
int a[1000001],k,flag=0;
void ef(int l,int r){
    int mid=l+(r-1)/2;
    if(a[mid]==k){
        cout<<mid+1;
        flag=1;
        return ;
    }
    if(l>r){
        return ;
    }
    a[mid]<k?ef(mid+1,r):ef(l,mid-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string p="";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        p+=(a[i]+'0');
    }
    cin>>k;
    string e="";
    e+=(k+'0');
    size_t i=p.find(e)+1;
    if(i==0){
        cout<<-1;
        return 0;
    }
    cout<<i;
    return 0;
}
