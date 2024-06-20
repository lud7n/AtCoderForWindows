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

set<ll> st;

// N の約数をすべて求める関数
void calc_divisors(long long N) {

    // 各整数 i が N の約数かどうかを調べる
    for (long long i = 1; i * i <= N; ++i) {
        // i が N の約数でない場合はスキップ
        if (N % i != 0) continue;

        // i は約数である
        st.insert(i);

        // N ÷ i も約数である (重複に注意)
        if (N / i != i) st.insert(N / i);
    }
}

int main() {
    ll k;
    cin >> k;
    ll ans = 0;

    calc_divisors(k);

    for(auto a = st.begin(); a != st.end(); a++){
        for(auto b = a; b != st.end(); b++){
            ll c = k;
            if((c / (*a)) < (*b)) continue;
            if(c % ((*a) * (*b)) != 0) continue;
            c /= ((*a) * (*b));
            if(*b <= c and st.count(c)) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
