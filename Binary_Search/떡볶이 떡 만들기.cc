#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int> dduk;
vector<int> candidate;

int cut(int h){
  int sum=0;
  for(int i=0;i<n;i++){
    if(dduk[i]<h)
      continue;
    else
      sum+=dduk[i]-h;
  }
  return sum;
}

int main() {
  freopen("input.txt","r",stdin);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    dduk.push_back(num);
  }
  sort(dduk.begin(),dduk.end());
  for(int i=1;i<=dduk[dduk.size()-1];i++){
    candidate.push_back(i);
  }

  int start=0;
  int end=candidate.size()-1;
  int mid;
  while(start<=end){
    mid=(start+end)/2;
    if(cut(mid)==m){
      cout<<mid;
      break;
    }
    if(cut(mid)<m){
      end=mid-1;
    }
    else if(cut(mid)>m){
      start=mid+1;
    }
  }
}