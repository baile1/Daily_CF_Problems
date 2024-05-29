#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int MAX32=2147483647;
void solve()
{
    int n;
    cin>>n;
    vector<int> p(n+10);
    vector<int> mp(n+10);
    vector<int> mp2(n+10);
    int xh1,xh2;
    for(int i=1;i<=n;i++) cin>>p[i],mp[p[i]] = i,mp2[i] = p[i];
    vector<PII> ans;
    for(int i=2;i<=n-1;i++)
    {
        if(mp[i]<=n/2)
        {
            xh1 = mp[i];
            xh2 = mp[mp2[n]];
            ans.push_back({xh1,xh2});
            swap(mp[i],mp[mp2[n]]);
            swap(mp2[xh1],mp2[xh2]);
            if(i<=n/2)
            {
                xh1 = mp[i];
                xh2 = mp[mp2[i]];
                ans.push_back({xh1,xh2});
                swap(mp[mp2[i]],mp[i]);
                swap(mp2[xh1],mp2[xh2]);
            }
            else
            {
                xh1 = mp[i];
                xh2 = mp[mp2[1]];
                ans.push_back({xh1,xh2});
                swap(mp[i],mp[mp2[1]]);
                swap(mp2[xh1],mp2[xh2]);
                xh1 = mp[i];
                xh2 = mp[mp2[i]];
                ans.push_back({xh1,xh2});
                swap(mp[mp2[i]],mp[i]);
                swap(mp2[xh1],mp2[xh2]);
            }
        }
        else
        {
            xh1 = mp[i];
            xh2 = mp[mp2[1]];
            ans.push_back({xh1,xh2});
            swap(mp[i],mp[mp2[1]]);
            swap(mp2[xh1],mp2[xh2]);
            if(i>n/2)
            {
                xh1 = mp[i];
                xh2 = mp[mp2[i]];
                ans.push_back({xh1,xh2});
                swap(mp[mp2[i]],mp[i]);
                swap(mp2[xh1],mp2[xh2]);
            }
            else
            {
                xh1 = mp[i];
                xh2 = mp[mp2[n]];
                ans.push_back({xh1,xh2});
                swap(mp[i],mp[mp2[n]]);
                swap(mp2[xh1],mp2[xh2]);
                xh1 = mp[i];
                xh2 = mp[mp2[i]];
                ans.push_back({xh1,xh2});
                swap(mp[mp2[i]],mp[i]);
                swap(mp2[xh1],mp2[xh2]);
            }
        }
    }
    if(mp[1]!=1&&mp[n]!=n)
        ans.push_back({1,n});
    cout<<ans.size()<<endl;
    for(auto& [x,y]:ans)
    {
        cout<<x<<" "<<y<<endl;
    }
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
