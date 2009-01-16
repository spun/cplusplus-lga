typedef char tVector[100][3];
//Vector de estados del AFD
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
void ResultadoAFD(tVector Orig, tVectEstados Estados, int lineas,tVectCaracteres VectCaract, int numCaract, bool estAceptacion[], bool evitaRepeticion[]);
void BuscarEstadosNuevos(bool evitaRepeticion[], bool estAceptacion[], bool newEstado[], tVector Orig, tVectCaracteres VectCaract, bool estadoAux[], tVectEstados Estados, int numCaract, int i);
int BuscarNumeroEstadoNuevo(bool evitaRepeticion[], bool estAceptacion[], tVectEstados Estados, bool newEstado[]);

void CaracteresAFI(tVector Orig, int lineas, tVectCaracteres Caracteres, int &numCaracteres, bool estAceptacion[]);
bool BuscarElemento(bool estAceptacion[], tVectCaracteres Caracteres, int tamano, char caracter, char estadoINI);
















