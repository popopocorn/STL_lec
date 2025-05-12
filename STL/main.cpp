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


	save("main.cpp");
	// [문제] "main.cpp"의 단어를 list에 모두 저장하라


	ifstream in{ "main.cpp" };
	if (not in) {
		return 90909090;
	}

	list<STRING> words{ istream_iterator<STRING>{in},{} };
	
	// [문제] 단어들에서 길이가 5인 것들만 화면에 출력하라

	copy(words.begin(), words.end(), 
				ostream_iterator<STRING>{cout, "\n"}
	);

	// 다음시간에 계속...!!!!!!!!!!!

	
}