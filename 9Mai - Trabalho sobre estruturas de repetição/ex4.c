#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if(n<2) return 0;
    for(int i=2;i<=sqrt((double)n);++i) if (n%i==0) return 0; 
    return 1;
}

int main(void) {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    isPrime(n) ? printf("\nPrimo") : printf("\nNao e' primo");
}
