<h1>Solução do problema "Coin Change" usando Brute Force</h1>

<p>Implementação de um algoritmo que, dado um conjunto de moedas de um sistema monetário e um valor, apresenta a quantidade mínima de moedas necessárias para o valor.</p>

<p>Exemplo:

```
Troco = 75;
Coins[] = {10, 25, 50} //Valores de moeda

Resultado: O valor pode ser pago usando 2 moedas.
```

<p> Essa abordagem, com Programação Dinâmica, é ótima em qualquer circunstância (ou seja, não depende que o sistema monetário seja canônico), pois resolve primeiro os casos menores e constrói a partir disso a solução completa, indicando qual a quantidade mínima de moedas necessárias.
Entretanto, não é possível mostrar quais moedas foram utilizadas.</p>
