#include"SortTestHelper.h"

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

	while (leftPos <= leftEnd) // Copy rest of first half
		tmpArray[tmpPos++] = a[leftPos++];

	while (rightPos <= rightEnd) // Copy rest of right half
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
		__shiftDown(a, n, i); //对n个元素heapify,每次shiftDown第i个元素
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		__shiftDown(a, i, 0);//只对前i个元素heapify，交换之后，shiftDown第[0]个元素
	}
}

//方法二：调用STL中的堆
template<typename T>
void heapSTL(vector<T>&a) {
	if (!is_heap(a.begin(), a.end()))
		make_heap(a.begin(), a.end());

	//比自己写的稍快，但比sort_heap慢
	//pop_heap每一次操作把头部最大值移动到最后，剩余的保证堆
	for (auto i = a.end(); i != a.begin();--i) {
		pop_heap(a.begin(), i);
	}

	//最快，比系统sort快
	//sort_heap(a.begin(), a.end());

	//最慢
	//for (int i = a.size() - 1; i > 0; i--) {
	//	swap(a[0], a[i]);
	//	make_heap(a.begin(), a.begin()+i);
	//}
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













//桶排序
//struct ListNode {
//	int val;
//	ListNode *next;
//  ListNode() : val(-1), next(NULL) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode *p) : val(x), next(p) {}
//};
//插入链表，保证有序
ListNode*insert(ListNode*head, int _val) {
	ListNode dummy(-1);
	dummy.next = head;
	ListNode *newNode = new ListNode(_val);
	
	ListNode *pre = &dummy;
	ListNode *cur = head;

	while (cur&&_val >= cur->val) {
		pre = cur;
		cur = cur->next;
	}

	newNode->next = cur;
	pre->next = newNode;

	return dummy.next;
}

ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)return l2;
	if (l2 == nullptr)return l1;

	ListNode dummy(-1);
	ListNode *p = &dummy;

	while (l1&&l2) {
		if (l1->val >= l2->val) {
			p->next = l2;
			l2 = l2->next;
		}else {
			p->next = l1;
			l1 = l1->next;
		}
		p = p->next;
	}
	//指向剩余的部分
	p->next = l1 ? l1 : l2;
	return dummy.next;
}

void bucketSort(vector<int>&a) {
	int BUCKET_NUM = 1+a.size() / 100;
	//初始化BUCKET_NUM个桶，
	vector<ListNode*>buckets;
	ListNode *p=new ListNode[BUCKET_NUM];	
	for (int i = 0; i != BUCKET_NUM; ++i)
		buckets.push_back(&p[i]);

	for (int i = 0; i != a.size(); ++i) {
		int index = a[i] / 100;
		ListNode*head = buckets[index];
		buckets[index] = insert(head, a[i]);
	}

	//删除表头-1的节点
	for (int i = 0; i != BUCKET_NUM; ++i) {
		buckets[i] = buckets[i]->next;
	}

	ListNode*merge = buckets[0];
	for (int i = 1; i != BUCKET_NUM; ++i) {
		merge = mergeTwoLists(merge, buckets[i]);
	}

	for (int i = 0; i != a.size(); ++i) {
		a[i] = merge->val;
		merge = merge->next;
	}
	delete p;
}




