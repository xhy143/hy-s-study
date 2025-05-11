#include<bits/stdc++.h>
using namespace std;
int ap(string s){
    char o;
    cin>>o;
    for(int i=0;i<s.size();i++){
        if(s[i]==o){
            s.erase(i,1);
        }
    }
    cout<<s;
}
int main(){
    string s;
    getline(cin,s);
    ap(s);
}//https://zhuoyue.codechild.cn/p/1131