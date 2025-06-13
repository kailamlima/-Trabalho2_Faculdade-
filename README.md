# -Trabalho2_Faculdade-
Sistema de Gerenciamento de Estoque em C.

Este é um sistema de console desenvolvido em C para gerenciar um estoque de produtos. O projeto foi criado como parte da disciplina de Algoritmos II e foca na manipulação direta de arquivos de texto para persistência de dados, sem o uso de vetores em memória para armazenamento em tempo de execução.

Uma lista com tudo que o programa faz:
* Cadastro de produtos com verificação de código único.
* Alteração de preço e quantidade.
* Exclusão de produtos.
* Listagem de todos os produtos ou com filtros por nome e marca.
* Relatórios de quantidade total e valor total por nome ou marca.

Um dos principais requisitos do projeto era que o sistema não tivesse um limite fixo de produtos. Para atender a isso, a arquitetura foi desenvolvida para manipular o arquivo estoque.txt diretamente a cada operação, em vez de carregar os dados para um vetor em memória. Para as operações de alteração e exclusão, foi implementada a técnica de arquivo temporário para garantir a integridade dos dados sem a necessidade de bibliotecas externas.

o projeto foi feito no Dev C++ 6.3

Para compilar o projeto, utilize um compilador GCC e execute o seguinte comando na pasta raiz: gcc main.c produto.c -o estoque.exe

por enqaunto o codigo funciona só em windows.
