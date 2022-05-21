#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,cnt;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int map[1001][1001];
int visited[1001][1001];


void dfs(int x,int y){
  visited[x][y]=1;
  for(int k=0;k<4;k++){
    int nx=x+dx[k];
    int ny=y+dy[k];
    if(0<=nx&&nx<n&&0<=ny&&ny<m){
      if(map[nx][ny]==0&&visited[nx][ny]==0){
        dfs(nx,ny);
      }
    }
  }
}

int main()
{
  freopen("input.txt","r",stdin);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>map[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]==0 && visited[i][j]==0){
        dfs(i,j);
        cnt++;
      }
    }
  }
  cout<<cnt;
}