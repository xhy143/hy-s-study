#include<bits/stdc++.h>
using namespace std;
long long task[100001],qzh[100001];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>task[i];
        qzh[0]=task[0];
        qzh[i]=qzh[i-1]+task[i];
    }

}