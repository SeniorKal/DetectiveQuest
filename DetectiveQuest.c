#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
 char nome[50];
 // Ponteiros para as salas conectadas na arvore.
 struct No* esquerda;
 struct No* direita;
}No;

No* criarSala(const char* nome) {
    // Aloca memoria para uma nova sala da mansao.
    No* nova = malloc(sizeof(No));

    if (nova == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    // Define o nome da sala e inicia seus caminhos como vazios.
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

No* montarMansao() {
    // Cria a raiz da arvore, que sera o ponto inicial da exploracao.
    No* hall = criarSala("Hall de Entrada");

    // Monta os caminhos principais a partir do Hall.
    hall->esquerda = criarSala("Biblioteca");
    hall->direita = criarSala("Sala de Estar");

    // Adiciona as salas ligadas a Biblioteca.
    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita = criarSala("Jardim");

    // Adiciona as salas ligadas a Sala de Estar.
    hall->direita->esquerda = criarSala("Quarto");
    hall->direita->direita = criarSala("Escritorio");

    return hall;
}

void liberarArvore(No* raiz){
    if (raiz != NULL){
        // Libera primeiro as salas filhas antes de liberar a sala atual.
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void explorarSalas(No* raiz) {
    // Guarda a sala em que o jogador esta no momento.
    No* atual = raiz;
    char opcao;

    while (atual != NULL) {
        printf("\nVoce esta na sala: %s\n", atual->nome);

        // Se a sala nao possui filhos, a exploracao termina.
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Essa sala nao possui mais caminhos. Fim da exploracao.\n");
            break;
        }

        printf("\nEscolha um caminho:\n");

        if (atual->esquerda != NULL) {
            printf("E - Ir para a esquerda (%s)\n", atual->esquerda->nome);
        }

        if (atual->direita != NULL) {
            printf("D - Ir para a direita (%s)\n", atual->direita->nome);
        }

        printf("S - Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        // Move o jogador para a sala escolhida, se o caminho existir.
        if ((opcao == 'E' || opcao == 'e') && atual->esquerda != NULL) {
            atual = atual->esquerda;
        }
        else if ((opcao == 'D' || opcao == 'd') && atual->direita != NULL) {
            atual = atual->direita;
        }
        else if (opcao == 'S' || opcao == 's') {
            printf("Voce saiu da mansao.\n");
            break;
        }
        else {
            printf("Caminho invalido.\n");
        }
    }
}


int main() {
// Cria a mansao, inicia a exploracao e libera a memoria ao final.
No* mansao = montarMansao();    
printf("Bem-vindo a Detective Quest!\n");
explorarSalas(mansao);
liberarArvore(mansao);
    return 0;
}
