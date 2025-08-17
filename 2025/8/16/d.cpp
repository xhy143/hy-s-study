#include<bits/stdc++.h>
using namespace std;
int R, C;
string G[1001];
int vis[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct node {
    int x, y, step;
};

void bfs(int bx,int by,int ex,int ey,int n,int m) {
    deque<node>q;
    q.push_back({bx,by,0});
    while(!q.empty()){
        node now=q.front();
        q.pop_front();
        if(now.x==ex&&now.y==ey){
            cout<<now.step<<endl;
            return;
        }
        for(int i=0;i<4;i++){
            node nxt=now;
            nxt.x+=dx[i];
            nxt.y+=dy[i];
            if(nxt.x>=0&&nxt.x<n&&nxt.y>=0&&nxt.y<m){
                if(!vis[nxt.x][nxt.y]){
                    if(G[now.x][now.y]==G[nxt.x][nxt.y]){
                        q.push_front(nxt);
                        vis[nxt.x][nxt.y]=1;
                    }
                    else{
                        nxt.step+=1;
                        q.push_back(nxt);
                        vis[nxt.x][nxt.y]=1;
                    }
                }
            }
        }
    }
    return ;
}

int main() {
    int bx,by,ey,ex;
    while(cin>>R>>C){
        if(R==0&&C==0){
            break;
        }
        for (int i = 0; i < R; i++) {
            cin >> G[i];
        }
        cin>>bx>>by>>ex>>ey;
        bfs(bx,by,ex,ey,R,C);
        memset(vis,0,sizeof(vis));
    }
}