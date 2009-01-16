// DNI1: 74368280   NOMBRE: VICTOR MANUEL GONZALEZ MIRA
// DNI2: 74368264   NOMBRE: VICTOR NUÑEZ MOLINA

#include <iostream>
#include <fstream>

using namespace std;

#include "libafi2afd.h"

int main (int argc , char *argv[])
{    
    int lin=0, fil=0 ,numCaracteres=0;
    char letra;
    ifstream fichero;
    bool especial, estAceptacion[maxEstados], evitaRepeticion[maxEstados];
    tVector vOrig;
    tVectEstados vEstados;
    tVectCaracteres vCaracteres; 
    
    //Iniciar el vector de booleanos
    for(int i=0; i<maxEstados; i++)
    {
        for(int j=0; j<tamEstados; j++)
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
            vOrig[lin][fil]=letra;             //Almacenamos la letra en el vector
            especial=ProcesarLetra(letra);        //Comprobamos si la letra que estamos tratando es un caracter especial

            if(especial==true || fil==tamTrans-1)        //Si es un caracter especial o final de linea, saltamos a la siguiente
            {
                fil=0;
                lin++;
            }
            else
            {
                fil++;
            }
            fichero>>letra;                //Leemos el siguiente caracter
            }
        fichero.close();
        //Una vez leido y almacenado el AFI, llevamos a cabo todas las operaciones
        CaracteresAFI(vOrig, lin, vCaracteres, numCaracteres, estAceptacion);
        BuscarInicios(vOrig,vEstados,lin);
        Buscar(vOrig,vEstados,lin, vCaracteres, numCaracteres);
        ResultadoAFD(vOrig, vEstados, lin, vCaracteres, numCaracteres, estAceptacion, evitaRepeticion);
    }
    else
    {
        cout<<errorFichero<<endl;    //En caso de error al abrir el fichero, se muestra un mensaje
    }
}


