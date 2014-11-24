/*
 * main.c file
 */

#include <iostream>
#include "PonyInt.h"
#include "PonyCore.h"

using namespace std;

int main(void)
{
	//Declaracion e Igualacion
	IntegerStruct * pony = allocateInteger(eINT);
	int_list["pony"] = pony;
	if(int_list.find("pony") == int_list.end())
	{
		cout << "la vaina e null!" << endl;
		return 1;
	}
	setInteger(&int_list["pony"], -129);
	cout << getInteger(int_list["pony"]) << endl;
    return 0;
}
