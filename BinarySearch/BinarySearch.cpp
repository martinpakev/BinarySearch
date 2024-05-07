#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <memory>
using namespace std;

//Binary Search
int findElementByIndex(vector<int>& numbers, int target) {
	int first = 0;
	int last = numbers.size() - 1;
	int counter = 0;

	while (first <= last) {
		int mid = (last + first) / 2;

		if (numbers[mid] == target) return mid;
		else if (numbers[mid] < target) {
			first = mid + 1;
		}
		else if (numbers[mid] > target) {
			last = mid - 1;
		}
		counter++;
		if (counter == numbers.size() + 1) break;
	}

	return -1;
}

int main(void) {
	string input;
	vector<int> numbers;
	getline(cin, input);

	istringstream istr(input);

	int number;
	while (istr >> number) {
		numbers.push_back(number);
	}

	cout << "Enter a numbe to find its index!" << endl;
	cin >> number;
	int result = findElementByIndex(numbers, number);
	if (result != -1) cout << "Number " << number << " is at index " << result << " in the vector." << endl;
	else if (result == -1) cout << "Number " << number << " is not in the vector." << endl;

	return 0;
}