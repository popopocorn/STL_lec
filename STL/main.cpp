//----------------------------------------------------------------------------
// 2025 / 1학기 STL
// 6/19 목요일 15주2일 - 기말시험
//----------------------------------------------------------------------------
// associative container
//	- set<key>			: key와 value를 구분하지 않는 컨테이너
//	- map<Key, Value>	: 아이돌 그룹 - 멤버
//						  모델링 - 텍스처
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
#include"STRING.h"
using namespace std;
//----------------------------------------------------------------------------
#include<fstream>
#include<array>
#include<set>
//----------------------------------------------------------------------------

extern bool 관찰;


int main() {
	
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
	{
		cout << "파일 읽기 실패\n\n";
		return -20250602;
	}
	
	multiset<STRING, less<STRING>> s{ istream_iterator<STRING>{in}, {} }; // 사용하지 말것
	save("main.cpp");
	// [문제] 멀티셋에 저장된 모든 알파벳의 사용 횟수를 다음과 같이 출력하라
	// 대문자는 소문자로 바꾸어 취급한다
	// a - 320
	// b - 645
	// ...
	// z - 2
	array<size_t, 26> alphaNum{};
	for (const STRING w : s) {
		for (char c : w) {
			if(isalpha(c)){
				c = tolower(c);
				alphaNum[c - 'a']++;
			}
		}
	}
	// 출현횟수 내림차순으로 출력하라
	for (int i = 0; i < alphaNum.size(); ++i) {
		cout << char('a' + i) << " - " << alphaNum[i] << endl;
	}
}