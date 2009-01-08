typedef char tVector[100][3];
//En el primer campo almacena la renombnracion de los estados 
typedef bool tVectEstados[100][10];

//El alfabeto de entrada del AFI tendrá como mucho 5 simbolos
typedef char tVectCaracteres[5];


bool ProcesarLetra(char letra);
void AlmacenaLetra(char l, bool e, int &lin, int &fil, tVector vOrig);
void BuscarInicios(tVector Orig, tVectEstados Estados, int lineas);
void Buscar(tVector Orig, tVectEstados Estados, int lineas,tVectCaracteres VectCaract, int numCaract);
bool BuscarRepetidos (tVectEstados Estados, bool newEstado[]);
void BuscarEstadoSiguiente(bool newEstado[], tVector Orig, tVectCaracteres VectCaract, bool estadoAux[], tVectEstados Estados, int numCaract);
void AgregarEstado(bool newEstado[], tVectEstados Estados);
void ResultadoAFD(tVector Orig, tVectEstados Estados, int lineas,tVectCaracteres VectCaract, int numCaract);
void BuscarEstadosNuevos(bool newEstado[], tVector Orig, tVectCaracteres VectCaract, bool estadoAux[], tVectEstados Estados, int numCaract, int i);
int BuscarNumeroEstadoNuevo(tVectEstados Estados, bool newEstado[]);

void CaracteresAFI(tVector Orig, int lineas, tVectCaracteres Caracteres, int &numCaracteres);
bool BuscarElemento(tVectCaracteres Caracteres, int tamano, char caracter);
















