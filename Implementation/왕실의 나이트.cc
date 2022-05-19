#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string input;
int row,col;
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};

int main()
{
  //freopen("input.txt","r",stdin);
  cin>>input;
  col=input[1]-'0';
  row=input[0]-'a'+1;
  int cnt=0;

  for(int i=0;i<8;i++){
    int nx=row+dx[i];
    int ny=col+dy[i];
    if(1<=nx && nx<=8 && 1<=ny && ny<=8)
      cnt++;
  }

  cout<<cnt;
}