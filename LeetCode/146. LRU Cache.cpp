#include"x.h"
class LRUCache {
private:
	struct CacheNode {
		int key;
		int value;
		CacheNode(int k, int v) :key(k), value(v) {}
	};
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end()) return -1;
		//(要插入的位置(这里总是插入到头部),从哪个list插入(这里是它本身）,插入的元素)
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);//把当前访问的节点移动到链表头部，并且更新map中该节点的地址
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end()) {
			if (cacheList.size() == capacity) { //删除链表尾部节点，最小访问的节点
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			//插入新节点到链表头部，并且在map中增加该节点
			cacheList.push_front(CacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else {
			//更新节点的值，把当前访问的节点移动到链表头部，并且更新map中该节点的地址
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;//哈希表保存每个节点的地址
	int capacity;

//写一个函数打印测试
public:
	void printList() {

		bool once = true;
		for (auto i : cacheList) {
			if (once) {
				once = false;
				cout << i.key << ":" << i.value;
			}
			else {
				cout <<"->"<< i.key << ":" << i.value;
			}			
		}
		cout << endl;
	}
};

int main_146() {
	LRUCache A(5);
	A.set(1, 1);
	A.set(2, 2);
	A.set(3, 3);
	A.set(4, 4);
	cout << "插入的四个元素：\n";
	A.printList();
	A.set(5, 5);
	cout << "插入第五个新元素：\n";
	A.printList();
	A.set(6, 6);
	A.set(7, 7);
	A.set(8, 8);
	cout << "插入第6、7、8新元素：\n";
	A.printList();
	A.set(9, 9);
	A.set(0, 0);
	A.printList();

	


	system("pause");
	return 0;
}