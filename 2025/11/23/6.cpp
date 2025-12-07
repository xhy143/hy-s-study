#include<bits/stdc++.h>
using namespace std;
bool c1(string a,string b){
    int err=0;
    for(int i=0;i<b.length();i++){
        if(a[i]!=b[i]) err++;
        if(err>=2){
            return 0;
        }
    }
    return 1;
}
bool c2(string a,string b){
    int l1=a.length();
    int l2=b.length();
    if(abs(l1-l2)!=1) return 0;
    if(l2>l1){
        swap(a,b);
        swap(l1,l2);
    }
    bool f=0;
    int i=0,j=0;
    for(i;i<l1;i++){
        if(a[i]!=b[j]){
            if(f){
                return 0;
            }
            else{
                f=1;
                continue;
            }
        }
        j++;
    }
    return 1;
}
int main(){
    string a,b;
    int T;
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a==b||(a.length()==b.length()&&c1(a,b))||c2(a,b)){
            cout<<"similar"<<endl;
        }else{
            cout<<"not similar"<<endl;
        }
    }
}