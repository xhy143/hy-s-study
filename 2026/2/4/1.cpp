#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int z[2];
    int siz=0,jw=0;
}a[6000001];
int tot=0;

void ins(int s){
    int u=0;
    for(int i=59;i>=0;i--){
        int p=(s>>i)&1;
        if(a[u].z[p]==0) a[u].z[p]=++tot;
        u=a[u].z[p];
        a[u].siz++;
    }
    a[u].jw++;
}
string zh(int x) {
    string s;
    do{
        s += x % 2 + '0';
        x /= 2;
    } while (x);
    reverse(s.begin(),s.end());
    return s;
}
int xors(int s){
    int u=0;
    int res=0;
    for(int i=59;i>=0;i--){
        int p=(s>>i)&1;
        int w=p^1;
        if(a[u].z[w]!=0 && a[a[u].z[w]].siz>0){
            res=(res<<1)|1; 
            u=a[u].z[w];
        }else{
            res=(res<<1);    
            u=a[u].z[p];
        }
    }
    return res;
}

signed main(){
    //freopen("114.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int pos;
        cin>>pos;
        int s;
        cin>>s;
        switch(pos){
            case 1:
                ins(s);
                break;
            case 2:
                string x=zh(s);
        }
    }
    return 0;
}