## 背景

把人家鸽了，感觉废了。

## 分析

这道题刚看到题目的时候很多人会想爆搜，但是因为 $10^3$ 的数据范围，所以应该去想一想是不是有什么性质。

我们稍微想一想就会发现，题目上提到了可以重复走，那么对于一般情况（就是有由不同字母构成的联通块）而言，直接找到两个字典序最大的字母，然后一直在它们之间兜圈子不就可以了？

考虑字典序是按照字母顺序一个一个排的，所以容易证明这个思路是正确的。

所以得到初步思路，枚举所有非 `#` 方格，然后找到字典序最大的方格，并对每个字典序最大的方格找到其四个角对应的最大字符，那么答案就是依次输出这两个字符。

考虑一点细节。当只有一种合法字符或只有一个合法字符时，因为要输出最小循环节，所以特判一下并只输出一个字符即可。

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
//const int mod=10000007;
const int maxn=1e6+10;
int n,m;
char c[3000][3000];
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
signed main()
{
//	freopen("list.in","r",stdin);
//	freopen("list.out","w",stdout);
	cin>>n>>m;
	char ma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]!='#')
			ma=max(ma,c[i][j]);
		}
		c[i][0]=c[i][m+1]='#';
	}
	for(int i=1;i<=m;i++)c[0][i]=c[n+1][i]='#';
	char cma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]==ma)
			{
				for(int k=0;k<4;k++)
				{
					int ii=i+dx[k],jj=j+dy[k];
					if(c[ii][jj]!='#')
					{
						cma=max(cma,c[ii][jj]);
					}
				}
			}
		}
	}
	if(cma==0||cma==ma)cout<<ma;
	else cout<<ma<<cma;
	return 0;
}
```