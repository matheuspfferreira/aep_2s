// Importação de bibliotecas
#include <stdio.h>
#include <string.h>

// Definição de constantes
#define CODIGO_CARACTERE_SUBSTITUTO 42

// Declaração de procedimentos
void criptografaSenha(char* senhaResgatada);

// Declaração de funções
int verificaIntegridadeSenha(char* senhaResgatada);

// Execução do programa
int main() {
	
	// Declaração de variáveis
	char nomeUsuario[30], senha[15];
	int continuarPrograma = 1;
	
	// Início da execução
	
		
	// Resgatando as informações
	printf("Informe seu nome de usuario: ");
	gets(nomeUsuario);
	printf("Informe sua senha: ");
	gets(senha);
		
	// Exibindo a nova senha
	if (verificaIntegridadeSenha(senha)) {
	    criptografaSenha(senha);
	    printf("%s", senha);
	} else if (!verificaIntegridadeSenha(senha)) {
	    printf("Senha pequena ou invalida");
	}
	
	// Fim da execução
	return 0;
	
}

// Inicialização de procedimentos
void criptografaSenha(char* senhaResgatada) {
	int tamanhoSenha, somador, codigoNovoCaractere; 
	somador = tamanhoSenha = strlen(senhaResgatada);
	for (int i = 0; i < tamanhoSenha; i++) {
		codigoNovoCaractere = (int) senhaResgatada[i] + somador;
		if (codigoNovoCaractere > 126) {
			codigoNovoCaractere = CODIGO_CARACTERE_SUBSTITUTO;
		} senhaResgatada[i] = (char) codigoNovoCaractere;	
		somador--;
	}	
}

// Inicialização de funções
int verificaIntegridadeSenha(char* senhaResgatada) {
    int tamanhoSenha = strlen(senhaResgatada), tamanhoValido, senhaValida;
    tamanhoValido = tamanhoSenha >= 6;
    if (tamanhoValido) {
        int quantidadeLetrasMaiusculas, quantidadeLetrasMinusculas, quantidadeNumeros, 
        letraMaiuscula, letraMinuscula, numero, codigoCaractere; 
        quantidadeLetrasMaiusculas = quantidadeLetrasMinusculas = quantidadeNumeros = 0;
        for (int i = 0; i < tamanhoSenha; i++) {
            codigoCaractere = (int) senhaResgatada[i];
            letraMaiuscula = codigoCaractere >= 65 && codigoCaractere <= 90;
            letraMinuscula = codigoCaractere >= 97 && codigoCaractere <= 122;
            numero = codigoCaractere >= 48 && codigoCaractere <= 57;
            if (letraMaiuscula) {
                quantidadeLetrasMaiusculas++;
            } else if (letraMinuscula) {
                quantidadeLetrasMinusculas++;
            } else if (numero) {
                quantidadeNumeros++;
            }
        } senhaValida = quantidadeLetrasMaiusculas >= 1 && quantidadeLetrasMinusculas >= 1 && quantidadeNumeros >= 1;
    } if (senhaValida) {
        return 1;
    } return 0;
}
