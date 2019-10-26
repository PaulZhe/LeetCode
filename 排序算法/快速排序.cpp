#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}

void QuickSort(vector<int> &arr, int left, int right) {
	int i, j, standard;
	if (left > right) {
		return;
	}
	standard = arr[left]; //standard中存的就是基准数
	i = left;
	j = right;
	while (i != j) {
		//顺序很重要，要从右往左找
		while (arr[j] >= standard && i < j) {
			j--;
		}
		while (arr[i] <= standard && i < j) {
			i++;
		}
		if (i < j) {  //当哨兵i和哨兵j没有相遇时
			swap(arr[i], arr[j]);
		}
	}
	//最终将基准数归位
	arr[left] = arr[i];
	arr[i] = standard;
	//继续处理两边的，这是一个递归的过程
	QuickSort(arr, left, i - 1);
	QuickSort(arr, i + 1, right);
	return;
}

int main(int argc, char *argv[]) {
	vector<int> arr = {2,4,5,3,1,1};
	
	QuickSort(arr, 0, 5);
	
	print(arr);
}