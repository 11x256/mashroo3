#include "Horspool.h"
#include "Quarantine.h"
#include"main.h"
using namespace std;

vector<string> filesToBeScanned;

char* openFile(string path ,streampos* size) {
	char * memblock ;
	ifstream file(path.c_str(), ios::in | ios::binary | ios::ate);
	if (file.is_open()) {
		*size = file.tellg();
		memblock = new char[*size];
		file.seekg(0, ios::beg);
		file.read(memblock, *size);
		file.close();
		return memblock;
	} else{
		cout << "Unable to open file";
		return 0;
	}
}

char* convertToHex(char * memblock , streampos size)
{
	int b;
	char * c = new char[size * 2];
	for (int i = 0; i < size; i++) {
		b = (memblock[i] >> 4) & 0xF;
		c[2 * i] = (char) (55 + b + (((b - 10) >> 31) & -7));
		b = memblock[i] & 0xF;
		c[2 * i + 1] = (char) (55 + b + (((b - 10) >> 31) & -7));
	}
	delete[] memblock;
	return c;

}

int main() {
	char* memblock;
	streampos size;
	char *c;

	Quarantine q ;
	q.add("c:\\a.exe");

/*
	Horspool x;
	string b = "5";

	filesToBeScanned.push_back("c://a.exe");

	for (unsigned int i = 0; i < filesToBeScanned.size(); i++) {

		memblock = openFile(filesToBeScanned[i] , &size);
		c = convertToHex( memblock , size);

		//for each signature in database scan (mesh mawgoda )

		for (unsigned int i = 0; i < b.length(); i++)
			b[i] = toupper(b[i]);

		int result = x.search(c, size * 2, &b);
		cout<<result;
		if(result != -1)
		{
			//q.add(filesToBeScanned[i]);
		}
		//	cin.ignore();
		delete (c);
	}*/
	return 0;

}
