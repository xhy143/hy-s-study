#include<bits/stdc++.h>
using namespace std;
int n;
int num[100001];
bool find(int j,int n){
    for(int i=j;i<n;i++){
        if(num[i]==n) return 1;
        
    }
    return 0;
}
int main(){
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        num[i]=p;
    }
    sort(num,num+n);
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(num[i]+num[j]>num[n-1]){
                break;
            }
            if(num[i]!=num[j]&&find(j,num[i]+num[j])) {
                printf("%d %d %d\n",num[i],num[j],num[i]+num[j]);
                ans++;
            }
        }
    }
    cout<<ans;
}