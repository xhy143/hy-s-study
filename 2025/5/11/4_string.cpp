#include<bits/stdc++.h>
using namespace std;
int ap(string s,string c,string o){
    size_t p;
    p=s.find(o);
    if(p==string::npos){
        cout<<s<<endl;
        return 0;
    }
    while(p!=-1){
        s.replace(p,o.size(),c);
        p=s.find(o);
        if(p==string::npos){
            break;
        }
    }
    cout<<s;
}
int main(){
    string s,c,o;
    getline(cin,s);
    getline(cin,o);
    getline(cin,c);
    ap(s,c,o);
}//https://zhuoyue.codechild.cn/p/1570
