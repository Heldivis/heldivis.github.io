## 背景

中考结束了，但是暑假只有一天，这就是我现在能在机房里面写题解的原因……

## 分析

这道题就是个单调栈。

题目上问你第一滴水流到每个位置的时间。我们考虑，答案其实就是比当前木板高且距离当前木板最近的那一个位置的答案加上当前木板的高度与那一个位置的距离构成的矩形面积再减去中间较低木板构成的矩形面积。这个思路联想到单调栈的话还是很好想到的。

所以我们存一个结构体栈，两个参数分别表示这个位置木板的高度和与上一个比它高的木板的距离。

在更新的时候，先按照一般单调栈操作用当前木板高度去更新栈的信息，用一个变量统计距离之和，并把每个栈位最终会影响答案的矩形面积累加一下。放一下代码：

```cpp
  while(!st.empty()&&st.top().h<=h[i])
  {
    int now=st.top().h,sum=st.top().sum;
    dat+=now*sum;
    t+=sum;
    st.pop();
  }
```

然后按照思路更新当前答案并输出，再让当前木板高度和距离进栈即可。

## Code

```cpp
#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
inline int read()
{
	int w=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+(ch-'0');ch=getchar();}
	return w*s;
}
const int maxn=1e6+10;
int n,h[maxn];
int ans=1;
struct no
{
	int h,sum;
};
stack<no> st; 
signed main()
{
//  freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<=n;i++)
	{
		int t=1,dat=0;
		while(!st.empty()&&st.top().h<=h[i])
		{
			int now=st.top().h,sum=st.top().sum;
			dat+=now*sum;
			t+=sum;
			st.pop();
		}
		ans=ans+h[i]*t-dat;
		st.push({h[i],t});
		printf("%lld ",ans);
	}
	return 0;
}
```