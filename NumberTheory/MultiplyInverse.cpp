
const int N=200000;

ll f[N+10],finv[N+10];

ll c(ll n,ll m) {
    ll ret=f[n];
    ret=(ret*finv[n-m])%MOD;
    ret=(ret*finv[m])%MOD;
    return ret;
}

ll qp(ll x,ll n) {
    ll ret=1;
    while (n) {
        if (n&1) ret=(ret*x)%MOD;
        n=n>>1;
        x=(x*x)%MOD;
    }
    return ret;
}

void init() {
    f[0]=finv[0]=1;
    for (int i=1;i<=N;i++) {
        f[i]=(f[i-1]*i)%MOD;
        finv[i]=qp(f[i],MOD-2);
    }
}
