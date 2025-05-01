//----------------------------------------------------------------------------
// 2025/1학기 STL
//----------------------------------------------------------------------------
// STL container - Containers are objects that store other objects.
// array<T, N> - 유일하게 크기가 고정
// vector<T> - random access가 가능, []연산자 제공O(1)시간에 access 가능, push_back도 O(1)
// deque<T> - random access가 가능, []연산자 제공O(1)시간에 access 가능, O(1) push_front, push_back
// 
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
#include"STRING.h"
using namespace std;
//----------------------------------------------------------------------------
#include<algorithm>
#include<deque>

//----------------------------------------------------------------------------

extern bool 관찰;


int main() {
	deque<int>d;
	
	save("main.cpp");
}