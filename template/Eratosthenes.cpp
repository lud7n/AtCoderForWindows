
int main() {
    //10e6までの素数を列挙するよ
    vector<ll> prime(1,2);
    vector<bool> pb(10e6+1, true);
    pb[0]=false;
    pb[1]=false;
  
    for(ll i=2; i*2 <= 10e6; i++) pb[i*2] = false;
    
    for(ll i=3; i <= 10e6; i+=2){
      if(pb[i]){
        prime.push_back(i);
        for(ll j=i; i*j <= 10e6; j+=2) pb[i*j] = false;
      }
    }

    rep(i,prime.size()) cout << prime[i] << endl;
}

// // N の約数をすべて求める関数
// vector<long long> calc_divisors(long long N) {
//     // 答えを表す集合
//     vector<long long> res;

//     // 各整数 i が N の約数かどうかを調べる
//     for (long long i = 1; i * i <= N; ++i) {
//         // i が N の約数でない場合はスキップ
//         if (N % i != 0) continue;

//         // i は約数である
//         res.push_back(i);

//         // N ÷ i も約数である (重複に注意)
//         if (N / i != i) res.push_back(N / i);
//     }

//     // 約数を小さい順に並び替えて出力
//     sort(res.begin(), res.end());
//     return res;
// }

// // vector 型を出力する関数 (Python の形式に合わせる)
// void print(const vector<long long> &v) {
//     cout << "[";
//     for (int i = 0; i < v.size(); ++i) {
//         if (i) cout << " ";
//         cout << v[i];
//     }
//     cout << "]" << endl;
// }

// int main() {
//     // 36 の約数
//     print(calc_divisors(36));

//     // 1000000007 の約数
//     print(calc_divisors(1000000007));
// }