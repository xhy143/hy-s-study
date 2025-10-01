    #include<bits/stdc++.h>
    using namespace std;
    int day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int main(){
        int l,r,ans=0;
        cin>>l>>r;
        
        for(int i=1;i<=12;i++){
            for(int j=1;j<=day[i];j++){
                int c=0;
                c=j%10*1000+j/10*100+i%10*10+i/10;
                
                int sum=c*10000+i*100+j;
                if((sum>=l&&sum<=r)) ans++;
            }
        }
        cout<<ans;
    }