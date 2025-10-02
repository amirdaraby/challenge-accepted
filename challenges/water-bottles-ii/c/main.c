#include<stdio.h>

int maxBottlesDrunk(int numBottles, int numExchange) {
    int drinked = 0;
    int emptyBottles = 0;
    while (numBottles || numExchange <= emptyBottles) {
        if (numExchange <= emptyBottles ) {
            emptyBottles = emptyBottles % numExchange;
            numBottles++;
            numExchange++;
        } else if (numExchange <= numBottles) {
            drinked += numExchange;
            emptyBottles += numExchange;
            numBottles -= numExchange;
        } else {
            drinked += numBottles;
            numBottles = 0;
        }
    }

    return drinked;
}

int main() {

    int result = maxBottlesDrunk(10,3);

    printf("%d", result);

    return 0;
}