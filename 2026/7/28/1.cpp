#include<bits/stdc++.h>
using namespace std;
const int maxn=3001,maxm=3001;
int main(){
    int n,m;
    cin>>n>>m;
    int minn[maxn],maxx[maxn];
    memset(minn,0x3f,sizeof(minn));
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        for(int j=0;j<m;j++){
            minn[i]=min((int)minn[i],(int)a[j]);
            maxx[i]=max((int)maxx[i],(int)a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=1;j<=n;j++){
            if(i!=j && minn[i]>=maxx[j]){
                flag=1;
                break;
            }
        }
        cout<<(flag?'0':'1');
    }
    return 0;
}