#include<bits/stdc++.h>
using namespace std;
struct node{
    int xh;
    string name,xb;
}a[10001];
int to_digit(string b){
    int ans=0;
    for(int i=0;i<b.length();i++){
        int bl=pow(10,b.length()-i-1);
        ans+=(int)(b[i]-'0')*bl;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i].name>>a[i].xh>>a[i].xb;
    }
    int m;
    cin>>m;
    bool f1=0,f2=0;
    while(m--){
        string b,c;
        cin>>b>>c;
        int d,e;
        if(b[0]<'9'){
            d=to_digit(b);
            for(int i=0;i<n;i++){
                if(a[i].xh==d){
                    b=a[i].name;
                    break;
                }
            }
        }
        if(c[0]<'9'){
            e=to_digit(c);
            for(int i=0;i<n;i++){
                if(a[i].xh==e){
                    c=a[i].name;
                    break;
                }
            }
        }
        string xa,xb;
        bool f1=0,f2=0;
        for(int i=0;i<n;i++){
                if(a[i].name==b){
                    xa=a[i].xb;
                    f1=1;
                }
                if(a[i].name==c){
                    xb=a[i].xb;
                    f2=1;
                }
                if(f1&&f2){
                    break;
                }
        }
        if(xa==xb){
            cout<<"N";
        }else{
            cout<<"Y";
        }
        cout<<endl;
    }
}