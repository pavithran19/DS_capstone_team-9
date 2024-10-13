#include <stdio.h>
#include <stdlib.h>

struct Stock {
    int price;
    int span;
};

void calculateSpan(int prices[], int n, int spans[]) {
    struct Stock* stack = (struct Stock*)malloc(n * sizeof(struct Stock));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && stack[top].price <= prices[i]) {
            top--;
        }
        spans[i] = (top == -1) ? (i + 1) : (i - stack[top].span);
        top++;
        stack[top].price = prices[i];
        stack[top].span = i;
    }

    free(stack);
}

void displayStockSpan(int prices[], int n) {
    int* spans = (int*)malloc(n * sizeof(int));
    calculateSpan(prices, n, spans);

    printf("Price\tSpan\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", prices[i], spans[i]);
    }

    free(spans);
}

int main() {
    int prices[] = {100, 105, 82, 70, 60, 73, 93};
    int n = sizeof(prices) / sizeof(prices[0]);
    displayStockSpan(prices, n);
    return 0;
}
