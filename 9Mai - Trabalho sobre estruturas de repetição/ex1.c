#include <stdio.h>

int main(void) {
    int countMaioresIgualZero = 0,
    countMenoresZero = 0,
    sumMaioresZero = 0,
    sumMenoresZero = 0;
    for(int i = 0; i<10;++i) {
        int n;
        printf("Digite um numero: ");
        scanf("%d", &n);
        if(n>=0) {
            ++countMaioresIgualZero;
            sumMaioresZero += n;
        } else if(n<0) {
            ++countMenoresZero;
            sumMenoresZero += n;
        }
    }
    printf("Quantidade de números digitados maiores ou igual a 0: %d\n", countMaioresIgualZero);
    printf("Quantidade de números digitados menores que 0: %d\n", countMenoresZero);
    printf("Soma de todos os números digitados maiores que 0: %d\n", sumMaioresZero);
    printf("Soma dos números digitados menoers que 0: %d\n", sumMenoresZero);
}
