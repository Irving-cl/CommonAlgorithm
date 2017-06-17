
const int N=10010;
int siz[N],son[N],dep[N],fa[N],w[N],top[N];
int totw=0;

void dfs(int u) {
    siz[u]=1;son[u]=0;
    for (int i=head[u];i!=-1;i=e[i].next) {
        int v=e[i].to;
        if (v!=fa[u]) {
            fa[v]=u;
            dep[v]=dep[u]+1;
            dfs(v);
            if (siz[v]>siz[son[u]]) son[u]=v;
            siz[u]+=siz[v];
        }
    }
}

void build_tree(int u,int tp) {
    w[u]=++totw;top[u]=tp;
    if (son[u]!=0) build_tree(son[u],top[u]);
    for (int i=head[u];i!=-1;i=e[i].next) {
        int v=e[i].to;
        if (v!=son[u]&&v!=fa[u]) {
            build_tree(v,v);
        }
    }
}

int find(int va,int vb) {
    int f1=top[va],f2=top[vb];
    int ans=0;
    while (f1!=f2) {
        if (dep[f1]<dep[f2]) { swap(f1,f2); swap(va,vb); }
        ans=max(ans,query(1,1,totw,w[f1],w[va]));
        va=fa[f1];f1=top[va];
    }
    if (va==vb) return ans;
    if (dep[va]>dep[vb]) swap(va,vb);
    return max(ans,query(1,1,totw,w[son[va]],w[vb]));
}