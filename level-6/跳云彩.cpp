//应该可以用贪心法，我用的递推
#include <cstdio>
using namespace std;
char a[505];
int f[505];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		{scanf("%d",&a[i]);
		 f[i]=1000;
		}
	f[0]=0;
	int maxs=1;
	if(a[1]==0) {f[1]=1;maxs=2;}else f[1]=1000;
	for(int i=2;i<n;++i)
		if(a[i]==1)
      {
      if (a[i-1]==1) break;
      }
		else{
			if(f[i-1]<f[i-2])
				f[i]=f[i-1]+1;
			else
				f[i]=f[i-2]+1;
			maxs=i+1;
		}
	if(f[n-1]>=1000)
		printf("%d\n",maxs);
	else
		printf("%d\n",f[n-1]);
	return 0;
}
