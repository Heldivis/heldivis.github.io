关于某c人士强制偷袭代码导致AT号被封，${\color{red}\mathrm{警钟敲碎}}$。

## 题意

一个长 $n$ 的数组 $a$，求所有顺序对中两元素之差的和。

## 分析

~~听说有大佬2min切掉~~。很明显，暴力过不去。

考虑计算每个元素的贡献。设 $id$ 为该元素之前所有比它小的元素个数，$sum$ 表示这些元素的和。因为要求所有差值的和，即理解为这个数乘上小于它的元素个数再减去比他小的数的和。那么此元素的贡献显然就是 $a_i\times id-sum$。

于是要维护 $id$ 和 $sum$。我们可以用桶树状数组或者动态开点权值线段树，作者懒，用了前者。开两个桶树状数组，分别存储元素个数和元素之和。对于每个元素 $a_i$，计算结果后让第一个桶添 $1$，第二个桶添 $a_i$。

这道题就做完了。但是显然，由于 $a_i$ 很大，所以需要离散化（这个应该不用讲了）。

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
const int maxn=4e6+10;
int n;
int a[maxn],li[maxn]; 
int cid[maxn*2],csum[maxn*2];
int lb(int x){return x&-x;}
void addid(int x,int y)
{
	for(;x<=maxn;x+=lb(x))cid[x]+=y;
}
int askid(int x)
{
	int ans=0;
	for(;x;x-=lb(x))ans+=cid[x];
	return ans;
}
void addsum(int x,int y)
{
	for(;x<=maxn;x+=lb(x))csum[x]+=y;
}
int asksum(int x)
{
	int ans=0;
	for(;x;x-=lb(x))ans+=csum[x];
	return ans;
}
signed main()
{
//  freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		li[i]=a[i];
	}
	sort(li+1,li+n+1);
	int tot=unique(li+1,li+n+1)-li-1,ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(li+1,li+tot+1,a[i])-li;
		int id=askid(x-1),sum=asksum(x-1);
		ans=ans+a[i]*id-sum;
		addid(x,1);addsum(x,a[i]);
	}
	cout<<ans;
	return 0;
}

```