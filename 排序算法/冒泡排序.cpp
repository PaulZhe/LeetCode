#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}
//时间复杂度O(n^2)
void BubbleSort(vector<int> &arr) {
	bool flag = true;
		for (int i = 0; i < arr.size() - 1 && flag; i++) {
			flag = false;
			for (int j = 0; j < arr.size() - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
					flag = true;
				}
			}
		}
}

int main(int argc, char *argv[]) {
	vector<int> arr = {2,4,5,3,1,1};
	
	BubbleSort(arr);
	
	print(arr);
}