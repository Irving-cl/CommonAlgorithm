const int N=1000010;
 
int t;
char haystack[N],needle[N];
int hlen,nlen;
int tb[N];
int match[N],tot;

void build_table() {
    tb[0]=-1;
    tb[1]=0;
    int pos=2,cnd=0;
    while (pos<nlen) {
        if (needle[pos-1]==needle[cnd]) {
            tb[pos]=cnd+1;
            pos++;
            cnd++;
        } else {
            if (cnd>0) {
                cnd=tb[cnd];
            } else {
                tb[pos]=0;
                pos++;
            }
        }
    }
}
 
void kmp() {
    tot=0;
    int pos=0;
    int i=0;
    while (pos+i<hlen) {
        if (haystack[pos+i]==needle[i]) {
            if (i==nlen-1) {
                match[tot++]=pos;
                pos=pos+i-tb[i];
                i=tb[i];
                if (i<0) i=0;
            } else {
                i++;
            }
        } else {
            pos=pos+i-tb[i];
            i=tb[i];
            if (i<0) i=0;
        }
    }
}
