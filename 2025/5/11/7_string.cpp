#include<bits/stdc++.h>
using namespace std;
void fas(string s){
    string ans="";
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='A'&&s[i]<='Z'){
            ans+=s[i];
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            ans+=s[i];
        }
    }
    cout<<ans;
}
int main(){
    string s;
    cin>>s;
    fas(s);
}