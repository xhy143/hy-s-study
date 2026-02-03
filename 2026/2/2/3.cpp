#include<bits/stdc++.h>
using namespace std;
map<int,int>p;
void p1(){
    int l,r;
    cin>>l>>r;
    p[l]=r;
}
void p2(){
    int n;
    cin>>n;
    map<int,int>::iterator it=p.upper_bound(n);
    if(it==p.begin()){
        cout<<"No"<<endl;
        return ;
    }
    it--;
    if(it->second>=n){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int pos;
        cin>>pos;
        pos==1?p1():p2();
    }
}