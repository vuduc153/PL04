#include <stack>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int eval(string rpnstring) {
	stack<int> stack;
	stringstream stream(rpnstring);
	string s;
	while(stream >> s) {
		if(s == "+" || s == "-" || s == "*" || s == "/") {
			int num_1, num_2;
			num_1 = stack.top();
			stack.pop();
			num_2 = stack.top();
			stack.pop();
			if(s == "+") stack.push(num_2 + num_1);
			if(s == "-") stack.push(num_2 - num_1);
			if(s == "*") stack.push(num_2 * num_1);
			if(s == "/") stack.push(num_2 / num_1);
		}
		else {
			stack.push(stoi(s));
		}
	}
	return stack.top();
}

int main() {
	cout << eval("-8 9 * 9 +") << endl;
	return 0;
}