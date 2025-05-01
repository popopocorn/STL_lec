//----------------------------------------------------------------------------
// 2025/1�б� STL
//----------------------------------------------------------------------------
// STL container - Containers are objects that store other objects.
// array<T, N> - �����ϰ� ũ�Ⱑ ����
// vector<T> - random access�� ����, []������ ����O(1)�ð��� access ����, push_back�� O(1)
// deque<T> - random access�� ����, []������ ����O(1)�ð��� access ����, O(1) push_front, push_back
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

extern bool ����;


int main() {
	deque<int>d;
	
	save("main.cpp");
}