// DNI1: 74368280   NOMBRE: VICTOR MANUEL GONZALEZ MIRA
// DNI2: 74368264   NOMBRE: VICTOR NUÑEZ MOLINA

//Declaracion de las constantes de tamaño
const int maxTrans = 100;
const int tamTrans = 3;
const int maxEstados = 100;
const int tamEstados = 10;
const int maxCaracteres = 5;

//Vector contenedor AFI
typedef char tVector[maxTrans][tamTrans];
//Vector de estados del AFD
typedef bool tVectEstados[maxEstados][tamEstados];
//El alfabeto de entrada del AFI tendrá como mucho 5 simbolos
typedef char tVectCaracteres[maxCaracteres];

//Declaracion de caracteras especiales
const char caractEsp1='!';
const char caractEsp2='#';

//Declaracion como constantes, de todos los posibles mensajes que se pueden mostrar
const string errorFichero="ERROR: NO ES POSIBLE ABRIR EL FICHERO";

//Decalaracion de funciones
bool ProcesarLetra(char letra);
void BuscarInicios(tVector Orig, tVectEstados Estados, int lineas);
void CaracteresAFI(tVector Orig, int lineas, tVectCaracteres Caracteres, int &numCaracteres, bool estAceptacion[]);
bool BuscarElemento(bool estAceptacion[], tVectCaracteres Caracteres, int tamano, char caracter, char estadoINI);
void Buscar(tVector Orig, tVectEstados Estados, int lineas,tVectCaracteres VectCaract, int numCaract);
bool BuscarRepetidos (tVectEstados Estados, bool newEstado[]);
void BuscarEstadoSiguiente(bool newEstado[], tVector Orig, tVectCaracteres VectCaract, bool estadoAux[], tVectEstados Estados, int numCaract);
void AgregarEstado(bool newEstado[], tVectEstados Estados);
void ResultadoAFD(tVector Orig, tVectEstados Estados, int lineas,tVectCaracteres VectCaract, int numCaract, bool estAceptacion[], bool evitaRepeticion[]);
void BuscarEstadosNuevos(bool evitaRepeticion[], bool estAceptacion[], bool newEstado[], tVector Orig, tVectCaracteres VectCaract, 
                         bool estadoAux[], tVectEstados Estados, int numCaract, int estadoInicial);
int BuscarNumeroEstadoNuevo(bool evitaRepeticion[], bool estAceptacion[], tVectEstados Estados, bool newEstado[]);
