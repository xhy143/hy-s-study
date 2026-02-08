#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int z[2];
    int siz=0, jw=0; 
}a[6000001];
int tot=0;
void ins(int s){
    int u=0;
    int start = -1;
    for(int i=59;i>=0;i--){
        if((s>>i)&1){
            start = i;
            break;
        }
    }
    if(start == -1){ 
        start = 0;
    }
    for(int i=start;i>=0;i--){
        int p=(s>>i)&1;
        if(a[u].z[p]==0) a[u].z[p]=++tot;
        u=a[u].z[p];
        a[u].siz++;
    }
    a[u].jw++;
}
int ask(int s){
    int u=0;
    int res=0;
    int start = -1;
    for(int i=59;i>=0;i--){
        if((s>>i)&1){
            start = i;
            break;
        }
    }
    if(start == -1){ 
        start = 0;
    }
    for(int i=start;i>=0;i--){
        int p=(s>>i)&1;
        if(p == 1){
            if(a[u].z[0] != 0){
                res += a[a[u].z[0]].siz;
            }
        }
        if(a[u].jw > 0 && i > 0){
            res += a[u].jw;
        }
        if(a[u].z[p] == 0) break;
        u = a[u].z[p];
    }
    return res;
}

signed main(){
    int q;
    cin>>q;
    while(q--){
        int op, x;
        cin>>op>>x;
        if(op == 1){
            ins(x);
        } else {
            cout << ask(x) << endl;
        }
    }
    return 0;
}