#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Counter {
public:
	Counter() {
		max_col = 0;
	}
	void add(string s);
	void print();
	int gamma();
	int epsilon();
	int power();

private:
	unordered_map<int, int> ones_count;
	unordered_map<int, int> zeroes_count;
	int max_col;

	int count_ones(int);
	int count_zeroes(int);
};

// Consume a string and update the counter. Get information about
// the structure of the string: the longest line, and the number of ones and zeroes.
// A non-binary character is ignored, but it counts as a column.
void Counter::add(string s) {
	int i = 0;
	for (auto c: s) {
		if (c == '1' || c == '0') {
			c == '1' ? ones_count[i]++ : zeroes_count[i]++;
		} else {
			cerr << "line " << i << ": " << c << " not a binary input; ignoring " << endl;
		}
		i++;
	}
	if (max_col < i)
		max_col = i;
}

int Counter::count_ones(int col) {
	auto ones = ones_count.find(col);
	if (ones != ones_count.end()) {
		return ones->second;
	} else {
		return 0;
	}
}

int Counter::count_zeroes(int col) {
	auto zeroes = zeroes_count.find(col);
	if (zeroes != zeroes_count.end()) {
		return zeroes->second;
	} else {
		return 0;
	}
}

// don't check for overflow
int Counter::gamma() {
	int g = 0;
	for (int i = 0; i < max_col; ++i) {
		int o = count_ones(i);
		int z = count_zeroes(i);
		g *= 2;
		if (o >= z)    // if o == z the program acts as if o > z
			g++;
	}
	return g;
}

int Counter::epsilon() {
	int e = 0;
	for (int i = 0; i < max_col; ++i) {
		int o = count_ones(i);
		int z = count_zeroes(i);
		e *= 2;
		if (o <= z)    // if o == z the program acts as if o > z
			e++;
	}
	return e;
}

int Counter::power() {
	return gamma() * epsilon();
}

void Counter::print() {
	cout << "ones count:" << endl;
	for(auto &k: ones_count) {
		cout << k.first << ": " << k.second << endl;
	}
	cout << "zeroes count:" << endl;
	for (auto &k: zeroes_count) {
		cout << k.first << ": " << k.second << endl;
	}
	cout << "maximum number of columns:" << endl;
	cout << max_col << endl;
}

int compute_power() {
	Counter c;
	string buf = "";

	while (getline(cin, buf)) {
		c.add(buf);
	}
	return c.power();
}

int main() {
	cout << compute_power() << endl;
}
