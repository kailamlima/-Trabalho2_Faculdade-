#ifndef PRODUTO_H
#define PRODUTO_H

#define TAM_STR 50

typedef struct {
    int codigo;
    char nome[TAM_STR];
    char marca[TAM_STR];
    int quantidade;
    float preco;
} Produto;

void limparBuffer();
void lerString(char *str, int tamanho);
int buscarProdutoPorCodigo(int codigo);

void imprimir(Produto P_tem);
void salvarProdutos(Produto produto);
void altearProduto2(Produto produto, int opcao);

void cadastrarProduto();
int alterarProduto();
int excluirProduto();

void listarProdutos();
void relatorioQuantidade();
void relatorioValor();

#endif
