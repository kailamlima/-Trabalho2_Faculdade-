#include <stdio.h>
#include "produto.h"

int main() {
    int n = 0, opcao, i;

    do {
    	
    	printf("\n------------ MENU ------------ \n");
        printf("Digite 1 para Cadastrar Produto\n");
        printf("Digite 2 para Alterar Produto\n");
        printf("Digite 3 para Excluir Produto\n");
        printf("Digite 4 para Listar Produtos\n");
        printf("Digite 5 para Relatorio\n");
        printf("Digite 0 para Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

		limparBuffer(); 
		
        system("cls");

        if (opcao == 1){
        	printf("quantidade de produtos para cadrastar: \n");
        	scanf("%d", &n);
        	
        	for(i = 0; i < n; i++){
            	cadastrarProduto();
			}
			
        }else if (opcao == 2){
            alterarProduto();

        }else if (opcao == 3){
            excluirProduto();

        }else if (opcao == 4){
            listarProdutos();

        }else if (opcao == 5){
        	do{
				printf("\n");
	        	printf("Digite 1 para Relatorio de Quantidade\n");
	        	printf("Digite 2 para Relatorio de Valor Total\n");
	        	printf("opcao: ");
	        	scanf("%d", &opcao);
	        	printf("\n");
	        	
	        	if(opcao == 1){
	        		
	        		relatorioQuantidade();	
				}else if(opcao == 2){
					
					relatorioValor();
				}else{
					system("cls");
					printf("Opcao invalida! Tente novamente \n");
				}
            
			}while (opcao < 1 || opcao > 2);
        }else if (opcao == 0){
            printf("Saindo do programa...\n");

        }else{
            printf("Opcao invalida! Tente novamente\n");
        }
    } while (opcao != 0);

    return 0;
}
