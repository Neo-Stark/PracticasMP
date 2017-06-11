#ifndef MATRIZDISPERSA
#define MATRIZDISPERSA

struct Valor
{
	int fila;
	int columna;
	double valor;
};
class MatrizDispersa
{
  private:
	int nfilas;
	int ncolumnas;
	Valor *valores;
	int numero_valores;
	void copiar_desde(const MatrizDispersa &copia);

  public:
	MatrizDispersa() : nfilas(0), ncolumnas(0), numero_valores(0){};
	~MatrizDispersa();
	MatrizDispersa(int nfil, int ncol, Valor *v1, int n1,
				   Valor *v2, int n2, Valor *v3, int n3);
	MatrizDispersa(int nfil, int ncol, double *datos = 0);
	MatrizDispersa(const MatrizDispersa &copia);
	MatrizDispersa &operator=(const MatrizDispersa &copia);
	MatrizDispersa operator+(const MatrizDispersa &copia);
	friend ostream &operator<<(ostream &flujo, const MatrizDispersa &matriz);
	friend istream &operator>>(istream &flujo, MatrizDispersa &matriz);
	double obtenerValor(int fila, int col);
	void asignarValor(int fila, int col, double valor);
	friend void AniadeValor(const Valor *vi, int i, Valor *vs, int &ns);
	friend int combinarSuma(const Valor *v1, int n1, const Valor *v2, int n2, Valor *v3);
	friend int cargar(char *fichero, MatrizDispersa &matriz);
	friend int salvar(char *fichero, const MatrizDispersa &matriz);
	void podar(double valor);
};

#endif