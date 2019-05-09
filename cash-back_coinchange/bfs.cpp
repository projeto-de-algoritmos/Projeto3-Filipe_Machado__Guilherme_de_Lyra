#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX { 100010 }, oo { 1000000010 };
vi adj[MAX];
int visited(int x, vi& path){
    int size=path.size();
    for(int i=0;i<size;++i)
        if(path[i]==x) return 0;

    return 1;
}

void printpath(vi& path){
    int size=path.size();
    for(int i =0;i<size;++i)cout<< path[i] << " ";
    cout<<'\n';
}

void bfs (int s) {
	queue<vi> q;
    vi path;
    path.pb(0);
    q.push(path);

	while (!q.empty()) {
		path = q.front();
		q.pop();
        int last = path[path.size()-1];
        cout<<last<<endl;
        if(last == s) printpath(path);
		for (const auto& v : adj[last]) {
			if (visited(v, path)) continue;
            vi newpath(path);
            newpath.pb(v);
            q.push(newpath);
		}
	}
}

void update_adj (int u, int v) {
    adj[u].pb(v);
    adj[v].pb(u);
}

void build_edges(vi money, int n){
    for (auto m : money) {
        for(int i = 0; i <= n; ++i) {
            update_adj(i, i+m);
        }
    }
}

int main()
{
    cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    vi money;
    for (int x; scanf("%d", &x) && x!=0;){
        money.pb(x);
    }

    cout << "Insira o troco:\n";
    int change;
    cin >> change;
    int n = max(*max_element(std::begin(money), std::end(money)), change);

    build_edges(money, n);
    bfs(n);

    return 0;
} 
