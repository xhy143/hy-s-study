#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string t,p,s;
int fail[maxn],cnt[maxn];
int main(){
    cin>>t>>p;
    s="";
    for(int i=1,j=0;i<p.size();i++){
        while(j&&p[i]!=p[j])j=fail[j-1];
        if(p[i]==p[j])j++;
        fail[i]=j;
    }
    for(int i=0,j=0;i<t.size();i++){
        s+=t[i];
        while(j&&t[i]!=p[j])j=fail[j-1];
        if(t[i]==p[j])j++;
        cnt[s.size()-1]=j;
        if(j==p.size()){
            s.resize(s.size()-p.size());
            if(s.size()==0)j=0;
            j=cnt[s.size()-1];
        }
    }
    cout<<s<<endl;
}