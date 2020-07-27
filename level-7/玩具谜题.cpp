#include <cstdio>
using namespace std;
const int N=100050;
struct Toy{
 int face;
 char name[15];
}toy[N];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d%s",&toy[i].face,&toy[i].name);
  int f,k=0;
	f=toy[0].face;
	for(int i=0;i<m;++i){
	  int dir,s;
		scanf("%d%d",&dir,&s);
		if(dir^f) //为1，表示逆时针
			k=(k+s%n)%n;//
		else//顺时针
			k=(k-(s % n)+n)%n;
	 f=toy[k].face;
	// printf("%d %s\n",toy[k].face,toy[k].name);
	}
	printf("%s\n",toy[k].name);
	return 0;
}
