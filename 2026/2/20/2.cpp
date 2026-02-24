#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<(n%2==0&&n>4&&n<=12)<<' '<<(n%2==0||(n>4&&n<=12))<<' '<<((n%2==0&&(n<=4||n>12))||(n>4&&n<=12&&(n%2)))<<' '<<(n%2&&(n<=4||n>12));
    return 0;

}