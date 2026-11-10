#include <stdio.h>

#define SALDO_INICIAL 1500
#define LIMITE_SAQUE 1000

void consultar_saldo(int saldo) {
    printf("\nSaldo atual: R$ %d\n", saldo);
}

int depositar(int saldo) {
    int valor;

    printf("\nDigite o valor do deposito: ");
    if (scanf("%d", &valor) != 1) {
        printf("Erro: entrada invalida.\n");
        while (getchar() != '\n');
        return saldo;
    }

    if (valor <= 0) {
        printf("Erro: o valor do deposito deve ser maior que zero.\n");
        return saldo;
    }

    saldo += valor;
    printf("Deposito realizado! Novo saldo: R$ %d\n", saldo);
    return saldo;
}

int sacar(int saldo) {
    int notas[] = {100, 50, 20, 10, 5};
    int qtd_tipos = sizeof(notas) / sizeof(notas[0]);
    int saque, restante, i;

    printf("\nDigite o valor do saque: ");
    if (scanf("%d", &saque) != 1) {
        printf("Erro: entrada invalida.\n");
        while (getchar() != '\n');
        return saldo;
    }

    if (saque <= 0) {
        printf("Erro: o valor do saque deve ser maior que zero.\n");
    } else if (saque % 5 != 0) {
        printf("Erro: o valor deve ser multiplo de 5.\n");
     } else if (saque > LIMITE_SAQUE) {
        printf("Erro: o limite por saque e de R$ %d.\n", LIMITE_SAQUE);
    } else if (saque > saldo) {
        printf("Erro: saldo insuficiente.\n");
    } else {
        
        restante = saque;
        printf("Notas entregues:\n");

        for (i = 0; i < qtd_tipos; i++) {
            int quantidade = restante / notas[i];
            if (quantidade > 0) {
                printf("%d nota(s) de %d\n", quantidade, notas[i]);
                restante %= notas[i];
            }
        }

        saldo -= saque;
        printf("Saldo restante: R$ %d\n", saldo);
    }

    return saldo;
}

int main(void) {
    int saldo = SALDO_INICIAL;
    int opcao;

    do {
        printf("\n===== CAIXA ELETRONICO =====\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Erro: entrada invalida.\n");
            while (getchar() != '\n');
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                consultar_saldo(saldo);
                break;
            case 2:
                saldo = depositar(saldo);
                break;
            case 3:
                saldo = sacar(saldo);
                break;
            case 0:
                printf("\nEncerrando. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
