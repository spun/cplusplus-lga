#include <iostream>
#include <fstream>

using namespace std;

#include "libafi2afd.h"


int main (int argc , char *argv[])
{
	char letra;
	ifstream fichero;
	bool especial, estAceptacion[100], evitaRepeticion[100];
	int lin=0, fil=0 ,numCaracteres=0; //Numero de caracteres que existen en el AFI
	tVector vOrig;
	tVectEstados vEstados;
	tVectCaracteres vCaracteres; 
	
	//Iniciar el vector de booleanos
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<10; j++)
		{
			estAceptacion[i]=false;
			vEstados[i][j]=false;
			evitaRepeticion[i]=false;
		}
	}
	
	fichero.open(argv[1],ios::in);
	if(fichero.is_open())
	{
		fichero>>letra;
		while(!fichero.eof())
		{
			especial=ProcesarLetra(letra);
			AlmacenaLetra(letra, especial, lin, fil, vOrig);
			if(especial==true || fil==2)
			{
				fil=0;
				lin++;
			}
			else
			{
				fil++;
			}
			fichero>>letra;
        	}
		fichero.close();

		CaracteresAFI(vOrig, lin, vCaracteres, numCaracteres, estAceptacion);
		BuscarInicios(vOrig,vEstados,lin);
		Buscar(vOrig,vEstados,lin, vCaracteres, numCaracteres);
		ResultadoAFD(vOrig, vEstados, lin, vCaracteres, numCaracteres, estAceptacion, evitaRepeticion);
	}
	else
	{
		cout<<"No se puede abrir"<<endl;
	}
}


