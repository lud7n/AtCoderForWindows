using namespace std;

#include <bits/stdc++.h>

#define ll long long

template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
using vi = vector<int>;
using vl = vector<long long>;
using vd = V<double>;
using vs = V<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;

template <typename T, typename U>
struct P : pair<T, U> {
    template <typename... Args>
    P(Args... args) : pair<T, U>(args...) {}

    using pair<T, U>::first;
    using pair<T, U>::second;

    P &operator+=(const P &r) {
        first += r.first;
        second += r.second;
        return *this;
    }
    P &operator-=(const P &r) {
        first -= r.first;
        second -= r.second;
        return *this;
    }
    P &operator*=(const P &r) {
        first *= r.first;
        second *= r.second;
        return *this;
    }
    template <typename S>
    P &operator*=(const S &r) {
        first *= r, second *= r;
        return *this;
    }
    P operator+(const P &r) const { return P(*this) += r; }
    P operator-(const P &r) const { return P(*this) -= r; }
    P operator*(const P &r) const { return P(*this) *= r; }
    template <typename S>
    P operator*(const S &r) const {
        return P(*this) *= r;
    }
    P operator-() const { return P{-first, -second}; }
};
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
using pl = P<long long, long long>;
using pi = P<int, int>;
using vp = V<pl>;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), v.rend()
#define each(i, v) for (auto i : v)
#define each2(x, y, v) for (auto [x, y] : v)
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N)-1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b)-1; i >= (a); i--)
// #define fi first
// #define se second

#define in(a) cin >> a
#define out2(a, b) cout << a << b
#define out(a) cout << a << "\n"
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
#define pb push_back
    
int main()
{
    ll r, c, sx, sy, gx, gy;
    cin >> r >> c >> sx >> sy >> gx >> gy;
    sy--, sx--, gy--, gx--;
    char a[r][c];
    rep(i, r) rep(j, c) cin >> a[i][j];
    queue<pair<ll,ll>> que;
    queue<int> vec;
    queue<int> q_ans;
    que.push(make_pair(sx, sy));
    vec.push(-1);
    q_ans.push(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dist[1010][1010];

    memset(dist, -1, sizeof(dist));
    dist[sx][sy] = 1;

    ll ans = 0, answer = 10000000000;
    bool ok = false;

    while (!que.empty())
    {
        pair<ll,ll> cur = que.front();
        que.pop();
        ll vector = vec.front();
        vec.pop();
        ans = q_ans.front();
        q_ans.pop();

        int x = cur.first;
        int y = cur.second;

        rep(dir, 4)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx == gx and ny == gy)
            {
                if(dir != vector and vector != -1) ans++;
                answer = min(ans, answer);
            }
            if (nx < 0 or nx >= r or ny < 0 or ny >= c) // 場外
                continue;
            if (a[nx][ny] == '#')
                continue;
            if(dir != vector and vector != -1) ans++;
            if (dist[nx][ny] == -1)
            {
                // cout << nx << " " << ny << endl;
                // ans++;
                dist[nx][ny] = dist[x][y] + 1;
                que.push(make_pair(nx, ny));
                vec.push(dir);
                q_ans.push(ans);
            }
        }
    }

    cout << answer << endl;

    return 0;
}
