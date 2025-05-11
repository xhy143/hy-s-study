#include<bits/stdc++.h>
using namespace std;
int ap(string s){
    char o;
    cin>>o;
    size_t p;
    p=s.find(o);
    if(p==string::npos){
        cout<<s<<endl;
        return 0;
    }
    while(p!=-1){
        s.erase(p,1);
        p=s.find(o);
        if(p==string::npos){
            break;
        }
    }
    cout<<s;
}
int main(){
    string s;
    getline(cin,s);
    ap(s);
}//https://zhuoyue.codechild.cn/p/1131
