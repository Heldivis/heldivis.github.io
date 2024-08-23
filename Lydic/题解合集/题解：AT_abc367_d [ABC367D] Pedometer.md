首先肯定要单层循环枚举元素，然后想方法求出一个元素的所有答案。

一开始我写了一个二分找 $m$ 倍数的方法，发现 $m$ 小的时候还不如暴力。

于是联想到之前做过的一道题，可以借助于取模的前缀和数组。

对于当前元素 $i$，如果一个元素之前的前缀和与 $i$ 之前的前缀和对 $m$ 取余后相同，那么说明中间的所有元素的和一定是 $m$ 的倍数。

有了这个思路，我们可以着手想代码了。首先二倍数组断环成链，然后计算前缀和数组 $sum$。用一个 $cnt$ 数组记录前缀和对 $m$ 取模后的值为一定值的个数。

在枚举 $i$ 的时候，我们可以从 $n+1$ 枚举到 $2n$。该元素对答案的贡献显然就是 $cnt_{sum_i\mod m}$。但需要注意的是，计算过 $i$ 的贡献之后，$i$ 就不能对以后的答案产生新贡献了，同时为保证找到的数字距离 $i$ 不超过 $n$，我们对 $cnt$ 数组进行更新，具体的，我们让 $cnt_{sum_{i-n+1}\mod m}--$ 和 $cnt_{sum_{i}\mod m}++$。这样使得 $cnt$ 一直表示的是 $i-n+1$ 到 $i$ 之间的结果。

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
const int maxn=1e6+10;
const int mod=1e9+7;
int n,m;
int a[maxn];
int sum[maxn],ans=0;
map<int,int> cnt;
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		a[i+n]=a[i];
	}
	for(int i=1;i<=n*2;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		cnt[sum[i]%m]++;
	}
	for(int i=n+1;i<=2*n;i++)
	{
		ans+=cnt[sum[i]%m];
		cnt[sum[i-n+1]%m]--;
		cnt[sum[i]%m]++;
	}
	cout<<ans;
	return 0;
}
```