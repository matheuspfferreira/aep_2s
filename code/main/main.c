// Importação de bibliotecas
#include <stdio.h>

// Declaração de procedimentos
void menuInicial();
void pularLinhas();

// Declaração de funções
int resgataOpcao();

// Execução do programa
int main() {

    // Declaração de variáveis
    int continuarPrograma = 1, opcaoEscolhida;

    // Iniciando o programa
    while (continuarPrograma) {

        // Exibindo as opções
        menuInicial();
        opcaoEscolhida = resgataOpcao();

        // Recolhendo a opção do usuário
        if (opcaoEscolhida != 0) {

            // Redirecionando o usuário
            switch (opcaoEscolhida) {
                case 1:
                    printf("Cadastro de usuario");
                    break;
                case 2:
                    printf("Alteracao de usuario");
                    break;
                case 3:
                    printf("Exclusao de usuario");
                    break;
                case 4:
                    printf("Lista de usuarios");
                    break;
                default:
                    printf("Encerrando o programa");
                    continuarPrograma = 0;
            } pularLinhas();
            
        } else {
            printf("Opcao invalida \n");
        } pularLinhas();

    }
    
    // Fim da execução
    return 0;

}

// Inicialização de procedimentos
void menuInicial() {
    printf("===== Menu Inicial ===== \n\n1. Cadastro de usuario\n2. Alteracao de usuario\n3. Exclusao de usuario\n4. Listagem de usuarios\n5. Sair\n\n");
}

void pularLinhas() {
    for (int i = 0; i < 3; i++) {
        printf("\n");
    }
}

// Inicialização de funções
int resgataOpcao() {
    int opcao; 
    printf("Informe a opcao desejada: ");
    scanf("%d", &opcao);
    if (opcao < 1 || opcao > 5) {
        return 0;
    }
    return opcao;
}