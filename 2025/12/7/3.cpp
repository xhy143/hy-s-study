#include<bits/stdc++.h>
using namespace std;
char w[11][11];int qzh[11][11];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>w[i][j];
            qzh[i][j]=qzh[i-1][j]+qzh[i][j-1]-qzh[i-1][j-1]+w[i][j]-'0';
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<qzh[i][j];
        }
        cout<<endl;
    }
    int maxx=-114514;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            for(int x2=1;x2<=n;x2++){
                for(int y2=1;y2<=m;y2++){
                    int h=qzh[x2][y2]-qzh[x][y2]-qzh[x2][y]+qzh[x][y];
                    cout<<x2<<' '<<y2<<' '<<x<<' '<<y<<' '<<h*2<<endl;
                    if(h*2==(x2-x+1)*(y2-y+1)){
                        maxx=max(maxx,h*2);
                    }
                }
            }
        }
    }
    cout<<maxx;
}