三维前缀和板子。

三维前缀和可以类似二维前缀和来做，先给一下二维前缀和数组的计算方法：
$$sum_{i,j}=a_{i,j}+sum_{i-1,j}+sum_{i,j-1}-sum_{i-1,j-1}$$
同样的，可以写出三维前缀和数组的计算方法：
$$sum_{i,j,k}=a_{i,j,k}+sum_{i,j,k-1}+sum_{i,j-1,k}+sum_{i-1,j,k}-sum_{i,j-1,k-1}-sum_{i-1,j,k-1}-sum_{i-1,j-1,k}+sum_{i-1,j-1,k-1};$$
计算答案的时候把加减号交换一下，其余还是类比二维前缀和即可。

这种高维前缀和（区别一下树状数组区间修改区间查询使用的高维前缀和）完全可以类比二维的来做，思维难度并不高。

### Code

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
const int maxn=3e2+10;
const int mod=1e9+7;
int n,a[maxn][maxn][maxn];
int sum[maxn][maxn][maxn];
int Q;
signed main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				a[i][j][k]=read();
				sum[i][j][k]=a[i][j][k]+sum[i][j][k-1]+sum[i][j-1][k]+sum[i-1][j][k]-sum[i][j-1][k-1]-sum[i-1][j][k-1]-sum[i-1][j-1][k]+sum[i-1][j-1][k-1];
			}
		}
	}
	Q=read();
	while(Q--)
	{
		int lx=read(),rx=read(),ly=read(),ry=read(),lz=read(),rz=read();
		int ans=0;
		ans=sum[rx][ry][rz]-sum[rx][ry][lz-1]-sum[rx][ly-1][rz]-sum[lx-1][ry][rz]+sum[rx][ly-1][lz-1]+sum[lx-1][ry][lz-1]+sum[lx-1][ly-1][rz]-sum[lx-1][ly-1][lz-1];
		printf("%lld\n",ans);
	}
	return 0;
}
```