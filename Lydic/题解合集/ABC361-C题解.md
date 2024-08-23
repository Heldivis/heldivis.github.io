## 背景

昨天打比赛的时候查了中考分，心快停跳了。

## 题意

从 $n$ 个数字中删除 $k$ 个数字，问剩下的数字中极差的最小值。

## 分析

首先把这 $n$ 个数字排序，然后问题就可以转化为求这 $n$ 个数字中所有长度为 $n-k$ 的连续子段的极差的最小值。

采用尺取法，可以从 $1$ 开始枚举左端点。设当前左端点为 $i$，则右端点为 $n-k+i-1$。然后中途更新 $ans$ 值即可。

## Code

```cpp
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
int n,k;
int a[maxn],ans=1e9+7;
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>k;
	k=n-k;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-k+1;i++)
	{
		ans=min(ans,a[i+k-1]-a[i]);
	}
	cout<<ans;
	return 0;
}
```