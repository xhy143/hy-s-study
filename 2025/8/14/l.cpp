#include<bits/stdc++.h>
using namespace std;
int sd[10][10];
void dfs(int n){
    
}
int main(){
    for(int i=0;i<9;i++){
        string a;
        cin>>a;
        for(int j=0;j<9;j++){
            if(a[j]=='.'){
                a[j]='0';
            }
            sd[i][j]=a[j]-'0';
        }
    }
}