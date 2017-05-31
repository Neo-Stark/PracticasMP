using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

const int DIM = 100;
int MezclarUnico(double *v1, int util_v1, double *v2, int util_v2, double *vs);

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
	double Altura(double x);
	SkyLine &operator=(const SkyLine &copia);
	SkyLine operator+(const SkyLine &sky2) const;
	friend ostream &operator<<(ostream &flujo, const SkyLine &sky);
	friend istream &operator>>(istream &flujo, SkyLine &sky);
	friend int cargar(ifstream &inData, SkyLine &sky);
	friend int salvar(ofstream &outData, SkyLine &sky);
};

////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// int main()
// {
// 	ifstream inData("prueba.txt");
// 	ofstream outData("salida.txt");

// 	SkyLine edificio(1, 2, 1);
// 	double altura = edificio.Altura(1.5);
// 	cout << altura << endl;
// 	// cin >> edificio;

// 	cargar(inData, edificio);
// 	salvar(outData, edificio);

// 	SkyLine edificio2(2, 4, 4);
// 	altura = edificio2.Altura(3);
// 	cout << altura << endl;

// 	SkyLine edificio3(edificio2);
// 	altura = edificio3.Altura(2);
// 	cout << altura << endl;

// 	SkyLine edificio4;
// 	edificio4 = edificio + edificio2;
// 	altura = edificio4.Altura(1);
// 	cout << altura;
// 	cout << edificio;

// 	inData.close();
// }

int main()
{
	double x1, x2, h;
	ofstream Outdata(argv[1]);

	cin >> x1 >> x2 >> h;
	SkyLine edificios(x1, x2, h);

	for (int i = 0; i < capacidad && x1 != x2; i++)
	{
		cin >> x1 >> x2;
		if (x1 != x2)
		{
			cin >> h;
			SkyLine aux(x1, x2, h);
			edificios = edificios + aux;
		}
	}

	Outdata << edificios;
	Outdata.close();
}
//////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int MezclarUnico(double *v1, int util_v1, double *v2, int util_v2, double *vs)
{
	int i = 0, j = 0, util_vs = 0;
	while (i < util_v1 && j < util_v2)
		if (v1[i] < v2[j])
		{
			vs[util_vs] = v1[i];

			util_vs++;
			i++;
		}
		else if (v2[j] < v1[i])
		{
			vs[util_vs] = v2[j];

			util_vs++;
			j++;
		}
		else
			i++;

	if (i == util_v1)
		for (int k = j; k < util_v2; k++)
		{
			vs[util_vs] = v2[k];
			util_vs++;
		}
	else
		for (int k = i; k < util_v1; k++)
		{
			vs[util_vs] = v1[k];
			util_vs++;
		}
	return util_vs;
}

bool SkyLine::es_valido(double abscisa, double altura, int i)
{
	bool valido = true;
	if (i > 0)
		valido = abscisa > abscisas[i - 1];
	if (valido)
	{
		if (i != n - 1)
			valido = altura >= 0;
		else
			valido = altura == 0;
	}
	return valido;
}
void SkyLine::limpiar()
{
	delete[] abscisas;
	delete[] alturas;
	n = 0;
}
void SkyLine::copiar_desde(const SkyLine &copia)
{
	n = copia.n;
	abscisas = new double[n];
	alturas = new double[n];

	for (int i = 0; i < n; i++)
	{
		abscisas[i] = copia.abscisas[i];
		alturas[i] = copia.alturas[i];
	}
}

SkyLine::~SkyLine()
{
	limpiar();
}
SkyLine::SkyLine(double x1, double x2, double y1)
	: n(2)
{
	if (x1 < x2)
	{
		abscisas = new double[n];
		alturas = new double[n];

		abscisas[0] = x1;
		alturas[0] = y1;
		abscisas[1] = x2;
		alturas[1] = 0;
	}
	else
		SkyLine();
}

SkyLine::SkyLine(const SkyLine &copia)
{
	copiar_desde(copia);
}

SkyLine &SkyLine::operator=(const SkyLine &copia)
{
	if (this != &copia)
	{
		limpiar();
		copiar_desde(copia);
	}
	return *this;
}

double SkyLine::Altura(double x)
{
	double altura = 0;
	if (n != 0 && (x >= abscisas[0] && x < abscisas[n - 1]))
	{
		for (int i = 0; i < n; i++)
			if (x < abscisas[i] && x >= abscisas[i - 1])
				altura = alturas[i - 1];
	}

	return altura;
}
SkyLine SkyLine::operator+(const SkyLine &sky2) const
{
	SkyLine suma;
	double altura1, altura2;
	suma.abscisas = new double[n + sky2.n];
	suma.alturas = new double[n + sky2.n];
	suma.n = MezclarUnico(abscisas, n, sky2.abscisas, sky2.n, suma.abscisas);

	for (int i = 0; i < suma.n; i++)
	{
		altura1 = Altura(suma.abscisas[i]);
		altura2 = sky2.Altura(suma.abscisas[i]);

		if (altura1 > altura2)
			suma.alturas[i] = altura1;
		else
			suma.alturas[i] = altura2;
	}
	return suma;
}

ostream &operator<<(ostream &flujo, const SkyLine &salida)
{
	flujo << "\nNumero de abscisas: " << salida.n << endl;

	for (int i = 0; i < salida.n; i++)
		flujo << "( " << salida.abscisas[i] << ", "
			  << salida.alturas[i] << " )" << endl;
}

istream &operator>>(istream &flujo, SkyLine &entrada)
{
	double abscisa, altura;
	bool valido = true;
	entrada.limpiar();

	cout << "\nIntroducir numero de abscisas: ";
	flujo >> entrada.n;

	entrada.abscisas = new double[entrada.n];
	entrada.alturas = new double[entrada.n];

	for (int i = 0; i < entrada.n && valido; i++)
	{
		cout << "\nIntroduzca valor de abscisa y altura: ";
		flujo >> abscisa;
		flujo >> altura;
		valido = entrada.es_valido(abscisa, altura, i);

		if (valido)
		{
			entrada.abscisas[i] = abscisa;
			entrada.alturas[i] = altura;
		}
		else
			cout << "\nPunto no valido. Fin de la entrada de datos." << endl;
	}

	return flujo;
}

int cargar(ifstream &inData, SkyLine &sky)
{
	char cadena[14];
	inData >> cadena;
	if (!strcmp(cadena, "MP-SKYLINE-1.0"))
		inData >> sky;

	return 0;
}

int salvar(ofstream &outData, SkyLine &sky)
{
	outData << "MP-SKYLINE-1.0" << endl;
	outData << sky;

	return 0;
}

void SkyLine::simplificar()
{
	int quitados = 0, cont = 0;

	for (int i = 0; i < n; i++)
		if (i == 0 || altura[i] != altura[i - 1])
		{
			abscisas[cont] = abscisas[i];
			alturas[cont] = alturas[i];
			cont++;
		}
		else
			quitados++;

	n -= quitados;
}