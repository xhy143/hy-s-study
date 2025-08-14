    #include<bits/stdc++.h>
    using namespace std;
    int cnt=0;
    int n;
    void han(int n,char a,char b,char c){
        if(n==0)return;
        han(n-1,a,c,b);
        cout<<++cnt<<' '<<a<<"->"<<c<<"\n";
        han(n-1,b,a,c);
    }
    int main(){
        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        cin>>n;
        han(n,'A','B','C');
        return 0;
    }