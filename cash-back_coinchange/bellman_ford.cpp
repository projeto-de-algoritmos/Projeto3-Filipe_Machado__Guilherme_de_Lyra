#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;
using vi = vector<int>;

const int MAX { 100010 }, oo { 1000000010 };
int dist[MAX], pred[MAX];
vector<ii> adj[MAX];
map<ii, int> weights;
bitset<MAX> processed;

vector<edge> edges;

void bellman_ford(int s, int n) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = oo;
        pred[i] = -1;
    }
    dist[s] = 0;
    pred[s] = s;

    for (int i = 1; i<= n-1; ++i) {
        for (const auto& uvw : edges) {
            auto u = get<0>(uvw);
            auto v = get<1>(uvw);
            auto w = get<2>(uvw);

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }
}

void dijkstra(int s, int N)
{
    for (int i = 1; i <= N; ++i) {
        dist[i] = oo;
        pred[i] = -1;
    }

    dist[s] = 0;
    pred[s] = s;
    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (not pq.empty()) {
        auto du = pq.top();
        auto d = du.first;
        auto u = du.second;
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (const auto& vw : adj[u]) {
            auto v = vw.first;
            auto w = vw.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push(ii(dist[v], v));
                pred[v] = u;
            }
        }
    }
}

void update_weights (int u, int v, int w) {
    weights[{u, v}]=w;
    weights[{v, u}]=w;
}

void update_adj (int u, int v, int w) {
    adj[u].pb({v, w});
    adj[v].pb({u, w});
}

void update_edges (int u, int v, int w) {
    edges.push_back(edge(v, u, w));
}

void add_edge (int u, int v, int w) {
    update_adj(u, v, w);
    update_weights(u, v, w);
    update_edges(u, v, w);
}

void build_edges(vi money, int n){
    for (auto m : money) {
        for(int i = n; i >= 0; --i) {
            add_edge(i, i+m, m);
        }
    }
}
int main()
{
    cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    vi money;
    for (int x; scanf("%d", &x) && x!=0;){
        money.pb(x);
        money.pb(-x);
    }
    sort(money.rbegin(), money.rend());

    cout << "Insira o troco:\n";
    int change;
    cin >> change;
    int n = max(*max_element(std::begin(money), std::end(money)), change);

    build_edges(money, n);

    bellman_ford(0, n);
    // for (int i = 0; i <= n; ++i) {
    //     for(auto vw : adj[i]) {
    //         cout << "{" << i << ", " << vw.first << "} - " << vw.second << endl;
    //     }
    // }

    // for (auto x : weights) {
    //     printf("\t%d -- %d[label=\"%d\",weight=\"%d\"];\n", x.first.first, x.first.second, x.second, x.second);
    // }

    // dijkstra(0, change);

    for (int u = 0; u < change; ++u)
    {
        cout << "dist(0," << u+1 << ") = " << dist[u+1] << endl;

        vector<int> path;
        auto p = u+1;

        while (p != 0) {
            path.pb(p);
            p = pred[p];
        } 

        path.pb(0);
        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i+1 == path.size()) {
                cout << '\n';
            } else {
                auto idx_1 = path[i];
                auto idx_2 = path[i+1];
                auto weight = weights[{idx_1, idx_2}];
                printf(" --(%d)-> ", weight);
            }
        }
    }
    return 0;
} 
