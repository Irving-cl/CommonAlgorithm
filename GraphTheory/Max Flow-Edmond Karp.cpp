
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int MAX=201,INF=0x3f3f3f3f;
int f[MAX];
int cap[MAX][MAX];
int pre[MAX];
int N,M,s,e,c;

int BFS(int src, int des) {
    queue<int> q;
    memset(pre,-1,sizeof(pre));
    pre[src]=0;
    f[src]=INF;
    q.push(src);
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        if (cur==des) {
            break;
        }
        for (int i=1;i<=M;i++) {
            if (i!=src&&cap[cur][i]>0&&pre[i]==-1) {
                pre[i]=cur;
                f[i]=min(f[cur],cap[cur][i]);
                q.push(i);
            }
        }
    }
    if (pre[des]==-1) {
        return -1;
    } else {
        return f[des];
    }
}

int maxFlow(int src,int des) {
    int increment;
    int sumFlow=0;
    while ((increment=BFS(src,des))!=-1) {
        int cur=des;
        while (cur!=src) {
            int last=pre[cur];
            cap[last][cur]-=increment;
            cap[cur][last]+=increment;
            cur=last;
        }
        sumFlow+=increment;
    }
    return sumFlow;
}

int main() {

}
