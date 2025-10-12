#include<bits/stdc++.h>
using namespace std;
struct zb{
    int x,y;
};
bool cnp(zb a,zb b){
    return (a.x==b.x)?(a.y<b.y):(a.x<b.x);
}
int main(){
    zb a[100001];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n,cnp);
    for(int i=0;i<n;i++){
        cout<<a[i].x<<' '<<a[i].y<<endl;
    }
}