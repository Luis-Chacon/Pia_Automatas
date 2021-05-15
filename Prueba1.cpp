#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

bool val_NomProg(char* linea);
bool val_iniciar(char* linea);
bool val_Quees(char* linea);
bool val_leer(char* linea1);
bool val_operacion(char* linea1);//Aiuda Lorenzo xd 
bool val_imprimir(char* linea1);
bool val_terminar(char* linea1);

int main()
{
	bool bandera = false;
	int contador=0;
	char cad[100];
	
	FILE *documento = fopen ("Pia_Automatas.txt","r");
	if(documento == NULL)
	{
		printf("Error no se pudo abrir el archivo de texto");
		puts("\n");
		system("pause");
		return 0;
	}
	

	while(feof(documento) == 0)
	{
		fgets(cad,100,documento);

		if(contador < 2)
		{
			if(contador == 0)
			{
				bandera = val_NomProg(cad);
				contador++;
				if(!bandera)
				{
					printf("Error en la instruccion programa nombre, ERROR DE SINTAXIS");
				}
			}
			else
			{
				bandera = val_iniciar(cad);
				contador++;
				if(!bandera)
				{
					printf("Error en la instruccion iniciar, ERROR DE SINTAXIS");
				}
			}
		}	
		else if(contador == 2)		//Validar que minimo haya un leer;
		{
			bandera = val_leer(cad);
			contador++;
			if(!bandera)
			{
					printf("Error en instruccion leer, ERROR DE SINTAXIS");
			}
		}
			else if(contador > 2)
			{
				bandera = val_Quees(cad);
			}
			
		if(!bandera)
			break;
			
	}
	
	if(bandera)
		puts("\nPrograma Copilado Correctamente");
		
	else
		puts("\n------ERROR DEL PROGRAMA------");
	
	
	
	fclose(documento);
	
	puts("\n");
	system("pause");
	return 0;
}

bool val_NomProg(char* linea)
{
	char NomProg[] = "programa ";
	int i,j=0;
	bool ban = false;
	
	for(i=0;i<strlen(linea);i++)
	{
		if( i<=8 && NomProg[i] == linea[i])
		{
			ban = true;
			//printf("\n%d",i);
		}
		else if(i>8)
		{
			if(isalpha(linea[i]) && j != -1)
			{
				j++;		
			}
			else if( (j > 0 || j == -1) && isdigit(linea[i]))
			{
				j = -1;
				//puts("\nBan Verdadero 2");
				ban = true;
			}
				else if(linea[i] == ';' && linea[i+1]=='\n')
				
				{
					ban = true;
					//puts("\nBan Verdadero 3");
					break;
				}
					else
					{
						ban = false;
						break;
					}
		}
			else
			{
				ban = false;
				break;
			}
					
	}

	return ban;
	
}

bool val_iniciar(char* linea)
{
	char iniciar[]= "iniciar\n";

	int i=strcmp(iniciar,linea);
	bool ban;
	
	if(i == 0)
	{
		ban=true;
	}
	
	return ban;
}



bool val_Quees(char* linea)
{
	char terminar[]= "terminar";
	char leer[]="leer";
	char operacion[] = ":=";
	char imprimir[]= "imprimir";
	
	bool ban= false;



	if(strstr(linea,leer) != NULL)
	{
		ban = val_leer(linea);
		if(!ban)
		{
			printf("Error en instruccion leer, ERROR DE SINTAXIS");
		}

	}
	else if(strstr(linea,operacion) != NULL)
	{
		ban = true;
		//val_operacion(linea);
		if(!ban)
		{
			printf("Error en instruccion Oprecion, ERROR DE SINTAXIS");
		}

	}
		else if(strstr(linea,imprimir) != NULL)
		{
			ban = val_imprimir(linea);
			if(!ban)
			{
				printf("Error en instruccion imprimir, ERROR DE SINTAXIS");
			}

		}
			else if(strstr(linea,terminar) != NULL)
			{
				ban=val_terminar(linea);
				if(!ban)
				{
				printf("Error en instruccion terminar, ERROR DE SINTAXIS");
				}
			}
				else
				{
					ban=false;
				}
	return ban;
}


bool val_leer(char* linea1)
{
	char leer[]="leer ";
	int i;
	int j=0;
	bool ban = false;
	
	for(i=0;i<strlen(linea1);i++)
	{
		if(i<=4 && leer[i] == linea1[i])
		{
			//printf("\n%c == %c", leer[i], linea[i]);
			//ban = true;
		}
		else if(i>4 && isalpha(linea1[i]) && j==0)
		{
			j = 1;
		}
			//Si fuera solo para una letra leer i; este else if no va
			else if((isalpha(linea1[i]) || isdigit(linea1[i])) && j == 1)
			{
			}
				else if(linea1[i] == ';' && linea1[i+1]=='\n')
				{
					ban = true;
					break;	
				}
				else 
				{
					ban = false;
					break;
				}
	}
	
	return ban;
	
}



bool val_imprimir(char* linea1)
{
	char imprimir[]= "imprimir ";
	int i;
	int j=0;
	bool ban = false;
	
	for(i=0;i<strlen(linea1);i++)
	{
		if(i<=8 && imprimir[i] == linea1[i])
		{
			//printf("\n%c == %c", leer[i], linea[i]);
			//ban = true;
		}
		else if(i>8 && isalpha(linea1[i]) && j==0)
		{
			j = 1;
		}
			//Si fuera solo para una letra leer i; este else if no va
			else if((isalpha(linea1[i]) || isdigit(linea1[i])) && j == 1)
			{
			}
				else if(linea1[i] == ';' && linea1[i+1]=='\n')
				{
					ban = true;
					break;	
				}
				else 
				{
					ban = false;
					break;
				}
	}
	
	return ban;
}


bool val_terminar(char* linea1)
{
	char terminar[]= "terminar.\n";

	int i=strcmp(terminar,linea1);
	bool ban;
	
	if(i == 0)
	{
		ban=true;
	}
	
	return ban;
}


