// Importação de bibliotecas
#include <stdio.h>
#include <string.h>

// Declaração de constantes
#define QUANTIDADE_LINHAS_PULAR 3
#define CODIGO_CARACTERE_SUBSTITUTO 42

// Declaração de procedimentos
void menuInicial();
void pularLinhas();
void criptografaSenha(char* senhaResgatada);

// Declaração de funções
int resgataOpcao();
int verificaIntegridadeSenha(char* senhaResgatada);

// Execução do programa
int main() {

    // Declaração de variáveis
    int continuarPrograma = 1, opcaoEscolhida;

    // Iniciando o programa
    while (continuarPrograma) {

        // Exibindo as opções
        menuInicial();
        opcaoEscolhida = resgataOpcao();

        // Direcionando o usuário
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
            } pularLinhas(QUANTIDADE_LINHAS_PULAR);
            
        } else {
            printf("Opcao invalida \n");
        } pularLinhas(QUANTIDADE_LINHAS_PULAR);

    }
    
    // Fim da execução
    return 0;

}

// Inicialização de procedimentos
void menuInicial() {

    // Mostrando as opções disponíveis
    printf("===== Menu Inicial ===== \n\n1. Cadastro de usuario\n2. Alteracao de usuario\n3. Exclusao de usuario\n4. Listagem de usuarios\n5. Sair\n\n");

}

void pularLinhas(int quantidadeLinhas) {

    // Pulando uma quantidade determinada de linhas
    for (int i = 0; i < quantidadeLinhas; i++) {
        printf("\n");
    }

}

void criptografaSenha(char* senhaResgatada) {

    // Declaração de variáveis
	int tamanhoSenha, somador, codigoNovoCaractere; 
	somador = tamanhoSenha = strlen(senhaResgatada);

    // Alterando todos os caracteres da senha
	for (int i = 0; i < tamanhoSenha; i++) {

        // Atribuições
		codigoNovoCaractere = (int) senhaResgatada[i] + somador;

        // Verificando se o caractere está fora da tabela ASCII
		if (codigoNovoCaractere > 126) {
			codigoNovoCaractere = CODIGO_CARACTERE_SUBSTITUTO;
		} 
        
        // Aplicando a mudança
        senhaResgatada[i] = (char) codigoNovoCaractere;	
		somador--;

	}	

}

// Inicialização de funções
int resgataOpcao() {

    // Declaração de variáveis
    int opcao; 

    // Entradas e saídas
    printf("Informe a opcao desejada: ");
    scanf("%d", &opcao);

    // Realizando a verificação
    if (opcao < 1 || opcao > 5) {
        return 0;
    }
    return opcao;

}

int verificaIntegridadeSenha(char* senhaResgatada) {

    // Declaração de variáveis
    int tamanhoSenha = strlen(senhaResgatada), tamanhoValido, senhaValida;

    // Atribuições
    tamanhoValido = tamanhoSenha >= 6;

    // Verificando se a senha possui um tamanho válido
    if (tamanhoValido) {

        // Declaração de variáveis
        int quantidadeLetrasMaiusculas, quantidadeLetrasMinusculas, quantidadeNumeros, 
        letraMaiuscula, letraMinuscula, numero, codigoCaractere; 

        // Atribuições
        quantidadeLetrasMaiusculas = quantidadeLetrasMinusculas = quantidadeNumeros = 0;

        // Verificando se a senha atende aos requisitos
        for (int i = 0; i < tamanhoSenha; i++) {

            // Atribuições
            codigoCaractere = (int) senhaResgatada[i];
            letraMaiuscula = codigoCaractere >= 65 && codigoCaractere <= 90;
            letraMinuscula = codigoCaractere >= 97 && codigoCaractere <= 122;
            numero = codigoCaractere >= 48 && codigoCaractere <= 57;

            // Realizando as verificações
            if (letraMaiuscula) {
                quantidadeLetrasMaiusculas++;
            } else if (letraMinuscula) {
                quantidadeLetrasMinusculas++;
            } else if (numero) {
                quantidadeNumeros++;
            }

        } 
        
        // Atribuições
        senhaValida = quantidadeLetrasMaiusculas >= 1 && quantidadeLetrasMinusculas >= 1 && quantidadeNumeros >= 1;

    } if (senhaValida) {
        return 1;
    } return 0;

}