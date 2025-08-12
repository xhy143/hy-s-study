#include<bits/stdc++.h>
using namespace std;
int hc[10]={6,2,5,5,4,5,6,3,7,6};
void f(int mg){
    for(long long i=0;i<=1145141919810;i++){
        if(i*7==mg){
            for(int j=0;j<i;j++){
                cout<<8;
            }
            return;
        }
    }
    cout<<-1;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int mg;
        cin>>mg;
        f(mg);
    }
}