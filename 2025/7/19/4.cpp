#include<bits/stdc++.h>
using namespace std;
int n,s[1001],m,used[10001]={0},zf[10001];
void dfs(int n,int depth){
    if(depth==n){
        for(int i=0;i<n;i++){
            cout<<char(zf[s[i]]);
        }
        cout<<endl;
        return;
    }



    for(int i=0;i<n;i++){
        if(used[i]==0){
            s[depth]=i;
            used[i]=1;
            dfs(n,depth+1);
            used[i]=0;
        }
    }
}
int main(){
    int n;
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        zf[i]=int(a[i]);
    }
    dfs(a.length(),0);

}