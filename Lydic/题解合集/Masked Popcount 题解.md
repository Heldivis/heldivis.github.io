## 背景

罚了一发，太菜了。~~为什么我终于有时间的时候她要考试？~~

## 题意

给你 $n,m$，问 $\sum_{i=0}^{n}popcount(i \&m)$。

其中 $\&$ 代表位运算，$popcount$ 代表一个数字二进制下 $1$ 的个数。

## 分析

两个数字在二进制下根据数据范围有 $60$ 位。所以我们考虑每一位对答案的贡献。

先把 $m$ 变成二进制存到数组里面，根据题意能产生贡献的数位只能是 $1$。那么题目就变成了 $0\sim n$ 中有多少个数字的指定数位为 $1$。

我们可以先看一下：

```
000
001
010
011
100
101
110
111
```

容易得到规律：数位 $i$ 从小到大中 $0$ 和 $1$ 按照长度为 $2^i$ 循环节交替出现，并且每个循环节中 $1$ 出现次数为 $2^{i-1}$。

因此可以得到算法：计算 $n$ 中出现了几次循环节，并把多余的部分判断是否大于该数位循环节长度的一半，如果是，加上剩余值与一半的差即可。

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
int mod=998244353;
int n,m;
int ans=0;
int cntm[maxn],totm;
void pre(int x)
{
	while(x)
	{
		int t=x%2;
		if(t)cntm[++totm]=1;
		else cntm[++totm]=0;
		x>>=1;
	}
}
signed main()
{
//  freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>m;
	if(n==0||m==0)return 0*printf("0");
	pre(m);
	for(int i=1;i<=totm;i++)
	{
		if(!cntm[i])continue;
		int qw=pow(2,i-1),xun=pow(2,i);
		ans=(ans+qw*((n+1)/xun))%mod;
		int nn=(n+1)%xun;
		if(nn>xun/2)ans=(ans+nn-xun/2)%mod;
	}
	cout<<ans%mod;
	return 0;
}
```

完结撒花