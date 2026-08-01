#include<bits/stdc++.h>
using namespace std;
struct toy{
    int dir;
    string zy;
};
vector<toy>a;//0r+
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int dirr;
        string zy;
        cin>>dirr>>zy;
        a.push_back({dirr,zy});
    }
    int pos=0;
    while(m--){
        int dir,num;
        cin>>dir>>num;
        int dirr=a[pos].dir;
        (pos+=((dirr?1:-1)*(dir?-1:1)*num+n))%=n;
    }
    cout<<a[pos].zy;
}