#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    
    string a[10001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<4||m<4){
        cout<<"No"<<endl;
        return ;
    }
    for(int i=0;i<=n-4;i++){
        for(int j=0;j<=m-4;j++){
            string p1=a[i].substr(j,4);
            string p4=a[i+3].substr(j,4);
            string p2=a[i+1].substr(j,4);
            string p3=a[i+2].substr(j,4);
            if(p1==p4&&p2==p3&&p1=="0000"&&p2=="0110"){
                cout<<"Yes"<<endl;
                return ;
            }
        }
    }
    cout<<"No"<<endl;
}
int main(){
    int K;
    cin>>K;
    while(K--){
        solve();
    }
}