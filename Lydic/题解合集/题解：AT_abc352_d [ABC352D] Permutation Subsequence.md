虽然比赛没打，但是想来~~水估值~~发表思路。

## 题意

给你一个 $1\sim n$ 的排列，让你从中找一段长为 $k$ 的子序列，使得这个子序列中的元素排序后数值连续。

## 分析

题意转换一下，先用结构体存储每个元素的编号和数值，按照数值排序。

于是这道题就成了：一个序列，让你求所有长 $k$ 的子段中每个段编号极差的最小值。

所以我们需要维护每个段编号最大最小值，我选择了 ST 表。

其他做法维护也有很多，这里就不讲了。

## code

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
int n,k;
struct no
{
	int d,id;
}a[maxn];
bool cmp(no x,no y)
{
	return x.d<y.d;
}
int ma[maxn][22],mi[maxn][22];
void pre()
{
	for(int j=1;j<=20;j++){
     	for(int i=1;i+(1<<j)-1<=n;i++)
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
	}
    for(int j=1;j<=20;j++){
     	for(int i=1;i+(1<<j)-1<=n;i++)
      		ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
	}
	
}
int askmax(int l,int r)
{
	int le=l,ri=r;
        int len=log2(ri-le+1);
        return max(ma[le][len],ma[ri-(1<<len)+1][len]);
}
int askmin(int l,int r)
{
	int le=l,ri=r;
        int len=log2(ri-le+1);
		return min(mi[le][len],mi[ri-(1<<len)+1][len]);
}
signed main()
{
//  freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i].d=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);	
	for(int i=1;i<=n;i++)swap(a[i].d,a[i].id);
	for(int i=1;i<=n;i++)mi[i][0]=ma[i][0]=a[i].d;
	pre();
	int ans=1e9+7;
	for(int l=1;l<=n-k+1;l++)
	{
		int r=l+k-1;
		ans=min(ans,askmax(l,r)-askmin(l,r));
	}
	cout<<ans;
	return 0;
}

```