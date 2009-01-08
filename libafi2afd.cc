#include <iostream>
#include <fstream>

using namespace std;


#include "libafi2afd.h"


bool ProcesarLetra(char letra)
{
	bool esp=false;

	if(letra=='!' || letra=='#')
	{
		esp=true;
	}

	return esp;
}

void AlmacenaLetra(char l, bool e, int &lin, int &fil, tVector vOrig)
{
	vOrig[lin][fil]=l;

}

//Almacena y renombra los estados inciales del AFI.
void BuscarInicios(tVector Orig, tVectEstados Estados, int lineas)
{
	int cont=0;
	
	for(cont=0; cont<lineas; cont++)
	{
		if(Orig[cont][1]=='!')
		{
			Estados[0][Orig[cont][0]-'0']=true;
		}
	}
}

//Tenemos que rellenar el vector de caracteres
void CaracteresAFI(tVector Orig, int lineas, tVectCaracteres Caracteres, int &numCaracteres)
{
	int cont1=0;

	for(cont1=0; cont1<lineas; cont1++)
	{
		
		if(numCaracteres!=0)
		{
			if(!BuscarElemento(Caracteres, numCaracteres, (Orig[cont1][1])))
			{
				Caracteres[numCaracteres]=Orig[cont1][1];
				numCaracteres++;
			}
		}
		else
		{			
				Caracteres[numCaracteres]=Orig[cont1][1];
				numCaracteres++;
		}

	}
}

//Informa si existe el caracter en el vector
bool BuscarElemento(tVectCaracteres Caracteres, int tamano, char caracter)
{
	int cont=0;
	bool encontrado=false;

	if(caracter=='!' || caracter=='#')
	{
		encontrado=true;
	}
	else
	{
		for(cont=0; cont<tamano && encontrado==false; cont++)
		{
			if(Caracteres[cont]==caracter)
			{
				encontrado=true;
			}	
		}
	}
	return encontrado; 
}

//Almacena y renombra el resto de estados del AFI.
void Buscar(tVector Orig, tVectEstados Estados, int lineas,tVectCaracteres VectCaract, int numCaract)
{
	bool newEstado[10], estadoAux[10];
	for(int cont=0; cont<10;cont++)
	{
		newEstado[cont]=false;
		estadoAux[cont]=false;
	}
	//Recorrer el vector de estados para crear los nuevos estados
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Estados[i][j]==true)
			{
				estadoAux[j]=true;
			}
		}
		BuscarEstadoSiguiente(newEstado, Orig, VectCaract, estadoAux, Estados); //Busca y añade al vector de estados
	}
	

			
}

//Devuelve TRUE si el estado ya existe
bool BuscarRepetidos (tVectEstados Estados, bool newEstado[])
{
	bool repetido=false, iguales=true;
	int cont=0, i=0, j=0;
	
	for(i=0; i<100 && repetido==false; i++) //Por cada linea si no se ha encontrado
	{
		iguales=true;
		for(j=0; j<11 && iguales==true; j++) //Recorremos la linea
		{
			if(Estados[i][j]==newEstado[j])	//Si las posiciones son iguales
			{
				cont++;	//Aumenatmos el contador
			}
			else
			{
				iguales=false;	//Si alguno falla dejamos de recorrer esa linea
				cont=0; //Y ponemos el contador de nuevo a 0
			}
		}
		if(cont==10) //Si al terminar con una linea el contador es igual a 10
			repetido=true; //Esta repetido y podemos terminar la ejecucion
	}

	return repetido;
}

//Busca los estados siguientes del estado que se le pasa para crear un nuevo Estado
void BuscarEstadoSiguiente(bool newEstado[], tVector Orig, tVectCaracteres VectCaract, bool estadoAux[], tVectEstados Estados)
{
	int i,k;
	for(int j=0; j<5; j++) //Para cada letra
	{
		for(k=0; k<10;k++) //Para cada estado
		{
			if(estadoAux[k]==true) //Si el estado esta a true lo buscamos
			{
				for(i=0; i<100; i++) //Recorremos para buscar ese estado en el vector de origen
				{
					if(Orig[i][0]-'0'==k) //Si encontramos uno que coincide
					{
						if(Orig[i][1]==VectCaract[j]) //Y si ademas coincide la letra que estamos buscando
						{
							newEstado[Orig[i][2]-'0']=true; //Ponemos un true en nuestro estado
						}
					}
				}
				i=0;
			}
		}
		k=0;
		//Comprobar si existe
		if(!BuscarRepetidos(Estados, newEstado)) //Si no existe
		{
			//Meterlo al vector de estados
		}
	}
}














