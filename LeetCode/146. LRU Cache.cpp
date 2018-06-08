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
		//(Ҫ�����λ��(�������ǲ��뵽ͷ��),���ĸ�list����(������������,�����Ԫ��)
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);//�ѵ�ǰ���ʵĽڵ��ƶ�������ͷ�������Ҹ���map�иýڵ�ĵ�ַ
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end()) {
			if (cacheList.size() == capacity) { //ɾ������β���ڵ㣬��С���ʵĽڵ�
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			//�����½ڵ㵽����ͷ����������map�����Ӹýڵ�
			cacheList.push_front(CacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else {
			//���½ڵ��ֵ���ѵ�ǰ���ʵĽڵ��ƶ�������ͷ�������Ҹ���map�иýڵ�ĵ�ַ
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;//��ϣ����ÿ���ڵ�ĵ�ַ
	int capacity;

//дһ��������ӡ����
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
	cout << "������ĸ�Ԫ�أ�\n";
	A.printList();
	A.set(5, 5);
	cout << "����������Ԫ�أ�\n";
	A.printList();
	A.set(6, 6);
	A.set(7, 7);
	A.set(8, 8);
	cout << "�����6��7��8��Ԫ�أ�\n";
	A.printList();
	A.set(9, 9);
	A.set(0, 0);
	A.printList();

	


	system("pause");
	return 0;
}