#include "SortTestHelper.h"


//sort.cpp

//鍐掓场鎺掑簭 绋冲畾 O(N^2)
//鎶婃渶澶х殑娌夊埌鏁扮粍鏈熬
template<typename T>
void Bubble_Sort(vector<T>&a) {
	int len = a.size();
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}
//鎶婃渶灏忕殑娴嚭鍒版暟缁勫紑澶?
template<typename T>
void BubbleSort(vector<T>&a) {
	int len = a.size();
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = len - 1; j >i; --j)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
//鍐掓场鎺掑簭鐨勬敼杩涳細楦″熬閰掓帓搴?
template<typename T>
void CocktailSort(vector<T>&a) {
	int left = 0;
	int right = a.size() - 1;
	while (left < right) {
		// 鍓嶅崐杞?灏嗘渶澶у厓绱犳斁鍒板悗闈?
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		}
		right--;
		// 鍚庡崐杞?灏嗘渶灏忓厓绱犳斁鍒板墠闈?
		for (int i = right; i > left; i--) {
			if (a[i - 1] > a[i])
				swap(a[i - 1], a[i]);
		}
		left++;
	}
}















//閫夋嫨鎺掑簭 O(N^2) 涓嶇ǔ瀹?
template<typename T>
void selectionSort(vector<T>&a) {
	int n = a.size();
	for (int i = 0; i != n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j != n; ++j)
			if (a[j] < a[minIndex])
				minIndex = j;
		if (i != minIndex)//鍑忓皯鑷韩浜ゆ崲
			swap(a[i], a[minIndex]);
	}
}
















//鎻掑叆鎺掑簭 骞冲潎O(N^2) 绋冲畾
//濉潙锛屾妸鍓嶉潰姣斾粬澶х殑鎺掑ソ搴忕殑鍏冪礌渚濇寰€鍚庣Щ鍔ㄤ竴涓厓绱?
//鐩村埌閬囧埌鍓嶉潰涓€涓暟姣斾粬灏?鐒跺悗鎶奿鎻掑叆鍧戦噷闈?
//濡傛灉杈撳叆鏁版嵁棰勫厛鎺掑簭锛岃繍琛屾椂闂翠负O(N锛夛紝鍥犱负鍐呭眰寰幆鐨勬娴嬫€绘槸绔嬪嵆鍒ゅ畾涓嶆垚绔嬭€岀粓姝€?
//鐢ㄤ簬灏戦噺鍏冪礌鐨勬帓搴?
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
//鎻掑叆鎺掑簭鐨勯珮鏁堟敼杩涳細甯屽皵鎺掑簭(Shell Sort)
//涓嶇ǔ瀹?
//鍙兘鏈夋洿濂界殑澧為噺
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











//褰掑苟鎺掑簭(Merge Sort) 绋冲畾
//鏈€宸椂闂村鏉傚害 ---- O(N*logN)
//鏈€浼樻椂闂村鏉傚害 ---- O(N*logN)
//骞冲潎鏃堕棿澶嶆潅搴?---- O(N*logN)
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
	if (left == right) return;// 褰撳緟鎺掑簭鐨勫簭鍒楅暱搴︿负1鏃讹紝閫掑綊寮€濮嬪洖婧紝杩涜merge鎿嶄綔

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


















//鍫嗘帓搴?Heap Sort) 涓嶇ǔ瀹?
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










//蹇€熸帓搴?Quick Sort) 涓嶇ǔ瀹?
// 鏈€宸?---- 姣忔閫夊彇鐨勫熀鍑嗛兘鏄渶澶э紙鎴栨渶灏忥級鐨勫厓绱?
//瀵艰嚧姣忔鍙垝鍒嗗嚭浜嗕竴涓垎鍖猴紝闇€瑕佽繘琛宯-1娆″垝鍒嗘墠鑳界粨鏉熼€掑綊锛屾椂闂村鏉傚害涓篛(N^2)

//鏈€浼?---- 姣忔閫夊彇鐨勫熀鍑嗛兘鏄腑浣嶆暟,杩欐牱姣忔閮藉潎鍖€鐨勫垝鍒嗗嚭涓や釜鍒嗗尯
//鍙渶瑕乴ogN娆″垝鍒嗗氨鑳界粨鏉熼€掑綊锛屾椂闂村鏉傚害涓篛(N*logN)

//骞冲潎鏃堕棿澶嶆潅搴?---- O(N*logN)
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
		swap(a[i], a[right - 1]);//鎶婁富鍏冩斁鍒板垎鐣岀嚎
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






//娴嬭瘯
int main_() {

	int n = 10000;
	
	//涓€鑸€ф祴璇?
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
		

	
	//杩戜箮鏈夊簭
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


	//閫夊彇[0,10]鍖洪棿涓婄殑鏁版瀯鎴愬ぇ閲忛噸澶嶉殢鏈烘暟缁?
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
娴嬭瘯缁撴灉(Realease鐗堟湰x64):
鏁版嵁閲忓崄涓?
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



娴嬭瘯缁撴灉(Realease鐗堟湰x64):
鏁版嵁閲忎竴涓?
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



娴嬭瘯缁撴灉(Debug鐗堟湰x86):
鏁版嵁閲忎竴涓?
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






鑺辫垂涓€鏅氫笂锛岄泦涓椂闂存妸鎺掑簭绠楁硶姊崇悊浜嗕竴閬嶏紝鍙傝€冭祫鏂欏涓嬶細
[1]  Mark Allen Weiss. 鏁版嵁缁撴瀯涓庣畻娉曞垎鏋?C++鎻忚堪(绗?鐗?[M]. 浜烘皯閭數鍑虹増绀? 2007.
[2]  Adam Drozdek. C++鏁版嵁缁撴瀯涓庣畻娉?绗?鐗?[M]. 娓呭崕澶у鍑虹増绀? 2014.
[3]  缁村熀鐧剧.鎺掑簭绠楁硶.
[4]  甯哥敤鎺掑簭绠楁硶鎬荤粨(涓€) http://www.cnblogs.com/eniac12/p/5329396.html#s5
[5]  甯哥敤鎺掑簭绠楁硶鎬荤粨(浜? http://www.cnblogs.com/eniac12/p/5332117.html
*/