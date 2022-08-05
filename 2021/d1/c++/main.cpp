#include <iostream>
#include <vector>

using namespace std;

vector<int> read_measurements() {
	int i = 0;
	vector<int> ms;
	while(cin >> i) {
		ms.push_back(i);
	}
	return ms;
}

int count_peaks(vector<int> measurements) {
	if (measurements.size() == 0)
		return 0;

	auto p = measurements.begin();
	auto c = ++measurements.begin();
	int inc = 0;
	while (c != measurements.end()) {
		if (*p++ < *c++)
			++inc;
	}
	return inc;
}

void test() {
	
	cout << count_peaks(read_measurements()) << endl;
}

int main() {
	test();
}
