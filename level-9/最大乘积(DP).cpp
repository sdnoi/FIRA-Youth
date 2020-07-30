/*
互不相同这个条件可以改为从1,2,\cdots,n1,2,⋯,n这nn个数中选出一些数，使得它们的和为nn。但是，0101背包只能处理从aa个物品中选出总共bb空间的物品，使得它们的价值和最大，可是我们要求乘积呀？

在数学里，对数有一个很好的性质：

\ln a+\ln b=\ln(a\times b)
lna+lnb=ln(a×b)

假如我们要选出一些数使得它们的乘积最大，就等价于这些数的对数之和最大。

因此题目就很显然了。nn个物品，背包体积为nn，每个物品体积C_iC 
i
​	
 为ii，价值W_iW 
i
​	
 为\ln ilni。设dp_{i,j}dp 
i,j
​	
 为前ii个物品总共花费了jj的空间的最大和，转移方程：

dp_{i,j}=\min\{dp_{i-1,j-C_i}+W_i,dp_{i-1,j}\}
dp 
i,j
​	
 =min{dp 
i−1,j−C 
i
​	
 
​	
 +W 
i
​	
 ,dp 
i−1,j
​	
 }

然后滚动数组优化一下，就可以\mathcal O(N^2)O(N 
2
 )时间复杂度，\mathcal O(N)O(N)空间复杂度求出最大乘积的方案了。（因为答案过大，而精度不够高，因此最大乘积直接输出\exp(dp_{n,n})exp(dp 
n,n
​	
 )显然是不行的）

接着我们只需要写一个高精乘低精的乘法就行了。
*/

#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(l,r,i) for(int i=l;i>=r;i--)
using namespace std;

typedef long long LL;
const int INF =2147483647;
int qread(){
    int w=1,c,ret;
    while((c=getchar())> '9'||c< '0')
    w=(c=='-'?-1:1); ret=c-'0';
    while((c=getchar())>='0'&&c<='9')
    ret=ret*10+c-'0';
    return ret*w;
}
const int MAXN =1e4+3,MAXL=1e5+3;
int n,C[MAXN],flg[MAXN];double W[MAXN],dp[MAXN];
vector <int> ans;
struct Node{
    int dt[MAXL],len; Node():len(0){memset(dt,0,sizeof(dt));}
    Node operator *(int t){
        Node res; up(1,len,i) res.dt[i]=dt[i]*t;
        up(1,len+10,i){
            res.dt[i+1]+=res.dt[i]/10,res.dt[i]%=10;
            if(res.dt[i]) res.len=i;
        }
        return res;
    }
}val;
int main(){
    n=qread(); up(1,n,i) W[i]=log(i);
    up(1,n,i) dp[i]=-INF;
    up(1,n,i) dn(n,i,j){
        if(dp[j-i]+W[i]>dp[j]) dp[j]=dp[j-i]+W[i],flg[j]=j-i;
    }
    for(int p=n;p;p=flg[p]) ans.push_back(p-flg[p]);
    dn(ans.size(),1,i) printf("%d ",ans[i-1]); puts("");
    val.len=1,val.dt[1]=1;
    up(1,ans.size(),i) val=val*ans[i-1];
    dn(val.len,1,i) putchar('0'+val.dt[i]); puts("");
    return 0;
}
