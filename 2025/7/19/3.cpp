#include<bits/stdc++.h>
using namespace std;
int G[150][150]={0},n,m,old[150]={0},ans=0,mans=1;
void dfs(int dq){
    ans++;
    old[dq]++;
    for(int i=96;i<150;i++){
        if(G[dq][i]==1&&old[i]==0){
            dfs(i);
        }
    }
    if(ans>=mans){
        mans=ans;
    }
    ans--;
    return;
}//-_-
int main( ){
    int ms=0;
    cin>>m;
    for(int i=0;i<m;i++){
        string a;
        cin>>a;
        if(i==0){
            ms=int(a[0]);
        }
        G[int(a[0])][int(a[1])];
    }
    dfs(ms);
    cout<<mans;
}

/*cout<< "           佛祖保佑       永无BUG" << endl;
cout << "                   _ooOoo_" << endl;
cout << "                  o8888888o" << endl;
cout << "                  88\" . \"88" << endl;
cout << "                  (| -_- |)" << endl;
cout << "                  O\\  =  /O" << endl;
cout << "               ____/`---'\\____" << endl;
cout << "             .'  \\\\|     |//  `." << endl;
cout << "            /  \\\\|||  :  |||//  \\" << endl;
cout << "           /  _||||| -:- |||||-  \\" << endl;
cout << "           |   | \\\\\\  -  /// |   |" << endl;
cout << "           | \\_|  ''\\---/''  |   |" << endl;
cout << "           \\  .-\\__  `-`  ___/-. /" << endl;
cout << "         ___`. .'  /--.--\\  `. . __" << endl;
cout << "      .\"\" '<  `.___\\_<|>_/___.'  >'\"\"." << endl;
cout << "     | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |" << endl;
cout << "     \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /" << endl;
cout << "======`-.____`-.___\\_____/___.-`____.-'======" << endl;
cout << "                   `=---='" << endl;
cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;*/