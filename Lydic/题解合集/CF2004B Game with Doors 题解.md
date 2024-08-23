## 题意

给你两个区间，现在可以封锁一些边，问使得两区间中任意两点都不能互相到达所需的最小封锁数。

## 分析

分点情况。

首先如果两区间不交，那么封锁一个即可。

否则，我们发现剩下的情况其实可以统一考虑，因为我们终究要封锁的是两区间的并集。

求出两区间中较小的 $r$ 和较大的 $l$，根据题意容易得出一般情况的答案为 $r-l+2$，但是考虑如果两个 $l$ 相等，那我无需封锁 $l-1$ 和 $l$，$r$ 同理。所以这时候特判并且略改答案即可。

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
void Main()
{
	int l1=read(),r1=read();
	int l2=read(),r2=read();
	if(l1>l2){swap(l1,l2);}
	if(r1>r2){swap(r1,r2);}
	if(r1<l2)return puts("1"),void();
	int ans=r1-l2;
	if(l1!=l2)ans++;
	if(r1!=r2)ans++;
	cout<<ans<<endl;
}
signed main()
{
	int T=read();
	while(T--)Main();
	return 0;
}
```
点个赞吧。