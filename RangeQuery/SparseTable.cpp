
#include <math.h>

int n;
int st[1000005][20];

// 1-based index
void st_init() {
    int k=log(n*1.0)/log(2.0);
    for (int j=1;j<=k;j++) {
        for (int i=1;i<=n;i++) {
            if (i+(1<<j)-1>n) {
                break;
            }
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}

int getMin(int x,int y) {
    int k=log(y-x+1.0)/log(2.0);
    return min(st[x][k],st[y-(1<<k)+1][k]);
}
