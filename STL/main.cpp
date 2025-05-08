//----------------------------------------------------------------------------
// 2025/1학기 STL
// 6/19 목요일 15주2일 - 기말시험
// 5/12 월요일 - 졸업작품 예정(16:00~) 끝나는 대로 수업
//----------------------------------------------------------------------------
// STL container - Containers are objects that store other objects.
// array<T, N> - 유일하게 크기가 고정
// vector<T> - random access가 가능, []연산자 제공O(1)시간에 access 가능, 
//			push_back도 O(1)
// deque<T> - random access가 가능, []연산자 제공O(1)시간에 access 가능, 
//			O(1) push_front, push_back
// List<T> - O(1) insert, delete, 자료 구조를 활용한 전용 함수 제공
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

extern bool 관찰;


int main() {
	
	// [문제] "main.cpp"의 단어를 list에 모두 저장하라


	ifstream in{ "main.cpp" };
	if (not in) {
		return 90909090;
	}
	STRING t;

	list<STRING> words{ istream_iterator<STRING>{in},{} };


	// [문제] 사용자가 입력한 단어가 리스트에 있는 지 알려주자
	// 단어가 없으면 없다고 출력하고, 있으면 리스트의 몇번 째 단어인지 출력하라.

	while (true)
	{
		STRING w;
		cout << "찾을 단어는: ";
		cin >> w;
		auto finded = find(words.begin(), words.end(), w);
		if (finded != words.end()) {
			cout << *finded;
		}
		else {
			cout << "없음\n";
		}


	}


	save("main.cpp");
}