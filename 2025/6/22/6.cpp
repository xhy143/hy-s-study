#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>=90){
        cout<<"A"<<endl;
        return 0;
    }
    if(n>=77){
        cout<<"B";
        return 0;
    }
    if(n>=67){
        cout<<"C";
        return 0;
    }
    if(n>=60){
        cout<<"D";
        return 0;
    }
    cout<<"E";
}