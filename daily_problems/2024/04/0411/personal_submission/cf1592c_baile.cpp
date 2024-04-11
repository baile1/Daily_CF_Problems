#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10,M = 4e5+10;
int e[M],ne[M],h[N],idx;
bool st[N];
int ans;
int cnt = 0;
void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int dfs(int u,vector<int> &a) 
{
//	cout<<"u="<<u<<endl;
	st[u] = true;
	int gg = a[u];
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			int tt = dfs(j,a);
			if(tt==ans) tt = 0,cnt++;
			gg^=tt;
		}
	}
	return gg;
}
void solve()
{
	idx = 0;
	cnt = 0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) h[i] = -1,st[i] = false; 
	vector<int> a(n+10);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}

	ans = a[1];
	for(int i=2;i<=n;i++) ans ^= a[i];
	
//	cout<<"ans="<<ans<<endl;
	if(ans==0) cout<<"YES"<<endl;
	else
	{
		int gg = dfs(1,a);
//		cout<<"gg="<<gg<<" cnt="<<cnt<<endl;
		if(((gg==ans&&cnt+1>=3)||(gg==0&&cnt>=3))&&k>=3) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
