
// RMQ, Single Entry Modify
const int N=1<<18;
int s[2*N];

int query(int x,int l,int r,int lq,int rq) {
    if (lq<=l&&r<=rq) return s[x];
    if (r<=lq||rq<=l) return 0;
    int m=(l+r)>>1;
    return max(query(2*x,l,m,lq,rq),query(2*x+1,m,r,lq,rq));
}

void upd(int x,int l,int r,int pos,int val) {
    if (r-l<2) {
        s[x]=val;
        return;
    }
    s[x]=max(s[x],val);
    int m=(l+r)>>1;
    if (pos<=m) upd(2*x,l,m,pos,val);
    else upd(2*x+1,m,r,pos,val);
}