#include "Horspool.h"
using namespace std;
char* memblock;
string File;
streampos size;
char *c;

void t() {
	ifstream file("hex view.exe", ios::in | ios::binary | ios::ate);
	string z;
	if (file.is_open()) {
		size = file.tellg();
		memblock = new char[size];
		file.seekg(0, ios::beg);
		file.read(memblock, size);
		file.close();
		stringstream ss;
		int b;
		c = new char[size * 2];
		for (int i = 0; i < size; i++) {
			b = (memblock[i] >> 4) & 0xF;
			c[2 * i] = (char) (55 + b + (((b - 10) >> 31) & -7));
			b = memblock[i] & 0xF;
			c[2 * i + 1] = (char) (55 + b + (((b - 10) >> 31) & -7));
		}
		delete[] memblock;
	} else
		cout << "Unable to open file";
}



int main() {
	t();
	string b = "645F63617374005F5F5A54535374";

	for(int i = 0 ;i < b.length() ; i++)
		b[i]=toupper(b[i]);
//	cout<<b;
	Horspool x;

	cout << x.search(c , size *2, &b);
	cin.ignore();
	delete (c);
	return 0;
}
