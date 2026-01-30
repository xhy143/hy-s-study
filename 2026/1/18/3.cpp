#include<bits/stdc++.h>
using namespace std;
int n,T,lead[10001];
bool check(int x,int y){
    int now=y;
    while(now!=-1){
        if(x==now) return true;
        now=lead[now];
    }
    return false;
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>lead[i];
        
    }
    lead[0]=-1;
    cin>>T;
    while(T--){
        int m,cy[10001];
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>cy[i];
        }
        for(int i=n-1;i>=0;i--){
            bool flag=1;
            for(int j=0;j<m;j++){
                if(!check(i,cy[j])){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cout<<i<<endl;
                break;
            }
        }
    }
}