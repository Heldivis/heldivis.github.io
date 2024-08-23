## 背景

机房大佬掉大分了，~~乐~~悲。

## 题意

给你几个箱子和每个箱子里装有的东西 $a$ 和对应的重量 $w$，现在要让每个箱子里都装有一个东西，每次可以移动任意一个箱子中的任意一个东西，代价为它的重量，问最小代价。

## 分析

贪心。首先最终状态里所有箱子一定只有一个东西，那么对于所有装东西的箱子，若装有 $x$ 个东西，那么一定要把它的 $x-1$ 个东西拿走。

由于东西数量和箱子数量相等，那么我们无需考虑每个箱子中的东西该放到那些箱子里，因为空箱子的数量一定是符合的。

那么就把每个箱子中的东西统计出来，从小到大排序，每个箱子的代价就是前 $x-1$ 个东西的重量之和。

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
//__gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> q;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}
const int mod=998244353;
const int maxn=1e6+10;
int n;
int a[maxn],w[maxn];
vector<int> v[maxn];
int ans=0;
bool f[maxn];
signed main()
{
//  freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		f[a[i]]=1;
	}
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=n;i++)
	{
		v[a[i]].push_back(w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])
		{
			sort(v[i].begin(),v[i].end());
			for(int j=0;j<v[i].size()-1;j++)
			{
				ans+=v[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}

```