#include<bits/stdc++.h>
using namespace std;
int G[11][11]={0},n,m,old[11]={0};
void dfs(int dq){
    cout<<dq+1<<" ";
    old[dq]++;
    for(int i=0;i<10;i++){
        if(G[dq][i]==1&&old[i]==0){
            dfs(i);
        }
    }
    return;
}//-_-
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        G[x-1][y-1]=1;
        G[y-1][x-1]=1;
    }
    dfs(0);
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