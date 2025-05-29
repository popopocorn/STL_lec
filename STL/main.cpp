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
#include<vector>
#include<set>
//----------------------------------------------------------------------------

extern bool 관찰;

int main() {
	
	// 이상한나라의 엘리스를 다운받는다
	// 1. vector<STRING> v;에 저장하라
	// 2. 모두 몇 단어로 만들었는지 출력하라
	ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
	{
		cout << "파일 읽기 실패\n\n";
		return -336558966555;
	}

	set<STRING> v{ istream_iterator<STRING>{in}, {} }; // 사용하지 말것
	// 하지만 associative에서는 괜찮다
	cout << v.size();
	
	save("main.cpp");
	관찰 = true;
}

