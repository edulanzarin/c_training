#include <stdint.h>
#include <stdio.h>

int main() {

    // cria 8 bytes contiguos na memoria
    uint8_t memory[8];

    // ponteiro que aponta para o primeiro byte
    uint8_t *reg = &memory[0];

    // escreve 00000000 no byte
    *reg = 0b00000000;

    // liga o bit 0
    *reg |= (1 << 0);

    // liga o bit 3
    *reg |= (1 << 3);

    // verifica se o bit 3 esta ligado
    if (*reg & (1 << 3)) {
        printf("bit 3 ligado\n");
    }

    // desliga o bit 0
    *reg &= ~(1 << 0);

    // imprime o valor final do byte
    printf("Valor final: %u\n", *reg);

    return 0;
}
