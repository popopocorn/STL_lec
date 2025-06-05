//----------------------------------------------------------------------------
// 2025 / 1학기 STL
// 6/19 목요일 15주2일 - 기말시험
//----------------------------------------------------------------------------
// unordered associative container - hash 기반
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
#include"STRING.h"
using namespace std;
//----------------------------------------------------------------------------
#include<unordered_set>
#include<string>
//----------------------------------------------------------------------------

extern bool 관찰;


int main() {
	unordered_set<string> us{"1", "22", "333", "4444", "55555"};
	us.insert("666666");
	for (const string& s : us)
		cout << s << endl;
	cout << std::hash<string>{}("666666") << endl;
	cout << std::hash<string>{}("4444") << endl;
	save("main.cpp");
}