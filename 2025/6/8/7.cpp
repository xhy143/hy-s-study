#include<bits/stdc++.h>
using namespace std;
int f(int n,char left,char mid,char right){
    if(n==1){
        cout<<left<<' '<<"To"<<" "<<right<<endl;return 0;
    }
    f(n-1,left,right,mid);
    cout<<left<<" To "<<right<<endl;
    f(n-1,mid,left,right);
}
int main(){
    int n;
    cin>>n;
    f(n,'A','B','C');
}