#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int a[maxn],b[maxn];
vector<int>line;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    line.push_back(0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        line.push_back(a[i]);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[i];
        line.push_back(b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    sort(line.begin(),line.end());
    line.erase(unique(line.begin(),line.end()),line.end());
    int ans=-INT_MAX,ansa=0,ansb=0;
    int i=0,j=0;
    for(auto lin:line){
        while(i<n&&a[i]<=lin)i++;
        while(j<m&&b[j]<=lin)j++;
        int A=2*i+(n-i)*3,B=2*j+(m-j)*3;
        int pans=A-B;
        if(pans>ans){
            ans=pans;ansa=A;ansb=B;
        }else if(pans==ans&&A>ansa){
            ans=pans;ansa=A;ansb=B;
        }
    }
    cout<<ansa<<':'<<ansb<<endl;
}