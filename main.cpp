#include "Horspool.h"
using namespace std;

char* memblock;
string File;
streampos size;
char *c;
vector<string> filesToBeScanned;

void openFile(string path) {
	ifstream file(path.c_str(), ios::in | ios::binary | ios::ate);
	if (file.is_open()) {
		size = file.tellg();
		memblock = new char[size];
		file.seekg(0, ios::beg);
		file.read(memblock, size);
		file.close();
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
	Horspool x;
	string b = "5";
	filesToBeScanned.resize(100);
	filesToBeScanned[0] = "c://a.exe";
	for (unsigned int i = 0; i < filesToBeScanned.size(); i++) {
		openFile(filesToBeScanned[i]);
		//for each signature in database scan (mesh mawgoda )

		for (unsigned int i = 0; i < b.length(); i++)
			b[i] = toupper(b[i]);

		cout << x.search(c, size * 2, &b);
		//	cin.ignore();
		delete (c);
	}
	return 0;
}
