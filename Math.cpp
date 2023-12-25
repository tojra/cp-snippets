#define MOD 998244353

// binary exponentiation
ll binexp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// modulo arithmetic
auto add = [](ll a, ll b){
    a%=MOD;b%=MOD;a=(a+b)%MOD;return (a+MOD)%MOD;
};
auto mul = [](ll a, ll b){
    a%=MOD;b%=MOD;a=(a*b)%MOD;return (a+MOD)%MOD;
};


// factorials & inverses
ll fact[MAXN], invfact[MAXN];
auto inv = [&](ll x){return binexp(x, MOD-2, MOD);};

fact[0]=invfact[0]=1;
for(int i=1;i<MAXN;i++){
    fact[i] = (fact[i-1]*i)%MOD;
    invfact[i] = inv(fact[i]);
}

// combinatorics
auto nCr = [&](ll n,ll r){
    if(n<0 || r<0 || n<r)return 0LL;
    return mul(mul(fact[n], invfact[r]), invfact[n-r]);
};
