#ifndef SKYLINE
#define SKYLINE

class SkyLine
{
	double *abscisas;
	double *alturas;
	int n;
	void copiar_desde(const SkyLine &copia);
	void limpiar();
	bool es_valido(double abscisa, double altura, int i);
	void simplificar();

  public:
	SkyLine() : abscisas(0), alturas(0), n(0){};
	~SkyLine();
	SkyLine(double x1, double x2, double y1);
	SkyLine(const SkyLine &copia);
	double Altura(double x) const;
	SkyLine &operator=(const SkyLine &copia);
	SkyLine operator+(const SkyLine &sky2) const;
	friend ostream &operator<<(ostream &flujo, const SkyLine &sky);
	friend istream &operator>>(istream &flujo, SkyLine &sky);
	friend int cargar(char *fichero, SkyLine &sky);
	friend int salvar(char *fichero, SkyLine &sky);
};

#endif