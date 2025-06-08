#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int hnt(int x){
    if(x==2){
        return 3;
    }
    return 2*hnt(x-1)+1;
}
int main(){
    cin>>n;
    cout<<hnt(n);
}