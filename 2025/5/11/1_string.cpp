#include<bits/stdc++.h>
using namespace std;
void strfine(string s,string sub){
    size_t pos=s.find(sub);
    if(pos==-1){
        cout<<"-1"<<endl;
        return;
    }
    while(pos!=-1){
        cout<<pos+1<<endl;
        pos=s.find(sub,pos+1);
    }
}
int main(){
    string s,sub;
    getline(cin,s);
	getline(cin,sub); 
    strfine(s,sub);
}//tise is in https://zhuoyue.codechild.cn/p/1591
