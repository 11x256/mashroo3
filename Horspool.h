/*
 * Horspool.h
 *
 *  Created on: Mar 23, 2014
 *      Author: abd-el-rahman
 */

#ifndef HORSPOOL_H_
#define HORSPOOL_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iomanip>
#include<vector>

#define ALPHABET_LEN 256
#define NOT_FOUND -1

class Horspool {
public:
	int delta[ALPHABET_LEN];
	void preProcess(std::string *pattern);
	int search(char *text, long long size, std::string *pattern);
};

#endif /* HORSPOOL_H_ */
