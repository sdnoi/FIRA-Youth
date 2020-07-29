#include <cstdio>
#include<cmath>
using namespace std;
int a[25],n,k,ans=0;
//int b[25];
long long sum=0;
bool isPrime(int x){
  for(int i=2;i<=sqrt(x);++i)
    if(x%i==0) return false;

  return true;
}
void pick(int st,int p){
  if(p==k+1){
    if(isPrime(sum))
       {ans++;
//       for(int i=1;i<p;++i)
//          printf("%d+",b[i]);
//       printf("=%d ",sum);
       }
    return ;
    }
  for(int i=st;i<=n;++i)
    {
//      b[p]=a[i];
      sum=sum+a[i];
      pick(i+1,p+1);
      sum=sum-a[i];
    }
}
int main(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;++i)
    scanf("%d",&a[i]);
  pick(1,1);
  printf("%d\n",ans);
	return 0;
}
