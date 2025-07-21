#include<bits/stdc++.h>
using namespace std;
int n,s[1001],m,used[10001]={0},ans=0;
bool isprime(int a){
    if(a==1){
        return 0;
    }
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return 0;
    }
    return 1;
}
void dfs(int n,int depth){
    if(depth==n){
        ans++;
            cout<<ans<<":";
        for(int i=0;i<n;i++){
            
            cout<<s[i]+1<<' ';
        }
        cout<<endl;
        return;
    }



    for(int i=0;i<n;i++){
        if(used[i]==0&&isprime(s[depth-1]+i)){
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
    cout<<"total:"<<ans;
}