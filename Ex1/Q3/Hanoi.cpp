// Hanoi.cpp
#include <iostream>
#include <string>

// COMPLETE:
// Define the function Hanoi. 
// Its argument is the number of disks.
//
// The function should print a series of instructions for 
// how to move the disks in order to solve the problem. 

void Hanoi(int n, char column_from, char column_to, char column_middle) {
	if(n == 1) {
		std::cout << "Move disk " << n << "th from " << column_from << " to " << column_to << std::endl;
		return;
	}
	Hanoi(n - 1, column_from, column_middle, column_to);
	std::cout << "Move disk " << n << "th from " << column_from << " to " << column_to << std::endl;
	Hanoi(n - 1, column_middle, column_to, column_from);
}

int main(int argc, char** argv) {
  if (argc!=2) {
    std::cout << "Usage: " << argv[0] << " n" << std::endl;
    std::cout << "where n is the number of disks." << std::endl;
    return 1;
  }

  int n = std::stoi(argv[1]); // convert the argv[1] to an int

  // COMPLETE:
  // Call Hanoi with n disks

  Hanoi(n, 'A', 'C', 'B');
}