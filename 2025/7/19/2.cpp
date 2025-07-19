#include<bits/stdc++.h>
using namespace std;
int n,s[1001],m,used[10001]={0};
void dfs(int n,int depth){
    if(depth==n){
        for(int i=0;i<n;i++){
            cout<<s[i]+1<<' ';
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
    cin>>n;
    dfs(n,0);

}