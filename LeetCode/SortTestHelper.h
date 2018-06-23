#include "x.h"


//SortTestHelper.h
#ifndef _QUICK_SORT_THREE_WAYS_SORTTESTHELPER_H
#define _QUICK_SORT_THREE_WAYS_SORTTESTHELPER_H

namespace SortTestHelper {

    vector<int> generateRandomArray(int n, int range_l, int range_r) {

		vector<int>x;

        srand(time(nullptr));
        for (int i = 0; i < n; i++)
			x.push_back(rand() % (range_r - range_l + 1) + range_l);
        return x;
    }

	vector<int> generateNearlyOrderedArray(int n, int swapTimes){

		vector<int>x;
        for(int i = 0 ; i < n ; i ++ )
			x.push_back(i);

        srand(time(nullptr));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( x[posx] , x[posy] );
        }

        return x;
    }


    template<typename T>
    void printArray(vector<T>&a) {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }

    template<typename T>
    void printArray(vector<T>&a, int l, int r) {
        for (int i = l; i <= r; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }

    template<typename T>
    bool isSorted(vector<T>&a) {
        for (int i = 0; i < a.size() - 1; i++)
            if (a[i] > a[i + 1])
                return false;
        return true;
    }

    template<typename T>
    void testSort(const string &sortName, void (*sort)(vector<T>&a), vector<T>&a) {

        clock_t startTime = clock();
        sort(a);
        clock_t endTime = clock();
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s."<<endl;

        assert(isSorted(a));

        return;
    }

};

#endif
