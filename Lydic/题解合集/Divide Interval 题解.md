## 背景

太逊了，调了三次才调出来，所以写篇题解寄念。~~LC好睿智~~

## 题意 

给你两个数 $a,b$，现在要从 $a$ 跑到 $b$，每次可以将当前的 $a$ 拆分成 $2^n\times m(n,m\in N)$ 的形式，并将它变成 $2^n\times (m+1)$。问最少变几次能跑到 $b$，输出次数和每次变化前后 $a$ 的值。 

## 分析

这道题有一个~~一眼~~贪心。在一次变化后不会超过 $b$ 的情况下，我们要让 $n$ 的值尽可能大来使得 $a$ 变化后更大。所以我们可以写一个函数来先找到 $n$ 最大可以是多少，具体就是看看 $a$ 的因数中最大的 $2$ 的整次幂是多少，下面给出：
```cpp
int p(int x)
{
	int ans=1;
	while(x%ans==0)
	{
		ans=ans<<1;
	}
	if(x%ans)ans/=2;
	return ans;
}
```
然后计算出 $m$，并判断这样拆分后一次变化是否会超过 $b$，如果超过就让 $n>>1$，直到满足条件。因为要先输出变化次数，所以用两个数组记录每次变化前后 $a$ 的值即可。

### 细节

如果 $a$ 的初值为 $0$，我们发现此时 $n$ 可以是任意值，所以我们特判一下，直接找到不大于 $b$ 的最大的 $2$ 的整次幂，让 $a$ 变成它就行了。

## Code
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
int w=1,s=0;char ch=getchar();
while(!isdigit(ch)){if(ch=='-') w=-1;ch=getchar();}
while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
return w*s;
}
const int maxn=6e7+10;
int l,r;
int p(int x)//得出最大因数 
{
	int ans=1;
	while(x%ans==0)
	{
		ans=ans<<1;
	}
	if(x%ans)ans/=2;
	return ans;
}
int lo(int x)//得出最大2的整次幂 
{
	int i;
	for(i=1;i<=x;i*=2);
	if(i>x)i/=2;
	return i;
}
int ansl[maxn],ansr[maxn],tot;//记录答案 
signed main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	cin>>l>>r;
	while(l<r)
	{
		if(l==r)break;
		ansl[++tot]=l;
		if(l==0)//特判 
		{
			int pr=lo(r);
			l=pr;
			ansr[tot]=l;
			continue;
		}
		int p2=p(l);
		int bei=l/p2;//计算n和m 
		while(p2*(bei+1)>r)//向下缩小n 
		{
			p2=p2>>1;
			bei=l/p2;
		}
		l=p2*(bei+1); 
		ansr[tot]=l;
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)
	cout<<ansl[i]<<' '<<ansr[i]<<endl;
	return 0;
}
```