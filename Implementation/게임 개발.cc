#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool flag=false;
int n,m;
int nowx,nowy;
int dir;
int cnt=1;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int map[51][51];
int visited[51][51];

void move(int x,int y){
  visited[x][y]=1;
  while(true){
    flag=false;
    for(int k=0;k<4;k++){
      int nx=x+dx[k];
      int ny=y+dy[k];
      if(0<=nx&&nx<n&&0<=ny&&ny<m){
        if(map[nx][ny]==0 && visited[nx][ny]==0){
          flag=true;
          dir--;
          if(dir==-1)
            dir=3;
          visited[nx][ny]=1;
          cnt++;
          x=nx; y=ny;
          break;
        }
        else{
          dir--;
          if(dir==-1)
            dir=3;
        }
      }
    }
    if(flag==false){
      if(dir==0){
        x+=1;
        if(map[x][y]==1)
          break;
      }
      else if(dir==1){
        y-=1;
        if(map[x][y]==1)
          break;
      }
      else if(dir==2){
        x-=1;
        if(map[x][y]==1)
          break;
      }
      else if(dir==3){
        y+=1;
        if(map[x][y]==1)
          break;
      }
    }
  }
}

int main()
{
  freopen("input.txt","r",stdin);
  cin>>n>>m;
  cin>>nowx>>nowy>>dir;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>map[i][j];
    }
  }
  move(nowx,nowy);
  cout<<cnt;
}