#include<bits/stdc++.h>
using namespace std;
bool tmp(char a,char b){
    if(a>b){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s[100001];
    int n;
    cin>>n;
    string t="";
    for(int i=0;i<n;i++){
        cin>>s[i];
        t+=s[i];
    }
    sort(t.begin(),t.end(),tmp);
    cout<<t;
}
