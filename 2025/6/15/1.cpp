#include<bits/stdc++.h>
using namespace std;
int fun(int e){
    if(e<0){
        return 0;
    }
    if(e==0){
        return 1;
    }
    return fun(e-1)+fun(e-2);
}
int main(){
    int a;
    while(cin>>a&&a>0){
        cout<<fun(a)<<endl;
    }
}//