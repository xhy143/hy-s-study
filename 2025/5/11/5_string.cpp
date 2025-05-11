#include<bits/stdc++.h>
using namespace std;
int bigalpha=0,smallalpha=0,num=0;
void fi(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            bigalpha++;
        }
        else if(s[i]>='a'&&s[i]<='z'){
            smallalpha++;
        }
        else if(s[i]>='0'&&s[i]<='9'){
            num++;
        }
    }
    cout<<bigalpha<<endl;
    cout<<smallalpha<<endl;
    cout<<num<<endl;
}
int main(){
    string s;
    getline(cin,s);
    fi(s);
}