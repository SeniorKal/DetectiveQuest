# Detective Quest

Detective Quest e um jogo simples de exploracao em terminal desenvolvido em C. O projeto usa uma arvore binaria para representar os caminhos de uma mansao, onde cada no da arvore e uma sala e cada ligacao representa uma escolha de caminho.

## Sobre o projeto

O jogador comeca no `Hall de Entrada` e pode escolher seguir para a esquerda ou para a direita. Cada escolha leva a uma nova sala da mansao ate que o jogador chegue a uma sala sem novos caminhos ou decida sair.

A estrutura da mansao e montada assim:

```text
Hall de Entrada
+-- Biblioteca
|   +-- Cozinha
|   +-- Jardim
+-- Sala de Estar
    +-- Quarto
    +-- Escritorio
```

## Conceitos utilizados

- Structs em C
- Ponteiros
- Alocacao dinamica de memoria com `malloc`
- Liberacao de memoria com `free`
- Arvore binaria
- Percurso interativo usando entrada do usuario

## Arquivos

- `DetectiveQuest.c`: codigo-fonte principal do jogo.
- `DetectiveQuest.exe`: executavel gerado a partir do codigo C.

## Como compilar

Para compilar o projeto com GCC, execute:

```bash
gcc DetectiveQuest.c -o DetectiveQuest
```

No Windows, o comando tambem pode gerar um executavel `.exe`:

```bash
gcc DetectiveQuest.c -o DetectiveQuest.exe
```

## Como executar

No Windows:

```bash
.\DetectiveQuest.exe
```

Em Linux ou macOS:

```bash
./DetectiveQuest
```

## Como jogar

Durante a execucao, o programa mostra a sala atual e as opcoes de caminho disponiveis:

- `E`: ir para a sala da esquerda.
- `D`: ir para a sala da direita.
- `S`: sair da mansao.

Exemplo de tela:

```text
Voce esta na sala: Hall de Entrada

Escolha um caminho:
E - Ir para a esquerda (Biblioteca)
D - Ir para a direita (Sala de Estar)
S - Sair
Opcao:
```

## Objetivo educacional

Este projeto foi criado para praticar o uso de arvores binarias em C de uma forma visual e interativa. Em vez de trabalhar apenas com numeros, a arvore representa salas de uma mansao, tornando mais facil entender como os nos se conectam e como a navegacao ocorre entre eles.
