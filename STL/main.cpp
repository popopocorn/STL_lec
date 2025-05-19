//----------------------------------------------------------------------------
// 2025 / 1학기 STL
// 6/19 목요일 15주2일 - 기말시험
//----------------------------------------------------------------------------
// 반복자 - 서로 다른 자료구조에서 c++프로그램이 동일한 방식으로
//			가능하게 해주는 것
// Iterators are a generalization of pointers that allow a C++ program to work 
// with different data structures in a uniform manner.
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
#include"STRING.h"
using namespace std;
//----------------------------------------------------------------------------
#include<vector>
//----------------------------------------------------------------------------

extern bool 관찰;



int main() {

	STRING s{ "2025. 5. 15" };


	// [예고] s를 거꾸로 출력하시오
	for (char c : s)
		cout << c << "----";
	cout << endl;

	save("main.cpp");
}
