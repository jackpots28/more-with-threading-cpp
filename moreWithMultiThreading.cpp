
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>
#include <random>

using namespace std;

template <class T>
class Test {
public:

	void runMultiThread() {
		
		for (int threadCount = 0; threadCount <= 7; threadCount++) {
			thread t4(&Test::calculate, this, cals.at(rand() % sizeMod), cals.at(rand() % sizeMod));
			t4.join();
			cout << "Thread: " << threadCount << " Result: " << entryVec.at(threadCount) << endl;
			++endOfLoop;
		}
		thread t1(&Test::calculate, this, cals.at(rand() % sizeMod), cals.at(rand() % sizeMod));
		thread t2(&Test::calculate, this, cals.at(rand() % sizeMod), cals.at(rand() % sizeMod));
		thread t3(&Test::calculate, this, cals.at(rand() % sizeMod), cals.at(rand() % sizeMod));
		t1.join();
		t2.join();
		t3.join();
		// cout << endOfLoop;
	}

	void getVec() {
		for (int i = endOfLoop; i < entryVec.size(); i++) {
			cout <<"Thread: " << i << " Result: " << entryVec.at(i) << endl;
		}
		cout << endl;
		cout << "Calculation vector has size: "<< entryVec.size() << endl << endl;
	}

	void fillVec(vector<T> &vec) {
		for (int i = 0; i < vec.size(); i++) {
			cals.push_back(vec.at(i));
		}
		sizeMod = cals.size();
	}

	void printVec() {
		for (int a = 0; a < cals.size(); a++) {
			cout << cals.at(a) << " ";
		}
		cout << endl;
	}

	void printCalVec() {
		for (float j = 0; j < entryVec.size(); j++) {
			cout << entryVec.at(j) << " ";
		}
		cout << endl << endl;
	}

private:
	void calculate(T from, T to) {
		entryVec.push_back(to * from);
		itt++;
	}

	vector<T> entryVec;
	vector<T> cals;

	int sizeMod;
	int endOfLoop;
	int itt = 0;
	T x, y;
};



int main() {
	
	Test<long> obj;
	vector<long> mainVec;
	for (float j = 0; j <= 10; j++) {
		mainVec.push_back(rand() % 100);
	}

	obj.fillVec(mainVec);
	obj.printVec();

	cout << endl;

	obj.runMultiThread();
	obj.getVec();

	obj.printCalVec();
	
	cout << endl << "-NEW OBJ-" << endl << endl << endl;

	Test<char> charObj;
	vector<char> charVec;
	for (char b = 'a'; b <= 'z'; b++) {
		charVec.push_back(b);
	}
	
	charObj.fillVec(charVec);
	charObj.printVec();

	cout << endl;

	charObj.runMultiThread();
	charObj.getVec();
	charObj.printCalVec();

    return 0;
}

