#include "Horspool.h"
using namespace std;

	void Horspool::preProcess(string *pattern) {
		for (int i = 0; i < ALPHABET_LEN; i++) {
			delta[i] = (*pattern).length();
		}

		for (int i = 0; i < (*pattern).length() - 1; i++) {
			delta[(*pattern)[i]] = (*pattern).length() - 1 - i;
		}

	}  

	int Horspool::search(char* text , long long size, string *pattern) {
		preProcess(pattern);
		int i = (*pattern).length() - 1;
		int j = i;
		int m = i;
		while (j >= 0 && i < size) {
			if ((int)(*pattern)[j] == (int)(text)[m]) {
				m--;
				j--;
			} else {
				j = (*pattern).length() - 1;
				i += delta[(text)[i]];
				m = i;
			}
		}

		if (j == -1)
			return m + 1;
		return NOT_FOUND;

	}


