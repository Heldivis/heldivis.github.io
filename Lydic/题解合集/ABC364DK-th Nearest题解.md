## 分析

首先想到答案一定有单调性，结合每次询问需要在低于 $O(n)$ 的时间内求出答案，不难想到二分。

容易想到，我们可以二分从起点 $x$ 开始的范围 $d$，即需要统计 $[x-d,x+d]$ 区间中有多少个点。

那么这个就好维护了，什么数据结构都行，但是这个用内置的两个二分函数就可以了。

具体的，如果我们要判断数列 $a$ 在区间 $[x-d,x+d]$ 中的元素个数是否不少于 $k$，可以用以下代码实现：

```cpp
bool ch(int d,int x,int k)
{
	int r=upper_bound(a+1,a+n+1,x+d)-a-1;
	int l=lower_bound(a+1,a+n+1,x-d)-a;
	return r-l+1>=k;
}
```

然后就做完了，复杂度 $O(nlog^2n)$。

<details>
<summary>点击查看代码</summary>

```
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
using namespace std;
using namespace  __gnu_pbds;
//gp_hash_table<string,int>mp2;
//__gnu_pbds::priority_queue<int,less<int>,pairing_heap_tag> q;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}
const int mod=998244353;
const int maxn=1e6+10;
int n,Q;
int a[maxn];
int mi=1e17,ma=-1e17;
bool ch(int x,int b,int k)
{
	int r=upper_bound(a+1,a+n+1,b+x)-a-1;
	int l=lower_bound(a+1,a+n+1,b-x)-a;
	return r-l+1>=k;
}
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)a[i]=read(),mi=min(mi,a[i]),ma=max(ma,a[i]);
	sort(a+1,a+n+1);a[0]=-1e9-7;a[n+1]=1e9+7;
	while(Q--)
	{
		int b=read(),k=read();
		int l=0,r=3e8;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(ch(mid,b,k))r=mid;
			else l=mid+1;
		}
		printf("%lld\n",r);
	}
	return 0;
}
```
</details>
