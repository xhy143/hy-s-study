#include<bits/stdc++.h>
using namespace std;
vector<int> G;
vector<int>vis(15,0);
int n;
void dfs(){
    if(G.size()==n){
        for(int i=0;i<G.size();i++){
            cout<<G[i];
            
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        G.push_back(i);
        dfs();
        G.pop_back();
    }
}
int main(){
    cin>>n;
    dfs();
}