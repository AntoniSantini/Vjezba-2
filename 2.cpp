//#include <iostream>
//using namespace std;
//
//struct Vektor {
//	int* el;
//	int log;
//	int fiz;
//};
//
//Vektor vector_new(int k) {
//	Vektor v;
//	v.el = new int[k];
//	v.log = 0;
//	v.fiz = k;
//	return v;
//}
//
//void vector_delete(Vektor& v) {
//	delete[] v.el;
//	v.el = nullptr;
//	v.log = 0;
//	v.fiz = 0;
//}
//
//void vector_push_back(Vektor& v, int al) {
//	if (v.log >= v.fiz) {
//		int* n = new int[v.fiz * 2];
//		for (int i = 0; i < v.log; i++)
//			n[i] = v.el[i];
//		delete[] v.el;
//		v.el = n;
//		v.fiz *= 2;
//	}
//	v.el[v.log++] = al;
//}
//
//void vector_pop_back(Vektor& v) {
//	if (v.log > 0)
//		v.log--;
//}
//
//int vector_front(const Vektor& v) {
//	return v.log > 0 ? v.el[0] : 0;
//}
//
//int vector_back(const Vektor& v) {
//	return v.log > 0 ? v.el[v.log - 1] : 0;
//}
//
//int vector_size(const Vektor& v) {
//	return v.log;
//}
//
//int main() {
//	Vektor v = vector_new(2);
//
//	vector_push_back(v, 10);
//	vector_push_back(v, 20);
//	vector_push_back(v, 30);
//
//	cout << "Prvi: " << vector_front << endl;
//	cout << "Zadnji: " << vector_back << endl;
//	cout << "Velicina: " << vector_size << endl;
//
//	cout << "Svi: ";
//	for (int i = 0; i < vector_size(v); i++)
//	   cout << v.el[i] << " "; 
//	cout << endl;
//
//	vector_delete(v);
//}