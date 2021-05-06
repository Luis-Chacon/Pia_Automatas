#include <stdio.h>
#include <stdlib.h>

struct datos_programa
{
	char nom_programa[20];
	char iniciar[8];
	char i[10];
	int val_i;
	char j[10];
	int val_j;
	char k[10];
	int val_k;
	char p[10];
	int val_p;
	char q[10];
	int val_q;
	char imprimir[15];
	char terminar[15];
};


int main()
{
	char cadena[20];
	
	struct datos_programa DP;
	int contador=0;
	int k=0;
	int *puntero;
	
	FILE *documento = fopen ("Pia_Automatas.txt","r");
	if(documento == NULL)
	{
		printf("Error no se pudo abrir el archivo de texto");
		puts("\n");
		system("pause");
		return 0;
	}
	
	char linea[100];
	//documento.getline(linea,sizeof(linea));
	while(feof(documento) == NULL)
	{

		/*switch (contador)
		{
		
			case 0: fscanf(documento,"%s",&DP.nom_programa);
					break;
			case 1: fscanf(documento,"%s",&DP.iniciar);
					break;
			
			case 2: if(k=0)
					{
						fscanf(documento,"%s %d",&DP.i, &DP.val_i);
						k++;
					}
					else if(k == 1)
					{
						puntero = strtok(linea, '34')
						strcpy(DP.val_i,puntero);
						//fscanf(documento,"%d",&DP.val_i);
						k=0;
					}	
					break;
			
			case 3: if(k=0)
					{
						fscanf(documento,"%s",&DP.j);
						k++;
					}
					else if(k == 1)
					{
						fscanf(documento,"%d",&DP.val_j);
						k=0;
					}	
					break;
			
			case 4: if(k=0)
					{
						fscanf(documento,"%s",&DP.k);
						k++;
					}
					else if(k == 1)
					{
						fscanf(documento,"%d",&DP.val_k);
						k=0;
					}	
					break;
			case 5: fscanf(documento,"%s",&DP.p);
					break;
			case 6: fscanf(documento,"%s",&DP.q);
					break;
			case 7: fscanf(documento,"%s",&DP.imprimir);
					break;
			case 8: fscanf(documento,"%s",&DP.terminar);
					break;
		}
		contador=contador+1;
		
		if(contador == 8)
		{
			printf("%s\n"
		   "%s\n"
		   "%s %d\n" 
		   "%s %d\n"
		   "%s %d\n"
		   "%s\n"
		   "%s\n"
		   "%s\n"
		   "%s\n",DP.nom_programa,DP.iniciar,DP.i,DP.val_i,DP.j,DP.val_j,DP.k,DP.val_k,DP.p,DP.q,DP.imprimir,DP.terminar);
		}*/
		fscanf(documento,"%s", &cadena);
		printf("\n%s", cadena);
	}
	
	
	
	fclose(documento);
	
	puts("\n");
	system("pause");
	return 0;
	
}
