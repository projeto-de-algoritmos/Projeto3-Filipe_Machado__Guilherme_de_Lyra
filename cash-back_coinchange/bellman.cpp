#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using edge = tuple<int, int, int>;
using vi = vector<int>;

const int MAX { 100010 }, oo { 1000000010 };
map<int, int> dist, pred;
int change;

void bellman_ford(int s, int N, const vector<edge>& edges)
{
    for (int i = 0; i <= N; ++i) {
        dist[i] = oo;
        pred[i] = -1;
    }

    dist[s] = 0; pred[s] = s;

    for (int i = 0; i <= N; i++)
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

vector<edge> get_input() {
    cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    vi money;
    for (int x; scanf("%d", &x) && x!=0;){
        money.pb(x);
        money.pb(-x);
    }

    sort(money.begin(), money.end());

    cout << "Insira o troco:\n";
    cin >> change;
    int n = max(*max_element(money.begin(), money.end()), change);
    vector<edge> ans;
    for (auto m : money) {
        ans.pb({0, m, m});
        for(int i = 1; i <= n; ++i) {
            ans.pb({i, i+m, 1});
            ans.pb({i+m, i, 1});
        }
    }
    return ans;
}

int main()
{
    auto edges = get_input();

    bellman_ford(0, change, edges);
    for (int u = 0; u <= change; ++u)
    {
        cout << "dist(0," << u+1 << ") = " << dist[u+1] << endl;

        puts("ok");
        vector<int> path;
        auto p = u+1;

        while (p != 0) {
            path.push_back(p);
            p = pred[p];
        } 

        path.push_back(0);
        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << (i + 1 == path.size() ? "\n" : " -> ");
    }

    return 0;
} 
