using namespace std;

#include <bits/stdc++.h>

#define ll long long

using vl = vector<long long>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using P = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), v.rend()
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)

#define in(a) cin >> a
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
#define pb push_back

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n,x;
    cin >> n >> x;
    vl a(n), p(n), b(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll hikaru, seiya;//?

    rep(i,n){
      ll hikakin = p[i], seikin = q[i];
      hikaru = min(hikakin, p[i]);
      seiya = min(seikin, q[i]);
    }

    if(min(hikaru,seiya) > x){
      cout << 0 << endl;
      return 0;
    }
    
    //にぶたん？？？？

    ll left = 0, right = LINF;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        
        ll sum = 0;
        bool ok = true;
        rep(i,n){
            if (mid == 0) {
                continue;
            }
            ll ss = (mid + a[i] - 1) / a[i];
            ll tt = (mid + b[i] - 1) / b[i];
            ll s_cost = ss * p[i];
            ll t_cost = tt * q[i];
            sum += min(s_cost, t_cost);
            if (sum > x) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

    return 0;
}