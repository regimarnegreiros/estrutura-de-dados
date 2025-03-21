#include "Caixa.h"

int main() {
    Caixa *c;
    c = criar_caixa(7, 2.5, 4);

    exibir_caixa(c);
    area_caixa(c);
    volume_caixa(c);

    liberar_caixa(c);
    return 0;
}