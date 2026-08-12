#include<bits/stdc++.h>
#define in freopen("xcpc.in","r",stdin);
#define out freopen("xcpc.out","w",stdout);
#define int long long
using namespace std;
struct node{
    int l,p1,p2,p3,p4,pos;
};
int n,ans=0,used[1001],t=0;
vector<node> q;
signed main(){
    string str;
    cin>>str;
    string str2=str;
    reverse(str.begin(),str.end());
    cout<<str2;
    int j=1;
    int l=str.size();
    while(l-j>=0){
        for(int i=0;i<str.size()-j;i++){
            cout<<str[i];
        }
        j++;
        for(int i=0;i<str.size()-j;i++){
            cout<<str2[i];
        }
        j++;
        if(j==l)break;
    }
}