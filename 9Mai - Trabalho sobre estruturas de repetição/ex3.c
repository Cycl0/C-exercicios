#include <stdio.h>

int main(void) {
    int n, i, inc, j;
    printf("Digite um numero: ");
    scanf("%d", &n);
    for(i = 1, inc = 1; inc<=n; i+=inc, ++inc) {
        for(j = 0; j<inc; ++j) {
            printf("%d ", i+j);
        }
        printf("\n");
    }
}
