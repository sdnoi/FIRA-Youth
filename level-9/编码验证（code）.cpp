
//链表：将数字连接为链表，消除连续两个相同的数字，最终链表为空，则是合法的
#include <cstdio>
using namespace std;
const int N=1000;
char str[N],a[N];

struct Node{
 int prev,next,val;
}node[N];
int head,tail,tot=0;
void initialize(){
  tot=2;
  head=1;tail=2;
  node[head].prev=0;node[head].next=tail;
  node[tail].prev=head;node[tail].next=0;

}
int insert(int p,int v){//在p之前插入一个节点
  ++tot;
  node[tot].val=v;
  node[node[p].prev].next=tot;
  node[tot].prev=node[p].prev;
  node[tot].next=p;
  node[p].prev=tot;
  return tot;
}
void remove(int p){
  node[node[p].prev].next=node[p].next;
  node[node[p].next].prev=node[p].prev;
}
int main(){
 initialize();
 gets(str);
 for(int i=0;str[i];++i)
  if(str[i]>'0' && str[i]<='9'){
    int p=node[tail].prev;
    if(p!=head && node[p].val==str[i])//相同，则消除
        remove(p);
    else
      insert(tail,str[i]);
  }
  if(node[head].next==tail)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
