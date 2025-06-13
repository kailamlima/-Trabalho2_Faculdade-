#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char *str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int buscarProdutoPorCodigo(int codigo){
	
	FILE *arqA = fopen("estoque.txt", "r");
	int temp;
	
	if(arqA == NULL){
		printf("ERRO: nao foi pocivel abrir o arquivo |estoque.txt|");
		return 2;
	}
	
	while(fscanf(arqA, "%d;%*49[^;];%*49[^;];%*d;%*f\n", &temp) == 1){
		if(codigo == temp){
			fclose(arqA);
			return 1;
		}
	}
	
	fclose(arqA);
	return 0;	
}

void imprimir(Produto P_tem){
	printf("--------------------------------------------------------------------------\n");
	printf("Codigo: %d | Nome: %s | Marca: %s | Qtd: %d | Preco: R$%.2f\n",
	P_tem.codigo,
	P_tem.nome,
	P_tem.marca,
	P_tem.quantidade,
	P_tem.preco);
	printf("--------------------------------------------------------------------------\n");
	printf("\n");
}

void salvarProdutos(Produto produto) {
	int i;
    FILE *f = fopen("estoque.txt", "a");
    
    fprintf(f, "%d;%s;%s;%d;%.2f\n",
        produto.codigo,
        produto.nome,
        produto.marca,
        produto.quantidade,
        produto.preco);
    
    fclose(f);
}

void altearProduto2(Produto produto, int opcao){
	FILE *f = fopen("estoque.txt", "r");
	FILE *temp = fopen("temp.txt", "w");
	Produto P_tem;
	
	if (f == NULL){
		printf("ERRO: Nao foi possivel abrir o estoque para leitura.\n");
		fclose(f);
		fclose(temp);
		return;
	}
	if (temp == NULL){
		printf("ERRO: Nao foi possivel criar arquivo temporario.\n");
		fclose(f);
		fclose(temp);
		return;
	}
	
	while(fscanf(f, "%d;%49[^;];%49[^;];%d;%f\n", 
		&P_tem.codigo, P_tem.nome, P_tem.marca,
		&P_tem.quantidade, &P_tem.preco) == 5){
						
		if(produto.codigo == P_tem.codigo){
			
			
			if(opcao !=5){
			fprintf(temp, "%d;%s;%s;%d;%.2f\n",
			P_tem.codigo,
			P_tem.nome,
			P_tem.marca,
			(opcao == 2) ? P_tem.quantidade : produto.quantidade,
			(opcao == 1) ? P_tem.preco : produto.preco);
			}
		
		}else{
			fprintf(temp, "%d;%s;%s;%d;%.2f\n",
			P_tem.codigo,
			P_tem.nome,
			P_tem.marca,
			P_tem.quantidade,
			P_tem.preco);
		}	
						
	}
	fclose(f);
	fclose(temp);
	remove("estoque.txt");
	rename("temp.txt", "estoque.txt");
}

void cadastrarProduto() {
    Produto novo;
    
    while(1){
	
	
	    printf("Codigo do produto: ");
	    scanf("%d", &novo.codigo);
	    
	    limparBuffer();
	    
	    if (buscarProdutoPorCodigo(novo.codigo) != 0) {
	        printf("\nEsse codigo ja existe! Tente outro\n\n");
	    }else{
	    	break;
		}
	}	
	
	printf("Nome do produto: ");
	lerString(novo.nome, TAM_STR);
	
	printf("Marca: ");
	lerString(novo.marca, TAM_STR);
	
	printf("Quantidade: ");
	scanf("%d", &novo.quantidade);
	
	printf("Preco unitario: ");
	scanf("%f", &novo.preco);
	limparBuffer();
	    
	salvarProdutos(novo);
	printf("Produto cadastrado com sucesso!\n");
	system("cls");
}

int alterarProduto() {
    int idx, opcao;
    Produto novo;
    
    printf("Informe o codigo do produto para alterar: ");
    scanf("%d", &novo.codigo);
    printf("\n");
    limparBuffer();

    if (buscarProdutoPorCodigo(novo.codigo) == 0) {
        printf("Produto nao encontrado!\n");
        printf("Retornando pro menu !! \n");
        return 0;
    }
    
	do{
	    printf("Escolha o que deseja alterar?\n");
	    printf("1 para Quantidade\n");
	    printf("2 para Preco\n");
	    printf("3 para Ambos\n");
	    printf("Opcao: ");
	    scanf("%d", &opcao);
	    
	    limparBuffer();
	
		if (opcao == 1){
			
	        printf("Nova quantidade: ");
	        scanf("%d", &novo.quantidade);
	            
	    }else if(opcao == 2){
		
	        printf("Novo preco: ");
	        scanf("%f", &novo.preco);
	            
		}else if(opcao == 3){
		
		
	        printf("Nova quantidade: ");
	        scanf("%d", &novo.quantidade);
	        printf("Novo preço: ");
	        scanf("%f", &novo.preco);
		}else{
		
	        printf("\nOpcao invalida! Tente novamente \n\n");
	        	
		}
		
	}while (opcao < 1 || opcao > 3);
	
    limparBuffer();

    altearProduto2(novo, opcao);
    printf("Produto alterado com sucesso!\n");
}

