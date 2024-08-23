## 背景

保佑LC能来一中。

## 题意

给你一个长度为 $n$ 的初始字符串和目标字符串，都由 `W` 和 `B` 两种字符构成。

现在初始字符串末尾接有两个空格字符，每次你可以在该字符串中选出连续两个非空格字符，并把它们按顺序与两个空格交换位置。问最少需要几步能得到目标字符串。

## 分析

首先如果两字符串中 `W` 和 `B` 字符的数量不相等，那么一定无解。

由于 $n\leq 14$，那么算法应该是搜索。因为要求最小步数，所以考虑 BFS 算法。

然后每次选出队头，枚举所有非空格字符，与空格字符交换后扔进队列，再写一个记忆化就能过了。

## Code

```cpp
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
using namespace std;
using namespace  __gnu_pbds;
//gp_hash_table<string,int>mp2;
//__gnu_pbds::priority_queue<int,less<int>,pairing_heap_tag> q;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}
const int mod=998244353;
const int maxn=1e6+10;
int n;
string s,t;
int sw,sb,tw,tb;
struct no
{
	string ss;
	int ans;
};
map<string,bool> mp;
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>s>>t;
	for(int i=1;i<=2;i++)s=s+'.';
	for(int i=1;i<=2;i++)t=t+'.';
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='W')sw++;
		else sb++;
	}
	for(int i=0;i<t.size();i++)
	{
		if(t[i]=='W')tw++;
		else tb++;
	}
	if(sw!=tw||sb!=tb)return 0*printf("-1");
	queue<no>q;
	q.push({s,0});
	mp[s]=1;
	while(!q.empty())
	{
		string ss=q.front().ss;
		int ans=q.front().ans;
		q.pop();
		if(ss==t)
		{
			cout<<ans;
			return 0;
		}
		int tt=0;
		for(int i=0;i<ss.size()-1;i++)
		{
			if(ss[i]=='.'&&ss[i+1]=='.')
			{
				tt=i;
				break;
			}
		}
		for(int i=0;i<ss.size()-1;i++)
		{
			if(ss[i]!='.'&&ss[i+1]!='.')
			{
				swap(ss[i],ss[tt]);
				swap(ss[i+1],ss[tt+1]);
				if(!mp[ss]){mp[ss]=1;q.push({ss,ans+1});}
				swap(ss[i],ss[tt]);
				swap(ss[i+1],ss[tt+1]);
			}
		}
	}
	cout<<-1;
	return 0;
}
```