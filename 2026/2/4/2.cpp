#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int z[27];
    int siz=0,jw=0;
}a[1000001];
int k;
int tot=1;
void ins(int s){
    int u=1;
    for(int i=61;i>=0;i--){
        int p=s>>1&1;
        if(a[u].z[p]==0) a[u].z[p]=++tot;
        u=a[u].z[p];
        a[u].siz++;
    }
    a[u].jw++;
}
int ans=0;
void xors(int s){
    
}
signed main(){
    int T;
    while(T--){
        int pos,u;
        cin>>pos>>u;
        switch(pos){
            case 1:
                ins(u);
                break;
            case 2:

        }
    }
}