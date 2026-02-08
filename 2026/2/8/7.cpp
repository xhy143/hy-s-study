#include<bits/stdc++.h>
using namespace std;
struct node{
    int z[27];
    int siz=0,jw=0,bh;
}a[1000001];
int tot=0;
void ins(string s){
    int u=0;
    for(int i= s.size()-1;i>=0;i--){
        int p=s[i]-'a';
        if(a[u].z[p]==0){ a[u].z[p]=++tot;a[u].bh=tot;}
        u=a[u].z[p];
        a[u].siz++;
    }
    a[u].jw++;
}
void finder(string s){
    int u=0;
    for(int i= s.size()-1;i>=0;i--){
        int p=s[i]-'a';
        if(a[u].z[p]==0) {cout<<0<<endl;return;}
        u=a[u].z[p];
    }
    cout<<a[u].siz<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int pos;
        cin>>pos;
        string s;
        cin>>s;
        switch(pos){
            case 1:
                ins(s);
                break;
            case 2:
                finder(s);
        }
    }
}