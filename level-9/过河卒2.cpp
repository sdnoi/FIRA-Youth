#include<cstdio>
#include<cstring>
using namespace std;
int bx,by,hx,hy,ans=0;
int zax[]={1,1,-1,-1,2,2,-2,-2};
int zay[]={2,-2,2,-2,1,-1,1,-1};
long long v[25][25];
bool check(int x,int y){
  if(x>bx || y>by ||x<0 ||y<0) return false;//越界
  if(x==hx&&y==hy) return false; //马占据的位置
  for(int i=0;i<8;++i) //马防守的位置
    if(zax[i]==x && zay[i]==y) return false;
  return true;
}
long long dfs(int x,int y){
  long long down=0,right=0;
  if(v[x][y]!=-1) return v[x][y];//该点被访问过
  if(x==bx&&y==by) {
    v[x][y]=1;
    return 1;
  }
//  if(!check(x,y))
//  { v[x][y]=0;
//    return 0;}
  down=dfs(x+1,y);
  right=dfs(x,y+1);
  v[x][y]=down+right;
  return v[x][y];
}
int main() {
   memset(v,-1,sizeof(v));
   scanf("%d%d%d%d",&bx,&by,&hx,&hy);
   for(int i=0;i<by;++i)
    v[bx+1][i]=0;
   for(int i=0;i<bx;++i)
    v[i][by+1]=0;
    v[hx][hy]=0;
   for(int i=0;i<8;++i){
    zax[i]=zax[i]+hx;
    zay[i]=zay[i]+hy;
    if(zax[i]>=0 && zay[i]>=0)
    v[zax[i]][zay[i]]=0;
   }

   dfs(0,0);
   printf("%lld\n",v[0][0]);
    return 0;
}
