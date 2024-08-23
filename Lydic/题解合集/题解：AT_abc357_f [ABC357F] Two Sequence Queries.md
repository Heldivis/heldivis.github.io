## 题意

维护一个数据结构，支持两个数列的区间求和，和查询区间内两数列各元素积的和。

## 分析

线段树万岁!

这道题要维护两个序列，所以线段树中要同时存储两个区间和。但还要在维护一个信息，是该区间内两序列元素积的和。大概长这样：

```cpp
struct no
{
	int l,r;
	int da,db,ab;
	int ta,tb;
}t[maxn<<2];
```

其他的更新就不讲了，主要说一说积的和信息的更新。

当更新一个序列时，该信息要传递的信息其实是另一盒序列的和乘上该序列的懒标记，这点很好想。

然后就没有什么问题了。但是注意这道题要取模，你少取一个就废了。

## Code

```cpp
#include<bits/stdc++.h>
//#include<atcoder/modint>
#define int long long
using namespace std;
//using mint=atcoder::modint998244353;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}
const int maxn=1e6+10;
const int mod=998244353;
struct no
{
	int l,r;
	int da,db,ab;
	int ta,tb;
}t[maxn<<2];
int a[maxn],b[maxn],n,Q;
void upd(int p)
{
	t[p].da=(t[p*2].da+t[p*2+1].da)%mod;
	t[p].db=(t[p*2].db+t[p*2+1].db)%mod;
	t[p].ab=(t[p*2].ab+t[p*2+1].ab)%mod;
}
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r)
	{
		t[p].da=a[l]%mod;t[p].db=b[l]%mod;
		t[p].ab=a[l]*b[l]%mod;
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	upd(p);
}
void spread(int p)
{
	if(t[p].ta)
	{
		t[p*2].da+=t[p].ta*(t[p*2].r-t[p*2].l+1)%mod;t[p*2].da%=mod;
		t[p*2+1].da+=t[p].ta*(t[1+p*2].r-t[1+p*2].l+1)%mod;t[p*2+1].da%=mod;
		t[p*2].ta+=t[p].ta;t[p*2].ta%=mod;
		t[p*2+1].ta+=t[p].ta;t[p*2+1].ta%=mod;
		t[p*2].ab+=t[p].ta*t[p*2].db%mod;t[p*2].ab%=mod;
		t[p*2+1].ab+=t[p].ta*t[p*2+1].db%mod;t[p*2+1].ab%=mod;
	}
	if(t[p].tb)
	{
		t[p*2].db+=t[p].tb*(t[p*2].r-t[p*2].l+1)%mod;t[p*2].db%=mod;
		t[p*2+1].db+=t[p].tb*(t[1+p*2].r-t[1+p*2].l+1)%mod;t[p*2+1].db%=mod;
		t[p*2].tb+=t[p].tb;t[p*2].tb%=mod;
		t[p*2+1].tb+=t[p].tb;t[p*2+1].tb%=mod;
		t[p*2].ab+=t[p].tb*t[p*2].da%mod;t[p*2].ab%=mod;
		t[p*2+1].ab+=t[p].tb*t[p*2+1].da%mod;t[p*2+1].ab%=mod;
	}
	t[p].ta=0;
	t[p].tb=0;
}
void changea(int p,int l,int r,int k)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		t[p].da+=k*(t[p].r-t[p].l+1)%mod;t[p].da%=mod;
		t[p].ta+=k;t[p].ta%=mod;
		t[p].ab+=k*t[p].db%mod;t[p].ab%=mod;
		return ;
	}
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(l<=mid)changea(p*2,l,r,k);
	if(mid<r) changea(p*2+1,l,r,k);
	upd(p);
}
void changeb(int p,int l,int r,int k)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		t[p].db+=k*(t[p].r-t[p].l+1)%mod;t[p].db%=mod;
		t[p].tb+=k;t[p].tb%=mod;
		t[p].ab+=k*t[p].da%mod;t[p].ab%=mod;
		return ;
	}
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(l<=mid)changeb(p*2,l,r,k);
	if(mid<r) changeb(p*2+1,l,r,k);
	upd(p);
}
int ask(int p,int l,int r)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		return t[p].ab%mod;
	}
	spread(p);
	int mid=(t[p].l+t[p].r)>>1,sum=0;
	if(l<=mid)sum=(sum+ask(p*2,l,r)%mod)%mod;
	if(mid<r) sum=(sum+ask(p*2+1,l,r)%mod)%mod;
	return sum%mod;
}
signed main()
{
//  freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	build(1,1,n);
	while(Q--)
	{
		int opt=read(),l=read(),r=read();
		if(opt==3)
		{
			printf("%lld\n",ask(1,l,r)%mod);
			continue;
		} 
		int x=read();
		if(opt==1)changea(1,l,r,x);
		if(opt==2)changeb(1,l,r,x);
	}
	return 0;
}

```