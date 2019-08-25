#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}
//时间复杂度O(n^2)
void SelectSort(vector<int> &arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(arr[i], arr[min]);
		}
	}
}

int main(int argc, char *argv[]) {
	vector<int> arr = {2,4,5,3,1,1};
	
	SelectSort(arr);
	
	print(arr);
}