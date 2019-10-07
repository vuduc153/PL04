#include <fstream>
#include <iostream>


ifstream fin("data.txt");
if (!fin.is_open()) {
	std::cerr << "Can not open file" << std::endl;
	exit(1); }

int number;
int fnumber;

while(!fin.eof()) {
	
}

fin.close();