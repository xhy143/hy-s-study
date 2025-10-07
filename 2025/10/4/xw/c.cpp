#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("dragon.in", "r", stdin);
    //freopen("dragon.out", "w", stdout);
    int n;
    cin>>n;
    int a[10086],cnt[10086];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cnt[0]=a[0];
    for(int i=1;i<n;i++){
        cnt[i]=cnt[i-1]+a[i];
    }
    int T;
    cin>>T;
    while(T--){
        int f,g;
        cin>>f>>g;
        int zz=0;
        for(int i=0;i<n;i++){
            if(a[i]>f){
                zz=i;
                break;
            }
        }
        if(cnt[n-1]-cnt[zz]>=g){
            cout<<0<<"0hf"<<endl;
            continue;
        }
        else{
            int pay=0,zh=cnt[n-1]-cnt[zz];
            while(zz--){
                if(zh>=g){
                    cout<<pay<<"yhf"<<endl;
                    break;
                }
                pay+=f-a[zz];
                zh+=f-a[zz];
            }
        }
    }
    return 0;
}