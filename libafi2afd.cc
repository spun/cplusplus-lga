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
//De momento no tengo NPI de como rellenarlo si no es al almacenarlo en el primero, asi que lo pongo antes 
//de la funcion que la necesita (Buscar) y relleno como me da la gana
/*int cont=0, cont2=0;
bool repetido=false;

	for(cont=0; cont<lineas; cont++)
	{
		for(cont2=0; cont2<numCaracteres || numCaracteres==0; cont2++)
		{
			if(Orig[cont][1]==Caracteres[cont2])
			{
				repetido=true;
			}
		}

		if(repetido==false)
		{
			Caracteres[numCaracteres+1]=Orig[lineas][2];
			
		}
	}
	*/

Caracteres[0]='a';
Caracteres[1]='b';
numCaracteres=2;

}

//Almacena y renombra el resto de estados del AFI.
void Buscar(tVector Orig, tVectEstados Estados, int lineas,tVectCaracteres VectCaract, int numCaract)
{
	bool newEstado[10];
	for(int cont=0; cont<10;cont++)
		newEstado[cont]=false;
	
	//Recorrer el vector de estados para crear los nuevos estados
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Estados[i][j]==true)
			{
				//Va a crear uno por cada estado, hay que juntarlos
				BuscarEstadoSiguiente(newEstado, j, Orig, VectCaract, Estados); //Busca y añade al vector de estados
			}
		}
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
void BuscarEstadoSiguiente(bool newEstado[], int estado, tVector Orig, tVectCaracteres VectCaract, tVectEstados Estados)
{
	int i,k;
	for(int j=0; j<5; j++) //Para cada letra
	{
		for(k=0; k<10;k++) //Para cada estado
		{
			if(Estados[0][k]==true) //Si el estado esta a true lo buscamos
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














