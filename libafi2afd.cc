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
	int cont=0, cont2=1;
	
	Estados[0][0]=1;
	for(cont=0; cont<lineas; cont++)
	{
		if(Orig[cont][1]=='!')
		{
			Estados[0][cont2]=Orig[cont][0]-'0';
			cont2++;
		}
	}
}

//Almacena y renombra el resto de estados del AFI.
void Buscar(tVector Orig, tVectEstados Estados, int lineas)
{
	int cont=0, cont2=0, referencia=0;
/*De momento solo para caracter a( hacer un for para comprobar todos los caracteres que de momento no almacenamos pero que shadow debe implementar algun dia en su casa mientras se aburre)*/
	for(cont=1; cont<=11; cont++)
	{
		referencia=Estados[0][cont];

		for(cont2=0; cont2<lineas; cont2++)
		{
			if((Orig[cont2][0]-'0')==referencia && Orig[cont2][1]=='a')
			{
				cout<<Orig[cont2][2]<<endl;
			}
		}
		
	}

}

















