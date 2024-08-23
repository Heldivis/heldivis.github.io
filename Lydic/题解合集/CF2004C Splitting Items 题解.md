## 题意

两个人玩游戏，轮流从序列 $a$ 中取数字，和大的获胜，所有人都按照最优策略行动。

现在一个人可以增加一些数字的值，需要保证总增加数不超过一个给定的 $k$。问另一个人的分数减去这个人分数的最小值。

## 分析

先从大到小排序，贪心地想如何修改最优。

首先，因为先手是另一个人，所以疯狂改一个数字肯定不优，所以想到平均地修改数字。

在当前序列中，我们找到这个人该选择的所有数字，根据刚才的策略，我们要尽可能不改变原序列中数字的相对大小关系，可以修改 $a_i$ 为 $a_{i-1}$。

为什么这样最优呢？因为这样修改完以后无论再修改哪个数字都一定会使答案更劣，所以这样修改保证了考虑到所有使答案更优的方法。

一点小细节，中途如果 $k$ 不够了，直接 $a_i+=k$ 然后跳出即可。

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
const int inf=1e17;
const double eps=1e-10;
int n,k,a[maxn];
void Main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=2;i<=n;i+=2)
	{
		int delta=a[i-1]-a[i];
		if(delta<=k)
		{
			a[i]=a[i-1];
			k-=delta;
		}
		else
		{
			a[i]+=k;
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i+=2)ans=ans+a[i];
	for(int i=2;i<=n;i+=2)ans=ans-a[i];
	cout<<ans<<endl;
}
signed main()
{
	int T=read();
	while(T--)Main();
	return 0;
}
```