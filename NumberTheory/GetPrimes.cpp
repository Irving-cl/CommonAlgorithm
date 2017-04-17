
const int N=500010;

bool p[N];
int primes[N],tot=0;

void get_primes() {
    for (int i=2;i<=N;i++) {
        if (!p[i]) {
            primes[tot++]=i;
        }
        for (int j=0;j<tot&&i*primes[j]<N;j++) {
             p[i*primes[j]]=true;
             if (i%primes[j]==0) break;
        }
    }
}