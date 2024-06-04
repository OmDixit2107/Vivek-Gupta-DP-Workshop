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

int queen[20];
int n;

// there are no overlaps so there is no
// meaning of dp here it is a simple
// backtracking problem

int check(int row,int col){
    for (int i = 0; i < row; ++i)
    {
        int prow=i;
        int pcol=queen[i];
        if (pcol==col||abs(col-pcol)==abs(row-prow))
        {
            return 0;
        }
    }
    return 1;
}


int rec(int level)
//rec-->no of ways to populate [level...n-1] rows
{
    if (level==n)
    {
        return 1;
    }
    // compute
    int ans=0;
    // loop over all choices
    for(int col=0;col<n;col++){
        // check if the choice is valid
        if (check(level,col))
        {
            // place queen
            queen[level]=col;
            //explore the option
            ans+=rec(level+1);
            // revert back the queen
            queen[level]=-1;
        }
    }
    return ans;
}


void solve() {
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0)<<endl;
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