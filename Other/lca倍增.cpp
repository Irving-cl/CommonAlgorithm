const int maxl=17;
int grand[N][maxl];
ll mn[N][maxl];
int len;
int depth[N];

void dfs(int x) {
    for (int i=1;i<=len;i++) {
        grand[x][i]=grand[grand[x][i-1]][i-1];
        mn[x][i]=min(mn[x][i-1],mn[grand[x][i-1]][i-1]);
        if (grand[x][i]==0) break;
    }
    for (int i=head[x];i;i=e[i].next) {
        if (safe[i]&&e[i].to!=grand[x][0]) {
            int y=e[i].to;
            grand[y][0]=x;
            mn[y][0]=e[i].val;
            depth[y]=depth[x]+1;
            dfs(y);
        }
    }
}

void init() {
    len=floor(log(N+0.0)/log(2.0));
    depth[0]=-1;depth[1]=0;
    dfs(1);
}

ll lca() {
    if (depth[x]>depth[y]) swap(x,y);
    ll ret=1e17;
    for (int i=len;i>=0;i--) {
        if (depth[x]<depth[y]&&depth[x]<=depth[grand[y][i]]) {
            ret=min(ret,mn[y][i]);
            y=grand[y][i];
        }
    }
    for (int i=len;i>=0;i--) {
        if (grand[x][i]!=grand[y][i]) {
            ret=min(ret,mn[x][i]);
            ret=min(ret,mn[y][i]);
            x=grand[x][i];
            y=grand[y][i];
        }
    }
    if (x!=y) {
        ret=min(ret,mn[x][0]);
        ret=min(ret,mn[y][0]);
    }
    return ret;
}