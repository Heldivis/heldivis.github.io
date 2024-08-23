最近一直掉分，谔谔。

## 分析

发现机房里面除了我以外都用递归写的，那我就来讲一种非递归的吧。

考虑第 $i$ 级地毯拆成九块以后其实就是八块第 $i-1$ 级地毯与一块大小为 $3^{i-1}\times 3^{i-1}$ 大小的白色地毯。所以用一个三维数组记录每一级地毯的状态，然后循环往上跑，每一级地毯用上一级地毯来更新，就结束了。

代码虽然有点长，但是基本都是复制粘贴的操作写完的，很好懂。

## Code

```cpp
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int read()
{
int w=1,s=0;char ch=getchar();
while(!isdigit(ch)){if(ch=='-') w=-1;ch=getchar();}
while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
return w*s;
}
const int maxn=1e6+10;
int n;
int a[10][4000][4000];
void work(int x)
{
	for(int k=0;k<3;k++)
	{
		for(int i=1;i<=pow(3,x-1);i++)
		{
			for(int j=1;j<=pow(3,x-1);j++)
			{
				a[x][i][k*(int)pow(3,x-1)+j]=a[x-1][i][j];
			}
		}
	}
	for(int i=1;i<=pow(3,x-1);i++)
		{
			for(int j=1;j<=pow(3,x-1);j++)
			{
				a[x][(int)pow(3,x-1)+i][j]=a[x-1][i][j];
			}
		}
	for(int i=1;i<=pow(3,x-1);i++)
		{
			for(int j=1;j<=pow(3,x-1);j++)
			{
				a[x][(int)pow(3,x-1)+i][(int)pow(3,x-1)+j]=0;
			}
		}
	for(int i=1;i<=pow(3,x-1);i++)
		{
			for(int j=1;j<=pow(3,x-1);j++)
			{
				a[x][(int)pow(3,x-1)+i][2*(int)pow(3,x-1)+j]=a[x-1][i][j];
			}
		}
	for(int k=0;k<3;k++)
	{
		for(int i=1;i<=pow(3,x-1);i++)
		{
			for(int j=1;j<=pow(3,x-1);j++)
			{
				a[x][2*(int)pow(3,x-1)+i][k*(int)pow(3,x-1)+j]=a[x-1][i][j];
			}
		}
	}
}
signed main()
{
	cin>>n;
	a[0][1][1]=1;
	for(int i=1;i<=n;i++)
	{
		work(i);
	}
//	cout<<a[1][2][2];
	for(int i=1;i<=pow(3,n);i++)
	{
		for(int j=1;j<=pow(3,n);j++)
		{
			cout<<(a[n][i][j]==0?'.':'#');
		}
		cout<<endl;
	}
	return 0;
}


```