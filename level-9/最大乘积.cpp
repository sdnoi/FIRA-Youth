//https://www.luogu.com.cn/problem/P1249
#include<iostream>
using namespace std;
long long n,x=0,sss=0,ss=1,i=2,t=1;
int a[10001]={};
int s[10001]={};
void jc(int x)
{
    for(int i=1;i<=t;i++)//从低位到高位依次乘以新的乘数x，每位相乘的结果先暂时存储在每位上，不进位
    {
        s[i]=s[i]*x;
    }
    for(int i=1;i<=t;i++)//处理进位
    {
        if(s[i]>=10) //如果当前位大于等于10，则需要进位，否者本位上的数不变
        {
            long long add=s[i]/10;
            s[i+1]+=add;
            s[i]=s[i]%10;
            if(i+1>t)
            	t=i+1;
        }
    }
}
int main()
{
	s[1]=1;
	cin>>n;
	while(sss<n)//sss为当前的和
	{
		a[++x]=i;//i为加数
		sss+=i;
		i++;
	}
	a[sss-n-1]=0;//sss-n存在第(sss-n-1)个位置上的，将此位置0,即不取其作为分解出的一个自然数

	for(int i=1;i<=x;i++)
	{
		if(a[i]!=0)cout<<a[i]<<' ';
		if(a[i]!=0)jc(a[i]);//当前结果乘以a[i]
	}
	cout<<endl;
	for(int i=t;i>=1;i--)
		cout<<s[i];
	cout<<endl;
	return 0;
}
