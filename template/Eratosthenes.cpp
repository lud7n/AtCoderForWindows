
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