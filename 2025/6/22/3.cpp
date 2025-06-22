#include<iostream>
using namespace std;
int main(){
    int n;
    int a=0,b;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k%9==0&&k%8!=0){
            a++;
        }
    }
    cout<<a;
}