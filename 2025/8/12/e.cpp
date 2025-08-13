#include<bits/stdc++.h>
using namespace std;
string a[100001];
bool cmp(string c,string b){
    return c.length()>b.length();
}
bool e(string b,string c){
    return b>c;
}
int main(){
    int n;
    cin>>n;
    string b[10001];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n,cmp);
    int maxl=a[0].length(),flag=n;
    for(int i=0;i<n;i++){
        if(a[i].length()<maxl){
            flag=i;
            break;
        }
    }
    sort(a,a+flag,e);
    for(int i=0;i<n;i++){
        if(b[i]==a[0]){
            cout<<i+1<<endl;
        }
    }
    cout<<a[0];
}