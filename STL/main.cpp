//----------------------------------------------------------------------------
// 2025 / 1�б� STL
// 6/19 ����� 15��2�� - �⸻����
//----------------------------------------------------------------------------
// unordered associative container - hash ���
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
#include"STRING.h"
using namespace std;
//----------------------------------------------------------------------------
#include<unordered_set>
#include<string>
//----------------------------------------------------------------------------

extern bool ����;


int main() {
	unordered_set<string> us{"1", "22", "333", "4444", "55555"};
	us.insert("666666");
	for (const string& s : us)
		cout << s << endl;
	cout << std::hash<string>{}("666666") << endl;
	cout << std::hash<string>{}("4444") << endl;
	save("main.cpp");
}