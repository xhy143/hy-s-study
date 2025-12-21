#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        string l;
        if(a[i]!='/'){
            l+=a[i];
        }
        else{
            if(l=="-----"){
                cout<<0;
            }
            else if(l[0]=='.'){
                int d=0;
                for(int j=0;j<l.length();j++){
                    if(l[i]=='.'){
                        d++;
                    }else{
                        break;
                    }
                }
                cout<<d;
            }
            else{
                int d=5;
                for(int j=0;j<l.length();j++){
                    if(l[i]=='-'){
                        d++;
                    }else{
                        break;
                    }
                }
                cout<<d;
            }
            cout<<' ';
        }
    }
}