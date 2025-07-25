#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    int ans=0;
    for(int i=1;i<=a;i++){
        if(i%4==0||i%7==0){
            ans++;
            continue;
        }
        int cnt=0,c4=0;
        int j=i;
        while(j>1){
            int s=j%10;
            if(s==7){
                cnt++;
                c4=0;
            }
            else if(s==4){
                c4++,cnt=0;
            }
            else{
                cnt=c4=0;
            }
            if(cnt==2||c4==2){
                ans++;
            }
            j/=10;
        }
    }
    cout<<ans;
}