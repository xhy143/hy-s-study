#include<bits/stdc++.h>
using namespace std;
void o(int* a,int n,int el){
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    if(el) cout<<endl;
}
int add(int a,int b=0);
int main(){
    int n,a[10001];
    cin>>n;
    cout<<add(2)<<add(2,3);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        sort(a+x-1,a+y);
        //o(a,n,1);
    }
    o(a,n,0);
}
int add(int a,int b){
    return a+b;
}