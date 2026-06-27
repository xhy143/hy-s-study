#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string str;
int n,l,state[30];
int fp(int a,int b){
    int res=1;
    while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res%mod;
}
int mod_exp(int a,int x){return fp(a,x)%mod;}
signed main(){
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>str;
        state[i]=0;
        for(char c:str){
            int idx=c-'A';
            state[i]|=(1<<idx);
        }
    }
    int ans=0;
    for(int s=1;s<(1<<n);s++){
        int bit=0;
        int intersection=(1<<26)-1;
        for(int i=0;i<n;i++){
            if(s&(1<<i)){
                bit++;
                intersection&=state[i];
            }
        }
        int num=0;
        for(int i=0;i<26;i++){
            if(intersection&(1<<i)){
                num++;
            }
        }
        if(bit%2==1){
            ans=(ans+mod_exp(num,l))%mod;
        }
        else ans=(ans-mod_exp(num,l)+mod)%mod;
    }
    cout<<ans<<endl;
}