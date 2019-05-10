#include <bits/stdc++.h>
#define pb push_back

using namespace std;

using vi = vector<int>;

vi coins;
const int oo { 1000000010 };

int get_input()
{
    cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    for (int x; scanf("%d", &x) && x!=0;)
    {
        coins.pb(x);
    }

    sort(coins.begin(), coins.end());

    cout << "Insira o troco:\n";
    int change;
    cin >> change;

    return change;
}

int main()
{
    int troco = get_input(), qtd = 0;
    map<int,int> result;

    for (int i = coins.size() - 1; i >= 0; i--)
    {
        while (troco >= coins[i])
        {
            troco -= coins[i];
            result[coins[i]]++;
            qtd++;
        }
    }

    cout << "Moedas utilizadas:\n";

    for (auto u : result)
    {
        printf("%dx %dc\n", u.second, u.first);
    }

    printf("Quantidade total de moedas utilizadas: %d\n", qtd);
    return 0;
}