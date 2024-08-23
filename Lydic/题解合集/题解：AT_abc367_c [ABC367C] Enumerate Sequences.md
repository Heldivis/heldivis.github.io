## 大致题意

让你按照字典序输出一些长 $n$ 的序列，序列中的数字有范围，且序列和需要为 $k$。

## 分析

直接深搜。搜索的时候对从第一个元素开始，每个元素从小到大枚举所有可能的值，这样就保证答案按照字典序升序排列。

用一个 `vector` 存储序列，到达边界之后计算一遍和，判断是否满足条件，然后直接输出 `vector` 中的元素即可。

按照题目的数据范围完全可以过。

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
int n,k;
int a[maxn];
void dfs(int x,vector<int> ans)
{
	if(x>n)
	{
		int sum=0;
		for(auto i : ans)sum+=i;
		if(sum%k)return ;
		for(auto i : ans)cout<<i<<' ';
		cout<<'\n';
		return ;
	}
	for(int i=1;i<=a[x];i++)
	{
		ans.push_back(i);
		dfs(x+1,ans);
		ans.pop_back();
	}
}
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	vector<int> v;
	dfs(1,v);
	return 0;
}

```