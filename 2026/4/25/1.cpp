#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<vector<int> > mat;
const int mod = 1e9+7;
mat operator * (mat a,mat b){
    int m=a.size(),n=b[0].size(),k=a[0].size();
    mat c(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ll sum=0;
            for(int p=0;p<k;p++) sum=(sum+1ll*a[i][p]*b[p][j]);
            c[i][j]=sum;
        }
    }
    return c;
}
int main(){
    int n1,m1,n2,m2;
    cin>>n1>>m1;
    mat a(n1,vector<int>(m1,0));
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cin>>a[i][j];
        }
    }
    cin>>n2>>m2;
    mat b(n2,vector<int>(m2,0));
    for(int i=0;i<n2;i++){
        for(int j=0;j<m2;j++){
            cin>>b[i][j];
        }
    }
    mat c=a*b;
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            cout<<c[i][j]<<"\n "[(j==m2-1?0:1)];
        }
    }
}