#include<bits/stdc++.h>
using namespace std;
string q1(string a,string b){
	int len1=a.size();
	int len2=b.size();
	int len3=max(len1,len2)+1;
	
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	for(int i=len1;i<=len3;i++){
		a+='0';
	}
	for(int i=len2;i<=len3;i++){
		b+='0';
	}
	
	int plus=0;
	string ans;
	
	for(int i=0;i<len3;i++){
		int num=int(a[i]-'0'+b[i]-'0');
		ans+=char(num%10+plus+'0');
		plus=num/10;
	}
	if(plus){
		ans+='1';
	}
	
	reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.length();i++){
        if(ans[i]!='0'){
            ans.erase(0,i);
            break;
        }
    }
	return ans;
}
int main(){
    int n;
    cin>>n;
    string ans="0";
    for(int i=0;i<n;i++){
        ans=q1(ans,ans);
        ans=q1(ans,"1");
    }
    cout<<ans;
}