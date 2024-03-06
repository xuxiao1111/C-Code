#include <iostream>
#include <vector>
using namespace std;

//抽象成绩操作类：目标接口
class ScoreOperation
{
public:
	virtual vector<int> sort(vector<int>& arr) = 0;
	virtual int search(vector<int>& arr, int key) = 0;
};

//快速排序类：适配者
class QuickSort
{
public:
	vector<int> quickSort(vector<int>& arr)
	{
		sort(arr, 0, arr.size() - 1);
		return arr;
	}
	void sort(vector<int>& arr, int p, int r)
	{
		int q = 0;
		if (p < r)
		{
			q = partition(arr, p, r);
			sort(arr, p, q - 1);
			sort(arr, q + 1, r);
		}
	}
	int partition(vector<int>& a, int p, int r)
	{
		int x = a[r];
		int j = p - 1;
		for (int i = p; i <= r - 1; i++) {
			if (a[i] <= x) {
				j++;
				swap(a, j, i);
			}
		}
		swap(a, j + 1, r);
		return j + 1;
	}
	void swap(vector<int>& a, int i, int j)
	{
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
};

//二分查找类：适配者
class BinarySearch
{
public:
	int binarySearch(vector<int>& arr, int key) {
		int low = 0;
		int high = arr.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int midVal = arr[mid];
			if (midVal < key) {
				low = mid + 1;
			}
			else if (midVal > key) {
				high = mid - 1;
			}
			else {
				return 1;
			}
		}
		return -1;
	}
};

//操作适配器：适配器
class OperationAdapter : public ScoreOperation
{
public:
	OperationAdapter() {
		sortObj = new QuickSort();
		searchObj = new BinarySearch();
	}
	vector<int> sort(vector<int>& arr) {
		return sortObj->quickSort(arr);
	}
	int search(vector<int>& arr, int key) {
		return searchObj->binarySearch(arr, key);
	}
	
private:
	QuickSort* sortObj;
	BinarySearch* searchObj;
};

int main()
{
	vector<int> arr = { 84,76,50,69,99,55,44,31,13 };
	vector<int> result;
	int score = -2;
	ScoreOperation* operation = new OperationAdapter();
	result = operation->sort(arr);
	for (int i : result) {
		cout << i << ",";
	}
	cout << "\n";

	cout << "查找成绩99：\n";
	score = operation->search(result, 99);
	if (score != -1) {
		cout << "找到成绩99\n";
	}
	else {
		cout << "没有找到成绩99\n";
	}

	cout << "查找成绩80：\n";
	score = operation->search(result, 80);
	if (score != -1) {
		cout << "找到成绩80\n";
	}
	else {
		cout << "没有找到成绩80\n";
	}
	return 0;
}
