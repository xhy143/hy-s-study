#include<bits/stdc++.h>
using namespace std;
int cnt(int a){
    int ans=0;
    while(a>=1){
        a/=10;
        ans++;
    }
    return ans;
}
bool check(int a,int b){
    int sw=cnt(a);
    int ls=0;
    for(int i=0;i<sw/2;i++){
        ls*=10;
        ls+=a%10;
        a/=10;
    }
    if(sw%2){
        a/=10;
    }
    if(a==ls){
        return 1;

    }else{
        return 0;
    }
}
int main(){
    freopen("pal.in","r",stdin);
    freopen("pal.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b=1;
        cin>>a;
        if(a%10==0){
            cout<<-1;
            continue;
        }
        while(1){
            int p=a*b;
            if(check(p,p)){
                cout<<b<<endl;
                break;
            }
            if(a*b<0){
                cout<<-1;
                break;
            }
            b++;
        }
    }
}