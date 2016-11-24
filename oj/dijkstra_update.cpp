/*************************************************************************
    > File Name: dijkstra_update.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年11月24日 星期四 19时54分00秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1000
#define INF 9999

using namespace std;

int cnte,cntn;
int s;

struct Edge {
    int from , to , w;
    Edge (int a=0 , int b=0 , int c=0) : from(a),to(b),w(c) {}
};

struct HeapNode {
    int d,u;
    bool operator< (const HeapNode &rhs) const{
        return d > rhs.d;
    }
};

struct Dijkstra {
public:
    vector<int> G[MAXN];
    vector<Edge> e;
    int d[MAXN];
    int p[MAXN];
    bool done[MAXN];

    void addEdge () {
        for (int i = 0 ; i < cnte ; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            e.push_back (Edge(u,v,w));
            G[u].push_back(i);
        }
    }

    void init () {
        for (int i = 0 ; i < cntn ; i++) {
            d[i]=INF;
            G[i].clear();
            done[i] = false;
        }
        e.clear();
        d[s] = 0;
    }

    void dijkstra () {
        priority_queue<HeapNode> q;
        q.push((HeapNode){0,s});

        while (!q.empty()) {
            HeapNode t = q.top();q.pop();
            int u = t.u;
            if (done[u]) continue;
            done[u] = true;

            for (int i = 0 ; i < G[u].size () ; i++) {
                Edge &et = e[G[u][i]];
                if (d[et.to] > d[u]+et.w) {
                    d[et.to] = d[u] + et.w;
                    p[et.to] = u;
                    q.push ((HeapNode){d[et.to],et.to});
                }
            }
        }
    }
};

int main () {
    cin >> cnte >> cntn >> s;
    Dijkstra algo;
    algo.init ();
    algo.addEdge ();
    algo.dijkstra ();

    for (int i = 0 ; i < cntn ; i++)
        cout << algo.d[i] << " ";
    cout << endl;

    return 0;
}
