// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

// NOT FINISHED

class LogFile {
private:
	FILE *p;
public:
	LogFile(const char* filename, const char* mode) {
		p = fopen(filename, mode);
		if(!p) {
   			throw runtime_error("failed to open file");
 		}
	}
	~LogFile() {
		cout << "closing logfile" << endl;
		fclose(p);
	}

	FILE* get_file() {
		return p;
	}
};

void doSomeComputation() {
 throw runtime_error("failure during doing some computation");
}

void example() {
 LogFile logfile("logfile.txt", "w+");

 fputs("log1", logfile.get_file());
 // call a function that performs some computation and may throw 
 // an exception
 doSomeComputation();
}

int main(void) {
 cout << "Calling example()" << endl;
 try {
 	example();
 }
 catch(runtime_error e) {
 	cout << e.what() << endl;
 }
 cout << "After calling example()" << endl;
 return 0;
}