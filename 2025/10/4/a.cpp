#include<bits/stdc++.h>
using namespace std;

struct node{
    int zc, wj; 
};

node a[10001];

int main(){
    freopen("labour.in","r",stdin);
    freopen("labour.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].zc >> a[i].wj;
    }
    int cmin[2] = {1000000, -1}, jmin[2] = {1000000, -1};
    
    for(int i = 0; i < n; i++){
        if(a[i].zc < cmin[0]){
            cmin[0] = a[i].zc;
            cmin[1] = i;
        }
        if(a[i].wj < jmin[0]){
            jmin[0] = a[i].wj;
            jmin[1] = i;
        }
    }
    if(cmin[1] != jmin[1]){
        int time1 = max(cmin[0], jmin[0]); 
        int time2 = 1000000;

        for(int i = 0; i < n; i++){
            time2 = min(time2, a[i].zc + a[i].wj);
        }
        
        cout << min(time1, time2) << endl;
    }
    else { 
        int same_person = cmin[0] + jmin[0]; 
        int second_cmin = 1000000;
        for(int i = 0; i < n; i++){
            if(i != cmin[1] && a[i].zc < second_cmin){
                second_cmin = a[i].zc;
            }
        }
        int second_jmin = 1000000;
        for(int i = 0; i < n; i++){
            if(i != jmin[1] && a[i].wj < second_jmin){
                second_jmin = a[i].wj;
            }
        }
        
        int diff_person = max(second_cmin, jmin[0]); 
        diff_person = min(diff_person, max(cmin[0], second_jmin)); 
        
        cout << min(same_person, diff_person) << endl;
    }
    
    return 0;
}