#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y=-1,p=0;
    cin>>x;
    for(int i=1;i<10000;i++){
        if((x&i)+(x|i)==2025){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}//answer test1 AC,test2 AC test3 AC