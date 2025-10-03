#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans1=0,ans2=0;
    cin>>n;
    while(n){
        ans1++;
        if(n%3==1&&!ans2) ans2=ans1;
        n=n-ceil(n/3.0);
    }
    printf("%d %d",ans1,ans2);
}