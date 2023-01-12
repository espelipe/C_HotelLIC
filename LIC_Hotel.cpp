//JMRG, FCE, AC - Projeto do Hotel
//João Marcos Ribeirete Garbelini, Felipe Casagrande Espel, Andre Cavalcanti 
//projeto do hotel completo.

#include <stdio.h>

void fMostra(struct sthot M[20][14]);
void fReserva(struct sthot M[20][14]);
void fCheckin(struct sthot M[20][14]);
void fCheckout(struct sthot M[20][14]);
void fCancelarR(struct sthot M[20][14]);
void fOcupacao(struct sthot M[20][14]);
void fInformacao(struct sthot M[20][14]);
void fclear();


struct sthot
	{
		char status;
		char CPF[14];
		char Nome[40];
		char Endereco[70];
		char Telefone[15];
		char Email[40];
	};


main()
{
	int op;
	int i, j;
	struct sthot Hotel[20][14];
	
	//gera o mapa do hotel
	for(i = 20; i >= 1; i--)
		for(j = 1; j <= 14; j++)
	Hotel[i - 1 ][j - 1].status = '.';
	
	
	do
	{
		op = -1;
		while (op != 8)
			{
			printf("\n               -Hotel Kanoa- ");	
			printf("\n---------------------------------------------\n");	
			printf("|1 - Check-in de hospede                    |\n");
			printf("|2 - Check-out de hospede                   |\n");
			printf("|3 - Reserva de apartamento                 |\n");
			printf("|4 - Cancelar uma reserva                   |\n");
			printf("|5 - Mapa de ocupacao e reservas do hotel   |\n");
			printf("|6 - Informacoes do hospede                 |\n");
			printf("|7 - Taxas de ocupacao e reservas do hotel  |\n");
			printf("|8 - Sair do programa                       |\n");
			printf("---------------------------------------------\n");
			printf("\nDigite a sua opcao: ");
			scanf("%d", &op);
			switch (op)
				{
			
				case 1: 
					fCheckin(Hotel);
					break;
				case 2:
					fCheckout(Hotel);
					break;
				case 3:
					fReserva(Hotel);
					break;
				case 4:
					fCancelarR(Hotel);
					break;
				case 5:
					fMostra(Hotel);
					break;	
				case 6:
					fInformacao(Hotel);
					break;
				case 7:
					fOcupacao(Hotel);
					break;
				case 8:	
					break; 
				default:
					printf("opcao invalida\n");
					
				}
			}
		
	}while (op != 8);
	
}

//Mostra o mapa do Hotel
void fMostra(struct sthot M[20][14]) 
{
	int i, j;
	printf("\nApartamentos\t");
	for( j = 1; j <= 14; j++)
		printf("%2d ", j);
	printf("\n\n");
					
					
	//apresentacao da tabela
	for( i = 20; i >= 1; i--)
	{
		printf("Andar %2d\t", i);
		for( j = 1; j <= 14; j++)
			printf(" %c ", M[i-1][j-1].status);
		printf("\n");
	}
	
}

//Permite fazer uma reserva no Hotel
void fReserva(struct sthot M[20][14])	
{
	int i,j;
	printf("\nDigite andar e apartamento (separado por virgula) que deseja reservar: ");
	scanf("%d,%d", &i, &j);
	
	if (i < 0 || i > 20 || j < 0 || j > 14)
	{
		printf("Nao existe esse quarto\n");
	}
	if (M[i - 1][j - 1].status == 'O')	
		printf("\nQuarto ocupado\n");
	else		
		M[i - 1][j - 1].status = 'R';
}

