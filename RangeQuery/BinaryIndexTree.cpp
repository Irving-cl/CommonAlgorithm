
// Binary Index Tree
// 1-based index
int n;
int a[10005];
int bit[10005];

void init() {
    for (int i=1;i<=n;i++) bit[i]=a[i];
    int gap=2;
    while (gap<=n) {
        for (int i=gap;i<=n;i+=gap) bit[i]+=bit[i-gap/2];
        gap*=2;
    }
}

int sum(int x) {
    int ret=0;
    while (x) {
        ret+=bit[x];
        x&=(x-1);
    }
    return ret;
}

int query(int l,int r) {
    return sum(r)-sum(l-1);
}

// Another version
inline int f(int x) { return x & -x; }
inline void add(int x) { for (int i = x; i < N; i += f (i)) c[i]++; }
inline void clear(int x) { for (int i = x; i < N; i += f (i)) c[i] = 0; }
inline int qry(int x) { int r = 0; for (int i = x; i; i -= f (i)) r += c[i]; return r; }

// Class version
class BIT
{
public:
    BIT(int n):N(n),c(vector<int>(n)){}
    int f (int x) { return x & -x; }
    void add (int x) { for (int i = x; i < N; i += f (i)) c[i]++; }
    void clear (int x) { for (int i = x; i < N; i += f (i)) c[i] = 0; }
    int qry (int x) { int r = 0; for (int i = x; i; i -= f (i)) r += c[i]; return r; }    
private:
    vector<int> c;
    int N;
};
