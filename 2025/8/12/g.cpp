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
		int num=int(a[i]-'0'+b[i]-'0'+plus);
		ans+=char(num%2+'0');
		plus=num/2;
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
    string n;
    cin>>n;
    string ans=n;
    ans=n+"0000";
    ans=q1(ans,n);
    cout<<ans;
}