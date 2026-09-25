#include <stdio.h>

int tamanho(char *str) {

    int i, tamanho = 0;
    for (i = 0; str[i] != '\0'; i++) {
        tamanho++;
    }
    return tamanho;
}

void inverter(char str[]) {

    int inicio = 0;
    int tam;
    int fim = tamanho(str) - 1;
    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}

void deslocar(char *str, int n) {

    scanf("%d", &n);
    int j;

    for (j = 0; str[j] != '\0'; j++) {
        if (str[j] >= 'a' && str[j] <= 'z') {
            str[j] = ((str[j] - 'a' + n) % 26) + 'a';
        }
        if (str[j] >= 'A' && str[j] <= 'Z') {
            str[j] = ((str[j] - 'A' + n) % 26) + 'A';
        }
        if (str[j] >= '0' && str[j] <= '9') {
            str[j] = ((str[j] - '0' + n) % 10) + '0';
        }
    }
}

void trocarParEImpar(char *str) { 

    int j;
    int *fim;
    for (j = 0; str[j] != '\0'; j++) {

        if (j == tamanho(str) - 1) {
            continue;
        }
        if (j % 2 == 0) {
            str[j] += 1;
        }
        else {
            str[j] -= 1;
        }
    }
}

void inverterCaixa(char *str) {

    int j;
    for (j = 0; str[j] != '\0'; j++) {
        if (str[j] >= 'a' && str[j] <= 'z') {
            str[j] -= 32;
        }
        else {
            if (str[j] >= 'A' && str[j] <= 'Z') {
                str[j] += 32;
            }
        }
    }
}

void rotacionaDireita(char *str, int n) {
    char temp;
    int j;
    int fim = tamanho(str) - 1;

    temp = str[fim];
    for (j = fim; j > 0; j--) {

        str[j] = str[j - 1];
    }
    str[0] = temp;
}

void rotacionaEsquerda(char *str, int n) {
    char temp;
    int j;
    int inicio = 0, fim = tamanho(str) - 1;

    temp = str[0];
    for (j = 0; j < fim; j++) {

        str[j] = str[j + 1];
    }
    str[fim] = temp;
}

void rotacionar(char *str, int n) {

    int cont;
    int tam = tamanho(str);

    n = n % tam;

    if (n > 0) {
        for (cont = 0; cont < n; cont++) {
            rotacionaDireita(str, n);
        }
    }
    else if (n < 0) {
        for (cont = 0; cont < -n; cont++) {
            rotacionaEsquerda(str, n);
        }
    }
}

void trocarMetades(char *str) {

    int j, tam = tamanho(str);
    int mid = tam / 2;
    int inicioSeg = tam - mid;
    char temp;

    for (j = 0; j < mid; j++) {
        temp = str[j];
        str[j] = str[inicioSeg + j];
        str[inicioSeg + j] = temp;
    }
}

int main() {

    char str[10001], str2[10001];
    int op, n;

    scanf("%[^\n]", str);
    scanf(" %d", &op);
    while (getchar() != '\n')
        ;

    while (op != 0) {
        switch (op) {
        case 1:
            inverter(str);
            printf("%s", str);
            break;
        case 2:
            deslocar(str, n);
            printf("%s", str);
            break;
        case 3:
            trocarParEImpar(str);
            printf("%s", str);
            break;
        case 4:
            inverterCaixa(str);
            printf("%s", str);
            break;
        case 5:
            scanf("%d", &n);
            rotacionar(str, n);
            printf("%s", str);
            break;
        case 6:
            trocarMetades(str);
            printf("%s", str);
            break;
        case 0:
            break;
        }

        scanf(" %d", &op);
    }

    return 0;
}
