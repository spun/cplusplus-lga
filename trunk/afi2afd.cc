#include <iostream>
#include <fstream>

using namespace std;

#include "libafi2afd.h"


int main (int argc , char *argv[])
{
	char letra;
	ifstream fichero;
	bool especial;
	int lin=0, fil=0 ;
	tVector vOrig;
	tVectEstados vEstados;

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
		BuscarInicios(vOrig,vEstados,lin);
		Buscar(vOrig,vEstados,lin);
		/*cout<<"Fila: "<<fil<<"   Linea: "<<lin<<endl<<endl<<endl<<endl;
		for(int cont=0; cont<lin; cont++)
		{
			for(int cont2=0; cont2<3; cont2++)
			{
				cout<<vOrig[cont][cont2];
			}
			cout<<endl;
		}*/
	}
	else
	{
		cout<<"No se puede abrir"<<endl;
	}
}


