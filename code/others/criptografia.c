// Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

// Defini��o de constantes
#define CODIGO_CARACTERE_SUBSTITUTO 42

// Declara��o de procedimentos
void criptografaSenha(char* senhaResgatada);

// Declara��o de fun��es
int verificaIntegridadeSenha(char* senhaResgatada);

// Execu��o do programa
int main() {
	
	// Declara��o de vari�veis
	char nomeUsuario[30], senha[15];
	int continuarPrograma = 1;
	
	// In�cio da execu��o
	
		
	// Resgatando as informa��es
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
	
	// Fim da execu��o
	return 0;
	
}

// Inicializa��o de procedimentos
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

// Inicializa��o de fun��es
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
