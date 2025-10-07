#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;map<string,int>a;
    cin>>n;
    for(int i=0;i<n;i++){
        string w;
        cin>>w;
        a[w]++;
    }
    cout<<52-a.size();
}