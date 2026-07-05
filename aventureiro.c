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
