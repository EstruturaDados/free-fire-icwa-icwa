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
    

    return 0;
}