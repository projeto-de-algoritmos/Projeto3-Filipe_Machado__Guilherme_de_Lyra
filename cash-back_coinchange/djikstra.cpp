#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;
using vi = vector<int>;

const int MAX { 100010 }, oo { 1000000010 };
// maps pois chaves negativas podem acontecer
map<int, int> dist, pred;
map<int, vector<ii> > adj;


void dijkstra(int s, int N)
{
    for (int i = 1; i <= N; ++i)
    {
        dist[i] = oo;
        pred[i] = -1;
    }

    dist[s] = 0;
    pred[s] = s;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (not pq.empty())
    {
        auto du = pq.top();
        auto d = du.first;
        auto u = du.second;
        pq.pop();

        // nós processados podem ser reprocessados, diferente da implementação padrão do djikstra

        for (const auto& vw : adj[u])
        {
            auto v = vw.first;
            auto w = vw.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push(ii(dist[v], v));
                pred[v] = u;
            }
        }
    }
}

void build_edges(const vi& money, int n)
{
    for (auto m : money)
    {
        for(int i = 0; i <= n; ++i)
        {
            adj[i].pb({i+m, m});
            adj[i+m].pb({i, -m});
        }
    }
}

int get_input()
{
    cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    vi money;
    for (int x; scanf("%d", &x) && x!=0;)
    {
        money.pb(x);
        // moedas negativas são adicionadas por conta do cashback
        money.pb(-x);
    }

    sort(money.begin(), money.end());

    cout << "Insira o troco:\n";
    int change;
    cin >> change;

    int n = max(*max_element(money.begin(), money.end()), change); // gera n nós (sendo n ou a maior moeda ou o troco, caso este seja maior que a maior moeda (rs))

    build_edges(money, n);

    return change;
}

void print_path(int dest)
{
    vi path;
    auto p = dest;
    map<int, int> coins;
    while(p != 0)
    {
        path.pb(p);
        p = pred[p];
    }

    path.pb(0);
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i)
    {
        if (i+1 != path.size())
        {
            auto weight = path[i+1] - path[i];
            coins[weight]++;
        }
    }

    cout << "Moedas utilizadas:\n";

    for (auto u : coins)
    {
        printf("%dx %dc%s\n", u.second, u.first, (u.first > 0 ? "" : "(cashback)"));
    }

    printf("Quantidade total de moedas utilizadas: %d\n", coins.size());
}

int main()
{
    int change = get_input();
    dijkstra(0, change);
    print_path(change);
    return 0;
} 
