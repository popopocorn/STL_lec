//----------------------------------------------------------------------------
// 2025/1�б� STL
// 6/19 ����� 15��2�� - �⸻����
// 5/12 ������ - ������ǰ ����(16:00~) ������ ��� ����
//----------------------------------------------------------------------------
// STL container - Containers are objects that store other objects.
// array<T, N> - �����ϰ� ũ�Ⱑ ����
// vector<T> - random access�� ����, []������ ����O(1)�ð��� access ����, 
//			push_back�� O(1)
// deque<T> - random access�� ����, []������ ����O(1)�ð��� access ����, 
//			O(1) push_front, push_back
// List<T> - O(1) insert, delete, �ڷ� ������ Ȱ���� ���� �Լ� ����
//														(remove, sort, splice)
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
#include"STRING.h"
using namespace std;
//----------------------------------------------------------------------------
#include<list>
#include<fstream>
#include<algorithm>
//----------------------------------------------------------------------------

extern bool ����;


int main() {
	
	// [����] "main.cpp"�� �ܾ list�� ��� �����϶�


	ifstream in{ "main.cpp" };
	if (not in) {
		return 90909090;
	}
	STRING t;

	list<STRING> words{ istream_iterator<STRING>{in},{} };


	// [����] ����ڰ� �Է��� �ܾ ����Ʈ�� �ִ� �� �˷�����
	// �ܾ ������ ���ٰ� ����ϰ�, ������ ����Ʈ�� ��� ° �ܾ����� ����϶�.

	while (true)
	{
		STRING w;
		cout << "ã�� �ܾ��: ";
		cin >> w;
		auto finded = find(words.begin(), words.end(), w);
		if (finded != words.end()) {
			cout << *finded;
		}
		else {
			cout << "����\n";
		}


	}


	save("main.cpp");
}