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
	int cont=0, cont2=0, referencia=0, contCaracter=0;
	
	for(contCaracter=0; contCaracter<numCaract; contCaracter++)
	{	
		cout<<"Caracter: "<<VectCaract[contCaracter]<<endl;

		for(cont=1; cont<=11; cont++)
		{
			//referencia=Estados[0][cont];

			for(cont2=0; cont2<lineas; cont2++)
			{

				if((Orig[cont2][0]-'0')==referencia && Orig[cont2][1]==VectCaract[contCaracter])
				{
					cout<<Orig[cont2][2]<<endl;;
				}
			}
		}
			
	}
}

//Devuelve TRUE si el estado ya existe
bool BuscarRepetidos (tVectEstados Estados, int a, int b)
{
	bool repetido=false, i=0, j=0;
	
	for(i=0; i<100; i++)
	{
		for(j=1; j<11; j++)
		{
			
		}
	}
	
	
	
	return repetido;
}
















