#pragma once
#include<cassert>
#include<windows.h>
#include<iostream>
#include<sstream>
#include <ostream>
#include<iomanip>
using std::ios;
using std::setw;
using std::fill;
using std::fill_n;
using std::copy;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<stack>
using std::stack;

#include<list>
using std::list;

#include <queue>
using std::queue;

#include <numeric>
#include <algorithm>
using std::min;
using std::max;
using std::sort;
using std::swap;
using std::next_permutation;
using std::accumulate;
using std::minus;

#include <functional> 
using std::bit_xor;

#include<set>
using std::set;

#include<utility>
using std::pair;
using std::make_pair;

#include<map>
#include<unordered_map>
using std::unordered_map;
using std::unordered_multimap;
using std::map;

using std::endl;
using std::cin;
using std::cout;
using std::to_string;
using std::stringstream;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *p) : val(x), next(p) {}
};

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template<typename T>
void print_vector(const vector<T>&vec)
{
	cout << "[";
		
		bool h=true;
		for (int i=0;i!=vec.size();++i)
		{
			if (h)
			{
				h = false;
				cout<< /*setiosflags(ios::right)<< setw(3)<<*/ vec[i];
			}
			else
			{
				cout << ",";
				cout << /*setiosflags(ios::right) << setw(5) <<*/ vec[i];
			}
		}
		cout << "]" << "\n";
}

template<typename T>
void __print_Link_Node(const T *head) {
	while (head) {
		if (head->next) {
			cout << head->val << "->";
		}
		else {
			cout << head->val << endl;
		}
		head = head->next;
	}
}