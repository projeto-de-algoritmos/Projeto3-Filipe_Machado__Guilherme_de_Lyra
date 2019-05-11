#include <bits/stdc++.h>
#define pb push_back

using namespace std;

using vi = vector<int>;

vi coins;
const int oo { 1000000010 };

//Brute-Force Coin Changing bottom-up
int bruteforceCC(int troco)
{
    vi result;
    for (int i = 0; i < troco + 1; i++)
    {
        result.pb(oo);
    }
    result[0] = 0;
    for (int i = 1; i <= troco; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
            {
                result[i] = min(result[i], result[i - coin] + 1);
            }
        }
    }

    return result[troco];
}

int get_input(int argc, char *argv[])
{
    bool silent = false;
    if (argc == 2 && strcmp(argv[1], "silent") == 0)
    {
        silent = true;
    }
    if(!silent) cout << "Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):\n";
    for (int x; scanf("%d", &x) && x!=0;)
    {
        coins.pb(x);
    }

    sort(coins.begin(), coins.end());

    if(!silent) cout << "Insira o troco:\n";
    int change;
    cin >> change;

    return change;
}

int main(int argc, char *argv[])
{
    int troco = get_input(argc, argv);
    int saida = bruteforceCC(troco);
    cout << "Moedas Disponiveis: ";
    for (auto x : coins)
    {
        cout << x << " ";
    }
    cout << endl;
    
    if (saida != oo)
        printf("Quantidade total de moedas utilizadas: %d\n", saida);
    else
        printf("Impossível.\n");
    return 0;
}