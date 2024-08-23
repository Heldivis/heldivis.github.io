## 背景

去中考了，比赛没打，来补一下题。

## 分析

这道题让我想起了[这道题](https://www.luogu.com.cn/problem/AT_abc353_f)（连题目名称都是连着的），不过显然要简单一些。

这道题显然要推一些式子。我们发现，和上面提到的那道题目一样，沿着对角线走台阶，纵坐标走到以后再走横坐标显然是最优策略。这时候的答案就是横纵坐标差的和的一半（这就不用证明了）。有一个细节就是当起点和终点在它所处的砖块中位置不同时，式子不成立，这时候应该改变一下，我这里把它们都变到了它所处砖块的左边，这样是不影响答案的。放一下代码：

```cpp
   int x=abs(ex-sx),y=abs(ey-sy);
	if(x%2==0&&y%2==1||x%2==1&&y%2==0)
	{
		if((sx+sy)%2==1)sx--;
		else ex--;
	}
```

但是当起点和终点横坐标差值小于纵坐标差值时，因为按照这个策略要往回走，所以显然要换方法。

多推几个样例可以发现，这种情况的答案就是纵坐标的差。我们来分析一下。（用了样例解释的图）

![](https://img.atcoder.jp/abc359/187d19c48a9a0fcedb2602063689ee77.png)

容易看出，这其实就是上面策略加上几个垂直上升的走法。这时候横坐标可以理解为是在纵坐标转移的时候顺带转移的，所以方法显然正确。

然后就做完了。

## Code

```cpp
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include<atcoder/modint>
#define int long long
#define mod 998244353
using namespace std;
using namespace  __gnu_pbds;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}
const int maxn=1e6+10;
int sx,sy,ex,ey;
signed main()
{
//  freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>sx>>sy>>ex>>ey;
	int x=abs(ex-sx),y=abs(ey-sy);
	if(x%2==0&&y%2==1||x%2==1&&y%2==0)
	{
		if((sx+sy)%2==1)sx--;
		else ex--;
	}
	x=abs(ex-sx),y=abs(ey-sy);
	if(x<=y)cout<<y;
	else cout<<(x+y)/2;
	return 0;
}

```