#include "SortTestHelper.h"


//sort.cpp

//冒泡排序 稳定 O(N^2)
//把最大的沉到数组末尾
template<typename T>
void Bubble_Sort(vector<T>&a) {
	int len = a.size();
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}
//把最小的浮出到数组开头
template<typename T>
void BubbleSort(vector<T>&a) {
	int len = a.size();
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = len - 1; j >i; --j)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
//冒泡排序的改进：鸡尾酒排序
template<typename T>
void CocktailSort(vector<T>&a) {
	int left = 0;
	int right = a.size() - 1;
	while (left < right) {
		// 前半轮,将最大元素放到后面
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		right--;
		// 后半轮,将最小元素放到前面
		for (int i = right; i > left; i--) {
			if (a[i - 1] > a[i])
				swap(a[i - 1], a[i]);
		}
		left++;
	}
}















//选择排序 O(N^2) 不稳定
template<typename T>
void selectionSort(vector<T>&a) {
	int n = a.size();
	for (int i = 0; i != n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j != n; ++j)
			if (a[j] < a[minIndex])
				minIndex = j;
		if (i != minIndex)//减少自身交换
			swap(a[i], a[minIndex]);
	}
}
















//插入排序 平均O(N^2) 稳定
//填坑，把前面比他大的排好序的元素依次往后移动一个元素
//直到遇到前面一个数比他小 然后把i插入坑里面
//如果输入数据预先排序，运行时间为O(N），因为内层循环的检测总是立即判定不成立而终止。
//用于少量元素的排序
template<typename T>
void insertionSort(vector<T>&a) {
	for (int i = 1; i<a.size(); i++) {
		T tmp = a[i];
		int j;
		for (j = i; j > 0 && tmp<a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}
//插入排序的高效改进：希尔排序(Shell Sort)
//不稳定
//可能有更好的增量
template<typename T>
void ShellSort(vector<T>&a) {
	for (int gap = a.size() / 2; gap != 0; gap /= 2) {
		for (int i = gap; i<a.size(); i++) {
			T tmp = a[i];
			int j = i;
			for (; j >= gap && tmp<a[j - gap]; j -= gap)
				a[j] = a[j - gap];
			a[j] = tmp;
		}
	}
}











//归并排序(Merge Sort) 稳定
//最差时间复杂度 ---- O(N*logN)
//最优时间复杂度 ---- O(N*logN)
//平均时间复杂度 ---- O(N*logN)
template <typename T>
void merge(vector<T> & a, vector<T> & tmpArray, int leftPos, int rightPos, int rightEnd) {
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	// Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd)
		if (a[leftPos] <= a[rightPos])
			tmpArray[tmpPos++] = a[leftPos++];
		else
			tmpArray[tmpPos++] = a[rightPos++];

	while (leftPos <= leftEnd)    // Copy rest of first half
		tmpArray[tmpPos++] = a[leftPos++];

	while (rightPos <= rightEnd)  // Copy rest of right half
		tmpArray[tmpPos++] = a[rightPos++];

	// Copy tmpArray back
	for (int i = 0; i < numElements; i++, rightEnd--)
		a[rightEnd] = tmpArray[rightEnd];
}
template<typename T>
void mergeSort(vector<T>&a, vector<T>&tmpArray, int left, int right) {
	if (left == right) return;// 当待排序的序列长度为1时，递归开始回溯，进行merge操作

	int center = (left + right) / 2;
	mergeSort(a, tmpArray, left, center);
	mergeSort(a, tmpArray, center + 1, right);
	merge(a, tmpArray, left, center + 1, right);
}
template<typename T>
void mergeSort(vector<T>&a) {
	vector<T>tmpArray(a.size());
	mergeSort(a, tmpArray, 0, a.size() - 1);
}


















//堆排序(Heap Sort) 不稳定
//O(N*logN)
template<typename T>
void __shiftDown(vector<T>&a, int n, int k) {
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
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
		__shiftDown(a, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		__shiftDown(a, i, 0);
	}
}










//快速排序(Quick Sort) 不稳定
// 最差 ---- 每次选取的基准都是最大（或最小）的元素
//导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(N^2)

//最优 ---- 每次选取的基准都是中位数,这样每次都均匀的划分出两个分区
//只需要logN次划分就能结束递归，时间复杂度为O(N*logN)

//平均时间复杂度 ---- O(N*logN)
template<typename T>
void insertionSort(vector<T>&a, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		T tmp = a[i];
		int j;
		for (j = i; j > left && tmp<a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}
template<typename T>
const T& median3(vector<T>&a, int left, int right) {
	int center = (left + right) / 2;
	if (a[center] < a[left])swap(a[center], a[left]);
	if (a[right] < a[left])swap(a[right], a[left]);
	if (a[right] < a[center])swap(a[right], a[center]);
	swap(a[center], a[right - 1]);
	return a[right - 1];
}
template<typename T>
void quickSort(vector<T>&a, int left, int right) {
	if (right - left > 10) {
		T pivot = median3(a, left, right);
		int i = left + 1;
		int j = right - 2;
		for (;;) {
			while (a[i] < pivot)i++;
			while (pivot < a[j])j++;
			if (i < j)swap(a[i], a[j]);
			else break;
		}
		swap(a[i], a[right - 1]);//把主元放到分界线
		quickSort(a, left, i - 1);
		quickSort(a, i + 1, right);
	}
	else
		insertionSort(a, left, right);
}
template<typename T>
void quickSort(vector<T>&a) {
	quickSort(a, 0, a.size() - 1);
}






//测试
int main() {

	int n = 10000;
	
	//一般性测试
	cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
	vector<int> a = SortTestHelper::generateRandomArray(n, 0, n);
	vector<int> b(a);
	vector<int> c(a); 
	vector<int> d(a); 
	vector<int> e(a); 
	vector<int> f(a); 
	vector<int> g(a); 
	vector<int> h(a);
	vector<int> m(a);
	SortTestHelper::testSort("Bubble_Sort", Bubble_Sort, a);
	SortTestHelper::testSort("BubbleSort", BubbleSort, b);
	SortTestHelper::testSort("CocktailSort", CocktailSort, c);
	SortTestHelper::testSort("selectionSort", selectionSort, d);
	SortTestHelper::testSort("insertionSort", insertionSort, e);
	SortTestHelper::testSort("ShellSort", ShellSort, f);
	SortTestHelper::testSort("mergeSort", mergeSort, g);
	SortTestHelper::testSort("heapSort", heapSort, h);
	SortTestHelper::testSort("quickSort", quickSort, m);
	cout << endl;
		

	
	//近乎有序
	int swapTimes = 100;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap times = " << swapTimes << endl;
	a = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	b=c=d=e=f=g=m=a;
	SortTestHelper::testSort("Bubble_Sort", Bubble_Sort, a);
	SortTestHelper::testSort("BubbleSort", BubbleSort, b);
	SortTestHelper::testSort("CocktailSort", CocktailSort, c);
	SortTestHelper::testSort("selectionSort", selectionSort, d);
	SortTestHelper::testSort("insertionSort", insertionSort, e);
	SortTestHelper::testSort("ShellSort", ShellSort, f);
	SortTestHelper::testSort("mergeSort", mergeSort, g);
	SortTestHelper::testSort("heapSort", heapSort, h);
	SortTestHelper::testSort("quickSort", quickSort, m);
	cout << endl;


	//选取[0,10]区间上的数构成大量重复随机数组
	cout << "Test for Volume Duplicate Random Number, size = " << n << ", Number range [0,10]."  << endl;
	a = SortTestHelper::generateRandomArray(n, 0, 10);
	b = c = d = e = f = g = m = a;
	SortTestHelper::testSort("Bubble_Sort", Bubble_Sort, a);
	SortTestHelper::testSort("BubbleSort", BubbleSort, b);
	SortTestHelper::testSort("CocktailSort", CocktailSort, c);
	SortTestHelper::testSort("selectionSort", selectionSort, d);
	SortTestHelper::testSort("insertionSort", insertionSort, e);
	SortTestHelper::testSort("ShellSort", ShellSort, f);
	SortTestHelper::testSort("mergeSort", mergeSort, g);
	SortTestHelper::testSort("heapSort", heapSort, h);
	SortTestHelper::testSort("quickSort", quickSort, m);
	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}



/*
测试结果(Realease版本x64):
数据量十万.
Test for Random Array, size = 100000, random range [0, 100000]
Bubble_Sort : 11.887 s.
BubbleSort : 11.365 s.
CocktailSort : 9.283 s.
selectionSort : 8.005 s.
insertionSort : 1.006 s.
ShellSort : 0.01 s.
mergeSort : 0.007 s.
heapSort : 0.007 s.
quickSort : 0.006 s.

Test for Random Nearly Ordered Array, size = 100000, swap times = 100
Bubble_Sort : 2.521 s.
BubbleSort : 4.092 s.
CocktailSort : 3.725 s.
selectionSort : 8.017 s.
insertionSort : 0.001 s.
ShellSort : 0.003 s.
mergeSort : 0.003 s.
heapSort : 0.004 s.
quickSort : 0.004 s.

Test for Volume Duplicate Random Number, size = 100000, Number range [0,10].
Bubble_Sort : 11.785 s.
BubbleSort : 11.58 s.
CocktailSort : 9.851 s.
selectionSort : 8.004 s.
insertionSort : 1.073 s.
ShellSort : 0.004 s.
mergeSort : 0.005 s.
heapSort : 0.004 s.
quickSort : 0.337 s.



测试结果(Realease版本x64):
数据量一万.
Test for Random Array, size = 10000, random range [0, 10000]
Bubble_Sort : 0.134 s.
BubbleSort : 0.101 s.
CocktailSort : 0.09 s.
selectionSort : 0.082 s.
insertionSort : 0.011 s.
ShellSort : 0.001 s.
mergeSort : 0 s.
heapSort : 0 s.
quickSort : 0.001 s.

Test for Random Nearly Ordered Array, size = 10000, swap times = 100
Bubble_Sort : 0.032 s.
BubbleSort : 0.047 s.
CocktailSort : 0.039 s.
selectionSort : 0.082 s.
insertionSort : 0.001 s.
ShellSort : 0 s.
mergeSort : 0 s.
heapSort : 0.001 s.
quickSort : 0 s.

Test for Volume Duplicate Random Number, size = 10000, Number range [0,10].
Bubble_Sort : 0.097 s.
BubbleSort : 0.094 s.
CocktailSort : 0.08 s.
selectionSort : 0.08 s.
insertionSort : 0.016 s.
ShellSort : 0 s.
mergeSort : 0.001 s.
heapSort : 0 s.
quickSort : 0.004 s.



测试结果(Debug版本x86):
数据量一万.
Test for Random Array, size = 10000, random range [0, 10000]
Bubble_Sort : 24.096 s.
BubbleSort : 24.303 s.
CocktailSort : 24.32 s.
selectionSort : 14.983 s.
insertionSort : 11.447 s.
ShellSort : 0.123 s.
mergeSort : 0.108 s.
heapSort : 0.107 s.
quickSort : 0.057 s.

Test for Random Nearly Ordered Array, size = 10000, swap times = 100
Bubble_Sort : 15.375 s.
BubbleSort : 15.443 s.
CocktailSort : 15.361 s.
selectionSort : 14.972 s.
insertionSort : 0.291 s.
ShellSort : 0.085 s.
mergeSort : 0.101 s.
heapSort : 0.112 s.
quickSort : 0.052 s.

Test for Volume Duplicate Random Number, size = 10000, Number range [0,10].
Bubble_Sort : 23.073 s.
BubbleSort : 23.023 s.
CocktailSort : 23.055 s.
selectionSort : 15.174 s.
insertionSort : 10.466 s.
ShellSort : 0.077 s.
mergeSort : 0.108 s.
heapSort : 0.122 s.
quickSort : 0.671 s.






花费一晚上，集中时间把排序算法梳理了一遍，参考资料如下：
[1]  Mark Allen Weiss. 数据结构与算法分析 C++描述(第3版)[M]. 人民邮电出版社, 2007.
[2]  Adam Drozdek. C++数据结构与算法(第4版)[M]. 清华大学出版社, 2014.
[3]  维基百科.排序算法.
[4]  常用排序算法总结(一) http://www.cnblogs.com/eniac12/p/5329396.html#s5
[5]  常用排序算法总结(二) http://www.cnblogs.com/eniac12/p/5332117.html
*/