const int N=505;
const int M=505;

struct edge {
    int to,next,flow;
} e[200010];
int head[N+M];
int tot;
int gap[N+M],dis[N+M];
int source,sink;

void add_edge(int u,int v,int f) {
    e[tot].to=v;
    e[tot].flow=f;
    e[tot].next=head[u];
    head[u]=tot++;
}

int dfs(int u,int flow) {
    if (u==sink) return flow;
    int rem=flow;
    int cand=sink;
    for (int i=head[u];i!=-1;i=e[i].next) {
        int v=e[i].to;
        int j=i^1;
        if (e[i].flow>0&&dis[u]==dis[v]+1) {
            int tmp=dfs(v,min(rem,e[i].flow));
            e[i].flow-=tmp;
            e[j].flow+=tmp;
            rem-=tmp;
            if (rem==0||dis[source]==sink+1) return flow-rem;
        }
        if (e[i].flow>0&&dis[v]<cand) cand=dis[v];
    }
    if (rem==flow) {
        gap[dis[u]]--;
        if (gap[dis[u]]==0) {
            dis[source]=sink+1;
        } else {
            dis[u]=cand+1;
            gap[dis[u]]++;
        }
    }
    return flow-rem;
}

void solve() {
	int mxflow=0;
    while (dis[source]<sink+1) mxflow+=dfs(source,INF);
}
