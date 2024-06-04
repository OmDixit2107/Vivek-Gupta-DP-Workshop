#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mod2 998244353   
#define ff first
#define ss second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define  MAXI(a) *max_element(all(a))
#define  MINI(a) *min_element(all(a))
#define  read(a) for(auto &it:a) cin>>it;
#define  print(a) for(auto i:a) cout<<i<<" "; cout<<endl;
#define vl vector<ll>
ll modexp(ll a,ll b,ll m){ll ans=1;while(b>0){if(b&1){ans=(ans*1LL*a)%m;}a=(a*1LL*a)%m;b>>=1;}return ans;}
ll mult_mod(ll x, ll y) { return ((x % mod) * (y % mod)) % mod;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll msb(ll x){for (int i = 31; i>=0; --i){if (((x>>i)&1)){return i;}}return 0;}

// int rec(int level){
//     for(all choices){
//         check(valid choice){
//             move(choice)
//         }
//     }
// }
int n;
int rec(int level)
int dp[100001];
//ret-no of way to N if we are
// at level
//level--> stair at i am 
{
    // pruning
    if (level>n)
    {
        return 0;
    }
    if (dp[level]!=-1)
    {
        return dp[level];
    }
    // base case
    if (level==n)
    {
        return 1;
    }
    // whenever you have a 
// counting problem u mostly
// return 0 or 1 
    int ans=0;
    for(int step=1;step<=3;step++){
        if (level+step<=n)
        {
            // check-->valid
            int ways=rec(level+step);
            ans+= ways;
        }
    }
    dp[level]=ans;
    return ans;
}


void solve() {
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0);
}

int main() {
   fastio();
   int t;
   // cin >> t;
   t=1;
   while(t--){
      solve();      
   }
   return 0;
}   