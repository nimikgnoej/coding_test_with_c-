#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int n,m; //회사 개수 N, 경로의 개수 M
int x,k;
int map[101][101];

int main()
{
  freopen("input.txt","r",stdin);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      map[i][j]=INF;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j)
        map[i][j]=0;
    }
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    map[a][b]=1;
    map[b][a]=1;
  }
  cin>>x>>k; //목표지점 x, 소개팅장소 k

  for(int k=1;k<=n;k++){
    for(int a=1;a<=n;a++){
      for(int b=1;b<=n;b++){
        map[a][b]=min(map[a][b],map[a][k]+map[k][b]);
      }
    }
  }
  if(map[1][k]+map[k][x]>=INF)
    cout<<"-1";
  else
    cout<<map[1][k]+map[k][x];

}