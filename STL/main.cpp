//----------------------------------------------------------------------------
// 2025/1�б� STL
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

extern bool ����;



int main() {

	vector<int> v;

	cout << "���� ���� - " << v.size() << endl;
	cout << "���� �� �ִ� ���� ���� - " << v.capacity() << endl;
	cout << "�ڿ� �ּ� - " << v.data() << endl;

	cout << endl;
	cout << "���� �� �� �߰� �� �� vector v�� field" << endl;
	v.push_back(1);

	cout << "���� ���� - " << v.size() << endl;
	cout << "���� �� �ִ� ���� ���� - " << v.capacity() << endl;
	cout << "�ڿ� �ּ� - " << v.data() << endl;

	save("main.cpp");
}