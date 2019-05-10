#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

    using namespace std;
    int coins[] = {1, 25, 75, 50, 100};
    int n = sizeof(coins)/sizeof(coins[0]);  
    //Brute-Force Coin Changing
    int bruteforceCC(int troco){
        int result = 999999;
        if(troco == 0){
            return 0;
        }
        for(auto i : coins){
            if(i <= troco){

                result = min(result , bruteforceCC(troco - i)+1);
            }
        }
        return result;
    }
    
    int main(){
        int troco = 150;
        int saida = bruteforceCC(troco);
        sort(coins, coins+n);
        cout<<"Moedas Disponiveis : \n";
        for (auto x : coins){
            cout << x << " ";
        }
        cout<<endl;
        cout<<"Cashback: "<<troco<<endl;
        cout<<"Quantidade minima de moedas para o troco : "<<saida<<endl;

        cout<<"Its Working!"<<endl;
        return 0;
    }