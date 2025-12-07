#include<bits/stdc++.h>
using namespace std;
map<string,string> a;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string c,b;
        cin>>c>>b;
        a[c]=b;
    }
    string art;
    cin>>art;
    int str=0,len=0;
    for(int i=0;i<art.length();i++){
        char ch = art[i];
        if(ch>='a' && ch<='z'){
            if(len==0){
                str = i;
                len = 1;
            }
        } else {
            if(len==1){
                string y = art.substr(str, i - str);
                auto it = a.find(y);
                if(it != a.end()) cout << it->second;
                else cout << "UNK";
                len = 0;
            }
            cout << ch;
        }
    }
    if(len==1){
        string y = art.substr(str);
        auto it = a.find(y);
        if(it != a.end()) cout << it->second;
        else cout << "UNK";
    }
    return 0;
}