#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> grasp[N];
int a[N], n, m, k, b;
bool cmp(int a, int b){
	return a > b;
}
int cnt[N];

int main(){
	
	cin >> m >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		cin >> b;
		grasp[a[i]].push_back(b); 
    }
	int ans = 0, maxN = 0, maxP; 
	for(int i = 1; i <= m; i++){ 
		
		sort(grasp[i].begin(), grasp[i].end(), cmp);  
		int len = grasp[i].size(), sum = 0;
		for(int j = 0; j < len; j++){
			sum += grasp[i][j]; 
			cnt[i]++;          
			if(sum >= k){       
				break;
			}
		}
		if(sum < k){  
			cout << "-1";   
			return 0; 	   
		}
		ans += cnt[i];    
		if(maxN < cnt[i]) maxN = cnt[i], maxP = i;  
	}
	if(ans - maxN >= maxN - 1){  
		cout << ans; 
	}
	else{  
		
		int remainder = 0;
		for(int i = 1; i <= m; i++){   
			if(i != maxP)  remainder += grasp[i].size() - cnt[i]; 
		}
		if(ans - maxN + remainder >= maxN - 1){  
			cout << 2*maxN - 1;  
		}
		else{ 
			cout << "-1";  
		}	
	} 
	return 0;
}

