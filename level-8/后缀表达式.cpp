#include <cstdio>
using namespace std;
int stack[1010];

int main() {
    char ch;
    int d=0,top=0,r=0;
    while((ch=getchar())!='@') {

        if(ch<='9' && ch>='0')
            d=d*10+ch-'0';
        else if(ch=='.') {
            stack[top++]=d;
            d=0;
        } else {

            switch (ch) {
            case '+':
                r=stack[top-2]+stack[top-1];break;
            case '-':
                r=stack[top-2]-stack[top-1];break;
            case '*':
                r=stack[top-2]*stack[top-1];break;
            case '/':
                r=stack[top-2]/stack[top-1];break;
            }
            stack[top-2]=r;
            top--;
        }
    }

    printf("%d\n",stack[--top]);
    return 0;
}
/*----------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
long long n[1010],i=0,now=0;
char c;
int main()
{
	while(scanf("%c",&c)==1&&c!='@'){
		if(c>='0'&&c<='9') now*=10,now+=c-'0';
		else if(c=='.') n[++i]=now,now=0;
		else if(c=='+') n[i-1]+=n[i],i--;
		else if(c=='-') n[i-1]-=n[i],i--;
		else if(c=='*') n[i-1]*=n[i],i--;
		else if(c=='/') n[i-1]/=n[i],i--;
	}
	printf("%lld",n[1]);
}
