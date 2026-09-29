# Central de Comunicações Alienígenas #

Programa em C que recebe uma mensagem e permite aplicar sobre ela uma **sequência livre de transformações**, cada uma implementada por uma função própria de manipulação de strings.

#  Sobre o projeto

O programa lê uma mensagem inicial e, em seguida, códigos numéricos de operação. Cada operação é aplicada sobre o **estado atual da mensagem**: o resultado de uma operação é a entrada da próxima. Quando o código `0` é lido, o protocolo termina e a mensagem final é impressa.

# Operações disponíveis

| Código | Operação | Função | Parâmetro | O que faz |
|:------:|----------|--------|:---------:|-----------|
| `1` | Inverter mensagem | `inverter` | — | Inverte a ordem dos caracteres |
| `2` | Deslocar caracteres | `deslocar` | `n` | Desloca letras (a–z, A–Z) e dígitos em `n` posições, mantendo maiúscula/minúscula; outros símbolos ficam iguais |
| `3` | Trocar pares e ímpares | `trocarParEImpar` | — | Troca cada caractere com o vizinho seguinte (posições 0 <->1, 2<->3, ...) |
| `4` | Inverter maiúsculas/minúsculas | `inverterCaixa` | — | Maiúsculas viram minúsculas e vice-versa |
| `5` | Rotacionar mensagem | `rotacionar` | `n` | `n > 0` rotaciona para a direita, `n < 0` para a esquerda |
| `6` | Trocar metades | `trocarMetades` | — | Troca a primeira metade com a segunda; em mensagens de tamanho ímpar, o caractere central permanece |
| `0` | Finalizar protocolo | — | — | Encerra e imprime a mensagem final |

Qualquer código não reconhecido também encerra o protocolo. A função auxiliar `tamanho` calcula o comprimento da string.

#Compilação e execução

```bash
gcc mp2.c -o mp2
./mp2
```

# Formato da entrada

1. Na primeira linha, a mensagem (pode conter espaços, até 10000 caracteres).
2. Em seguida, a sequência de códigos de operação, separados por espaço ou quebra de linha. Nas operações `2` e `5`, o código é seguido do inteiro `n`.
3. A sequência termina com `0`.

A saída é a mensagem final em uma linha.

# Exemplo de uso

Entrada:

```
Ola Mundo
1 4 0
```

Passo a passo:

1. `Ola Mundo`
2. Operação `1` (inverter): `odnuM aloO`
3. Operação `4` (inverter caixa): `ODNUm ALOo`

Saída:

```
ODNUm ALOo
```

# Estrutura

```
.
├── mp2.c      # código-fonte do projeto
└── README.md
```

# Autoras:

Amanda de Bastos Chagas e Isadora Aires Franca
