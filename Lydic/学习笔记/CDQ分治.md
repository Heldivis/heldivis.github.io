该分治算法由CDQ提出，主要用于解决三维偏序问题。

下面的内容就三维偏序例题来讲。

## 题目

给你一个序列，每个元素有 $a,b,c$ 三个属性，问满足 $a_i>a_j,b_i>b_j,c_i>c_j$ 的数对 $i,j$ 的数量。

## 分析

将原序列按照 $a$ 值排序，将其变为下标。

CDQ分治的主要步骤是对于一个需要解决的区间 $l,r$，找到区间中点 $mid$，并把原区间中的数对 $(i,j)$ 分为三部分

~ $i\le mid,j\le mid$
~ $mid\le i,mid\le j$
~ $i\le mid,mid\le j$

对于前两种数对，递归计算，所以我们需要设计算法解决第三类数对。

考虑把区间 $l\sim mid$ 和 $mid\sim r$ 按照 $b$ 排序，并设计两个指针 $i,j$，分别从 $l$ 和 $mid+1$ 开始向右移动。对于每一个当前的 $j$，我们需要计算 $b_i\le b_j$ 的数对个数。因为序列已经排好序，所以我们将 $i$ 指针一直右移，并把途中的所有 $c_i$ 加入值域树状数组，最后累加答案并消除影响即可。

## Code

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}
const int mod=998244353;
const int maxn=2e5+10;
int t[maxn<<2];
int lb(int x){return x&-x;}
void add(int x,int y){for(;x<=maxn;x+=lb(x))t[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=t[x];return ans;}
int n;
struct no
{
	int a,b,c,d,ans;
	inline friend bool operator < (no x,no y)
	{
		return x.a<y.a||x.a==y.a&&x.b<y.b||x.a==y.a&&x.b==y.b&&x.c<y.c;
	}
	inline friend bool operator != (no x,no y)
	{
		return x.a!=y.a||x.b!=y.b||x.c!=y.c;
	}
}x[maxn],y[maxn];
int tot;
void solve(int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	sort(y+l,y+mid+1,[](no x,no y){
		return x.b<y.b||x.b==y.b&&x.c<y.c;
	});
	sort(y+mid+1,y+r+1,[](no x,no y){
		return x.b<y.b||x.b==y.b&&x.c<y.c;
	});
	int i=l,j=mid+1;
	while(j<=r) 
	{
		while(i<=mid&&y[i].b<=y[j].b) 
		{
			add(y[i].c,y[i].d);
			i++;
	    }
	    y[j].ans+=ask(y[j].c);
	    j++;
  }
  for(int k=l;k<i;k++) add(y[k].c,-y[k].d);
  return;
}
int ans[maxn];
signed main()
{
	n=read();int k=read();k=0;
	for(int i=1;i<=n;i++)
	{
		x[i].a=read();x[i].b=read();x[i].c=read();
		x[i].d=1;x[i].ans=0;
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
		k++;
		if(x[i]!=x[i+1])
		{
			y[++tot]=x[i];
			y[tot].d=k;
			k=0;
		}
	}
	solve(1,tot); 
	for(int i=1;i<=tot;i++) 
	{
		x[i].ans+=x[i].d-1;
		ans[x[i].ans]+=x[i].d;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
```