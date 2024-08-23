[题面](https://www.luogu.com.cn/problem/AT_abc265_e "题面")

简单计数 DP。

由于数据范围很大，所以状态不能常规设置为 $dp_{i,j}$。

注意到 $n$ 只有 $300$，考虑设 $dp_{i,j,k}$ 表示三种行走方法分别使用 $i$，$j$，$k$ 次的路径数量。

状态转移很简单，先计算出来当前所在位置，如果是障碍就跳过，否则$dp_{i,j,k}=dp_{i-1,j,k}+dp_{i,j-1,k}+dp_{i,j,k-1} $ 即可。

累加答案的话，如果 $i+j+k=n$ 的话，就把 $dp_{i,j,k}$ 累加到 $ans$ 上面即可。

有一些细节，因为转移方程里面出现了 $-1$，所以要先判断 $i,j,k$ 是否大于 $0$，否则会 $RE$（\JK本地不会RE所以很危险）。

<details>
<summary>点击查看代码</summary>

```cpp
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+(ch^	48);ch=getchar();}
	return w*s;
} 
using namespace std;
using namespace __gnu_pbds;
const int maxn=1e6+100;
const int mod=998244353;
map<pair<int,int>,bool > mp;
int n,m;
int dy[10],dx[10];
int x[maxn],y[maxn];
int dp[310][310][310];
int ans=0;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=3;i++)
	cin>>dx[i]>>dy[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[{x,y}]=1;
	}
	dp[0][0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			for(int k=0;k<=n-i-j;k++)
			{
				int xx=i*dx[1]+j*dx[2]+k*dx[3];
				int yy=i*dy[1]+j*dy[2]+k*dy[3];
				if(mp[{xx,yy}])continue;
				dp[i][j][k]=((((dp[i][j][k]+(i?dp[i-1][j][k]:0))%mod+(j?dp[i][j-1][k]:0))%mod)+(k?dp[i][j][k-1]:0))%mod;
				if(i+j+k==n)ans=(ans+dp[i][j][k])%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
```

</details>
