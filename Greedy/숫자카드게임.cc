#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[101][101];
vector<int> comparenum;

int main()
{
  freopen("input.txt","r",stdin);
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>map[i][j];

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<map[i][j]<<" ";
    }
    cout<<'\n';
  }

  int num=10001;
  int idx=0;
  while(n--){
    int num=10001;
    for(int i=0;i<m;i++){
      if(num>map[idx][i]){
        num=map[idx][i];
      }
    }
    comparenum.push_back(num);
    idx++;
  }
  sort(comparenum.begin(),comparenum.end());
  cout<<comparenum.back();
}