#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constante estática que pode ser alterada só aqui, com valor máximo
#define MAX_VETOR 10

// criacao structs - vetor
// define uma struct chamada Item que aloca memoria para guardar o nome, tipo e quantidade
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
}Item; //atalho para chamar apenas Item e não struct Item

//define uma mochila com tamanho fixo
typedef struct {
    Item itens[MAX_VETOR];//cria um vetor sequencial que contém 10 structs do tipo Item
    int quantidadeItens;// contador que indica quantos itens reais existem dentro dos 10 espaços alocados
} Mochila_Vetor; //nome da nova struct que guarda a struct Item

// criacao structs - Encadeada
// aponta para o primeiro No logo na definicao
typedef struct No {
    Item dados;//carrega uma copia completa da struct Item
    struct No*proximo; // aponta para o proximo No que guarda a struct Item
}No;

typedef struct{
    No* inicio;//guarda o endereço do 1o. No da lista
}Mochila_Encadeada;//ao ser chamada aponta para o inicio da lista

// prototipo das funções
//funções para vetor
void inicializarMochilaVetor(Mochila_Vetor* mochila);
int inserirItemVetor(Mochila_Vetor* mochila, Item novo);
int removerItemVetor(Mochila_Vetor* mochila, const char* nome);
void buscarSequencialVetor(const Mochila_Vetor* mochila, const char* nome);
void ordenarVetorNome(Mochila_Vetor*mochila);
void buscarBinariaVetor(const Mochila_Vetor* mochila, const char* nome);
void listarItensVetor(const Mochila_Vetor* mochila);
//funções para encadeada
void inicializarMochilaEncadeada(Mochila_Encadeada* mochila);
int inserirItemEncadeada(Mochila_Encadeada* mochila, Item novo);
int removerItemEncadeada(Mochila_Encadeada* mochila, const char* nome);
void listarItensEncadeada(const Mochila_Encadeada* mochila);
void buscarSequencialEncadeada(const Mochila_Encadeada* mochila, const char* nome);
void limparMochilaEncadeada(Mochila_Encadeada* mochila);
// função main
int main() {
    Mochila_Vetor mochilaVetor;
    Mochila_Encadeada mochilaEncadeada;

    inicializarMochilaVetor(&mochilaVetor);
    inicializarMochilaEncadeada(&mochilaEncadeada);

    int opcao, subOpcao;
    char nome_busca[30];

    do {
        printf("\n=================================================");
        printf("\n   MOCHILA DA SOBREVIVÊNCIA - CÓDIGO DA ILHA \n");
        printf("=================================================\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens na Mochila\n");
        printf("4. Buscar Itens por Nome\n");
        printf("5. Ordenar Itens por Nome (Selection Sort)\n");
        printf("0. Sair\n");
        printf("\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch(opcao){
            case 1:{
                Item novo;
                printf("\n=== Adicionar Novo Item ===\n");
                printf("Nome do item: ");
                fgets(novo.nome, sizeof(novo.nome), stdin);
                novo.nome[strcspn(novo.nome, "\n")] = '\0'; // Remove o caractere de nova linha

                printf("Tipo do item: ");
                fgets(novo.tipo, sizeof(novo.tipo), stdin);
                novo.tipo[strcspn(novo.tipo, "\n")] = '\0'; // Remove o caractere de nova linha

                printf("Quantidade do item: ");
                scanf("%d", &novo.quantidade);
                getchar(); // Limpar o buffer do teclado

                printf("\n");
                printf("Escolha o tipo de lista para adicionar o item:\n");
                printf("1. Vetor\n");
                printf("2. Encadeada\n");
                printf("\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);
                getchar(); // Limpar o buffer do teclado

                if(subOpcao == 1) {
                    if (inserirItemVetor(&mochilaVetor, novo)) {
                        printf("\n");
                        printf("Item '%s' adicionado com sucesso na Mochila Vetor!\n", novo.nome);
                    } else {
                        printf("\n");
                        printf("Erro: Mochila (Vetor) cheia!\n");
                    }
                } else if(subOpcao == 2) {
                    if (inserirItemEncadeada(&mochilaEncadeada, novo)) {
                        printf("\n");
                        printf("Item '%s' adicionado com sucesso na Mochila Encadeada!\n", novo.nome);
                    } else {
                        printf("\n");
                        printf("Erro: Falha ao adicionar item na Mochila Encadeada!\n");
                    }
                } else {
                    printf("\n");
                    printf("Opcao inválida!\n");
                }
                break;
            }
            case 2: 
                printf("\n");
                printf("De qual estrutura de dados deseja remover o item?\n");
                printf("1. Vetor\n");
                printf("2. Encadeada\n");
                printf("\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);
                getchar(); // Limpar o buffer do teclado

                if(subOpcao == 1) {
                    printf("Digite o nome do item a ser removido: ");
                    fgets(nome_busca, sizeof(nome_busca), stdin);
                    nome_busca[strcspn(nome_busca, "\n")] = '\0';

                    if (removerItemVetor(&mochilaVetor, nome_busca)) {
                        printf("\n");
                        printf("Item '%s' removido com sucesso da Mochila Vetor!\n", nome_busca);
                    } else {
                        printf("\n");
                        printf("Erro: Item '%s' não encontrado na Mochila Vetor!\n", nome_busca);
                    }
                } else if(subOpcao == 2) {
                    printf("\n");
                    printf("Digite o nome do item a ser removido: ");
                    fgets(nome_busca, sizeof(nome_busca), stdin);
                    nome_busca[strcspn(nome_busca, "\n")] = '\0';

                    if (removerItemEncadeada(&mochilaEncadeada, nome_busca)) {
                        printf("\n");
                        printf("Item '%s' removido com sucesso da Mochila Encadeada!\n", nome_busca);
                    } else {
                        printf("\n");
                        printf("Erro: Item '%s' não encontrado na Mochila Encadeada!\n", nome_busca);
                    }
                } else {
                    printf("\n");
                    printf("Opcao inválida!\n");
                }
            break;

        case 3:
            printf("\n");
            printf("De qual estrutura de dados deseja listar os itens?\n");
            printf("1. Vetor\n");
            printf("2. Encadeada\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &subOpcao);
            getchar(); // Limpar o buffer do teclado

            printf("\n");
            if(subOpcao == 1) {
                listarItensVetor(&mochilaVetor);
            } else if(subOpcao == 2) {
                listarItensEncadeada(&mochilaEncadeada);
            } else {
                printf("Opcao inválida!\n");
            }
            break;
        // o único caso em que aparece a subopção é no caso 4, 
        case 4:
            printf("\n");
            printf("De qual estrutura de dados deseja buscar o item?\n");
            printf("1. Vetor\n");
            printf("2. Encadeada\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &subOpcao);
            getchar(); // Limpar o buffer do teclado

            if(subOpcao == 1) {
                printf("\n");
                printf("Digite o nome do item a ser buscado: ");
                fgets(nome_busca, sizeof(nome_busca), stdin);
                nome_busca[strcspn(nome_busca, "\n")] = '\0';

                printf("Escolha o tipo de busca para o Vetor:\n");
                printf("1. Busca Sequencial\n");
                // a busca binária não é recomendada para a lista encadeada, pois ela não é ordenada e não tem acesso direto aos elementos
                printf("2. Busca Binaria (O vetor precisa estar ordenado!)\n");//pode achar por coincidência matemática 
                printf("\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);
                getchar();

                if(subOpcao == 1) {
                    buscarSequencialVetor(&mochilaVetor, nome_busca);
                } else if(subOpcao == 2) {
                    buscarBinariaVetor(&mochilaVetor, nome_busca);
                } else {
                    printf("Opcao inválida!\n");
                }
            } else if(subOpcao == 2) {
                printf("\n");
                printf("Digite o nome do item a ser buscado: ");
                fgets(nome_busca, sizeof(nome_busca), stdin);
                nome_busca[strcspn(nome_busca, "\n")] = '\0';

                buscarSequencialEncadeada(&mochilaEncadeada, nome_busca);
            } else {
                printf("Opcao inválida!\n");
            }
            break;
        //só feito para a Mochila Vetor, pois a lista encadeada não tem ordenação
        case 5:
            printf("Ordenando itens da mochila (Vetor) por nome...\n");
            ordenarVetorPorNome(&mochilaVetor);
            printf("Itens ordenados com sucesso!\n");
            break;

        case 0:
            printf("Saindo do programa...\n");
            limparMochilaEncadeada(&mochilaEncadeada);
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
    }
} while(opcao != 0);

return 0;
}
// IMPLEMENTAÇÃO FUNÇÃO - VETOR

void inicializarMochilaVetor(Mochila_Vetor* mochila) {
    mochila->quantidadeItens = 0;
}
int inserirItemVetor(Mochila_Vetor* mochila, Item novo) {
    if (mochila->quantidadeItens >= MAX_VETOR) {
        return 0; // vetor cheio
    }
    mochila->itens[mochila->quantidadeItens] = novo;
    mochila->quantidadeItens++;
    return 1; // inserido com sucesso
}
int removerItemVetor(Mochila_Vetor* mochila, const char* nome) {
    for (int i = 0; i < mochila->quantidadeItens; i++) {
        if (strcmp(mochila->itens[i].nome, nome) == 0) {
            // desloca os itens restantes para preencher o espaço do item removido
            for (int j = i; j < mochila->quantidadeItens - 1; j++) {
                mochila->itens[j] = mochila->itens[j + 1];
            }
            mochila->quantidadeItens--;
            return 1; // removido com sucesso
        }
    }
    return 0; // item não encontrado
}
void buscarSequencialVetor(const Mochila_Vetor* mochila, const char* nome) {
    int comparacoes = 0;
    for (int i = 0; i < mochila->quantidadeItens; i++) {
        comparacoes++;
        if (strcmp(mochila->itens[i].nome, nome) == 0) {
            printf("\nItem encontrado (Sequencial - Vetor):\n");
            printf("Nome: %s | Tipo: %s | Qtd: %d\n", mochila->itens[i].nome, mochila->itens[i].tipo, mochila->itens[i].quantidade);
            printf("Número de comparações: %d\n", comparacoes);
            return;
        }
    }
    printf("Número de comparações: %d\n", comparacoes);
    printf("Erro: Item não encontrado na Mochila Vetor!\n");
}
void ordenarVetorPorNome(Mochila_Vetor* mochila) {
    // implementação do algoritmo de ordenação Selection Sort para ordenar os itens da mochila por nome
    for (int i = 0; i < mochila->quantidadeItens - 1; i++) {
        int min_indice = i;
        for (int j = i + 1; j < mochila->quantidadeItens; j++) {
            if (strcmp(mochila->itens[j].nome, mochila->itens[min_indice].nome) < 0) {
                min_indice = j;
            }
        }
        if (min_indice != i) {
            Item temp = mochila->itens[i];
            mochila->itens[i] = mochila->itens[min_indice];
            mochila->itens[min_indice] = temp;
        }
    }
}
// essa função de busca binária só funciona para a mochila do tipo vetor, pois a lista encadeada não tem ordenação e não tem acesso direto aos elementos
void buscarBinariaVetor(const Mochila_Vetor* mochila, const char* nome) {
    int comparacoes = 0;
    int inicio = 0;
    int fim = mochila->quantidadeItens - 1;

    while (inicio <= fim) {
        comparacoes++;
        int meio = inicio + (fim - inicio) / 2;
        int res = strcmp(mochila->itens[meio].nome, nome);

        if (res == 0) {
            printf("\nItem encontrado (Binária - Vetor):\n");
            printf("Nome: %s | Tipo: %s | Qtd: %d\n", mochila->itens[meio].nome, mochila->itens[meio].tipo, mochila->itens[meio].quantidade);
            printf("Número de comparações: %d\n", comparacoes);
            return;
        } else if (res < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("Número de comparações: %d\n", comparacoes);
    printf("Erro: Item não encontrado na Mochila Vetor!\n");
}
void listarItensVetor(const Mochila_Vetor* mochila) {
    if (mochila->quantidadeItens == 0) {
        printf("A Mochila Vetor está vazia!\n");
        return;
    }
    printf("\n============= Itens na Mochila Vetor (%d/10) =============\n", mochila->quantidadeItens);
    printf("\n%-4s |%-20s|%-20s|%s\n", "Nº", "NOME", "TIPO", "QUANTIDADE");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < mochila->quantidadeItens; i++) {
        printf("%-4d|%-20s|%-20s|%d\n", i + 1, mochila->itens[i].nome, mochila->itens[i].tipo, mochila->itens[i].quantidade);
    }
}
