//----------------------------------------------------------------------------
// 2025/1학기 STL
//----------------------------------------------------------------------------
//	STL container - Containers are objects that store other objects.
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

	vector<int> v;

	cout << "원소 개수 - " << v.size() << endl;
	cout << "담을 수 있는 원소 개수 - " << v.capacity() << endl;
	cout << "자원 주수 - " << v.data() << endl;

	cout << endl;
	cout << "원소 한 개 추가 한 후 vector v의 field" << endl;
	v.push_back(1);

	cout << "원소 개수 - " << v.size() << endl;
	cout << "담을 수 있는 원소 개수 - " << v.capacity() << endl;
	cout << "자원 주수 - " << v.data() << endl;

	save("main.cpp");
}