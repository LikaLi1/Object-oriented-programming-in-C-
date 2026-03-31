#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6 };

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	for (int x : v) {
		cout << x << endl;
	}
}
