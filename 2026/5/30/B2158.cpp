#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long xh;
    double sc;
    bool operator < (const stu& b) const{
        return sc>b.sc;
    }
};
int main(){
    stu a[100001];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i].xh>>a[i].sc;
    }
    sort(a,a+n);
    printf("%d %g",a[k-1].xh,a[k-1].sc);
}