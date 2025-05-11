#include<bits/stdc++.h>
using namespace std;
void re(string s){
    string jq;
    for(int i=0;i<s.size();i++){
        if(s[i]==','){
            jq=s.substr(i+1);
            cout<<jq+","+s.substr(0,i)<<endl;
            break;
        }
    }
}
int main(){
    string s;
    cin>>s;
    re(s);
}