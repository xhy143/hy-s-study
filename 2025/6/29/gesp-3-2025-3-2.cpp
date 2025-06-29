#include<bits/stdc++.h>
using namespace std;
int main(){
    string a[100001];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    sort(a,a+n);
    int count=0,maxcount;
    string maxdc="";
    for(int i=0;i<n;i++){
        if(a[i]!=a[i-1]){
            if(maxcount<count){
                maxcount=count;
                maxdc=a[i-1];
                count=0;
            }
        }
        count++;
    }
    cout<<maxdc;
}