//测试
int main() {

	int n = 100000;

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
	vector<int> x(a);
	vector<int> y(a);
	vector<int> z(a);
	//SortTestHelper::testSort("Bubble_Sort", Bubble_Sort, a);
	//SortTestHelper::testSort("BubbleSort", BubbleSort, b);
	//SortTestHelper::testSort("CocktailSort", CocktailSort, c);
	//SortTestHelper::testSort("selectionSort", selectionSort, d);
	//SortTestHelper::testSort("insertionSort", insertionSort, e);
	SortTestHelper::testSort("ShellSort", ShellSort, f);
	SortTestHelper::testSort("mergeSort", mergeSort, g);
	SortTestHelper::testSort("heapSort", heapSort, h);
	//SortTestHelper::testSort("quickSort", quickSort, m);
	SortTestHelper::testSort("bucketSort", bucketSort, x);

	clock_t _startTime = clock();
	sort(y.begin(), y.end());
	clock_t _endTime = clock();
	cout << "sort     : " << double(_endTime - _startTime) / CLOCKS_PER_SEC << " s." << endl;


	clock_t startTime_ = clock();
	make_heap(z.begin(), z.end());
	sort_heap(z.begin(), z.end());
	clock_t endTime_ = clock();
	cout << "sort_heap : " << double(endTime_ - startTime_) / CLOCKS_PER_SEC << " s." << endl;

	cout << endl;



	//近乎有序
	int swapTimes = 100;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap times = " << swapTimes << endl;
	a = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	b = c = d = e = f = g = m =x=y=z= a;
	SortTestHelper::testSort("ShellSort", ShellSort, f);
	SortTestHelper::testSort("mergeSort", mergeSort, g);
	SortTestHelper::testSort("heapSort", heapSort, h);
	//SortTestHelper::testSort("quickSort", quickSort, m);
	SortTestHelper::testSort("bucketSort", bucketSort, x);

	clock_t startTime_2 = clock();
	sort(y.begin(), y.end());
	clock_t endTime_2 = clock();
	cout << "sort      : " << double(endTime_2 - startTime_2) / CLOCKS_PER_SEC << " s." << endl;


	clock_t __startTime = clock();
	make_heap(z.begin(), z.end());
	sort_heap(z.begin(), z.end());
	clock_t __endTime = clock();
	cout << "sort_heap : " << double(__endTime - __startTime) / CLOCKS_PER_SEC << " s." << endl;

	cout << endl;


	//选取[0,10]区间上的数构成大量重复随机数组
	cout << "Test for Volume Duplicate Random Number, size = " << n << ", Number range [0,10]." << endl;
	a = SortTestHelper::generateRandomArray(n, 0, 10);
	b = c = d = e = f = g = m =x=y=z= a;
	SortTestHelper::testSort("ShellSort", ShellSort, f);
	SortTestHelper::testSort("mergeSort", mergeSort, g);
	SortTestHelper::testSort("heapSort", heapSort, h);
	//SortTestHelper::testSort("quickSort", quickSort, m);
	SortTestHelper::testSort("bucketSort", bucketSort, x);

	clock_t startTime_3 = clock();
	sort(y.begin(), y.end());
	clock_t endTime_3 = clock();
	cout << "sort    : " << double(endTime_3 - startTime_3) / CLOCKS_PER_SEC << " s." << endl;

	clock_t startTime__ = clock();
	make_heap(z.begin(), z.end());
	sort_heap(z.begin(), z.end());
	clock_t endTime__ = clock();
	cout << "sort_heap : " << double(endTime__ - startTime__) / CLOCKS_PER_SEC << " s." << endl;

	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}


/******************************测试结果************************************

Test for Random Array, size = 100000, random range [0, 100000]
ShellSort : 1.874 s.
mergeSort : 1.266 s.
heapSort : 1.276 s.
bucketSort : 0.489 s.
sort     : 0.113 s.
sort_heap : 0.095 s.

Test for Random Nearly Ordered Array, size = 100000, swap times = 100
ShellSort : 0.821 s.
mergeSort : 1.112 s.
heapSort : 1.336 s.
bucketSort : 0.37 s.
sort      : 0.055 s.
sort_heap : 0.091 s.

Test for Volume Duplicate Random Number, size = 100000, Number range [0,10].
ShellSort : 0.884 s.
mergeSort : 1.251 s.
heapSort : 1.307 s.
bucketSort : 29.607 s.
sort    : 0.022 s.
sort_heap : 0.089 s.


**********************************************************************2018*7*2*/