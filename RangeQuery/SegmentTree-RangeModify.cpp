
// Range Sum, Range Modify
const int N=1<<17;
int s[N*2],t[N*2];

void push(int x,int l,int r) {
    int m=(l+r)>>1;
    s[2*x]=(m-l)*t[x];
    s[2*x+1]=(r-m)*t[x];
    t[2*x]=t[x];
    t[2*x+1]=t[x];
    t[x]=0;
}

int sum(int x,int l,int r,int lq,int rq) {
    if (lq<=l&&r<=rq) return s[x];
    if (rq<=l||r<=lq) return 0;
    if (t[x]>0) push(x,l,r);
    int m=(l+r)>>1;
    return sum(2*x,l,m,lq,rq)+sum(2*x+1,m,r,lq,rq);
}

void upd(int x,int l,int r,int lq,int rq,int val) {
    if (lq<=l&&r<=rq) {
        t[x]=val;
        s[x]=(r-l)*val;
        return;
    }
    if (rq<=l||r<=lq) return;
    if (t[x]>0) push(x,l,r);
    int m=(l+r)>>1;
    upd(2*x,l,m,lq,rq,val);
    upd(2*x+1,m,r,lq,rq,val);
    s[x]=s[2*x]+s[2*x+1];
}
