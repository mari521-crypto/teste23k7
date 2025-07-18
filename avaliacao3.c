#include <stdio.h>
#include <stdlib.h>

#define SALAS 3
#define PERIODOS 2

int exibirMenu() {
int opcao;
printf("\n MENU \n");
printf("1. Inserir temperatura\n");
printf("2. Exibir temperatura média geral\n");
printf("3. Exibir maior e menor temperatura\n");
printf("4. Verificar temperaturas acima de 30°C\n");
printf("0. Sair\n");
printf("Escolha uma opção: ");
scanf("%d", &opcao);
return opcao;
}

int main() {
float temperaturas[SALAS][PERIODOS];
int i, j;
int preenchido = 0;

int opcao;
do {
opcao = exibirMenu();
    
switch (opcao) {
 case 1:
            
printf("\n--- Inserir Temperaturas ---\n");
for (i = 0; i < SALAS; i++) {
for (j = 0; j < PERIODOS; j++) {
printf("Digite a temperatura da Sala %d, Período %d: ", i + 1, j + 1);
scanf("%f", &temperaturas[i][j]);
}
}
preenchido = 1;
break;

case 2:
if (!preenchido) {
printf("Insira as temperaturas primeiro (opção 1).\n");
break;
}

        
{
float soma = 0;
int total = SALAS * PERIODOS;
for (i = 0; i < SALAS; i++) {
for (j = 0; j < PERIODOS; j++) {
soma += temperaturas[i][j];
}
}
printf("Temperatura média geral: %.2f°C\n", soma / total);
}
break;

case 3:
if (!preenchido) {
printf("Insira as temperaturas primeiro (opção 1).\n");
break;
}
         
{
float maior = temperaturas[0][0];
float menor = temperaturas[0][0];

for (i = 0; i < SALAS; i++) {
for (j = 0; j < PERIODOS; j++) {
if (temperaturas[i][j] > maior)
maior = temperaturas[i][j];
if (temperaturas[i][j] < menor)
menor = temperaturas[i][j];
}
}
printf("Maior temperatura registrada: %.2f°C\n", maior);
printf("Menor temperatura registrada: %.2f°C\n", menor);
}
break;

case 4:
if (!preenchido) {
printf("Insira as temperaturas primeiro (opção 1).\n");
break;
}       

         
printf("\nTemperaturas acima de 30°C:\n");
int encontrou = 0;
for (i = 0; i < SALAS; i++) {
for (j = 0; j < PERIODOS; j++) {
if (temperaturas[i][j] > 30.0) {
printf("Sala %d, Período %d: %.2f°C\n", i + 1, j + 1, temperaturas[i][j]);
encontrou = 1;
}
}
}
 if (!encontrou) {
printf("Nenhuma temperatura acima de 30°C foi registrada.\n");
}
break;

case 0:
printf("Saindo do sistema...\n");
break;

default:
printf("Opção inválida. Tente novamente.\n");
}

} while (opcao != 0);

 return 0;
}
       