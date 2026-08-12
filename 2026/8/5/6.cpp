#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int t;
int p[maxn],a[maxn];
bool check(int x){
    while(x>1){
        if(x%10==7){
            return 1;
        }
        x/=10;
    }
    return 0;
}
void init(){
    for(int i=6;i<=maxn;i++){
        if(check(i)&&p[i]==0){
            for(int j=i;j<=maxn;j+=i){
                p[j]=1;
            }
        }
    }
    for(int i=maxn-1;i>0;i--){
        if(p[i+1]==0)a[i]=i+1;
        else a[i]=a[i+1];
    }
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>t;
    init();
    while(t--){
        int n;
        cin>>n;
        if(p[n]){
            cout<<-1<<endl;
            continue;
        }
        cout<<a[n]<<endl;
    }
}