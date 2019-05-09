#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;
using vi = vector<int>;

const int MAX { 100010 }, oo { 1000000010 };
map<int, int> dist, pred;
map<int, vector<ii> > adj;
map<ii, int> weights;
bitset<MAX> processed;


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
    weights[{v, u}]=-w;
}

void update_adj (int u, int v, int w) {
    adj[u].pb({v, w});
    adj[v].pb({u, -w});
}

void add_edge (int u, int v, int w) {
    update_adj(u, v, w);
    update_weights(u, v, w);
}

void build_edges(const vi& money, int n){
    for (auto m : money) {
        for(int i = 0; i <= n; ++i) {
            add_edge(i, i+m, m);
        }
    }
}

int get_input() {
    cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    vi money;
    for (int x; scanf("%d", &x) && x!=0;){
        money.pb(x);
        money.pb(-x);
    }

    sort(money.begin(), money.end());

    cout << "Insira o troco:\n";
    int change;
    cin >> change;
    int n = max(*max_element(std::begin(money), std::end(money)), change);

    build_edges(money, n);

    return change;
}

void print_weights() {
    cout<<"ok\n";
    for(auto u : weights) {
        printf("{%d - %d}\n", u.first.first, u.first.second);
    }
}

void print_path(int dest) {
    vi path;
    auto p = dest;
    map<int, int> coins;
    while(p != 0) {
        path.pb(p);
        p = pred[p];
    }

    path.pb(0);
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i) {
        if (i+1 != path.size()){
            // cout << path[i] << endl;
            auto weight = path[i+1] - path[i];
            coins[weight]++;
        }
    }

    cout << "Moedas utilizadas:\n";

    for (auto u : coins) {
        printf("%dx %dc%s\n", u.second, u.first, (u.first > 0 ? "" : "(cashback)"));
    } 
}

int main()
{
    int change = get_input();
    dijkstra(0, change);
    // print_weights();
    print_path(change);
    return 0;
} 
