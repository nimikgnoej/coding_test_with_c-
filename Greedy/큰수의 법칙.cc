#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,k;
vector<int> v;
int ans;

int main()
{
  freopen("input.txt","r",stdin);
  cin>>n>>m>>k;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    v.push_back(num);
  }
  sort(v.begin(),v.end());
  int check=0;
  while(m--){
    if(check<k){
      check++;
      ans+=v.back();
    }
    else{
      check=0;
      int sec=v.size()-2;
      ans+=v[sec];
    }
  }

  cout<<ans;
}