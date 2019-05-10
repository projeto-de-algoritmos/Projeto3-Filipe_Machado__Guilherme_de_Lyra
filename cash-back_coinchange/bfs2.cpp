// CPP program to print all paths of source to 
// destination in given graph 
#include <bits/stdc++.h> 
#define pb push_back

using namespace std; 

using vi = vector<int>;

// utility function for printing 
// the found path in graph 
void printpath(vector<int>& path) 
{ 
	int size = path.size(); 
	for (int i = 0; i < size; i++) 
		cout << path[i] << " ";	 
	cout << endl; 
} 

// utility function to check if current 
// vertex is already present in path 
int isNotVisited(int x, vector<int>& path) 
{ 
	int size = path.size(); 
	for (int i = 0; i < size; i++) 
		if (path[i] == x) 
			return 0; 
	return 1; 
} 

// utility function for finding paths in graph 
// from source to destination 
void findpaths(vector<vector<int> >&g, int src, 
								int dst, int v) 
{ 
	// create a queue which stores 
	// the paths 
	queue<vector<int> > q; 

	// path vector to store the current path 
	vector<int> path; 
	path.push_back(src); 
	q.push(path); 
	while (!q.empty()) { 
		path = q.front(); 
		q.pop(); 
		int last = path[path.size() - 1]; 

		// if last vertex is the desired destination 
		// then print the path 
		if (last == dst) 
			printpath(path);		 

		// traverse to all the nodes connected to 
		// current vertex and push new path to queue 
		for (int i = 0; i < g[last].size(); i++) { 
			if (isNotVisited(g[last][i], path)) { 
				vector<int> newpath(path); 
				newpath.push_back(g[last][i]); 
				q.push(newpath); 
			} 
		} 
	} 
} 

void build_edges(vi money, int n, vector<vi> &g){
    for (auto m : money) {
        for(int i = 0; i <= n; ++i) {
            g[i].pb(i+m);
            g[i+m].pb(i);
        }
    }
}

// driver program 
int main() 
{ 
    vector<vi> g;
    cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    vi money;
    for (int x; scanf("%d", &x) && x!=0;){
        money.pb(x);
    }

    cout << "Insira o troco:\n";
    int change;
    cin >> change;
    int n = max(*max_element(std::begin(money), std::end(money)), change);

    build_edges(money, n, g);

	int src = 0, dst = n-1; 
	cout << "path from src " << src 
		<< " to dst " << dst << " are \n"; 

	// function for finding the paths 
	findpaths(g, src, dst, n-1); 

	return 0; 
} 
