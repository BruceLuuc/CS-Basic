#include<iostream>
#include<cassert>
#include<algorithm>
#include<ctime>
#include <string>
#include <cmath>
#include<vector>
using namespace std;
//E盘视频教程 整理

//根节点从1
template<typename T>
class MaxHeap {
public:
	MaxHeap(int capacity) {
		data = new T[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	MaxHeap(vector<T>&a) {
		data = new T[a.size() + 1];
		capacity = a.size();
		for (int i = 0; i < a.size(); i++)
			data[i + 1] = a[i];
		count = a.size();
		for (int i = count / 2; i >= 1; i--)
			shiftDown(i);
	}
	~MaxHeap() { delete[] data; }
	int size() { return count; }
	bool isEmpty() { return count == 0; }
	void insert(T item) { 
		assert(count + 1 <= capacity);
		data[count + 1] = item; 
		count++; 
		shiftUp(count);
	}
	T extractMax() {
		assert(count > 0);
		T res = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return res;
	}
	void print() {
		cout << "The heap size is:"<<size()<<endl;
		cout << "data in heap:";
		if (count) {
			for (int i=1;i<=count;i++)
				cout << data[i] << "  ";
		}
		cout << endl;
		int n = size();
		int max_level = 0;
		int number_per_level = 1;
		while (n > 0) {
			max_level += 1;
			n -= number_per_level;
			number_per_level *= 2;
		}

		int max_level_number = int(pow(2, max_level - 1));
		int cur_tree_max_level_number = max_level_number;
		int index = 1;
		for (int level = 0; level < max_level; level++) {
			string line1 = string(max_level_number * 3 - 1, ' ');

			int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
			bool isLeft = true;
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
				putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
				isLeft = !isLeft;
			}
			cout << line1 << endl;

			if (level == max_level - 1)
				break;

			string line2 = string(max_level_number * 3 - 1, ' ');
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
				putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
			cout << line2 << endl;

			cur_tree_max_level_number /= 2;
		}
	}
private:
	T * data;
	int count;
	int capacity;
	void shiftUp(int k) {
		while(k>1 && data[k / 2] < data[k]) {
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	void shiftDown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] > data[j])
				j += 1;
			if (data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}
	void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
		assert(offset + 1 < line.size());
		if (num >= 10) {
			line[offset + 0] = '0' + num / 10;
			line[offset + 1] = '0' + num % 10;
		}
		else {
			if (isLeft)
				line[offset + 0] = '0' + num;
			else
				line[offset + 1] = '0' + num;
		}
	}

	void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int sub_sub_tree_width = (sub_tree_width - 1) / 2;
		int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
		assert(offset_left + 1 < line.size());
		int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
		assert(offset_right < line.size());

		line[offset_left + 1] = '/';
		line[offset_right + 0] = '\\';
	}
};


//使用堆排序
template<typename T>
void heapSort1(vector<T>&a) {
	MaxHeap<T>heap(a.size());
	for (int i = 0; i < a.size(); i++)
		heap.insert(a[i]);
	for (int i = a.size() - 1; i >= 0; i--)
		a[i] = heap.extractMax();
}
template<typename T>
void heapSort2(vector<T>&a) {
	MaxHeap<T>heap(a);
	for (int i = a.size() - 1; i >= 0; i--)
		a[i] = heap.extractMax();
}

//原地堆排序
template<typename T>
void __shiftDown(vector<T>&a,int n, int k) {
	while (2 * k+1 < n) {
		int j = 2 * k+1;
		if (j + 1 < n && a[j + 1] > a[j])
			j += 1;
		if (a[k] >= a[j])
			break;
		swap(a[k], a[j]);
		k = j;
	}
}
template<typename T>
void heapSort(vector<T>&a) {
	//heapify
	int n = a.size();
	for (int i = (n - 1) / 2; i >= 0; i--)
		__shiftDown(a, n,i);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		__shiftDown(a,i, 0);
	}
}








//快速排序
//返回P，使得a[l,……,p-1]<a[p];a[p+1,……,r]>a[p]
template<typename T>
int __partition(vector<T>&a, int l, int r) {
	swap(a[l], a[rand() % (r - l + 1) + l]);
	T v = a[l];//选第一个为枢纽
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < v)
			swap(a[++j], a[i]);		
	}
	swap(a[l], a[j]);
	return j;
}
template<typename T>
void __quickSort(vector<T>&a, int l, int r) {
	if (l >= r)return;
	int p = __partition(a, l, r);
	__quickSort(a, l, p - 1);
	__quickSort(a, p + 1, r);
}
template<typename T>
void quickSort(vector<T>&a) {
	srand(time(nullptr));
	__quickSort(a, 0, a.size() - 1);
}









int main1____() {
	MaxHeap<int>heap(100);

	srand(time(nullptr));
	for (int i = 0; i < 15; i++)
		heap.insert(rand() % 100);

	heap.print();

	while (!heap.isEmpty()) {
		cout << heap.extractMax() << "  ";
	}

	cout <<endl<< "测试堆排序：" << endl;
	vector<int>x;
	for (int i = 0; i < 15; i++)
		x.push_back(rand() % 100);
	for (auto i : x)
		cout << i << "  ";
	cout << endl;

	quickSort(x);
	for (auto i : x)
		cout << i << "  ";
	cout << endl;

	system("pause");
	return 0;
}