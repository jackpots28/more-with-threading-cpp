
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Test {
public:
	void runMultiThread() {
		thread t1(&Test::calculate, this, x, y);
		thread t2(&Test::calculate, this, x +2, y +20);
		t1.join();
		t2.join();
	}

	void getVec() {
		for (int i = 0; i < v.size(); i++) {
			cout << "Result: " << v.at(i) << " on Thread: " << i +1 << endl;
		}
	}

	void setXY(int a, int b) {
		x = a;
		y = b;
	}

private:
	void calculate(int from, int to);
	vector<int> v;

	int itt = 0;
	int x, y;
};

void Test::calculate(int from, int to) {
	v.push_back(to - from);
	itt++;
}

int main() {
	Test obj;
	obj.setXY(3, 7);
	obj.runMultiThread();
	obj.getVec();

    return 0;
}

