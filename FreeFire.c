#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Estrutura que representa um item do inventário
typedef struct {
    char nome[30];      // Nome do item (ex: "Rifle", "Bandagem")
    char tipo[20];      // Tipo do item (ex: "Arma", "Cura", "Munição")
    int quantidade;     // Quantidade de unidades
} Item;

// Função para inserir um novo item no inventário
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\n⚠ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n--- Cadastro de novo item ---\n");
    printf("Nome do item: ");
    scanf("%s", mochila[*total].nome);

    printf("Tipo do item: ");
    scanf("%s", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;
    printf("✅ Item adicionado com sucesso!\n");
}

// Função para listar todos os itens do inventário
void listarItens(Item mochila[], int total) {
    printf("\n===== Itens na mochila =====\n");
    if (total == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%d. Nome: %-15s | Tipo: %-10s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função de busca sequencial (procura item pelo nome)
int buscarItem(Item mochila[], int total, char nomeBusca[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0)
            return i; // Retorna o índice do item encontrado
    }
    return -1; // Retorna -1 se não encontrar
}

// Função para remover um item pelo nome
void removerItem(Item mochila[], int *total) {
    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%s", nomeRemover);

    int pos = buscarItem(mochila, *total, nomeRemover);

    if (pos == -1) {
        printf("❌ Item não encontrado.\n");
        return;
    }

    // Desloca os itens para preencher o espaço vazio
    for (int i = pos; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--; // Reduz o contador total
    printf("🗑 Item removido com sucesso!\n");
}

// Função para buscar e exibir dados de um item específico
void exibirItem(Item mochila[], int total) {
    char nomeBusca[30];
    printf("\nDigite o nome do item para busca: ");
    scanf("%s", nomeBusca);

    int pos = buscarItem(mochila, total, nomeBusca);

    if (pos == -1) {
        printf("❌ Item não encontrado.\n");
        return;
    }

    printf("\n=== Item encontrado ===\n");
    printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
           mochila[pos].nome, mochila[pos].tipo, mochila[pos].quantidade);
}

int main() {
    Item mochila[MAX_ITENS]; // Vetor de structs representando a mochila
    int total = 0;           // Quantidade atual de itens
    int opcao;

    do {
        printf("\n===== MENU DE INVENTÁRIO =====\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                exibirItem(mochila, total);
                break;
            case 0:
                printf("\n👋 Saindo do sistema de inventário...\n");
                break;
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}