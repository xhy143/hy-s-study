#include<bits/stdc++.h>
using namespace std;
int f[100001],v[100001],ans;
int find(int x){ 
    if(f[x]==x){
        return x;
    }else{
        return f[x]=find(f[x]);
    }
}
void hb(int x,int y){ 
    int findx=find(x);
    int findy=find(y);
    if(findx==findy) return;
    f[findy]=findx;
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        f[i]=i; 
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        hb(x,y);
    }
    for(int i=1;i<=n;i++){
        int x=find(i);
        if(!v[x]) ans++,v[x]=1; 
    }
    cout<<ans-1; 
    return 0;  
}
