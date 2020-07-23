#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20;
int a[N];
int main(){
  int sum;
  for(int i=0;i<14;++i)
    scanf("%d",&a[i]);
  sort(a,a+14);

//  for(int i=0;i<14;++i)
//    printf("%d ",a[i]);
//  printf("\n");

  int light=10000,heavy=0;
  for(int i=0;i<7;++i)
  {
    int t=a[i]+a[13-i];
   // printf("%d,",t);
    if(light>t)
      light=t;
    if(heavy<t)
     heavy=t;
  }
   printf("%d\n",heavy-light) ;
}
