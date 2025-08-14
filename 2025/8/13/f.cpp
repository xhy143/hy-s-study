#include<iostream>
using namespace std;
long long  ys;
long long pos(long long d,long long z){
    if(z==1){
        return d;
    }
    return pos(d*ys,--z);
}
int main(){
    long long  z,d;
    cin>>d>>z;
    ys=d;
    cout<<pos(d,z);
    return 0;
}