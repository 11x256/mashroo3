#include "Quarantine.h"
#include"main.h"

using namespace std;

#include <fstream>
#include<iostream>
int Quarantine::add(string path) {
	ofstream outFile;
	streampos size;
	char* memblock;
	string name = path.substr(3, path.length() - 3);
	cout << name;
	outFile.open(("Quarantine/" + name).c_str());
	memblock = openFile(path, &size);

	for(int i = 0 ; i < size ; i++)
	{
		memblock[i] = memblock[i]^0x55;

	}


	outFile.write(memblock , size);

}

