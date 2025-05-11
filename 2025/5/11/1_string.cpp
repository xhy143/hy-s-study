#include<bits/stdc++.h>
using namespace std;
void strfine(string a,string b,int c){
    int i=0;
    bool flag=0;
    while(i<=a.size()){
        size_t a1=a.find(b,i);
        if(a1==string::npos){
            if(!flag){
                cout<<-1;
                return;
            }else{
                return;
            }
        }
        flag=1;
        cout<<a1<<' ';
        i=a1+1;
    }
}
int main(){
    string s,sub;
    cin >> s >> sub;
    strfine(s,sub,0);
}//tese is in https://zhuoyue.codechild.cn/p/1591