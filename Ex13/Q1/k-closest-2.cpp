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
	int mid = v.size() / 2;
	double median;
	
	std::nth_element(v.begin(), v.begin()+mid, v.end());
	if(v.size() % 2 == 1)
		median = v[mid];
	else {
		std::nth_element(v.begin(), v.begin()+mid-1, v.end());
		median = 0.5 * (v[mid]+v[mid-1]);
	}

	return median;
}

std::vector<int> compute_k_closest(std::vector<int> v, int k) {
	double median = compute_median(v);
	Compare<double> comparefunc(median);
	
	std::vector<int> result;
	
	for(int i = 0; i < k; ++i) {
		std::nth_element(v.begin(), v.begin()+i, v.end(), comparefunc);
		result.push_back(v[i]);
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