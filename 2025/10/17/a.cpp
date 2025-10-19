#include<bits/stdc++.h>
using namespace std;
double k=0,c=0,f=0;
int main(){
    cin>>k;
    c=k-273.15;
    f=c*1.8+32;
    if(f>212){
        cout<<"Temperature is too high!"<<endl;
        return 0;
    }
    cout<<fixed<<setprecision(2)<<c<<"  "<<f<<endl;
}