#include <fstream>
#include <iostream>
#include <iomanip>


int main(void) {
	
	std::ifstream file("data.txt");
	if(!file.is_open()) {
		std::cerr << "Can not open file" << std::endl;
		exit(1); 
	}

	int number;
	double dnumber;

	std::cout << "---------------------+---------------------+--------------------" << std::endl;

	int i = 1;

	while(!file.eof()) {
		file >> number >> dnumber;
		if(file.eof()) break;
		std::cout << std::setw(20) << i << " |" << std::setw(20) << number << " |" << std::setw(20) << dnumber << std::endl;
		i ++;
	}

	file.close();

	return 0;
}