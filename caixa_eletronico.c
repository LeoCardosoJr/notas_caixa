#include <stdio.h>
#include <conio.h> // getch

int qtd_notas(float *valor, float notas); // Verifica quantas notas podem ser entregues de determinado valor

// função main inicia execução do programa
int main (void) {

	int invalido;
	float valor = 0;
    
   do{ // Refazer o saque (caso o valor do saque tenha sido inválido)
   
   	   invalido = 0;
   		
	   int qtd100, qtd50, qtd20, qtd10, qtd5, qtd2; 
	   
	   system("clear || cls"); // Clear para linux e cls para windows
	   	
	   printf("Informe o valor de saque:"); // Solicita ao usuuário que insira o valor de saque
	   scanf("%f", &valor); // lê o valor de saque
	   
	   qtd100 = qtd_notas(&valor, 100.00);
	   qtd50  = qtd_notas(&valor, 50.00);
	   qtd20  = qtd_notas(&valor, 20.00);
	   qtd10  = qtd_notas(&valor, 10.00);
	   qtd5   = qtd_notas(&valor, 5.00);
	   qtd2   = qtd_notas(&valor, 2.00);
	   
	   if(valor == 0){
	   	
			printf("A quantidade de notas de 100: %d\n", qtd100);
			
			printf("A quantidade de notas de 50: %d\n", qtd50);
			
			printf("A quantidade de notas de 20: %d\n", qtd20);
			
			printf("A quantidade de notas de 10: %d\n", qtd10);
			
			printf("A quantidade de notas de 5: %d\n", qtd5);
			
			printf("A quantidade de notas de 2: %d\n", qtd2);
	    
		} // Fim do if
		else{
			
			printf("Saques somente com valores que possam ser entregues com as notas de 100, 50, 20, 10, 5 e 2 reais\n\n");
			printf("1 - Refazer saque\nQualquer telca - Sair\n");
			setbuf(stdin, NULL);
			invalido = (int) getch();
			invalido -= 48; // 0 da tabela ASC = 48 a função getch pega o valor da tabela ASC
			
			if(invalido != 1){
				return 0;
			} // Fim do if
			
		} // Fim do else
		
	}while(invalido == 1);
	    
    return 0; // retorna ao SO que o programa foi concluído com sucesso
    
} // fim função main

int qtd_notas(float *valor, float notas){
	
	int aux;
	
	if(*valor >= notas){
		
		aux = (int) *valor/notas; // Retorna o inteiro da divisão
		*valor = *valor - (aux * notas); // Verifica o valor de notas que foi passado ao usuário e diminui do valor do saque
		return aux; // Retorna quantidade de notas 
		
	} // Fim do if
	else{
		return 0; // Zero notas podem ser dados do valor passado
	} // Fim do else
	
} // Fim quantidade de notas
