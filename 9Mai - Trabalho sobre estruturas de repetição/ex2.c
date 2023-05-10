#include <stdio.h>
#define BIRTH_RATE_A 1.03
#define BIRTH_RATE_B 1.02

int main(void) {
    int anos;
    int popA = 5000000;
    int popB = 7000000;
    for(anos = 0; popA <= popB; ++anos) {
        popA *= BIRTH_RATE_A;
        popB *= BIRTH_RATE_B;
    }
    printf("Anos passados para que A superasse B: %d", anos);
}
