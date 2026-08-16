#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,fail[maxn],minlen[maxn];
char s[maxn];
int main(){
    cin>>n;
    cin>>s+1;
    fail[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j&&s[i]!=s[j+1])j=fail[j];
        if(s[i]==s[j+1])j++;
        fail[i]=j;
        if(minlen[j]>0)minlen[i]=minlen[j];
        else minlen[i]=j;
    }
    long long ans=0;/*163mc.cn:25564*/
    for(int i=1;i<=n;i++){
        if(minlen[i]<=i/2&&minlen[i]>0){
            ans+=i-minlen[i];
        }
    }
    cout<<ans<<endl;
}