#include<bits/stdc++.h>
using namespace std;
int G[10][10],k=0;
void dfs(int i,int j){
    int ky[10];
            if(G[i][j]==0){
                for(int k=1;k<=9;k++){
                     G[i][j]=k;
                     bool flag=false;
                     for(int h=0;h<9;h++){
                        if(G[i][h]==k&&h!=j){
                            flag=1;
                        }
                     }
                     if(flag){
                        continue;
                     }
                     for(int l=0;l<9;l++){
                        if(G[l][j]==k&&l!=i){
                            flag=1;
                        }
                     }
                     if(flag){
                        continue;
                     }
                     int ix=i-i%3;
                     int iy=j-j%3;
                     for(int gx=0;gx<3;gx++){
                        for(int gy=0;gy<3;gy++){
                            if(G[ix+gx][iy+gy]==k&&ix+gx!=i&&iy+gy!=j){
                                flag=1;
                            }
                        }
                     }
                     if(flag){
                        continue;
                     }

                }
            }
        }
int main(){
    for(int i=0;i<9;i++){
        string a;
        cin>>a;
        for(int j=0;j<9;j++){
            if(a[j]=='.'){
                a[j]='0';
                k++;
            }
            G[i][j]=a[j]-'0';
        }
    }
}