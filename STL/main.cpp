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


	save("main.cpp");
	// [����] "main.cpp"�� �ܾ list�� ��� �����϶�


	ifstream in{ "main.cpp" };
	if (not in) {
		return 90909090;
	}

	list<STRING> words{ istream_iterator<STRING>{in},{} };
	
	// [����] �ܾ�鿡�� ���̰� 5�� �͵鸸 ȭ�鿡 ����϶�

	copy(words.begin(), words.end(), 
				ostream_iterator<STRING>{cout, "\n"}
	);

	// �����ð��� ���...!!!!!!!!!!!

	
}