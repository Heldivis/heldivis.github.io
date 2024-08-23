## 背景

前几天打了比赛，崩麻了，所以来水一篇题解。~~LC真睿智~~

## 题意

给你 $n$ 个点，问最多能组成几个三角形。

## 分析

~~听说可以随机化~~。这道题就是一个简单贪心。

我们考虑，如果没有共线的点，那么答案显然就是 $\frac{n}{3}$ 了。

如果有共线，我们容易想到一个贪心思路：既然同一直线上的点不能组成三角形，那么应该尽可能让多的不在这条直线上的点消耗这条直线上的点，即设直线上点的集合为 $C$，那么对于任意 $\{x,y\}\notin C$，让它和 $C$ 中的两个元素组成三角形即可。这种情况下答案显然是 $n-card(C)$，限制条件是直线上的点能够消耗完其余点，即 $\frac{card(C)}{2}> n-card(C) $。

由于 $1\leq n \leq 300 $ 的奇妙范围，直线的寻找可以直接暴力三重循环。对于是否共线的判断，可以用相似来证，具体在代码里面。

然后就可以上代码了。

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
const int maxn=1e6+10;
int n;
struct no
{
	int x,y;
}a[500]; 
int ans=-maxn;//记录最长直线 
bool ch(no x,no y)//判断是否共线 
{
    return x.x*y.y==x.y*y.x;
}
no operator -(no x,no y)
{
    return (no){x.x-y.x,x.y-y.y};
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int sum=2;
			for(int k=1;k<=n;k++)
			{
				if(k==i||k==j)continue;
				if(ch(a[k]-a[i],a[k]-a[j]))sum++;
			}
			ans=max(ans,sum);//更新最大值 
		}
	}
	if(ans/2>n-ans)cout<<n-ans;//直线可以消耗所有点 
	else cout<<n/3;//不能 
	return 0;
}
```