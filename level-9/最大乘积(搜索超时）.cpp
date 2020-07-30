#include <cstdio>
using namespace std;
//此题有后效性，在举例动归需要后效性时可用此例子说明不能用动态规划
//增加一维，二维用01背包
const int N=10000;
int p=1,m;
long long myMax=0;
int a[N],ans[N];

void printArray(int depth){

  for(int i=0;i<=depth;++i)
   printf("%d ",ans[i]);
   printf("\n");

}
void dfs(int k,int r,int depth){

  if(k<r && myMax<p*r) {
      myMax=p*r;
     a[depth]=r;
     m=depth;
     for(int i=0;i<=depth;++i)
      ans[i]=a[i];
  }
  for(int i=k+1;i<=r/2;++i){
    if(i==r){
      if(myMax<p*i)
      {
        myMax=p*i;
        m=depth;
        for(int i=0;i<=depth;++i)
         ans[i]=a[i];
       }
    }
    else{
      a[depth]=i;
      p=p*i;
      dfs(i,r-i,depth+1);
      p=p/i;
    }
  }
}
int main(){
  int n;
  scanf("%d",&n);
  dfs(1,n,0);
  printArray(m);
  printf("%lld\n",myMax);
	return 0;
}
