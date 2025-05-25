#include<bits/stdc++.h>
using namespace std;
void zhaoyingshu(int n){
    int i=1;
    cout<<n<<":";
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    cout<<n;
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        zhaoyingshu(i);
    }
}