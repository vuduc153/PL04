#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

template<class T>
class Compare {
public:
	Compare(const T& median): median(median) {} 
	bool operator() (T first, T second) {
		return abs(first - median) < abs(second - median);
	}
private:
	T median;
};


double compute_median(std::vector<int> v) {
	std::sort(v.begin(), v.end());
	int mid = v.size() / 2;
	double median;
	if(v.size() % 2 == 1)  median = v[mid];
	else median = 0.5 * (v[mid-1]+v[mid]);
	return median;
}

std::vector<int> compute_k_closest(std::vector<int> v, int k) {
	double median = compute_median(v);
	Compare<double> comparefunc(median);
	std::priority_queue<int, std::vector<int>, Compare<double>> sorted(median);

	for(int i = 0; i < v.size(); ++i) {
		if(sorted.size() < k)
			sorted.push(v[i]);
		else if(comparefunc(v[i], sorted.top())) {
			sorted.pop();
			sorted.push(v[i]);
		}
	}

	std::vector<int> result;
	for(int i = 0; i < k; ++i) {
		result.push_back(sorted.top());
		sorted.pop();
	}

	return result;

}

int main() {

	std::vector<int> v {7, 14, 10, 12, 2, 11, 29, 3, 4};
	std::vector<int> result = compute_k_closest(v, 3);
	for(int i = 0; i < 3; ++i) {
		std::cout << result[i] << std::endl;
	}
	return 0;
}