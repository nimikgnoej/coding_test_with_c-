#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[30000];

int main() {
  //freopen("input.txt","r",stdin);
  dp[1]=0;

  int x;
  cin>>x;
  for(int i=2;i<=x;i++){
    dp[i]=dp[i-1]+1;
    
    if(i%5==0)
      dp[i]=min(dp[i],dp[i/5]+1);
    if(i%3==0)
      dp[i]=min(dp[i],dp[i/3]+1);
    if(i%2==0)
      dp[i]=min(dp[i/2]+1,dp[i]);
  }  

  cout<<dp[x];
}