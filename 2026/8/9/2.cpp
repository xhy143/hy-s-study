#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int fail[maxn],n,m;
string str,s;
int main(){
    int t;
    cin>>t;
    t--;
    cin>>str;
    while(t--){
        int i,j;
        cin>>s;
        m=s.size();
        n=str.size();
        fail[0]=0;
        for(i=1,j=0;i<m;i++){
            while(j&&s[i]!=s[j]){
                j=fail[j-1];
            }
            if(s[i]==s[j])j++;
            fail[i]=j;
        }
        int st=max(0,n-m);
        for(i=st,j=0;i<n;i++){
            while(j&&str[i]!=s[j])j=fail[j-1];
            if(str[i]==s[j])j++;
        }
        str+=s.substr(j);
    }
    cout<<str<<endl;
}