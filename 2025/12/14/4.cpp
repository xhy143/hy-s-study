#include<bits/stdc++.h>
using namespace std;
int qz[100001];
int main(){
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        int p;  
        scanf("%d",&p);
        if(i==0){
            qz[0]=p;
            continue;
        }
        qz[i]=qz[i-1]+p;
    }
    
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",qz[y-1]-qz[x-2]);
    }
}