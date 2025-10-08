#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    string a;
    cin>>a;
    int ans=0;
    stack<char> s;
    for(int i=0;i<n;i++){
        if(!s.empty()&&s.top()==a[i]){
            ans++;
            s.pop();
        }else{
            s.push(a[i]);
        }
    }
    cout<<ans;
    return 0;
}