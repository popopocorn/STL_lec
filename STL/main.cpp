//----------------------------------------------------------------------------
// 2025 / 1�б� STL
// 6/19 ����� 15��2�� - �⸻����
//----------------------------------------------------------------------------
// associative container
//	- set<key>			: key�� value�� �������� �ʴ� �����̳�
//	- map<Key, Value>	: ���̵� �׷� - ���
//						  �𵨸� - �ؽ�ó
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

extern bool ����;


int main() {
	
	ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in)
	{
		cout << "���� �б� ����\n\n";
		return -20250602;
	}
	
	multiset<STRING, less<STRING>> s{ istream_iterator<STRING>{in}, {} }; // ������� ����
	save("main.cpp");
	// [����] ��Ƽ�¿� ����� ��� ���ĺ��� ��� Ƚ���� ������ ���� ����϶�
	// �빮�ڴ� �ҹ��ڷ� �ٲپ� ����Ѵ�
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
	// ����Ƚ�� ������������ ����϶�
	for (int i = 0; i < alphaNum.size(); ++i) {
		cout << char('a' + i) << " - " << alphaNum[i] << endl;
	}
}