//Executa o Check-in no Hotel
void fCheckin(struct sthot M[20][14])	
{
	int i,j;
	printf("\nDigite andar e apartamento (separado por virgula) que deseja ocupar: ");
	scanf("%d,%d", &i, &j);	
	if (i < 0 || i > 20 || j < 0 || j > 14)
	{
		printf("Nao existe esse apartamento\n");
	}
	if(M[i - 1][j - 1].status == 'O')
	{
		printf("Este quarto esta ocupado");
	}
	else
	{
		fclear();
		M[i - 1][j - 1].status = 'R';
		printf("\nNome:");
		gets(M[i - 1][j - 1].Nome);
		printf("\nCPF: ");
		gets(M[i - 1][j - 1].CPF);
		printf("\nEndereco: ");
		gets(M[i - 1][j - 1].Endereco);
		printf("\nTelefone: ");
		gets(M[i - 1][j - 1].Telefone);
		printf("\nEmail: ");
		gets(M[i - 1][j - 1].Email);
		M[i - 1][j - 1].status = 'O';
	}
	
}

//Desocupa o quarto do Hotel 
void fCheckout(struct sthot M[20][14])	 
{
	int i, j;
	printf("\nDigite andar e apartamento (separado por virgula) que ira desoculpar: ");
	scanf("%d,%d", &i, &j);	
	if (M[i-1][j-1].status != 'O')	
		printf("\nNao ha Check-in nesse apartamente\n");
	else		
		M[i-1][j-1].status = '.';
}

//Faz o cancelamento de uma Reserva
void fCancelarR(struct sthot M[20][14])	
{
	int i, j;
	printf("\nDigite andar e apartamento (separado por virgula) que deseja cancelar a reservar: ");
	scanf("%d,%d", &i, &j);
	if (M[i - 1][j - 1].status != 'R')	
		printf("\nEste quarto nao esta reservado\n");	
	else
		M[i - 1][j - 1].status = '.';
}

//Mostra a Taxa de Ocupacao e Reserva 
void fOcupacao(struct sthot M[20][14])	
{
	int r, o;
	float taxaR, taxaO, taxaT;
	
	//contagem de quantos quartos reservados
	r = 0;	
	for(int i=20; i>=1; i--)
		for(int j= 1 ; j<=14; j++)
		{
			if(M[i-1][j-1].status == 'R')
				r=r+1;	
		}
		
	//contagem de quantos quartos ocupados	
	o = 0;
	for(int i=20; i>=1; i--)
		for(int j= 1 ; j<=14; j++)
		{
			if(M[i-1][j-1].status == 'O')
				o=o+1;	
		}
	taxaR = r * 100.0 / (20 * 14);	//calculo da taxa de reserva
	taxaO = o * 100.0 /(20 * 14);	//calculo da taxa de ocupacao
	taxaT = (r+o)* 100.0 /(20 * 14);	//taxa de ocupacao total
	printf("\nA taxa de ocupacao e de %5.2f porcento\n ", taxaO);
	printf("A taxa de reserva e de %5.2f porcento\n ", taxaR);
	printf("o total de ocupado e reservado e de %5.2f porcento\n", taxaT);	
}

//Mostra a informacao do hospede
void fInformacao(struct sthot M[20][14])
{
	int i, j;
	printf("\nApartamento e andar (separado por virgula) que deseja as informacoes do hospede: ");
	scanf("%d,%d", &i, &j);
	if(M[i-1][j-1].status == '.' || M[i-1][j-1].status == 'R')
	{
		printf("Este quarto esta vazio");
	}
	else
	{
    	printf("\n------------------------------------------------------------\n");
    	printf("Nome: %s",M[i-1][j-1].Nome);
    	printf("\tCPF: %s\t\t",M[i-1][j-1].CPF);
    	printf("Endereco: %s\t\n",M[i-1][j-1].Endereco);
    	printf("Telefone: %s \n",M[i-1][j-1].Telefone); 
    	printf("Email: %s \n",M[i-1][j-1].Email);
    	printf("--------------------------------------------------------------\n");
    }	
	
}

//para limpeza do buffer do teclado
void fclear()
{
	char carac;
    while( (carac = fgetc(stdin)) != EOF && carac != '\n') {}
}
