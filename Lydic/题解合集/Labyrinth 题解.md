[题目链接](https://www.luogu.com.cn/problem/CF1578L)

挖性质好题。

## 分析

首先注意到一个性质，最开始的时候是没有宽度的，即可以在图上随便走，所以从 $1$ 号节点开始的限制等于无。

然后根据贪心的思想，走的时候我们要尽可能的使路径上最小的边权最大，所以不难想到要在最大生成树上跑。

先把最大生成树求出来，然后为了方便建上 Kruskal 重构树，以下分析在重构树上面考虑。

现在我们考虑怎样吃是最优的。容易发现，我们一定是先吃完一颗子树再去吃另一棵子树最优。简要证明一下，如果我们还没吃完一颗子树就去吃另一棵，那么当我们回来吃这颗子树的时候时宽度一定会增大，完全不优，所以证明完毕。

性质都出来以后，我们考虑如何合并子树信息，我们设 $dp_i$ 表示吃完子树 $i$ 所需的最大初始宽度，$sum_i$ 表示子树 $i$ 的点权和。

现在我们要合并两棵子树 $a$ 和 $b$ 的信息，分两种情况，即先吃 $a$ 再吃 $b$ 和先吃 $b$ 再吃 $a$。

以第一种情况为例，设 $u$ 表示 $a$ 和 $b$ 子树的父亲节点，$w$ 为它的点权。因为我们求的是最大生成树，所以这个点的点权一定是当前所有点中最小的。吃完 $a$ 子树以后，如果我们想要走到 $b$，那么需要保证 $w\ge sum_a+dp_u$ 且 $dp_b\ge sum_a+dp_u$，所以得出 $dp_u=\min(w-sum_a,dp_b-sum_a)$。

另一种情况同理，可以得到转移方程为
$$dp_u=\max(\min(w-sum_a,dp_b-sum_a),\min(w-sum_b,dp_a-sum_b))$$

正常递归处理即可。

## Code

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return w*s;
}
const int maxn=5e5+10;
int n,m,k;
struct no
{
	int x,y,v;
	inline friend bool operator < (no x,no y)
	{
		return x.v>y.v;
	}
}edge[maxn];
int fa[maxn];
int gf(int x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
vector<int> G[maxn];
int c[maxn];
void add(int x,int y)
{
	G[x].push_back(y);
	G[y].push_back(x);
}
int dp[maxn],sum[maxn];
void dfs(int u,int fa)
{
	int mi=1e9+7;
	int d[3],tt=0;
	for(auto y : G[u])
	{
		if(y==fa)continue;
		dfs(y,u);
		d[++tt]=y;
	}
	if(!tt)return ;
	int x=d[1],y=d[2],w=c[u];
	dp[u]=max(min(w-sum[x],dp[y]-sum[x]),min(w-sum[y],dp[x]-sum[y]));
	sum[u]=sum[x]+sum[y];
}
signed main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=m;i++)
	{
		edge[i]={read(),read(),read()};
	}
	for(int i=1;i<=n+m+1;i++)fa[i]=i;
	for(int i=1;i<=n;i++)sum[i]=c[i],dp[i]=1e9+7;
	sort(edge+1,edge+m+1);
	int tot=0,cnt=n;
	for(int i=1;i<=m;i++)
	{
		int fx=gf(edge[i].x),fy=gf(edge[i].y);
		if(fx!=fy)
		{
			c[++cnt]=edge[i].v;
			add(fy,cnt);
			add(fx,cnt);
			fa[fx]=fa[fy]=cnt;
			if(++tot==n-1)break;
		}
	}
	dfs(cnt,-1);
	if(dp[cnt]<=0)cout<<-1;
	else cout<<dp[cnt];
	return 0;
}
```

记得点赞欧。