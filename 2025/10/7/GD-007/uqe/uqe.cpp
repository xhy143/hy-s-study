#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0<<endl;
            continue;
        }
        else if(b==0){
            if(a<0){
                double p=sqrt(abs(a)*abs(c));
                if((int)p==p){
                    cout<<p<<endl;
                }else{
                    printf("sqrt(%d)\n",abs(a)*abs(c));
                }
            }else{
                cout<<"NO"<<endl;
            }
            continue;
        }else if(c==0){
            cout<<0<<endl;
            continue;
        }else{
            cout<<"NO"<<endl;
        }
    }
}