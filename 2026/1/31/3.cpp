#include<bits/stdc++.h>
using namespace std;

struct node{
    int ls, rs;
    char xz;     
} a[1000001];

int nodeCount = 1;
int check(string p){
    int f1 = 1, f2 = 1;
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '1') f1 = 0;
        if(p[i] == '0') f2 = 0;
        if(!(f1 || f2)) break;
    }
    if(f1) return 0;    
    else if(f2) return 1; 
    else return 2;        
}
int build(string p){
    int cur = nodeCount++;
    int len = p.length();
    int x = check(p);
    a[cur].xz = (x == 0 ? 'B' : (x == 1 ? 'I' : 'F'));
    
    if(len > 1){
        int mid = len / 2;
        string leftStr = p.substr(0, mid);
        string rightStr = p.substr(mid);
        
        a[cur].ls = build(leftStr); 
        a[cur].rs = build(rightStr); 
    } else {
        a[cur].ls = a[cur].rs = 0; 
    }
    
    return cur;
}
void dfs(int root){
    if(root == 0) return;
    dfs(a[root].ls);
    dfs(a[root].rs);
    cout << a[root].xz;
}

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    int root = build(s);
    dfs(root);
    
    return 0;
}