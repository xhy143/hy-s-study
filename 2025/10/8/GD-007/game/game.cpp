#include<bits/stdc++.h>
using namespace std;
struct node{
    int sm;
    int dl;
};
int main(){
    int s,T,ds;
    cin.tie(0);
    cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    node enermy[100001];
    cin>>s>>ds>>T;
    for(int i=1;i<=ds;i++){
        cin>>enermy[i].sm>>enermy[i].dl;
    }
    while(T--){
        int k;
        cin>>k;
        int dl=0,sm=s;
        if(k==ds){
            if(s>enermy[ds].sm){
                cout<<0;
                continue;
            }else{
                cout<<ds;
            }
        }
            for(int i=k;i<=ds;i++){
                
                if(dl>enermy[i].dl){
                    continue;
                }
                else{
                    if(sm>enermy[i].sm){
                        dl+=enermy[i].dl;
                        sm-=enermy[i].sm;
                    }else{
                        cout<<i;
                        break;
                    }
                }
                if(i==ds-1){
                    cout<<0;
                    break;
                }
            }
            
    }
}