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

    int j;
    for (j = 0; str[j] != '\0'; j++) {
        if (str[j] >= 'a' && str[j] <= 'z') {
            int deslocamento = (str[j] - 'a' + n) % 26;
            if (deslocamento < 0)
                deslocamento += 26;
            str[j] = deslocamento + 'a';
        }
        if (str[j] >= 'A' && str[j] <= 'Z') {
            int deslocamento = (str[j] - 'A' + n) % 26;
            if (deslocamento < 0)
                deslocamento += 26;
            str[j] = deslocamento + 'A';
        }
        if (str[j] >= '0' && str[j] <= '9') {
            int deslocamento = (str[j] - '0' + n) % 10;
            if (deslocamento < 0)
                deslocamento += 10;
            str[j] = deslocamento + '0';
        }
    }
}

void trocarParEImpar(char *str) { 

    int j;
    char temp;
    for (j = 0; str[j] != '\0' && str[j + 1] != '\0'; j += 2) {
        temp = str[j];
        str[j] = str[j + 1];
        str[j + 1] = temp;
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

void rotacionaDireita(char *str) {
    
    char temp;
    int j;
    int fim = tamanho(str) - 1;
    
    temp = str[fim];
    for (j = fim; j > 0; j--) {
        str[j] = str[j - 1];
    }
    str[0] = temp;
}

void rotacionaEsquerda(char *str) {
    
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
            rotacionaDireita(str);
        }
    }
    else if (n < 0) {
        for (cont = 0; cont < -n; cont++) {
            rotacionaEsquerda(str);
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

    char str[10001];
    int op, n;
    int continua = 1;

    scanf("%[^\n]", str);
    scanf(" %d", &op);

    while (continua) {
        switch (op) {
        case 1:
            inverter(str);
            break;
        case 2:
            scanf(" %d", &n);
            deslocar(str, n);
            break;
        case 3:
            trocarParEImpar(str);
            break;
        case 4:
            inverterCaixa(str);
            break;
        case 5:
            scanf(" %d", &n);
            rotacionar(str, n);
            break;
        case 6:
            trocarMetades(str);
            break;
        case 0:
            continua = 0;
            break;
        default:
            continua = 0;
            break;
        }
        if (continua) {
            scanf(" %d", &op);
        }
    }
    printf("%s\n", str);

    return 0;
}
