#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
        int k;
        cin>>k;
        string a;
        cin>>a;
        
        reverse(a.begin(),a.end());
        long long ans=0;
        for(int i=0;i<a.length();i++){
            long long dq=0;
            if(a[i]<='9'){
                dq=(a[i]-'0')*pow(k,i);
            }else{
                dq=(a[i]-'A'+10)*pow(k,i);
            }
            ans+=dq;
        }
        cout<<ans<<endl;
    }
}