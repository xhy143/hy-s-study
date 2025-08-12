#include<bits/stdc++.h>
using namespace std;
string s;
string a[100001];
int g=0;
bool is_mail(string mail){
    bool at=0,dou=0;
    if(mail[0]=='.'||mail[mail.length()-1]=='.'){
        return 0;
    }
    size_t p=mail.find("@");
    if(p==string::npos){
        return 0;
    }
    if(p==0||p==mail.length()-1||mail[p-1]=='.'||mail[p+1]=='.'){
        return 0;
    }
    return 1;
}
void check(string s){
    string t=s;
    size_t pos=s.find("at",0);
    while(pos!=string::npos){
        a[++g]=t.replace(pos,2,"@");
        t=s;
        pos=s.find("at",pos+2);
    }
}
int main(){
    cin>>s;
    check(s);
    size_t pos=s.find("nospam",0);
    while(pos!=string::npos){
        string t=s;
        t.replace(pos , 6 , "");
        check(t);
        pos=s.find("nospam",pos+6);
    }
    sort(a+1,a+g+1);
    for(int i=1;i<=g;i++){
        if(is_mail(a[i])&&a[i]!=a[i+1]){
            cout<<a[i]<<endl;
        }
    }
}