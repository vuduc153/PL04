#include "sort.h"
#include <array>

int main() {
	std::array<int, 6> a = {3, 5, 2, 1, 9, 6};
	sort<std::array<int, 6>::iterator> (a.begin(), a.end());

	for(int i = 0; i < a.size(); i ++) {
		std::cout << a[i] << std::endl;
	}

	return 0;
}