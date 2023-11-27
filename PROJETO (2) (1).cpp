//Nome: Daniel Muller, TIA:32372523
//Nome: Victor Salvatore Benatar, TIA:32334729
//Tudo bem professor, passamos o final de semana inteiro tentando resolver os problemas com o codigo,
//conseguimos fazer com que ele funcionace porem, so para os 2x2 e 3x3,pedimos que o senhor considere o trabalho,
//muito obrigado e boas ferias

#include <stdio.h>

void mostrarMatriz(int matriz[], int linha, int coluna) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%2d ", matriz[i * coluna + j]);
        }
        printf("\n");
    }
}

void verificarCores(int matriz[], int linha, int coluna) {
    if (linha == 1 && coluna == 1) {
        if (matriz[0] == 0) {
            printf("B");
        } else if (matriz[0] == 1) {
            printf("P");
        }
        return;
    }

    int cor = matriz[0];
    int uniforme = 1;

    for (int i = 0; i < linha && uniforme; i++) {
        for (int j = 0; j < coluna; j++) {
            if (matriz[i * coluna + j] != cor) {
                uniforme = 0;
                break;
            }
        }
    }

    if (uniforme) {
        if (cor == 0) {
            printf("B");
        } else if (cor == 1) {
            printf("P");
        }
    } else {
        printf("X");

        int linhaMetade, colunaMetade;

        if (linha % 2 == 0) {
            linhaMetade = linha / 2;
        } else {
            linhaMetade = linha / 2 + 1;
        }

        if (coluna % 2 == 0) {
            colunaMetade = coluna / 2;
        } else {
            colunaMetade = coluna / 2 + 1;
        }

        
        verificarCores(matriz, linhaMetade, colunaMetade);
        verificarCores(matriz + colunaMetade, linhaMetade, coluna - colunaMetade);
        verificarCores(matriz + linhaMetade * coluna, linha - linhaMetade, colunaMetade);
        verificarCores(matriz + linhaMetade * coluna + colunaMetade, linha - linhaMetade, coluna - colunaMetade);
    }
}

int main() {
    int linha, coluna;
    printf("Digite o valor da linha: \n");
    scanf("%d", &linha);
    printf("Digite o valor da coluna: \n");
    scanf("%d", &coluna);
    int matriz[linha * coluna];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("Digite o valor da imagem:");
            scanf("%d", &matriz[i * coluna + j]);
        }
    }

    printf("Imagem: \n");
    mostrarMatriz(matriz, linha, coluna);

    verificarCores(matriz, linha, coluna);

    return 0;
}
