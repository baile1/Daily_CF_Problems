#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int MAX32=2147483647;
void solve()
{
    int n,k;
    cin>>n>>k;
    if(k*(k-1)<n)
    {
        cout<<"NO"<<endl;
        return;
    }
    int cnt = 0;
    cout<<"YES"<<endl;
    for(int i=1;i<=k-1;i++)
    {
        if(cnt==n) break;
        for(int j=i+1;j<=k;j++)
        {
            cout<<i<<" "<<j<<endl;
            cnt++;
            if(cnt==n) break;
            cout<<j<<" "<<i<<endl;
            cnt++;
            if(cnt==n) break;
        }
        // if(cnt==n) break;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin>>t;
    t=1;
    while (t--)
    {
        solve();
    }
}
