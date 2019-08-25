#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}
//时间复杂度O(n^2)
void InsertSort(vector<int> &arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			} else {
				break;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	vector<int> arr = {2,4,5,3,1,1};
	
	InsertSort(arr);
	
	print(arr);
}