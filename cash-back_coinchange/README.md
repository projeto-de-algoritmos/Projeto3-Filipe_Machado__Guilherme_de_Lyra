# Coin change com Djikstra

Bem, antes de tudo, essa ideia é totalmente baseada [nesse artigo](http://noenthuda.com/blog/2016/12/02/coin-change-problem-with-change-dijkstras-algorithm/)

Agora, contextualizando:
Todos conhecemos o famigerado problema do coin-change (ou change-making), que consiste, basicamente, em conceder a menor quantidade possiveis de moedas (ou notas etc) para pagar uma certa quantia.
```
Exemplo:
Tenho que pagar 56 centavos à alguem; e, para isso, poderia pagar com 56 moedas de 1 centavo.
Entretanto, a solução ótima (no que tange a quantidade de moedas), no sistema monetário brasileiro, seria:
50c + 5c + 1c, totalizando, obviamente, 3 moedas.
```

Entretanto, esse problema normalmente não leva em consideração a possibilidade do <i>Outro</i> me devolver uma certa quantia (<i>cashback</i>) para facilitar o pagamento.
```
Exemplo:
Tenho que pagar 99 centavos à alguem.
Dou a ele 1 real (100 centavos) e ele me devolve 1 centavo.
Total de moedas = 2

Já na solução ótima da implementação original do coin-change, o resultado seria:
50+25+10+10+1+1+1+1
Total de moedas = 8
```

Então, para isso surge essa solução.
Consiste basicamente nisso:
* Todas as quantias viram nós (de 1 a N, sendo N a maior quantia (o maior entre: maior moeda e o quanto hei de pagar))
* Dois nós possuem uma aresta se a diferença entre os dois puder ser paga por apenas 1 moeda
* Moedas negativas são incluídas (para o cashback funcionar)
    * ```
        ex:
        se o sistema monetário é: {1, 5, 10}
        as moedas serão: {-1, -5, -10, 1, 5, 10}
       ```

É isso.

Para rodar o programa, basta:
```
$ g++ djikstra.cpp
$ ./a.out
[sistema monetario]
0
[quantia à ser paga]

exemplo:
$ ./a.out
Insira as moedas/os valores que compõem o sistema monetário (Insira 0 para parar):
1 2 5 10 20 50 100
0
Insira o troco:
99
Moedas utilizadas:
1x -1c(cashback)
1x 100c
Quantidade total de moedas utilizadas: 2
```