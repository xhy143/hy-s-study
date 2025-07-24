#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maxn=0,maxi[1001]={-1},maxs=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>maxn){
            maxn=a;
            maxs=0;
            maxi[maxs]=i+1;
            continue;
        }
        else if(a==maxn){
            maxs++;
            maxi[maxs]=i+1;
        }
    }
    for(int i=0;i<=maxs;i++){
        cout<<maxi[i]<<endl;
    }
}