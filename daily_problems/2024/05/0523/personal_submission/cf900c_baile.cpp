#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int MAX32=2147483647;
const int N = 1e5+10;
int tr[N];
int n;
bool cmp(PII a,PII b)
{
    if(a.first!=b.first)
        return a.first>b.first;
    else return a.second<b.second;
}
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tr[i]+=v;
}
int query(int x)
{
    int sum = 0;
    for(int i=x;i>0;i-=lowbit(i))
        sum+=tr[i];
    return sum;
}
void solve()
{
    cin>>n;
    vector<int> p(n+10);
    vector<int> mmp(n+10);
    vector<int> mp(n+10);
    vector<int> mmax(n+10);
    bool pd = false;
    for(int i=1;i<=n;i++) cin>>p[i],mmp[p[i]] = i;
    mp[p[1]] = -1;
    for(int i=1;i<=n;i++)
    {
        if(query(n) - query(p[i]-1)==1)
        {
            mp[mmax[i-1]]++;
        }
        add(p[i],1);
        mmax[i] = max(mmax[i-1],p[i]);
        if(mmax[i-1] < p[i])
            mp[mmax[i]] = -1;
    }
    vector<PII> ans;
    for(int i=1;i<=n;i++)
    {
        ans.push_back({mp[i],i});
        pd = true;
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans.begin()->second<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        solve();
    }
}
