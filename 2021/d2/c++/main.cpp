#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct position {
	int X;
	int Y;
};

struct instruction {
	string direction;
	int distance;
};

vector<instruction> read_instructions() {
	string buf;
	vector<instruction> ins;

	while (getline(cin, buf)) {
		instruction i = {"", 0};
		stringstream(buf) >> i.direction >> i.distance;
		ins.push_back(i);
	}

	return ins;
}

position compute_position(vector<instruction> is) {
	int line = 0;
	position p = {0, 0};

	// move according to the instructions
	for (auto i = is.begin(); i != is.end(); i++) {
		if (i->direction == "forward") {
			p.X += i->distance;
		} else if (i->direction == "down") {
			p.Y += i->distance;
		} else if (i->direction == "up") {
			p.Y -= i->distance;
		}
		// ignore bad instructions
	}
	return {p.X, p.Y};
}

int main() {
	position p = compute_position(read_instructions());
	cout << (p.X) * (p.Y) << endl;
}
