#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,c5,c10,c50,c100,c500,a;
    cin>>c1>>c5>>c10>>c50>>c100>>c500>>a;
    int b=a;
    int yb=0;
    while(c500&&a>=500){
        c500--;
        a-=500;
        yb++;
    }
    while(c100&&a>=100){
        c100--;
        a-=100;
        yb++;
    }
    while(c50&&a>=50){
        c50--;
        a-=50;
        yb++;
    }
    while(c10&&a>=10){
        c10--;
        a-=10;
        yb++;
    }
    while(c5&&a>=5){
        c5--;
        a-=5;
        yb++;
    }
    while(c1&&a>=1){
        c1--;
        a-=1;yb++;
    }
    cout<<yb;
}