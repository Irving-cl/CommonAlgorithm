
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
