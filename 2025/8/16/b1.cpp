#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,cnt;
};
int G[4][4],ans[10001][1001];
bool check(){
    string c="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c+=(char)G[i][j]+'0';
        }
    }
    cout<<c<<endl;
    return (c=="123804765"?  1:  0);
}
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs(int x,int y){
    queue<node>jd;
    jd.push({x,y,0});
    while(!jd.empty()){
        node q=jd.front();
        jd.pop();
        if(check()){
            cout<<q.cnt;
            return;
        }
        for(int i=0;i<4;i++){
            node nxt=q;
            int nx=nxt.x+dx[i];
            int ny=nxt.y+dy[i];
            if(nx>=0&&nx<3&&ny<3&&ny>=0){
                swap(G[nx][ny],G[q.x][q.y]);
                nxt.cnt++;
                jd.push({nx,ny,nxt.cnt});
            }
        }
    }
}
int main(){
    string ls;
    cin>>ls;
    int x,y;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            G[i][j]=ls[i*3+j]-'0';
            if(G[i][j]==0){
                x=i,y=j;
            }
        }
    }
    bfs(x,y);
}