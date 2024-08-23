## 题意

给你一个可重集，要求支持插入，删除，元素种类查询三种操作。

## 分析

直接乱搞，用一个桶记录每种数字的出现次数，再用一个变量 $sum$ 记录元素种类数。

插入的时候看看当前该元素出现次数是否为 $1$，删除的时候看看当前元素出现次数是否为 $0$，如果是的话让 $sum$ 相应加减即可。

查询的时候直接输出 $sum$。

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
int Q;
int cnt[maxn],ans;
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>Q;
	while(Q--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read();
			cnt[x]++;
			if(cnt[x]==1)
			{
				ans++;
			}
		}
		else if(opt==2)
		{
			int x=read();
			cnt[x]--;
			if(cnt[x]==0)
			{
				ans--;
			}
		}
		else printf("%lld\n",ans);
	}
	return 0;
}

```