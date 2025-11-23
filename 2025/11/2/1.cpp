#include<bits/stdc++.h>
using namespace std;
int main(){
    int yh[12]={3,6,6,2,4,7,2,5,1,3,6,1},ds[12]={31,28,31,30,31,30,31,31,30,31,30,30},yf;
    cin>>yf;
    string yff="MON TUE WED THU FRI SAT SUN";
    cout<<yff<<endl;
    yf--;
    for(int i=1;i<yh[yf];i++){
        cout<<"    ";
    }
    int d=yh[yf];
    for(int i=1;i<=ds[yf];i++){
        if(d==8){
            cout<<endl;
            d=0;
        }
        int j=4;
        if(d==0||(i==1&&yf==9)){
            j=3;
        }
        cout<<setw(j)<<i;
        d++;
    }
}