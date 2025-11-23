#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a<b) swap(a,b);
    if(a%b==0){
        return a;
    }
    return gcd(a%b,a);
}
int main(){
    int T;
    int n;
    vector<int> a;
    cin>>n;
    cin>>T;
    int b[100001];
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        if(b[p]==0){
            a.push_back(p);
        }
        b[p]++;
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=T;i++){
        int gys=a[0]+i;
        for(int j=1;j<a.size();j++){
            gys=gcd(gys,a[j]+i);
            if(gys==1){
                break;
            }
        }
        cout<<gys<<endl;
    }
}