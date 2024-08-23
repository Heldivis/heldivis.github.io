正常动规，但是赛时死了。

## 分析

看到 $n$ 很小，但是 $X$ 和 $Y$ 有点大，所以状态稍微改变一下。

设 $dp_{i,j}$ 表示已经选到第 $j$ 个，且甜度为 $i$ 时咸度的最小值。

转移方程为：

$$dp_{j,k}=\min_{0\le k\le i,a_i\le j\le X}(dp_{j,k},dp_{j-a_i,k-1}+b_i)$$

按照 $i,j,k$ 的顺序依次枚举就行，注意 $j$ 要倒序枚举来避免后效性。

统计答案的时候遍历一遍，在所有满足条件的值里面找到最大值即可。

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
const int maxn=1e6+10;
int n,X,Y;
struct no
{
	int x,y;
}a[maxn];
int dp[10010][100],ans=0;
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>X>>Y;
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read();
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=X;j>=a[i].x;j--)
		{
			for(int now=0;now<=i;now++)
			{
				dp[j][now]=min(dp[j-a[i].x][now-1]+a[i].y,dp[j][now]);
				if(dp[j][now]<=Y) ans=max(ans,now);
			}
		}
	}
	cout<<min(ans+1,n);
	return 0;
}

```

看完记得点个赞偶。