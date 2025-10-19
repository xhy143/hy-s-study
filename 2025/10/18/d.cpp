#include<bits/stdc++.h>
using namespace std;
/*
4,小木棍
思路 /7
预估得分 20;
*/
int sz[200]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int main(){
    int T;
    cin>>T;
    while(T>0){
        int n;
        cin>>n;
        if(n<=14){
            cout<<sz[n];
            continue;
        }
            if(n%7==1){ cout<<10; n-=8;} 
            else if(n%7==2){ cout<<sz[n%7]; n-=2;}
            else if(n%7==3){ cout<<200; n-=17;}
            else if(n%7==4){ cout<<20; n-=11;}
            else if(n%7==5){ cout<<sz[n%7]; n-=5;}
            else if(n%7==6){ cout<<sz[n%7]; n-=6;}
        while(n>0){
            cout<<8;
            n-=7;
        }
        cout<<endl;
        T--;
    }
}