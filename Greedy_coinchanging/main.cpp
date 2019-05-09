#include <iostream>
#include <bits/stdc++.h>
    using namespace std;
    
   

    int main(){     
        int coins[]={ 1, 5, 10};
        int n = sizeof(coins)/sizeof(coins[0]);     
        int V = 19;
        vector<int> result; 
        sort(coins, coins+n);
        cout<<"troco para "<<V<<endl;
        cout<<"Moedas dps do sort : \n";
        for (auto x : coins){
            cout << x << " ";
        }
        cout<<endl;
        cout<<"Minimal coins: "<<endl;              
        for(int i = n - 1; i>= 0; i--){
            while(V>=coins[i]){
                V -= coins[i];
                result.push_back(coins[i]);
            }         
        }

        for(int i = 0; i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
        
        cout << "Its Working!!" << endl;
            return 0;
    }