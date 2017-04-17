
const int N=10010;

int head[N],eIdx;

struct edge {  
    int to;
    int next; 
} e[2*N]; 

void add_edge(int u,int v) {  
    e[eIdx].to=v;
    e[eIdx].next=head[u];
    head[u]=eIdx++; 
}
