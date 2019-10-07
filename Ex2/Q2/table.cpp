#include <fstream>
#include <iostream>


ifstream input("data.txt");
if (!input.is_open()) {
	std::cerr << "Can not open file" << std::endl;
	exit(1); }
int number;
input >> number;
input.close();