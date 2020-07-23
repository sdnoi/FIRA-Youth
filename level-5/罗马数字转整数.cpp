#include<cstdio>
#include<algorithm>
using namespace std;
const int N=30;
int a[N],v[N];
char str[550];
int main(){
  a['M'-'A']=6;  a['D'-'A']=5;  a['C'-'A']=4;
  a['L'-'A']=3;a['X'-'A']=2;a['V'-'A']=1;a['I'-'A']=0;
  v['M'-'A']=1000;v['D'-'A']=500;v['C'-'A']=100;
  v['L'-'A']=50;v['X'-'A']=10;v['V'-'A']=5;v['I'-'A']=1;
  int sum=0;
  scanf("%s",str);
  int i;
  for(i=0;str[i+1];){
    int x=str[i]-'A';
    int y=str[i+1]-'A';
    //printf("%d,%d\n",x,y);
    if(a[x]>=a[y])
     {sum+=v[x];i++;}
    else
     {sum+=v[y]-v[x];i=i+2;
     if(str[i]==0) break;}
  }
  if(str[i]) sum+=v[str[i]-'A'];
  printf("%d\n",sum);
return 0;
}
