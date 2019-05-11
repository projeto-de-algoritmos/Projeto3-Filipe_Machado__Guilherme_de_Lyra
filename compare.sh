#!bin/bash

echo "~~ Djikstra ~~"
START=$(date +%s.%N)
echo "$(./cash-back_coinchange/a.out silent < $1)"
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo "Tempo de execução: $DIFF segundos"
echo ""

echo "~~ Ambicioso ~~"
START=$(date +%s.%N)
echo "$(./Greedy_coinchanging/a.out silent < $1)"
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo "Tempo de execução: $DIFF segundos"
echo ""

echo "~~ DP (Bottom-Up) ~~"
START=$(date +%s.%N)
echo "$(./dp_coinchanging/a.out silent < $1)"
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo "Tempo de execução: $DIFF segundos"
echo ""
