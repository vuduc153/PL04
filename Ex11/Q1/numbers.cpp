#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	istream_iterator<int> is(cin);
	ofstream file("numbers.txt");
	ostream_iterator<int> os(file, " ");
	istream_iterator<int> eos;

	while(is != eos) {
		int i = *is;
		if(i % 3 == 0 && i % 5 != 0) {
			*os = i;
			++os;
		}
		++is;
	}
	file.close();
	return 0;
}