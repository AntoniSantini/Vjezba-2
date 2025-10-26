#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

double** nova(int r, int s) {
	double** m = new double*[r];
	for (int i = 0; i < r; i++)
		m[i] = new double[s];
	return m;
}

void unos(double** m, int r, int s) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			cin >> m[i][j];
}

void raspon(double** m, int r, int s, double min, double max) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			m[i][j] = min + (rand() / (double)RAND_MAX) * (max - min);
}

void prikaz(double** m, int r, int s) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++)
			cout << setw(9) << fixed << setprecision(4) << m[i][j];
		cout << endl;
	}
}

double** zbroj(double** a, double** b, int r, int s) {
	double** c = nova(r, s);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			c[i][j] = a[i][j] + b[i][j];
	return c;
}

double** razl(double** a, double** b, int r, int s) {
	double** c = nova(r, s);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			c[i][j] = a[i][j] - b[i][j];
	return c;
}

double** trans(double** m, int r, int s) {
	double** t = nova(s, r);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			t[j][i] = m[i][j];
	return t;
}

void obrisi(double** m, int r) {
	for (int i = 0; i < r; i++)
		delete[] m[i];
	delete[] m;
}

int main() {
	srand(time(0));
	int r, s;
	cout << "Unesi retke i stupce: ";
	cin >> r >> s;

	double** A = nova(r, s);
	double** B = nova(r, s);

	cout << "Unesi matricu A:" << endl;
	unos(A, r, s);

	cout << "Unesi granice za matricu B: ";
	double min, max;
	cin >> min >> max;
	raspon(B, r, s, min, max);

	cout << "\nMatrica A:\n"; prikaz(A, r, s);
	cout << "\nMatrica B:\n"; prikaz(B, r, s);

	double** C = zbroj(A, B, r, s);
	cout << "\nZbroj A+B:\n"; prikaz(C, r, s);

	double** D = razl(A, B, r, s);
	cout << "\nRazlika A-B:\n"; prikaz(D, r, s);

	double** T = trans(A, r, s);
	cout << "\nTransponirana A:\n"; prikaz(T, s, r);

	obrisi(A, r);
	obrisi(B, r);
	obrisi(C, r);
	obrisi(D, r);
	obrisi(T, s);

	return 0;
}
