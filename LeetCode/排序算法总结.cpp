#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<ctime>
#include <string>
#include <cmath>
using namespace std;




//冒泡排序 稳定 O(N^2)
//把最大的沉到数组末尾
template<typename T>
void Bubble_Sort(vector<T>&a){
	int len = a.size();
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (a[j] > a[j + 1])			
				swap(a[j], a[j + 1]);
}
//把最小的浮出到数组开头
template<typename T>
void BubbleSort(vector<T>&a){
	int len = a.size();
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = len - 1; j >i; --j)
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
}
//冒泡排序的改进：鸡尾酒排序
template<typename T>
void CocktailSort(vector<T>&a){
	int left = 0;                            // 初始化边界
	int right = a.size() - 1;
	while (left < right){
		// 前半轮,将最大元素放到后面	
		for (int i = left; i < right; i++){   	
			if (a[i] > a[i + 1])
				swap(a[i] , a[i + 1]);
		}
		right--;
		// 后半轮,将最小元素放到前面
		for (int i = right; i > left; i--){   		
			if (a[i - 1] > a[i])
				swap(a[i - 1] , a[i]);
		}
		left++;
	}
}















//选择排序 O(N^2) 不稳定
template<typename T>
void selectionSort(vector<T>&a){
	int n = a.size();
	for (int i = 0; i != n - 1; ++i){
		int minIndex = i;
		for (int j = i + 1; j != n; ++j)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		if (i != minIndex)//减少自身交换
			swap(arr[i], arr[minIndex]);
	}
}
















//插入排序 平均O(N^2) 稳定
//填坑，把前面比他大的排好序的元素依次往后移动一个元素，直到遇到前面一个数比他小 然后把i插入坑里面
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
	for (int gap = a.size() / 2; gap != 0; --gap) {
		for (int i = gap; i<a.size(); i++) {
			T tmp = a[i];
			int j=i;
			for (; j >= gap && tmp<a[j - gap]; j-=gap)
				a[j] = a[j - gap];
			a[j] = tmp;
		}
	}
}











//归并排序(Merge Sort) 稳定
// 最差时间复杂度 ---- O(N*logN)
// 最优时间复杂度 ---- O(N*logN)
// 平均时间复杂度 ---- O(N*logN)
template<typename T>
void mergeSort(vector<T>&a) {
	vector<T>tmpArray(a.size());
	mergeSort(a,tmpArray, 0, a.size() - 1);
}
template<typename T>
void mergeSort(vector<T>&a,vector<T>&tmpArray,int left,int right) {	
	if (left == right) return;// 当待排序的序列长度为1时，递归开始回溯，进行merge操作

	int center = (left + right) / 2;
	mergeSort(a, tmpArray, left, center);
	mergeSort(a, tmpArray, center + 1, right);
	merge(a, tmpArray, left, center + 1, right);	
}
template <typename T>
void merge(vector<T> & a, vector<T> & tmpArray,	int leftPos, int rightPos, int rightEnd){
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

// 平均时间复杂度 ---- O(N*logN)
template<typename T>
void insertionSort(vector<T>&a,int left,int right) {
	for (int i = left+1; i<=right; i++) {
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






//测试用例
int main2() {
	

	srand(time(nullptr));

	cout << endl << "快排：" << endl;
	vector<int>x;
	for (int i = 0; i < 100; i++)
		x.push_back(rand() % 1000);

	for (int i=0 ;i<20;i++ )
		cout << x[i] << "  ";
	cout << endl;

	clock_t startTime = clock();
	quickSort(x);
	clock_t endTime = clock();
	cout << " 耗费时间: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	for (int i = 0; i<20; i++)
		cout << x[i] << "  ";
	cout << endl;

	system("pause");
	return 0;
}

/*
花费一晚上，集中时间把排序算法梳理了一遍，参考资料如下：
[1]  Mark Allen Weiss. 数据结构与算法分析 C++描述(第3版)[M]. 人民邮电出版社, 2007.
[2]  Adam Drozdek. C++数据结构与算法(第4版)[M]. 清华大学出版社, 2014.
[3]  维基百科.排序算法.
[4]  常用排序算法总结(一) http://www.cnblogs.com/eniac12/p/5329396.html#s5
[5]  常用排序算法总结(二) http://www.cnblogs.com/eniac12/p/5332117.html
*/