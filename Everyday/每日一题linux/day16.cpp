#include<iostream>
using namespace std;
int count(int n){
  int sum=0,res=0;
  for(int i=1;i<=n;i++){
    sum=0;
    for(int j=1;j<i;j++){
      if(i%j==0){
        sum+=j;
      }
    }
    if(sum==i){
      res++;
    }
  }
  return res;
}
int main() {
    int n;
    while(cin>>n){
        cout<<count(n)<<endl;
    }
    return 0;
}
