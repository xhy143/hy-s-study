#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,z[10001];
    cin>>n>>x;;
    for(int i=0;i<n;i++){
        cin>>z[i];
    }
    sort(z,z+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(z[i]>x){
            break;
        }
        else{
            ans++;
            x-=z[i];
        }
    }
    cout<<ans;
}