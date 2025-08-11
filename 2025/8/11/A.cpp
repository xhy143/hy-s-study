#include<bits/stdc++.h>
using namespace std;
int gb;
string kw;
int main(){
    cin>>kw;
    gb=kw.length();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        if(a=='L'&&gb!=0){
            gb--;
        }
        else if(a=='D'&&gb!=kw.length()){
            gb++;
        }else if(a=='B'&&gb!=0){
            kw.erase(gb-1,1);
        }else if(a=='P'){
            string c;
            cin>>c;
            kw.insert(gb,c);
        }
    }
    cout<<kw;
}