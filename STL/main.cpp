//----------------------------------------------------------------------------
// 2025 / 1�б� STL
// 6/19 ����� 15��2�� - �⸻����
//----------------------------------------------------------------------------
// distance�� ���� - tag dispatch, if constexpr, concept, SFINAE
//----------------------------------------------------------------------------
#include<iostream>
#include"save.h"
#include"STRING.h"
using namespace std;
//----------------------------------------------------------------------------
#include<vector>
#include<list>
#include<algorithm>
//----------------------------------------------------------------------------
extern bool ����;


template<class Iter>
iterator_traits<Iter>::difference_type my_distance(Iter b, Iter e){
	typename iterator_traits<Iter>::difference_type d{};
	while (b != e) {
		++b;
		++d;
	}
	return d;
}
int main() {
	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> c{ 1, 2, 3, 4, 5 };
	cout << my_distance(v.begin(), v.end()) << endl;
	cout << my_distance(c.begin(), c.end()) << endl;



	save("main.cpp");
	
}
