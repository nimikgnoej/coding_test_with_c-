#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int n,m,start; //도시 개수 N, 경로의 개수 M, 시작점 start
vector<pair<int,int>> map[30001];
int dist[30001];
priority_queue<pair<int,int>> q;

void ds(int st){
  q.push({0,st});
  dist[st]=0;
  while(!q.empty()){
    int distance=-q.top().first;
    int now=q.top().second;
    q.pop();
    if(dist[now]<distance) continue;
    for(int k=0;k<map[now].size();k++){
      int cost=distance+map[now][k].second;
      if(cost<dist[map[now][k].first]){
        dist[map[now][k].first]=cost;
        q.push({-cost,map[now][k].first});
      }
    }
  }
}

int main()
{
  freopen("input.txt","r",stdin);
  cin>>n>>m>>start;
  for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    map[x].push_back({y,z});
  }
  fill_n(dist,30001,INF);
  ds(start);
  int ans=0;
  for(int i=1;i<=n;i++){
    if(ans<dist[i])
      ans=dist[i];
  }
  cout<<ans;
}