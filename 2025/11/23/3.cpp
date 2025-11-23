#include<bits/stdc++.h>
using namespace std;
int qzh[101][101][3];//dang  b  w
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char p;
            cin>>p;
            qzh[i][j][0]=p-'0';
            qzh[i][j][(qzh[i][j][0]==0?1:2)]+1;
        }
    }
    int maxw=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                for(int z=0;z<m;z++){
                    int b=qzh[k][z][1]-qzh[i][z][1]-qzh[j][k][1];+qzh[i][j][1];
                    int w=qzh[k][z][2]-qzh[i][z][2]-qzh[j][k][2];+qzh[i][j][2];
                    if(b==w){
                        maxw=max(maxw,(k-i)*(z-j));
                        printf("%d %d %d %d\n",i,j,k,z);
                    }
                }
            }
        }
    }
    cout<<maxw;
}