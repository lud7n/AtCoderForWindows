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

ll n,s,t;
vector<P> points;
vector<P> segments[6];
double dist[13][13];
double dp[64][13]; // 6状あれば足りる？

//移動時間計算関数
double time(P a, P b) {
  //斜辺を返すらしい
    return hypot(a.first - b.first, a.second - b.second);
}

int main() {
  cin >> n >> s >> t;
  points.emplace_back(0,0);

  rep(i,n){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    segments[i] = {{a,b},{c,d}};
    //短点をぶち込む
    points.push_back(segments[i][0]);
    points.push_back(segments[i][1]);
  }

  //巡回セールスマン問題
  ll m = points.size();

  rep(i,m){
    rep(j,m){
      //全探索で距離をわりだす
      if(i == j){
        dist[i][j] = 0;
      }else{
        //レーザー照射してないときのじかん
        //i番目の点からj番目への時間
        dist[i][j] = time(points[i], points[j]) / s;
      }
    }
  }

  rep(i,n){
    //全部の線分についてかかる時間
    double length = time(segments[i][0], segments[i][1]);
    //短点の添え字は(2*i+1, 2*i+2)、無向
    dist[2*i+1][2*i+2] = length / t;
    dist[2*i+2][2*i+1] = dist[2*i+1][2*i+2];
  }

  //DP

  rep(i, 1<<n){ //2のn乗
    rep(j,m){
      dp[i][j] = LINF;
      //状態iで、点jにいるときの最小時間を目盛っていく
    }
  }

  dp[0][0] = 0;

  rep(i, 1<<n){
    //印字したor印字していないの全部試す
    rep(j,m){
      //全部の点ぶちこみ
      if(dp[i][j] >= LINF) continue;
      rep(k,n){
        //印字してないやつ全部
        if(i >> k & 1){
          //既に印字されている
          continue;
        }
        ll x = 2*k+1;
        ll y = 2*k+2;
        //新しいコスト
        //i または2のk乗の真偽
        dp[i | 1 << k][y] = min(dp[i | 1 << k][y], dp[i][j] + dist[j][x] + dist[x][y]);
        dp[i | 1 << k][x] = min(dp[i | 1 << k][x], dp[i][j] + dist[j][y] + dist[y][x]);

      }
    }
  }

  double ans = LINF;
  rep(i,m){
    ans = min(ans, dp[(1 << n) - 1][i]);
  }

  cout << fixed << setprecision(20) << ans << endl;


    
    return 0;
}

// int main(){
//   cin >> n >> s >> t;
//   points.emplace_back(0,0);

//   rep(i,n){
//     ll a,b,c,d;
//     cin >> a >> b >> c >> d;
//     segments[i] = {{a,b},{c,d}};
//     //短点をぶち込む
//     points.push_back(segments[i][0]);
//     points.push_back(segments[i][1]);
//   }

//   //巡回セールスマン問題
//   ll m = points.size();

//   rep(i,m){
//     rep(j,m){
//       //全探索で距離をわりだす
//       if(i == j){
//         dist[i][j] = 0;
//       }else{
//         //レーザー照射してないときのじかん
//         //i番目の点からj番目への時間
//         dist[i][j] = time(points[i], points[j]) / s;
//       }
//     }
//   }
// }

//巡回セールス問題
// int main() {
//     int n;
//     cin >> n;
//     vvl a(n, vl(n));
//     rep(i,0,n) rep(j,0,n) cin >> a[i][j];
//     int n2 = 1<<n;
//     vvl dp(n2, vl(n, LINF));
//     rep(i,0,n) {
//         dp[1<<i][i] = a[0][i];
//     }
//     rep(i,0,n2) rep(j,0,n) {
//         if (~i>>j&1) continue;
//         rep(k,0,n) {
//             if (i>>k&1) continue;
//             chmin(dp[i|1<<k][k], dp[i][j]+a[j][k]);
//         }
//     }
//     cout << dp[n2-1][0] << endl;
// }