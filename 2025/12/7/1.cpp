#include<bits/stdc++.h>
using namespace std;
struct node{
    string xs;
    int cs=0;
}a[256];

int stt(string a){
    int t=0;
    if(a[1]>='A'){
        t+=a[1]-55;
    }else{
        t+=a[1]-'0';
    }
    if(a[0]>='A'){
        t+=16*(a[0]-55);
    }else{
        t+=16*(a[0]-'0');
    }
    //cout<<t<<endl;
    return t;
}
bool cmp(node a,node b){
    return (a.cs==b.cs?a.xs<b.xs:a.cs>b.cs);
}
string s[100001];
int main(){
    int len=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        string word = "";
        for(int j=0;j<s[i].size();j+=2){
            word += s[i][j];
            word += s[i][j+1];

            a[stt(word)].cs++;
            a[stt(word)].xs=(word);
            word="";
        }
    }
    len=s[0].length();
    sort(a,a+(len*n/2),cmp);

    map<string,int> xq;
    for(int i=0;i<16;i++){
        xq[a[i].xs]=i;
        cout<<a[i].xs;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        string word = "";
        for(int j=0;j<s[i].size();j+=2){
            word += s[i][j];
            word += s[i][j+1];
            int minabs=114514;
            string minxs="";
            for(auto p:xq){
                if(p.first==word){
                    cout<<p.second;
                }
                int nabs=abs(stt(p.first)-stt(word));
                if(nabs<minabs){
                    minabs=nabs;
                    minxs=p.second;
                }
            }
            cout<<minxs;
            word="";
        }
        cout<<endl;
    }
}
