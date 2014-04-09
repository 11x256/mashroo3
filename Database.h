/*
 * Database.h
 *
 *  Created on: Apr 9, 2014
 *      Author: abd-el-rahman
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include<vector>
using namespace std;
class Database{
private :
	string signatureXMLPath;
	string patternXMLPath;
public :
	int addToDatabase(string signature , string virusName); // return 1 for success
	string getLastModifiedDate(string pathToXml);
	int addPreprocessResult(vector<int> delta, int indexOfSignature);
	vector<int> getPreprocessResult(int index);


};



#endif /* DATABASE_H_ */
