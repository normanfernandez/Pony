#include <iostream>
#include <fstream>
#include "file_reader.h"
#define LINE_BUFFER 1024

using namespace std;

void file_reader(fstream& f){
	size_t buffer_size = 0;
	size_t current_line = 1;
	char buffer[LINE_BUFFER] = {0};
	char * buffer_ptr = &buffer[0];

	printf("The file contains: %i line(s)\n", current_line);
}
