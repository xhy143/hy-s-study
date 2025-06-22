#include<bits/stdc++.h>
using namespace std;
void find(int f,int* a,int j){
    for(int i=0;i<j;i++){
        if(a[i]<f){
            cout<<"Y"<<endl;
            return;
        }
    }
    cout<<"N"<<endl;
}
int main(){
    int n;
    int a[1001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            cout<<"N"<<endl;
            continue;
        }
        find(a[i],a,i);
    }
}