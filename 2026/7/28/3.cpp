#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int last=0,ans=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a>=last){
            ans+=a-last;
        }
        last=a;
    }
    cout<<ans<<endl;
    return 0;
}