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

int n;
int t[1001];
int s[1001];
int x,k;
int taken[1001];

// if we can have a track on what if we have done
// previously then i can optimise the code more
// and more

bool check(int level){
    int timetaken=0;
    int leveltaken=0;
    for (int i = 0; i <= level; ++i)
    {
        if (taken[i])
        {
            itemtaken+=t[i];
            leveltaken++;
        }
    }
    if (timetaken<=x&&itemtaken<=k)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


int rec(int level)
//mxm skill i can make from [level...n-1] 
{
    if (level==n)
    {
        return 0;
    }
    // choice 1 : don't take
    int ans=rec(level+1);
    // choice 2 : take
    if (check(level))
    {
        // placing the change
        taken[level]=1;
        //move
        ans+=max(ans,s[level]+rec[level+1]);
        //revert
        taken[leve]=0;
    }
    return ans;
}


void solve() {
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>t[i]>>s[i];
    }
    cin>>x>>s;
    cout<<rec[0]<<endl;
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