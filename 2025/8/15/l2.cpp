#include<bits/stdc++.h>
using namespace std;
int n,m,y,a[10001],ans=0;
bool check(int x){
    int tot=0;
    int i=0;
    int now=0;
    
}
int main(){
    cin>>n>>m>>y;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=l+(r>>1);
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
}