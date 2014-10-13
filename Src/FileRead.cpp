/*
 * FileRead.cpp
 *
 *  Created on: Sep 18, 2014
 *      Author: Norman
 */

#include "Headers/FileRead.hpp"
#include <string>
#include <fstream>

using namespace std;

const char * FileRead(const char * filepath)
{
	string buffer = "";
	ifstream * in = new ifstream(filepath, ifstream::in);
	while(!in->eof())
		buffer += in->get();
	return buffer.c_str();
}
