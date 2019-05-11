# Projeto 3 de Algoritmos Ambiciosos
## Objetivo:
O objetivo desse trabalho é realizar uma comparação entre alguns métodos que solucionam o problema "Coin Change".

## O que foi feito:
Foram implementados 3 algoritmos diferentes na linguagem C++:
<ul><li>Coin Change ultilizando o algoritmo de Dijkstra;</li><li>Coin Change ultilizando o algoritmo ambicioso;</li><li>Coin Change ultilizando o algoritmo com Dynamic Programming;</li></ul>
 e com isso, tornando perceptível a diferença de qualidade de resultados que esses algoritmos mostram como saída.

## Detalhes:
Cada pasta nesse projeto contém um algoritmo e há também um README.md que contém detalhes sobre o algoritmo.

## Execução da Comparação:
É possível montar um arquivo de entrada ([como esse](cash-back_coinchange/in2)) para comparar o resultado dos 3 algoritmos.
Para criar esse arquivo de entrada, basta seguir esse padrão:
```
[sistema monetario]
0
[quantia à ser paga]
```

Exemplo:
```
1 2 5
0
20
```

### Executando a comparação
Após criar o arquivo de entrada, basta executar

`$ bash compare.sh <nome do arquivo de entrada>`

Exemplo de execução:
```
$ bash compare.sh cash-back_coinchange/in
~~ Djikstra ~~
Moedas utilizadas:
1x -1c(cashback)
1000x 100c
Quantidade total de moedas utilizadas: 1001
Tempo de execução: 5.759263538 segundos

~~ Ambicioso ~~
Moedas utilizadas:
1x 2c
1x 5c
1x 20c
1x 72c
999x 100c
Quantidade total de moedas utilizadas: 1003
Tempo de execução: .002886541 segundos

~~ DP (Bottom-Up) ~~
Moedas Disponiveis: 1 2 3 5 10 20 50 72 100 
Quantidade total de moedas utilizadas: 1002
Tempo de execução: .035129321 segundos
```

## Conclusão:
* Djikstra:
 Possui sempre a melhor resposta, independente se o sistema monetário é canônico ou não. Entretanto é o mais lento.
* DP (Bottom-up):
 Possui sempre a melhor resposta (quando cashback não é permitido), independente se o sistema monetário é canônico ou não. Entretanto é mais lento que o Greedy.
* Greedy:
 Falha em dar a melhor resposta caso o sistema monetário não seja canônico, entretanto é o mais rápido.

<h5>Filipe Santana Machado _  Matrícula: 18/0016563</h5>
<h5>Guilherme de Lyra _       Matrícula: 15/0128231</h5>
