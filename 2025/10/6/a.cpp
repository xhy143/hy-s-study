#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    int q=0,h=a.length()-1;
    for(int i=0;i<a.length()-1;i++){
        if(a[i]!='*'){
            q=i;
            break;
        }
    }
    for(int i=a.length()-1;i>=0;i--){
        if(a[i]!='*'){
            h=i;
            break;
        }
    }
    queue<int>jl;
    for(int i=q;i<h;i++){
        if(a[i]=='*'){
            jl.push(i);
        }
    }
    int cw=0;
    while(!jl.empty()){
        a.erase(jl.front()-cw,1);
        cw++;
        jl.pop();
    }
    cout<<a;
    return 0;
}