int excluirProduto() {
    
    Produto novo;
    int opcao = 5;
    
    printf("Informe o codigo do produto para excluir: ");
    scanf("%d", &novo.codigo);
    limparBuffer();

    if (buscarProdutoPorCodigo(novo.codigo) == 0) {
        printf("Produto nao encontrado!\n");
        return 0;
    }

    

    altearProduto2(novo, opcao);
    printf("Produto excluido com sucesso!\n");
}

void listarProdutos() {
	int opcao, i;
    char filtro[TAM_STR];
    Produto P_tem;
    
	do{
	    printf("Escolha a opcao desejada para a listagem \n");
	    printf("1 para listar todos os produtos cadastrados \n");
	    printf("2 para Nome\n");
		printf("3 para Marca\n");
	    printf("opcao: ");
	    scanf("%d", &opcao);
	    printf("\n");
	    
	    limparBuffer();
	    
		if(opcao == 2){
			printf("Digite o NOME para filtrar: ");
			lerString(filtro, TAM_STR);
		}
		
		if(opcao == 3){
			printf("Digite o Marca para filtrar: ");
			lerString(filtro, TAM_STR);
		}
	    
	    
		
	    FILE *f = fopen("estoque.txt", "r");
	    if (f == NULL){ printf("erro na leitura"); return; } 
	    	
		
	    	
	    printf("Lista de todos os Produtos:\n");
	    	
		while(fscanf(f, "%d;%49[^;];%49[^;];%d;%f\n", 
		&P_tem.codigo, P_tem.nome, P_tem.marca,
		&P_tem.quantidade, &P_tem.preco) == 5){
		    if((opcao == 1) ||
            (opcao == 2 && strcmp(P_tem.nome, filtro) == 0) ||
            (opcao == 3 && strcmp(P_tem.marca, filtro) == 0)) {
					imprimir(P_tem);
			}
		}
		
		fclose(f);
		
	    if(opcao < 1 || opcao > 3) {
            printf("Opcao invalida!\n");
        }
	}while (opcao < 1 || opcao > 3);
}

void relatorioQuantidade() {
    int opcao, i;
	int total = 0;
    char filtro[TAM_STR];
	Produto P_tem;
	
	do{
	    printf("Consultar quantidade por:\n");
	    printf("1 para Nome \n");
	    printf("2 para Marca\n");
	    printf("Opcao: ");
	    scanf("%d", &opcao);
	    
	    if(opcao == 1 || opcao == 2){
	    	
	    	FILE *f = fopen("estoque.txt", "r");
	    	if (f == NULL){ printf("erro na leitura"); return; }
	    	
		    limparBuffer();
		
		    printf((opcao == 1)? "Informe o Nome: " : "Informe o Marca: ");
		    lerString(filtro, TAM_STR);
		
		    while(fscanf(f, "%d;%49[^;];%49[^;];%d;%f\n", 
			&P_tem.codigo, P_tem.nome, P_tem.marca,
			&P_tem.quantidade, &P_tem.preco) == 5) {
		        
				if ((opcao == 1 && strcmp(P_tem.nome, filtro) == 0) ||
		            (opcao == 2 && strcmp(P_tem.marca, filtro) == 0)) {
		            total += P_tem.quantidade;
		        }
		    }
		    
		    fclose(f);
		    
	    	printf("Quantidade total encontrada: %d unidades\n", total);
	    }else{
	    	system("cls");
			printf("\nOpcao invalida! Tente novamente \n\n");
			}
	}while (opcao < 1 || opcao > 2);
}

void relatorioValor() {
    int opcao;
    char filtro[TAM_STR];
    Produto p_temp;
    float total = 0.0;

    do {
        printf("--- Relatorio de Valor em Estoque (R$) ---\n");
        printf("1. Consultar por NOME\n");
        printf("2. Consultar por MARCA\n");
        printf("Opcao (ou 0 para voltar): ");
        scanf("%d", &opcao);
        limparBuffer();

        if (opcao == 1 || opcao == 2) {
            
            printf((opcao == 1) ? "Informe o Nome: " : "Informe a Marca: ");
            lerString(filtro, TAM_STR);

            FILE *f = fopen("estoque.txt", "r");
            if (f == NULL) {
                printf("ERRO ao abrir o arquivo!\n");
                return;
            }

            while (fscanf(f, "%d;%49[^;];%49[^;];%d;%f\n",
                          &p_temp.codigo, p_temp.nome, p_temp.marca,
                          &p_temp.quantidade, &p_temp.preco) == 5) {
                
                if ((opcao == 1 && strcmp(p_temp.nome, filtro) == 0) ||
                    (opcao == 2 && strcmp(p_temp.marca, filtro) == 0)) {
                    
                    
                    total += p_temp.quantidade * p_temp.preco;
                }
            }

            fclose(f);

            
            printf("\nValor total em estoque para o filtro '%s': R$%.2f\n\n", filtro, total);
            total = 0.0;

        } else if (opcao != 0 && opcao != 1 && opcao != 2) {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0 && opcao != 1 && opcao != 2);
}



