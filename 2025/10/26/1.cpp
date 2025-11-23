#include<bits/stdc++.h>
using namespace std;
int t[100001];
int main(){
    int x;
    cin>>x;
    int y=1;
    while((x&y)+(x|y)!=2025){
        y++;
    }
    cout<<y;
}