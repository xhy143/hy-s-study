#include<bits/stdc++.h>
using namespace std;
int main(){
    int j=0,o=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k%2){
            j++;
            continue;
        }
        o++;
    }
    cout<<j<<' '<<o;
}