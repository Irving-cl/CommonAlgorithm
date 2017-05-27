const int N=105;
const db PI=acos(-1.0);

int T,n,d;
struct V2 {
    db x,y;
} vt[N],hull[N];
int s;

void init() {
    s=0;
    scanf("%d%d",&n,&d);
    for (int i=0;i<n;i++) {
        scanf("%lf%lf",&vt[i].x,&vt[i].y);
        if (vt[i].y<vt[s].y||(vt[i].y==vt[s].y&&vt[i].x<vt[s].x)) s=i;
    }
    if (s!=0) {
        swap(vt[s],vt[0]);
    }
}

V2 diff(const V2& lhs,const V2& rhs) {
    return {rhs.x-lhs.x,rhs.y-lhs.y};
}

db cross(const V2& v0,const V2& v1,const V2& v2) {
    return (v1.x-v0.x)*(v2.y-v0.y)-(v1.y-v0.y)*(v2.x-v0.x);
}

db dist(const V2& lhs,const V2& rhs) {
    db dx=lhs.x-rhs.x;
    db dy=lhs.y-rhs.y;
    return sqrt(dx*dx+dy*dy);
}

bool cmp(const V2& lhs,const V2& rhs) {
    return cross(vt[0],lhs,rhs)>0.0;
}

int graham() {
    if (n<3) return n;
    sort(vt+1,vt+n,cmp);
    hull[0]=vt[0];
    hull[1]=vt[1];
    int hPos=2;
    for (int i=2;i<n;i++) {
        while (hPos>1&&cross(hull[hPos-2],hull[hPos-1],vt[i])<0.0) {
            hPos--;
        }
        hull[hPos++]=vt[i];
    }
    return hPos;
}
