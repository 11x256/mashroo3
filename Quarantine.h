/*
 * Quarantine.h
 *
 *  Created on: Apr 9, 2014
 *      Author: abd-el-rahman
 */

#ifndef QUARANTINE_H_
#define QUARANTINE_H_

#include<string>
using namespace std;

class Quarantine{

private:
	string quarantinePath ;

public:
	int add(string path);
	int remove(string path);
	int restore(string path);
};


#endif /* QUARANTINE_H_ */
